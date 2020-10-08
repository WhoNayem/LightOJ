#include <bits/stdc++.h>
using namespace std;
#define Bismillah__Kun_Fayakun      ios_base :: sync_with_stdio(false);
#define ll                          long long
#define MAXN                        10007
#define NIL                         -1

int n, m;
vector <int> visited(MAXN, 0), low(MAXN, 0), parent(MAXN, 0), disc(MAXN, 0), ap(MAXN, 0), graph[MAXN];

void APUtil(int u)
{
	static int time = 0;
	int children = 0; visited[u] = 1; disc[u] = low[u] = ++time;

	for (auto i = graph[u].begin(); i != graph[u].end(); ++i)
	{
		int v = *i;
		if (!visited[v])
		{
			children++; parent[v] = u;
			APUtil(v);
			low[u] = min(low[u], low[v]);

			if (parent[u] == NIL && children > 1) {ap[u] = 1;}
			if (parent[u] != NIL && low[v] >= disc[u]) {ap[u] = 1;}
		}
		else if (v != parent[u]) {low[u] = min(low[u], disc[v]);}
	}
}

int articulationPoint()
{
	for (int i = 1; i <= n; i++) {if (!visited[i]) APUtil(i);}

    int cnt = 0;
	for (int i = 1; i <= n; i++) {if (ap[i]) {++cnt;}}
    return cnt;
}

void init()
{
    for (int i = 0; i < MAXN; ++i)
    {
        visited[i] = 0, parent[i] = NIL;
        low[i] = ap[i] = disc[i] = 0;
        graph[i].clear();
    }
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
        cout << "Case " << ++case_no << ": " << articulationPoint() << endl;
    }

	return 0;
}
