/*
 * Complete the 'getCost' function below.
 *
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

void getCost(int g_nodes, vector<int> g_from, vector<int> g_to, vector<int> g_weight)
{
    // Print your answer within the function and return nothing
    vector<vector<pair<int, int>>> graph(g_nodes + 1);

    for (int i = 0; i < (int)g_from.size(); i++)
    {
        int u = g_from[i];
        int v = g_to[i];
        int w = g_weight[i];
        graph[u].push_back({v, w});
        graph[v].push_back({u, w});
    }

    vector<int> minCosts(g_nodes + 1, INT_MAX);
    vector<bool> visited(g_nodes + 1, false);

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    minCosts[1] = 0;
    pq.push({0, 1});

    while (!pq.empty())
    {
        auto [cost, node] = pq.top();
        pq.pop();

        if (visited[node])
            continue;
        visited[node] = true;

        for (auto &[dest, weight] : graph[node])
        {
            int maxCost = max(cost, weight);
            if (maxCost < minCosts[dest])
            {
                minCosts[dest] = maxCost;
                pq.push({maxCost, dest});
            }
        }
    }

    if (minCosts[g_nodes] == INT_MAX)
    {
        cout << "NO PATH EXISTS" << '\n';
    }
    else
    {
        cout << minCosts[g_nodes] << '\n';
    }
}