#include <bits/stdc++.h>
using namespace std;
#define Bismillah__Kun_Fayakun      ios_base :: sync_with_stdio(false);
#define ll                          long long
#define MAXN                        507

struct Edge
{
    int des, weight;
};
vector <Edge> graph[MAXN];
vector <int> dis(MAXN, INT_MAX);

void bfs(int src)
{
    dis[src] = 0;

    queue <int> q; q.push(src);
    while(!q.empty())
    {
        int temp = q.front(); q.pop();
        for (auto it = graph[temp].begin(); it != graph[temp].end(); ++it)
        {
            int maxEdge =  max(it->weight, dis[temp]);
            if (maxEdge < dis[it->des]) {dis[it->des] = maxEdge, q.push(it->des);}
        }
    }
}

int main ()
{
    Bismillah__Kun_Fayakun

    int test_case, case_no = 0; scanf("%d", &test_case);
    while(test_case--)
    {
        int nodes, edges; scanf("%d %d", &nodes, &edges);
        for (int i = 0; i < edges; ++i)
        {
            int src, des, weight; scanf("%d %d %d", &src, &des, &weight);
            graph[src].push_back({des, weight});
            graph[des].push_back({src, weight});
        }

        int q; scanf("%d", &q);
        bfs(q);

        printf("Case %d:\n", ++case_no);

        for (int i = 0; i<nodes; ++i)
        {
            if (dis[i] != INT_MAX) printf("%d\n", dis[i]);
            else puts("Impossible");
            graph[i].clear();
            dis[i] = INT_MAX;
        }
    }
    return 0;
}
