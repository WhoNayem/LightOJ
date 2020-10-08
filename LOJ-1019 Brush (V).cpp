#include<bits/stdc++.h>
using namespace std;
#define MAXN 107

vector <pair <int, int> > graph[MAXN];

void DijkstraShortestPath(int nodes, int src)
{
	vector <int> dis(MAXN, INT_MAX); dis[src] = 0;

	priority_queue<pair <int, int> , vector <pair <int, int> > , greater<pair <int, int> > > pq;
	pq.push({src, 0});

	while (!pq.empty())
	{
        int temp = pq.top().first; pq.pop();

		for (auto it = graph[temp].begin(); it != graph[temp].end(); ++it)
		{
			int des = it->first;
			int weight = it->second;

			if (dis[des] > dis[temp] + weight)
			{
				dis[des] = dis[temp] + weight;
				pq.push({des, dis[des]});
			}
		}
	}
    if (dis[nodes] == INT_MAX) printf("Impossible\n");
    else printf("%d\n", dis[nodes]);
}

int main()
{
	int test_case, case_no = 0; scanf("%d", &test_case);
	while(test_case--)
    {
        int nodes, edges; scanf("%d %d", &nodes, &edges);
        for (int i = 0; i<edges; ++i)
        {
            int src, des, weight; scanf("%d %d %d", &src, &des, &weight);
            graph[src].push_back({des, weight});
            graph[des].push_back({src, weight});
        }

        printf("Case %d: ", ++case_no);
        DijkstraShortestPath(nodes, 1);

        for (int i = 0; i < MAXN; ++i) graph[i].clear();
    }

	return 0;
}
