#include <bits/stdc++.h>
using namespace std;
#define Bismillah__Kun_Fayakun      ios_base :: sync_with_stdio(false);
#define ll                          long long
#define MAXN                        200007

int n, m, no = 0;
map <int, int> id;
vector <pair <int, int> >edges;
map <pair <int, int>, int> isBridge;
vector <int> visited(MAXN, 0), disc(MAXN, 0), parent(MAXN, 0), low(MAXN, 0), graph[MAXN];

void bridgeUtil(int u)
{
	static int time = 0;
	visited[u] = true;
	disc[u] = low[u] = ++time;

	for (auto i = graph[u].begin(); i != graph[u].end(); ++i)
	{
		int v = *i;
		if (!visited[v])
		{
			parent[v] = u;
			bridgeUtil(v);
			low[u] = min(low[u], low[v]);
			if (low[v] > disc[u]) {isBridge[{u, v}] = 1, isBridge[{v, u}] = 1;}
		}
		else if (v != parent[u]) low[u] = min(low[u], disc[v]);
	}
}

void bridge()
{
	for (int i = 0; i < n; i++)
		if (visited[i] == false)
			bridgeUtil(i);
}

void dfs(int src, int no)
{
    visited[src] = true; id[src] = no;
    for (auto x : graph[src])
        if (!visited[x] && !isBridge[{src, x}])
            dfs(x, no);
}

void init()
{
    for (int i = 0; i < n; ++i)
    {
        parent[i] = -1; low[i] = 0;
        visited[i] = 0; disc[i] = 0;
        graph[i].clear();
    }
    isBridge.clear(); id.clear(); edges.clear(); no = 0;
}

int main()
{
    int test_case, case_no = 0; cin >> test_case;
    while(test_case--)
    {
        cin >> n >> m; init();
        for (int i = 0; i<m; ++i)
        {
            int u, v; cin >> u >> v;
            graph[u].push_back(v);
            graph[v].push_back(u);
            edges.push_back({u, v});
        }
        bridge();

        for (int i = 0; i < n; ++i) visited[i] = false;

        for (int i = 0; i < n; ++i)
            if (!visited[i])
                dfs(i, no++);

        map <int, int> degree;

        for (int i = 0; i < edges.size(); ++i)
        {
            int nodeSrc = id[edges[i].first], nodeDes = id[edges[i].second];
            if (nodeSrc != nodeDes)
            {
                degree[nodeSrc]++;
                degree[nodeDes]++;
            }
        }
        int leaf = 0;
        for (auto it = degree.begin(); it != degree.end(); ++it) if (it->second == 1) leaf++;

        cout << "Case " << ++case_no << ": " << ceil((double)leaf / 2) << endl;




    }

	return 0;
}
