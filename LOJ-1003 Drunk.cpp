#include <bits/stdc++.h>
using namespace std;
#define Bismillah__Kun_Fayakun      ios_base :: sync_with_stdio(false);
#define ll                          long long
#define MAXN                        10007

int n, id = 0;
map <string, int> Map;
vector <int> visited(MAXN, 0), recStack(MAXN, 0), graph[MAXN];

bool isCyclicUtil(int v)
{
    if(!visited[v] )
    {
        visited[v] = 1; recStack[v] = 1;
        for(auto i = graph[v].begin(); i != graph[v].end(); ++i)
        {
            if (!visited[*i] && isCyclicUtil(*i) ) return true;
            else if (recStack[*i]) return true;
        }
    }
    recStack[v] = false;
    return false;
}

bool isCyclic()
{
    for(int i = 1; i <= n; i++)
        if (isCyclicUtil(i))
            return true;
    return false;
}

void init()
{
    for (int i = 0; i < MAXN; ++i)
    {
        visited[i] = 0; recStack[i] = 0;
        graph[i].clear();
    }
    Map.clear(); id = 0;
}

int main()
{
    int test_case, case_no = 0; cin >> test_case;
    while(test_case--)
    {
        cin >> n; init();
        for (int i = 0; i<n; ++i)
        {
            string src, des; cin >> src >> des;
            int u, v;
            if (Map[src]) u = Map[src];
            else Map[src] = ++id, u = Map[src];
            if (Map[des]) v = Map[des];
            else Map[des] = ++id, v = Map[des];
            graph[u].push_back(v);
        }
        cout << "Case " << ++case_no << ": ";
        if (!isCyclic()) cout << "Yes" << endl;
        else cout << "No" << endl;
    }

	return 0;
}
