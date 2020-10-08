#include <bits/stdc++.h>
using namespace std;
#define Bismillah__Kun_Fayakun      ios_base :: sync_with_stdio(false);
#define ll                          long long
#define MAXN                        200007

int n, m, cnt = 0;
stack <int> Stack;
vector <int> visited(MAXN, 0), graph[MAXN];

void dfs(int src, bool topSort)
{
    visited[src] = true;
    for (auto i = graph[src].begin(); i != graph[src].end(); ++i)
        if (!visited[*i])
            dfs(*i, topSort);
    if (topSort) Stack.push(src);
}

void init()
{
    for (int i = 0; i <= n; ++i) visited[i] = 0, graph[i].clear();
    cnt = 0;
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
        }
        for (int i = 1; i<=n; ++i)
            if (!visited[i])
                dfs(i, true);
        for (int i = 1; i <= n; ++i) visited[i] = false;

        while(!Stack.empty())
        {
            int ver = Stack.top(); Stack.pop();
            if (!visited[ver])
                dfs(ver, false), cnt++;
        }
        cout << "Case " << ++case_no << ": " << cnt << endl;
    }

	return 0;
}
