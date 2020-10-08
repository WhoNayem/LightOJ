#include <bits/stdc++.h>
using namespace std;
#define __Mammamia__                ios_base :: sync_with_stdio(false);
#define ll                          long long
#define MAXN                        20007

int n, m, no = 1, zeroDeg = 0;
stack <int> Stack;
map <int, int> id;
vector <pair <int, int> > edges;
vector <int> graph[MAXN], Tgraph[MAXN], visited(MAXN, 0), inDegree(MAXN, 0), outDegree(MAXN, 0);

void DFSUtil(int src, int giveId)
{
    visited[src] = true; id[src] = giveId;

    for(auto i : Tgraph[src])
        if(!visited[i])
            DFSUtil(i, giveId);
}


void fillOrder(int src)
{
    visited[src] = true;

    for(auto i : graph[src])
        if(!visited[i])
            fillOrder(i);

    Stack.push(src);
}

void findSCCs()
{
    for(int i = 1; i <= n; i++)
        if(!visited[i])
            fillOrder(i);

    for(int i = 1; i <= n; i++) visited[i] = false;

    while (!Stack.empty())
    {
        int v = Stack.top(); Stack.pop();
        if (!visited[v])
            DFSUtil(v, no++);
    }
}

void init()
{
    for (int i = 0; i < MAXN; ++i)
    {
        visited[i] = 0; inDegree[i] = 0; outDegree[i] = 0;
        graph[i].clear();
        Tgraph[i].clear();
    }
    id.clear(); edges.clear(); no = 1; zeroDeg = 0;
}

int main ()
{
    __Mammamia__

    int test_case, case_no = 0; cin >> test_case;
    while(test_case--)
    {
        cin >> n >> m; init();

        if (n == 1) {cout << "Case " << ++case_no << ": " << 0 << endl; continue;}

        for (int i = 0; i<m; ++i)
        {
            int u, v; cin >> u >> v;
            graph[u].push_back(v);
            Tgraph[v].push_back(u);
            edges.push_back({u, v});
        }

        findSCCs();

        for (int i = 0; i < edges.size(); ++i)
        {
            int nodeSrc = id[edges[i].first], nodeDes = id[edges[i].second];
            if (nodeSrc != nodeDes)
            {
                inDegree[nodeSrc]++;
                outDegree[nodeDes]++;
            }
        }
        int zeroIndegree = 0, zeroOutdegree = 0;
        for (int i = 1; i < no; ++i)
        {
            if (!inDegree[i]) zeroIndegree++;
            if (!outDegree[i]) zeroOutdegree++;
        }
        int res = max(zeroIndegree, zeroOutdegree);
        if (no < 3) res = 0;
        cout << "Case " << ++case_no << ": " << res << endl;
    }

    return 0;
}
