#include <bits/stdc++.h>
using namespace std;
#define Bismillah__Kun_Fayakun      ios_base :: sync_with_stdio(false);
#define ll                          unsigned long long
#define MAXN                        10007
#define NIL                         -1

unsigned long long int res = 1;
int n, m, node = 0, shaft = 0;
set <int> apCnt;
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
	for (int i = 0; i < n; i++)
        if (!visited[i])
            APUtil(i);
}

void dfs(int src)
{
    visited[src] = true; node++;
    for (auto x : graph[src])
    {
        if (ap[x]) apCnt.insert(x);
        if (!ap[x] && !visited[x])
            dfs(x);
    }
}


void init()
{
    for (int i = 0; i < MAXN; ++i)
    {
        visited[i] = 0, parent[i] = NIL;
        low[i] = ap[i] = disc[i] = 0;
        graph[i].clear();
    }
    node = 0; res = 1; shaft = 0;
}

int main()
{
    int test_case, case_no = 0; cin >> test_case;
    while(test_case--)
    {
        cin >> n >> m; init();
        if (n == 1) {cout << "Case " << ++case_no << ": " << 0 << " " << 1 << endl; continue;}
        for (int i = 0; i<m; ++i)
        {
            int u, v; cin >> u >> v;
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        articulationPoint();

        for (int i = 0; i < n; ++i) visited[i] = 0;

        for (int i  = 0; i < n; ++i)
        {
            if (!ap[i] && !visited[i])
            {
                node = 0, apCnt.clear(), dfs(i);
                if (apCnt.size() < 2) {res *= node; shaft++;}
            }
        }
        if (shaft == 1) shaft = 2, res = (n * (n - 1)) / 2;
        cout << "Case " << ++case_no << ": " << shaft << " " << res << endl;
    }
	return 0;
}
