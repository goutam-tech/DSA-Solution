using System;
using System.Collections.Generic;

namespace Hard;

public class Solution
{
    const long INF = long.MaxValue / 4;

    public long MinimumCost(
        string source,
        string target,
        string[] original,
        string[] changed,
        int[] cost)
    {
        int n = source.Length;

        Dictionary<string, int> id = new();
        int idx = 0;

        foreach (var s in original)
            if (!id.ContainsKey(s)) id[s] = idx++;

        foreach (var s in changed)
            if (!id.ContainsKey(s)) id[s] = idx++;

        int m = id.Count;

        List<(int to, int cost)>[] graph = new List<(int, int)>[m];
        for (int i = 0; i < m; i++) graph[i] = new();

        for (int i = 0; i < original.Length; i++)
        {
            graph[id[original[i]]].Add((id[changed[i]], cost[i]));
        }

        long[,] dist = new long[m, m];
        for (int i = 0; i < m; i++)
            Dijkstra(i, graph, dist, m);

        TrieNode root = new TrieNode();
        foreach (var s in original)
        {
            TrieNode cur = root;
            foreach (char c in s)
            {
                if (!cur.Next.ContainsKey(c))
                    cur.Next[c] = new TrieNode();
                cur = cur.Next[c];
            }
            cur.RuleId = id[s];
        }

        long[] dp = new long[n + 1];
        Array.Fill(dp, INF);
        dp[n] = 0;

        for (int i = n - 1; i >= 0; i--)
        {
            if (source[i] == target[i])
                dp[i] = dp[i + 1];

            TrieNode cur = root;
            for (int j = i; j < n; j++)
            {
                if (!cur.Next.ContainsKey(source[j])) break;
                cur = cur.Next[source[j]];

                if (cur.RuleId != -1)
                {
                    int len = j - i + 1;
                    string tgt = target.Substring(i, len);

                    if (id.TryGetValue(tgt, out int tid))
                    {
                        long c = dist[cur.RuleId, tid];
                        if (c < INF)
                            dp[i] = Math.Min(dp[i], c + dp[j + 1]);
                    }
                }
            }
        }

        return dp[0] >= INF ? -1 : dp[0];
    }

    void Dijkstra(int src, List<(int to, int cost)>[] graph, long[,] dist, int m)
    {
        for (int i = 0; i < m; i++)
            dist[src, i] = INF;

        dist[src, src] = 0;

        var pq = new PriorityQueue<int, long>();
        pq.Enqueue(src, 0);

        while (pq.Count > 0)
        {
            pq.TryDequeue(out int u, out long d);
            if (d > dist[src, u]) continue;

            foreach (var (v, w) in graph[u])
            {
                if (d + w < dist[src, v])
                {
                    dist[src, v] = d + w;
                    pq.Enqueue(v, dist[src, v]);
                }
            }
        }
    }
}

class TrieNode
{
    public Dictionary<char, TrieNode> Next = new();
    public int RuleId = -1;
}