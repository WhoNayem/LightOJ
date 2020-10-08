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
        int n, cnt = 0; scanf("%d", &n);
        vector <int> vec(n);
        for (int  i = 0; i<n; ++i) scanf("%d", &vec[i]);

        sort(vec.rbegin(), vec.rend());

        for (int i = 0; i<n - 2; ++i)
        {
            int range = n - 1;
            for (int j = i + 1; j< n - 1; ++j)
            {
                int needed = (vec[i] - vec[j]) + 1;
                while(range > j && needed > vec[range]) --range;
                if (needed <= vec[range]) cnt += range - j;
                else break;
            }
        }
        printf("Case %d: %d\n", ++case_no, cnt);
    }
    return 0;
}
