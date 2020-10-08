#include <bits/stdc++.h>
using namespace std;
#define Bismillah__Kun_Fayakun      ios_base :: sync_with_stdio(false);
#define ll                          long long
#define MAXN                        200007

int main()
{
    int test_case, case_no = 0; scanf("%d", &test_case);
    while(test_case--)
    {
        int n, q, cnt = 0; scanf("%d %d", &n, &q);
        vector <pair <int, int> > vec(n); map <int, int> Map;
        vector <int> queries(q);

        for (int i = 0; i<n; ++i)
        {
            scanf("%d %d", &vec[i].first, &vec[i].second);
            Map[vec[i].first] = 1; Map[vec[i].second] = 1;
        }
        for (int i = 0; i<q; ++i) {scanf("%d", &queries[i]); Map[queries[i]] = 1;}
        for (auto it = Map.begin(); it != Map.end(); ++it) it->second = ++cnt;

        vector <int> line(cnt + 7, 0);

        for (int i = 0; i<n; ++i){line[Map[vec[i].first]]++; line[Map[vec[i].second] + 1]--;}
        printf("Case %d:\n", ++case_no);

        for (int i = 1; i<= cnt + 1; ++i) line[i] += line[i - 1];
        for (int i = 0; i<q; ++i) printf("%d\n", line[Map[queries[i]]]);
    }
    return 0;
}
