#include <bits/stdc++.h>
using namespace std;

const long long MOD = 1000000007;

struct RNode
{
    char op;
    RNode *l, *r;
    RNode(char c) : op(c), l(nullptr), r(nullptr) {}
};

struct Parser
{
    string s;
    int pos;
    Parser(const string &str) : s(str), pos(0) {}
    RNode *parseAlt()
    {
        RNode *left = parseConcat();
        while (pos < (int)s.size() && s[pos] == '|')
        {
            pos++;
            RNode *p = new RNode('|');
            p->l = left;
            p->r = parseConcat();
            left = p;
        }
        return left;
    }
    RNode *parseConcat()
    {
        RNode *left = parseRepeat();
        while (pos < (int)s.size() && (s[pos] == 'a' || s[pos] == 'b' || s[pos] == '('))
        {
            RNode *p = new RNode('.');
            p->l = left;
            p->r = parseRepeat();
            left = p;
        }
        return left;
    }
    RNode *parseRepeat()
    {
        RNode *n = parseBase();
        while (pos < (int)s.size() && s[pos] == '*')
        {
            RNode *p = new RNode('*');
            p->l = n;
            pos++;
            n = p;
        }
        return n;
    }
    RNode *parseBase()
    {
        if (s[pos] == 'a' || s[pos] == 'b')
        {
            RNode *n = new RNode(s[pos]);
            pos++;
            return n;
        }
        pos++;
        RNode *n = parseAlt();
        pos++;
        return n;
    }
};

struct Frag
{
    int st, en;
};

struct NFA
{
    vector<vector<int>> eps;
    vector<vector<int>> tr[2];
    int newState()
    {
        eps.push_back({});
        tr[0].push_back({});
        tr[1].push_back({});
        return (int)eps.size() - 1;
    }
    Frag build(RNode *n)
    {
        if (n->op == 'a' || n->op == 'b')
        {
            int s = newState(), t = newState();
            tr[n->op == 'a' ? 0 : 1][s].push_back(t);
            return {s, t};
        }
        if (n->op == '|')
        {
            Frag L = build(n->l), R = build(n->r);
            int s = newState(), t = newState();
            eps[s].push_back(L.st);
            eps[s].push_back(R.st);
            eps[L.en].push_back(t);
            eps[R.en].push_back(t);
            return {s, t};
        }
        if (n->op == '.')
        {
            Frag A = build(n->l), B = build(n->r);
            eps[A.en].push_back(B.st);
            return {A.st, B.en};
        }
        Frag A = build(n->l);
        int s = newState(), t = newState();
        eps[s].push_back(A.st);
        eps[s].push_back(t);
        eps[A.en].push_back(A.st);
        eps[A.en].push_back(t);
        return {s, t};
    }
};

vector<int> closure(vector<int> start, vector<vector<int>> &eps)
{
    vector<char> vis(eps.size(), 0);
    for (int x : start)
        vis[x] = 1;
    queue<int> q;
    for (int x : start)
        q.push(x);
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        for (int v : eps[u])
            if (!vis[v])
            {
                vis[v] = 1;
                q.push(v);
            }
    }
    vector<int> res;
    for (int i = 0; i < (int)vis.size(); i++)
        if (vis[i])
            res.push_back(i);
    return res;
}

typedef vector<vector<long long>> Mat;
Mat matmul(const Mat &A, const Mat &B)
{
    int n = A.size();
    Mat C(n, vector<long long>(n, 0));
    for (int i = 0; i < n; i++)
        for (int k = 0; k < n; k++)
        {
            if (!A[i][k])
                continue;
            for (int j = 0; j < n; j++)
                C[i][j] = (C[i][j] + A[i][k] * B[k][j]) % MOD;
        }
    return C;
}

int countStrings(string r, int l)
{
    Parser parser(r);
    RNode *root = parser.parseAlt();
    NFA nfa;
    Frag f = nfa.build(root);
    int N = nfa.eps.size();

    map<vector<int>, int> idOf;
    vector<vector<int>> states;
    vector<int> accept;
    vector<array<int, 2>> trans;

    vector<int> startClosure = closure({f.st}, nfa.eps);
    idOf[startClosure] = 0;
    states.push_back(startClosure);
    int acc0 = 0;
    for (int x : startClosure)
        if (x == f.en)
        {
            acc0 = 1;
            break;
        }
    accept.push_back(acc0);
    trans.push_back({-1, -1});

    queue<int> q;
    q.push(0);
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        for (int c = 0; c < 2; c++)
        {
            vector<int> moveset;
            vector<char> vis(N, 0);
            for (int x : states[u])
                for (int y : nfa.tr[c][x])
                    if (!vis[y])
                    {
                        vis[y] = 1;
                        moveset.push_back(y);
                    }
            if (moveset.empty())
            {
                trans[u][c] = -1;
                continue;
            }
            vector<int> clo = closure(moveset, nfa.eps);
            auto it = idOf.find(clo);
            int idx;
            if (it == idOf.end())
            {
                idx = (int)states.size();
                idOf[clo] = idx;
                states.push_back(clo);
                int acc = 0;
                for (int x : clo)
                    if (x == f.en)
                    {
                        acc = 1;
                        break;
                    }
                accept.push_back(acc);
                trans.push_back({-1, -1});
                q.push(idx);
            }
            else
                idx = it->second;
            trans[u][c] = idx;
        }
    }

    int M = states.size();
    if (l == 0)
        return accept[0];

    int dead = M;
    int size = M + 1;
    Mat A(size, vector<long long>(size, 0));
    for (int i = 0; i < M; i++)
    {
        for (int c = 0; c < 2; c++)
        {
            int t = trans[i][c];
            if (t == -1)
                t = dead;
            A[i][t] = (A[i][t] + 1) % MOD;
        }
    }
    A[dead][dead] = 2;

    Mat result(size, vector<long long>(size, 0));
    for (int i = 0; i < size; i++)
        result[i][i] = 1;
    Mat base = A;
    int e = l;
    while (e > 0)
    {
        if (e & 1)
            result = matmul(result, base);
        base = matmul(base, base);
        e >>= 1;
    }

    long long ans = 0;
    for (int j = 0; j < M; j++)
        if (accept[j])
            ans = (ans + result[0][j]) % MOD;
    return (int)ans;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
    {
        string r;
        int l;
        cin >> r >> l;
        cout << countStrings(r, l) << "\n";
    }
    return 0;
}