#include <bits/stdc++.h>
using namespace std;
#define __Mammamia__                ios_base :: sync_with_stdio(false);
#define ll                          long long
#define MAXN                        50007

int n, no = 1, node = 0;
stack <int> Stack;
vector <pair <int, int> > res, edges;
vector <int> graph[MAXN], Tgraph[MAXN], ID(MAXN, 0), comGraph[MAXN], visited(MAXN, 0), Min(MAXN, MAXN), cnt(MAXN, 0), dp(MAXN, 0);

void dfs(int src)
{
    visited[src] = true;

    for (auto x : graph[src])
        if (!visited[x])
            dfs(x);

    Stack.push(src);
}

int dfsforTREE(int src)
{
    visited[src] = true; int Node = cnt[src];

    for (auto x : comGraph[src])
    {
        if (!visited[x]) Node += dfsforTREE(x);
        else Node += dp[x];
    }
    return dp[src] = Node;
}


void dfsTranspose(int src, int id)
{
    visited[src] = true; ID[src] = id; Min[id] = min(Min[id], src); cnt[id]++;

    for (auto x : Tgraph[src])
        if (!visited[x])
            dfsTranspose(x, id);
}

void findSCCs()
{
    for (int i = 1; i <= n; ++i)
        if (!visited[i])
            dfs(i);

    for (int i = 1; i <= n; ++i) visited[i] = 0;

    while(!Stack.empty())
    {
        int v = Stack.top(); Stack.pop();
        if (!visited[v])
            dfsTranspose(v, no++);
    }
}


void init()
{
    for (int i = 0; i < MAXN; ++i)
    {
        ID[i] = 0; cnt[i] = 0; visited[i] = 0; dp[i] = 0; Min[i] = MAXN;
        graph[i].clear(); Tgraph[i].clear(); comGraph[i].clear();
    }
    res.clear(); edges.clear(); no = 1;
}

bool comp(pair <int, int> a, pair <int, int> b)
{
    if (a.first != b.first) return a.first > b.first;
    return a.second < b.second;
}

int main ()
{
    __Mammamia__

    int test_case, case_no = 0; cin >> test_case;
    while(test_case--)
    {
        cin >> n; init();
        for (int i = 1; i <= n; ++i)
        {
            int u, v; cin >> u >> v;
            graph[u].push_back(v);
            Tgraph[v].push_back(u);
            edges.push_back({u, v});
        }
        findSCCs();

        for (int i = 0; i < n; ++i)
        {
            int src = edges[i].first, des = edges[i].second;
            if (ID[src] != ID[des])
            {
                comGraph[ID[src]].push_back(ID[des]);
            }
            visited[i + 1] = 0;
        }

        for (int i = 1; i <= n; ++i) visited[i] = 0;

        for (int i = 1; i < no; ++i)
        {
            if (!visited[i])
            {
                node = 0;
                int total = dfsforTREE(i);
                res.push_back({total, Min[i]});
            }
        }

        sort(res.begin(), res.end(), comp);
        cout << "Case " << ++case_no << ": " << res[0].second << endl;
    }

    return 0;
}
