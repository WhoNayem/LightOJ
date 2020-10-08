#include <bits/stdc++.h>
using namespace std;
#define __Mammamia__                ios_base :: sync_with_stdio(false);
#define ll                          long long
#define MAXN                        1007

int n, m, no = 1, cntTimes = 0;
stack <int> Stack;
map <int, int> id;
set <int> nodes;
vector <pair <int, int> > edges;
vector <int> graph[MAXN], Tgraph[MAXN], comGraph[MAXN], visited(MAXN, 0), outDegree(MAXN, 0);

void DFSUtil(int src, int giveId)
{
    visited[src] = true; id[src] = giveId;

    for(auto i : Tgraph[src])
        if(!visited[i])
            DFSUtil(i, giveId);
}

void fillOrder(int src)
{
    cntTimes++;
    visited[src] = true;

    for(auto i : graph[src])
        if(!visited[i])
            fillOrder(i);

    Stack.push(src);
}

void findSCCs()
{
    fillOrder(0);

    for(int i = 0; i < MAXN; i++) visited[i] = false;

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
        visited[i] = 0; outDegree[i] = 0;
        graph[i].clear();
        Tgraph[i].clear();
    }
    id.clear(); edges.clear(); no = 1; nodes.clear(); cntTimes = 0;
}

int main ()
{
    __Mammamia__

    int test_case, case_no = 0; cin >> test_case;
    while(test_case--)
    {
        int children; cin >> children; init();
        while(children--)
        {
            int wishes; cin >> wishes;
            while(wishes--)
            {
                int u, v; cin >> u >> v;
                graph[u].push_back(v);
                Tgraph[v].push_back(u);
                edges.push_back({u, v});
                nodes.insert(u); nodes.insert(v);
            }
        }

        findSCCs();
        if (cntTimes != nodes.size()) {cout << "Case " << ++case_no << ": NO" << endl; continue;}
        for (int i = 0; i < MAXN; ++i) visited[i] = false;

        bool okay = true;

        for (int i = 0; i < edges.size(); ++i)
        {
            int nodeSrc = id[edges[i].first], nodeDes = id[edges[i].second];
            if (nodeSrc != nodeDes)
            {
                outDegree[nodeSrc]++;
                if (outDegree[nodeSrc] > 1) {okay = false; break;}
            }
        }
        if (okay) cout << "Case " << ++case_no << ": YES" << endl;
        else cout << "Case " << ++case_no << ": NO" << endl;
    }

    return 0;
}
