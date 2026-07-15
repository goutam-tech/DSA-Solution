#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

int gNPaths = 0;
const unsigned int kHashSize = 4096 * 16;
vector<set<unsigned int>> gHashTab;
size_t gN = 0;
size_t gNx = 0;

inline void checkThis(const char *knightPath, const unsigned int hashp = 0)
{
    auto hashx = (hashp) ? hashp : std::_Hash_impl::hash(knightPath, gNx, 11);
    auto hashy = std::_Hash_impl::hash(knightPath + gNx, gNx, 11);
    auto hash2 = hashx ^ (hashy << 1);
    auto hash = hashx % kHashSize;

    if (!gHashTab[hash].count(hash2))
    {
        gHashTab[hash].insert(hash2);
        ++gNPaths;
    }
}

void zigs(const string aS, const string bS)
{
    int n = aS.size();

    string raS = aS;
    reverse(raS.begin(), raS.end());

    string rbS = bS;
    reverse(rbS.begin(), rbS.end());

    if (n < 3)
        return;

    vector<char> a(n + 1), b(n + 1), ra(n + 1), rb(n + 1);

    strcpy(a.data(), aS.c_str());
    strcpy(b.data(), bS.c_str());
    strcpy(ra.data(), raS.c_str());
    strcpy(rb.data(), rbS.c_str());

    a[n] = '\0';
    b[n] = '\0';
    ra[n] = '\0';
    rb[n] = '\0';

    int kStart = 0;
    while (kStart < n &&
           a[kStart] == a[0] &&
           b[kStart] == a[0])
        kStart++;

    kStart = max(1, kStart);

    int kEnd = n - 1;
    while (kEnd > 0 &&
           a[kEnd] == a[n - 1] &&
           b[kEnd] == a[n - 1])
        kEnd--;

    kEnd += 2;
    kEnd = min(n + 1, kEnd);

    vector<char> knightPath(gN + 1), revKnightPath(gN + 1);
    knightPath[gN] = '\0';
    revKnightPath[gN] = '\0';

    vector<char> frontLoopTop(gN + 1);
    memcpy(frontLoopTop.data(), ra.data(), n);
    memcpy(frontLoopTop.data() + n, b.data(), n);

    vector<char> frontLoopBottom(gN + 1);
    memcpy(frontLoopBottom.data(), rb.data(), n);
    memcpy(frontLoopBottom.data() + n, a.data(), n);

    vector<char> tailLoopTop(gN + 1);
    memcpy(tailLoopTop.data(), a.data(), n);
    memcpy(tailLoopTop.data() + n, rb.data(), n);

    vector<char> tailLoopBottom(gN + 1);
    memcpy(tailLoopBottom.data(), b.data(), n);
    memcpy(tailLoopBottom.data() + n, ra.data(), n);

    vector<char> zigEvenUp(gN + 1), zigEvenDown(gN + 1);

    bool down = true;
    for (int i = 0; i < n; i++)
    {
        if (down)
        {
            zigEvenDown[2 * i] = a[i];
            zigEvenDown[2 * i + 1] = b[i];

            zigEvenUp[2 * i] = b[i];
            zigEvenUp[2 * i + 1] = a[i];
        }
        else
        {
            zigEvenDown[2 * i] = b[i];
            zigEvenDown[2 * i + 1] = a[i];

            zigEvenUp[2 * i] = a[i];
            zigEvenUp[2 * i + 1] = b[i];
        }
        down = !down;
    }

    for (int k = kStart; k < n; k++)
    {
        memcpy(knightPath.data(), frontLoopTop.data() + n - k, 2 * k);
        memcpy(revKnightPath.data(), frontLoopBottom.data() + n - k, 2 * k);

        unsigned int hashx = 0;
        unsigned int revHashx = 0;

        if (2 * k > n)
        {
            hashx = std::_Hash_impl::hash(knightPath.data(), gNx, 11);
            revHashx = std::_Hash_impl::hash(revKnightPath.data(), gNx, 11);
        }

        for (int i = k + 1; i < kEnd; i++)
        {

            if (k & 1)
            {
                memcpy(knightPath.data() + 2 * k,
                       zigEvenDown.data() + 2 * k,
                       2 * (i - k));

                memcpy(revKnightPath.data() + 2 * k,
                       zigEvenUp.data() + 2 * k,
                       2 * (i - k));
            }
            else
            {
                memcpy(knightPath.data() + 2 * k,
                       zigEvenUp.data() + 2 * k,
                       2 * (i - k));

                memcpy(revKnightPath.data() + 2 * k,
                       zigEvenDown.data() + 2 * k,
                       2 * (i - k));
            }

            if (i < n)
            {
                if ((i & 1) == (k & 1))
                {
                    memcpy(knightPath.data() + 2 * i,
                           tailLoopBottom.data() + i,
                           2 * (n - i));

                    memcpy(revKnightPath.data() + 2 * i,
                           tailLoopTop.data() + i,
                           2 * (n - i));
                }
                else
                {
                    memcpy(knightPath.data() + 2 * i,
                           tailLoopTop.data() + i,
                           2 * (n - i));

                    memcpy(revKnightPath.data() + 2 * i,
                           tailLoopBottom.data() + i,
                           2 * (n - i));
                }
            }

            checkThis(knightPath.data(), hashx);
            checkThis(revKnightPath.data(), revHashx);
        }
    }
}

void bigLoop(const string &a, const string &b)
{
    int n = a.size();

    string knightPath = a + b;
    reverse(knightPath.begin(), knightPath.begin() + n);

    for (int i = 0; i < (int)gN; i++)
    {
        rotate(knightPath.begin(), knightPath.begin() + 1, knightPath.end());
        checkThis(knightPath.c_str());
    }
}

void paths(const string &a, const string &b)
{

    string ra = a;
    reverse(ra.begin(), ra.end());

    string rb = b;
    reverse(rb.begin(), rb.end());

    bigLoop(a, b);

    if (ra == b)
        return;

    zigs(a, b);

    if (a != ra || b != rb)
    {
        bigLoop(ra, rb);
        zigs(ra, rb);
    }
}

/*
 * Complete the 'gridlandProvinces' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. STRING s1
 *  2. STRING s2
 */

int gridlandProvinces(string s1, string s2)
{

    gHashTab.clear();
    gHashTab.resize(kHashSize);

    gNPaths = 0;
    gN = s1.size() * 2;
    gNx = s1.size();

    paths(s1, s2);

    return gNPaths;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string p_temp;
    getline(cin, p_temp);

    int p = stoi(ltrim(rtrim(p_temp)));

    for (int p_itr = 0; p_itr < p; p_itr++)
    {
        string n_temp;
        getline(cin, n_temp);

        int n = stoi(ltrim(rtrim(n_temp)));

        string s1;
        getline(cin, s1);

        string s2;
        getline(cin, s2);

        int result = gridlandProvinces(s1, s2);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}

string ltrim(const string &str)
{
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace))));

    return s;
}

string rtrim(const string &str)
{
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end());

    return s;
}