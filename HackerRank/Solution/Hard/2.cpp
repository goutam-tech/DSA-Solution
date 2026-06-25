#include <bits/stdc++.h>
using namespace std;

vector<array<int, 26>> trans_;
vector<int> fail_;
vector<int> tin_, tout_;
vector<vector<int>> failChildren_;
int nodeCount_;

vector<long long> bitArr_;
int bitSize_;

void bitAdd(int i, long long delta)
{
    for (; i <= bitSize_; i += i & (-i))
        bitArr_[i] += delta;
}
long long bitQuery(int i)
{
    long long s = 0;
    for (; i > 0; i -= i & (-i))
        s += bitArr_[i];
    return s;
}
void rangeAdd(int l, int r, long long delta)
{
    bitAdd(l, delta);
    bitAdd(r + 1, -delta);
}

long long matchSum(const string &d)
{
    long long sum = 0;
    int cur = 0;
    for (char ch : d)
    {
        int c = ch - 'a';
        cur = trans_[cur][c];
        sum += bitQuery(tin_[cur]);
    }
    return sum;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<string> genes(n);
    for (int i = 0; i < n; i++)
        cin >> genes[i];

    vector<long long> health(n);
    for (int i = 0; i < n; i++)
        cin >> health[i];

    int s;
    cin >> s;

    vector<int> qFirst(s), qLast(s);
    vector<string> qD(s);
    for (int i = 0; i < s; i++)
        cin >> qFirst[i] >> qLast[i] >> qD[i];

    int maxNodes = 1;
    for (auto &g : genes)
        maxNodes += g.size();

    trans_.assign(maxNodes, array<int, 26>());
    for (auto &row : trans_)
        row.fill(-1);
    fail_.assign(maxNodes, 0);

    nodeCount_ = 1;
    vector<int> endNode(n);

    for (int i = 0; i < n; i++)
    {
        int cur = 0;
        for (char ch : genes[i])
        {
            int c = ch - 'a';
            if (trans_[cur][c] == -1)
                trans_[cur][c] = nodeCount_++;
            cur = trans_[cur][c];
        }
        endNode[i] = cur;
    }

    {
        queue<int> q;
        for (int c = 0; c < 26; c++)
        {
            if (trans_[0][c] == -1)
            {
                trans_[0][c] = 0;
            }
            else
            {
                fail_[trans_[0][c]] = 0;
                q.push(trans_[0][c]);
            }
        }
        while (!q.empty())
        {
            int u = q.front();
            q.pop();
            for (int c = 0; c < 26; c++)
            {
                int v = trans_[u][c];
                if (v != -1)
                {
                    fail_[v] = trans_[fail_[u]][c];
                    q.push(v);
                }
                else
                {
                    trans_[u][c] = trans_[fail_[u]][c];
                }
            }
        }
    }

    failChildren_.assign(nodeCount_, vector<int>());
    for (int v = 1; v < nodeCount_; v++)
        failChildren_[fail_[v]].push_back(v);

    tin_.assign(nodeCount_, 0);
    tout_.assign(nodeCount_, 0);
    {
        vector<int> stackNode, stackIdx;
        stackNode.push_back(0);
        stackIdx.push_back(0);
        int timer = 1;
        tin_[0] = timer++;
        while (!stackNode.empty())
        {
            int u = stackNode.back();
            int &idx = stackIdx.back();
            if (idx < (int)failChildren_[u].size())
            {
                int v = failChildren_[u][idx++];
                tin_[v] = timer++;
                stackNode.push_back(v);
                stackIdx.push_back(0);
            }
            else
            {
                tout_[u] = timer - 1;
                stackNode.pop_back();
                stackIdx.pop_back();
            }
        }
    }

    bitSize_ = nodeCount_ + 2;

    vector<long long> totalAns(s, 0), upperAns(s, 0), lowerAns(s, 0);

    bitArr_.assign(bitSize_ + 2, 0);
    for (int i = 0; i < n; i++)
        rangeAdd(tin_[endNode[i]], tout_[endNode[i]], health[i]);
    for (int i = 0; i < s; i++)
        totalAns[i] = matchSum(qD[i]);

    bitArr_.assign(bitSize_ + 2, 0);
    vector<int> orderByLast(s);
    for (int i = 0; i < s; i++)
        orderByLast[i] = i;
    sort(orderByLast.begin(), orderByLast.end(), [&](int a, int b)
         { return qLast[a] < qLast[b]; });
    {
        int ptr = 0;
        for (int idx : orderByLast)
        {
            int L = qLast[idx];
            while (ptr <= L)
            {
                rangeAdd(tin_[endNode[ptr]], tout_[endNode[ptr]], health[ptr]);
                ptr++;
            }
            upperAns[idx] = matchSum(qD[idx]);
        }
    }

    bitArr_.assign(bitSize_ + 2, 0);
    vector<int> orderByFirst(s);
    for (int i = 0; i < s; i++)
        orderByFirst[i] = i;
    sort(orderByFirst.begin(), orderByFirst.end(), [&](int a, int b)
         { return qFirst[a] > qFirst[b]; });
    {
        int ptr = n - 1;
        for (int idx : orderByFirst)
        {
            int F = qFirst[idx];
            while (ptr >= F)
            {
                rangeAdd(tin_[endNode[ptr]], tout_[endNode[ptr]], health[ptr]);
                ptr--;
            }
            lowerAns[idx] = matchSum(qD[idx]);
        }
    }

    long long mn = LLONG_MAX, mx = LLONG_MIN;
    for (int i = 0; i < s; i++)
    {
        long long ans = upperAns[i] + lowerAns[i] - totalAns[i];
        mn = min(mn, ans);
        mx = max(mx, ans);
    }

    cout << mn << " " << mx << "\n";
    return 0;
}