#include <bits/stdc++.h>
using namespace std;

#define __Mammamia__                ios_base :: sync_with_stdio(false);
#define ll                          long long
#define MAXN                        200007
#define LOGN                        17

int nodes, q, vec[MAXN], table[MAXN][LOGN];
vector < pair <int, int> > graph[MAXN];
vector <int> par(MAXN), Log(MAXN), level(MAXN);

void init()
{
    vec[0] = 1;
    for (int i = 0; i < MAXN; ++i)
        graph[i].clear();

    memset(table, -1, sizeof table);
}

void dfs(int node, int father = -1, int depth = 0, int cost = 1)
{
    level[node] = depth, par[node] = father, table[node][0] = father;

    for (auto x : graph[node])
        if (x.first != father)
            dfs(x.first, node, depth + 1, x.second);
}

void build()
{
    for (int j = 1; (1 << j) < nodes; ++j)
    {
        for (int i = 0; i < nodes; ++i)
        {
            if (table[i][j - 1] == -1) continue;
            table[i][j] = table[table[i][j - 1]][j - 1];
        }
    }

    for (int i = 0; i < LOGN; ++i)
        Log[1 << i] = i;

    for (int i = 1; i < MAXN; ++i)
        if (!Log[i])
            Log[i] = Log[i - 1];
}

int query(int x, int y, int value)
{
    int log = Log[level[x]];

    for( int i = log; i >= 0; --i)
        if (vec[table[x][i]] >= value)
            x = table[x][i];

    return x;
}



int main ()
{
    __Mammamia__

    int test_case, case_no = 0; scanf("%d", &test_case);
    while(test_case--)
    {
        scanf("%d %d", &nodes, &q); init();

        for (int i = 1; i < nodes; ++i)
        {
            int parent, value; scanf("%d %d", &parent, &value); vec[i] = value;
            graph[i].push_back({parent, value});
            graph[parent].push_back({i, value});
        }

        dfs(0);
        build();

        printf("Case %d:\n", ++case_no);
        while(q--)
        {
            int idx, value; scanf("%d %d", &idx, &value);
            printf("%d\n", query(idx, 0, value));
        }
    }

    return 0;
}
