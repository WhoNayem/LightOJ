#include <bits/stdc++.h>
using namespace std;
#define Bismillah__Kun_Fayakun      ios_base :: sync_with_stdio(false);
#define ll                          long long
#define MAXN                        200007

int n, cnt = 0;
vector <int> visited(MAXN, 0), disc(MAXN, 0), parent(MAXN, 0), low(MAXN, 0), graph[MAXN];
map <pair <int, int>, int> Map;

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
			if (low[v] > disc[u]) {int p = u, q = v; if (p > q) swap(p, q); Map[{p, q}] = 1, ++cnt;}
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

void init()
{
    for (int i = 0; i < n; ++i)
    {
        parent[i] = -1; low[i] = 0;
        visited[i] = 0; disc[i] = 0;
        graph[i].clear();
    }
    Map.clear(); cnt = 0;
}

int main()
{
    int test_case, case_no = 0; cin >> test_case;
    while(test_case--)
    {
        cin >> n; init();
        for (int i = 0; i<n; ++i)
        {
            int node, adj; scanf("%d (%d)", &node, &adj);
            for (int j = 0; j<adj; ++j)
            {
                int a; scanf("%d", &a);
                graph[node].push_back(a);
            }
        }
        bridge();
        printf("Case %d:\n", ++case_no);
        printf("%d critical links\n", cnt);
        for (auto it = Map.begin(); it != Map.end(); ++it) printf("%d - %d\n", it->first.first, it->first.second);
    }

	return 0;
}
