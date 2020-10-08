#include <bits/stdc++.h>
using namespace std;
#define Bismillah__Kun_Fayakun      ios_base :: sync_with_stdio(false);
#define ll                          long long
#define MAXN                        200007

int n, m, node = 0;
vector <string> res;
bool foundOddCircle = false;
map <pair <int, int>, int> isBridge;
vector <int> visited(MAXN, 0), disc(MAXN, 0), parent(MAXN, 0), low(MAXN, 0), dis(MAXN, 0), graph[MAXN];

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

void dfs(int src, int parent)
{
    visited[src] = true; node++;

    for (auto x : graph[src])
    {
        if (!visited[x] && !isBridge[{src, x}])
        {
            dis[x] = dis[src] + 1;
            dfs(x, src);
        }
        else if (visited[x] && !isBridge[{src, x}] && x != parent)
        {
            if ((dis[src] + dis[x] + 1)%2) foundOddCircle = true;
        }
    }
}

void init()
{
    for (int i = 0; i < n; ++i)
    {
        parent[i] = -1; low[i] = 0;
        visited[i] = 0; disc[i] = 0; dis[i] = 0;
        graph[i].clear();
    }
    isBridge.clear(); node = 0;
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
        }
        bridge();

        for (int i = 0; i < n; ++i) visited[i] = false;

        int cnt = 0;

        for (int i = 0; i < n; ++i)
        {
            if (!visited[i])
            {
                foundOddCircle = false;
                node = 0;
                dis[i] = 0;
                dfs(i, -1);
                if (foundOddCircle) cnt += node;
            }
        }
        cout << "Case " << ++case_no << ": " << cnt << endl;
    }
	return 0;
}
