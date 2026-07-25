#include <bits/stdc++.h>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

const int N = 30000 + 5;
int n, A, B;
char c[N];
int a_arr[N], b_arr[N], d_arr[N], st_arr[N * 4];
const long long P = 1000000009;
long long has[N], pr[N];

inline bool ch(int x, int y, int z) {
    return (has[x + z - 1] - has[x - 1] + P) * pr[n - x] % P == (has[y + z - 1] - has[y - 1] + P) * pr[n - y] % P;
}

inline bool boo(int x, int y) {
    int r = n - max(x, y) + 2;
    if (ch(x, y, r - 1)) return x > y;
    int m, l = 0;
    while (l + 1 < r) {
        m = (l + r) / 2;
        if (ch(x, y, m)) l = m;
        else            r = m;
    }
    return c[x + l] < c[y + l];
}

void build(int l, int r, int x) {
    if (l + 1 == r) {
        st_arr[x] = a_arr[l];
        return;
    }
    build(l, (l + r) / 2, x * 2);
    build((l + r) / 2, r, x * 2 + 1);
    st_arr[x] = min(st_arr[x * 2], st_arr[x * 2 + 1]);
}

int get(int l, int r, int x, int L, int R) {
    if (L <= l && r - 1 <= R) return st_arr[x];
    if (r - 1 < L || R < l) return n + 5;
    return min(get(l, (l + r) / 2, x * 2, L, R), get((l + r) / 2, r, x * 2 + 1, L, R));
}

int buildString(int a, int b, string s) {
    n = s.length();
    A = a;
    B = b;

    memset(c, 0, sizeof(c));
    memset(a_arr, 0, sizeof(a_arr));
    memset(b_arr, 0, sizeof(b_arr));
    memset(d_arr, 0, sizeof(d_arr));
    memset(st_arr, 0, sizeof(st_arr));
    memset(has, 0, sizeof(has));
    memset(pr, 0, sizeof(pr));

    for (int i = 0; i < n; i++) {
        c[i + 1] = s[i];
    }

    pr[0] = 1;
    c[n + 1] = 0;
    for (int i = 1; i <= n + 1; i++) pr[i] = pr[i - 1] * 349 % P;
    for (int i = 1; i <= n + 1; i++) has[i] = (has[i - 1] + pr[i] * c[i]) % P;

    for (int i = 1; i <= n; i++) a_arr[i] = i;
    sort(a_arr + 1, a_arr + n + 1, boo);
    for (int i = 1; i <= n; i++) b_arr[a_arr[i]] = i;

    build(1, n + 1, 1);

    d_arr[0] = 0;
    for (int i = 1; i <= n; i++) {
        d_arr[i] = d_arr[i - 1] + A;
        int l = 0;
        int r = i / 2 + 1;
        while (l + 1 < r) {
            int m = (l + r) / 2;
            int ll = 1;
            int mm, rr = b_arr[i - m + 1];
            while (ll < rr) {
                mm = (ll + rr) / 2;
                if (ch(a_arr[mm], i - m + 1, m))  rr = mm;
                else                    ll = mm + 1;
            }
            int L = ll;
            ll = b_arr[i - m + 1];
            rr = n + 1;
            while (ll + 1 < rr) {
                mm = (ll + rr) / 2;
                if (ch(a_arr[mm], i - m + 1, m))   ll = mm;
                else                     rr = mm;
            }
            int R = ll;
            if (get(1, n + 1, 1, L, R) <= i - m * 2 + 1)  l = m;
            else                            r = m;
        }
        d_arr[i] = min(d_arr[i], d_arr[i - l] + B);
    }

    return d_arr[n];
}

int main() {
    ofstream fout(getenv("OUTPUT_PATH"));

    string t_temp;
    getline(cin, t_temp);

    int t = stoi(ltrim(rtrim(t_temp)));

    for (int t_itr = 0; t_itr < t; t_itr++) {
        string first_multiple_input_temp;
        getline(cin, first_multiple_input_temp);

        vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

        int n = stoi(first_multiple_input[0]);

        int a = stoi(first_multiple_input[1]);

        int b = stoi(first_multiple_input[2]);

        string s;
        getline(cin, s);

        int result = buildString(a, b, s);
        
        fout << result << "\n";
    }

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}