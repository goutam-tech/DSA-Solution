#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'kruskals' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts WEIGHTED_INTEGER_GRAPH g as parameter.
 */

/*
 * For the weighted graph, <name>:
 *
 * 1. The number of nodes is <name>_nodes.
 * 2. The number of edges is <name>_edges.
 * 3. An edge exists between <name>_from[i] and <name>_to[i]. The weight of the edge is <name>_weight[i].
 *
 */

int kruskals(int g_nodes, vector<int> g_from, vector<int> g_to, vector<int> g_weight)
{
    vector<int> parent(g_nodes + 1);
    iota(parent.begin(), parent.end(), 0);

    function<int(int)> find = [&](int x)
    {
        while (parent[x] != x)
        {
            parent[x] = parent[parent[x]];
            x = parent[x];
        }
        return x;
    };

    int edgeCount = g_weight.size();
    vector<int> idx(edgeCount);
    iota(idx.begin(), idx.end(), 0);
    sort(idx.begin(), idx.end(), [&](int a, int b)
         { return g_weight[a] < g_weight[b]; });

    int weightSubtree = 0;
    for (int i : idx)
    {
        int rootA = find(g_from[i]);
        int rootB = find(g_to[i]);
        if (rootA == rootB)
            continue;
        parent[rootA] = rootB;
        weightSubtree += g_weight[i];
    }
    return weightSubtree;
}

int main()
{
    string g_nodes_edges_temp;
    getline(cin, g_nodes_edges_temp);

    vector<string> g_nodes_edges = split(rtrim(g_nodes_edges_temp));

    int g_nodes = stoi(g_nodes_edges[0]);
    int g_edges = stoi(g_nodes_edges[1]);

    vector<int> g_from(g_edges);
    vector<int> g_to(g_edges);
    vector<int> g_weight(g_edges);

    for (int i = 0; i < g_edges; i++)
    {
        string g_from_to_weight_temp;
        getline(cin, g_from_to_weight_temp);

        vector<string> g_from_to_weight = split(rtrim(g_from_to_weight_temp));

        g_from[i] = stoi(g_from_to_weight[0]);
        g_to[i] = stoi(g_from_to_weight[1]);
        g_weight[i] = stoi(g_from_to_weight[2]);
    }

    int res = kruskals(g_nodes, g_from, g_to, g_weight);

    cout << res << '\n';

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

vector<string> split(const string &str)
{
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos)
    {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}