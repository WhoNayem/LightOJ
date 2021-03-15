#include <bits/stdc++.h>
using namespace std;

#define __Mammamia__                ios_base :: sync_with_stdio(false);
#define ll                          long long
#define MAXN                        100007
#define LOGN                        16

struct edge
{
    int u, v, cost;
};

int nodes, edges, table[MAXN][LOGN], Min[MAXN][LOGN];
vector <edge> g, temp_graph;
vector < pair <int, int> > graph[MAXN];
vector <int> parent(MAXN), par(MAXN), rnk(MAXN), cnt(MAXN), Log(MAXN), level(MAXN);

bool comp(edge a, edge b)
{
    if (a.cost != b.cost) return a.cost < b.cost;
    if (a.u != b.u) return a.u < b.u;
    return a.v < b.v;
}

void init()
{
    g.clear(); temp_graph.clear();
    for (int i = 0; i < MAXN; ++i)
    {
        parent[i] = i, cnt[i] = 1, rnk[i] = 0;
        graph[i].clear();
    }
}

int find_parent(int x)
{
    if (x != parent[x])
        parent[x] = find_parent(parent[x]);
    return parent[x];
}

void kruskal()
{
    sort(g.begin(), g.end(), comp);

    for (auto x : g)
    {
        int u = x.u, v = x.v;

        if ((u = find_parent(u)) != (v = find_parent(v)))
        {
            if (rnk[u] < rnk[v])
            {
                cnt[v] += cnt[u];
                parent[u] = parent[v];
            }
            else
            {
                rnk[u] = max(rnk[u], rnk[v] + 1);
                cnt[u] += cnt[v];
                parent[v] = parent[u];
            }
            temp_graph.emplace_back(x);
        }
    }

}

void dfs(int node, int father = -1, int depth = 0, int cost = 0)
{
    level[node] = depth, par[node] = father, Min[node][0] = cost;

    for (auto x : graph[node])
        if (x.first != father)
            dfs(x.first, node, depth + 1, x.second);
}

void init_LCA()
{
    for( int i = 0; i < nodes; ++i) table[i][0] = par[i];

    for (int j = 1; (1 << j) < nodes; ++j)
    {
        for (int i = 0; i < nodes; ++i)
        {
            if (table[i][j - 1] == -1) continue;

            table[i][j] = table[table[i][j - 1]][j - 1];
            Min[i][j] = max(Min[table[i][j - 1]][j - 1], Min[i][j - 1]);
        }
    }

    for (int i = 0; i < 16; ++i)
        Log[1 << i] = i;

    for (int i = 1; i < MAXN; ++i)
        if (!Log[i])
            Log[i] = Log[i - 1];
}

int query(int x, int y)
{
    int ret = 0;
    if(level[x] < level[y] ) swap(x, y);

    int log = Log[level[x]];

    for( int i = log; i >= 0; --i)
    {
        if(level[x] - (1 << i) >= level[y])
        {
            ret = max(ret, Min[x][i]);
            x = table[x][i];
        }
    }

    if(x == y) return ret;

    for(int i = log; i >= 0; --i)
    {
        if(table[x][i] != -1 && table[y][i] != -1 && table[x][i] != table[y][i])
        {
            ret = max(ret, Min[x][i]);
            ret = max(ret, Min[y][i]);
            x = table[x][i];
            y = table[y][i];
        }
    }
    ret = max(ret, Min[x][0]);
    ret = max(ret, Min[y][0]);
    return ret;
}



int main ()
{
    __Mammamia__

    int test_case, case_no = 0; scanf("%d", &test_case);
    while(test_case--)
    {
        scanf("%d %d", &nodes, &edges); init();

        for (int i = 0; i < edges; ++i)
        {
            int u, v, cost; scanf("%d %d %d", &u, &v, &cost);
            g.emplace_back(edge{u, v, cost});
        }

        kruskal();

        for (auto x : temp_graph)
        {
            graph[x.u - 1].push_back({x.v - 1, x.cost});
            graph[x.v - 1].push_back({x.u - 1, x.cost});
        }

        for (int i = 0; i < nodes; ++i)
            for (int j = 0; j < LOGN; ++j)
                table[i][j] = -1, Min[i][j] = 0;

        dfs(0);
        init_LCA();

        printf("Case %d:\n", ++case_no);
        int q; scanf("%d", &q);
        while(q--)
        {
            int x, y; scanf("%d %d", &x, &y); --x, --y;
            printf("%d\n", query(x, y));
        }
    }

    return 0;
}
