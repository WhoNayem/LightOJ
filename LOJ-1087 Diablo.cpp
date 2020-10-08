#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;

#define Bismillah__Kun_Fayakun      ios_base :: sync_with_stdio(false);
#define ll                          long long
#define MAXN                        200007

#define orderedSet  tree<pair <int, int>, null_type, less<pair <int, int> >, rb_tree_tag, tree_order_statistics_node_update>

int main ()
{
    Bismillah__Kun_Fayakun

    int test_case, case_no = 0; scanf("%d", &test_case);
    while(test_case--)
    {
        orderedSet os;

        int n, q, a, cnt = 0, range = 0; scanf("%d %d", &n, &q);
        for (int i = 0; i<n; ++i)
        {
            scanf("%d", &a);
            os.insert({++cnt, a});
        }

        printf("Case %d:\n", ++case_no);
        while(q--)
        {
            char type[2]; scanf("%s", &type);
            if (type[0] == 'a')
            {
                int val; scanf("%d", &val);
                os.insert({++cnt, val});
            }
            else
            {
                int idx; scanf("%d", &idx); --idx;
                if (os.size() <= idx) printf("none\n");
                else
                {
                    auto it = os.find_by_order(idx);
                    printf("%d\n", it->second);
                    os.erase(os.find_by_order(idx));
                }
            }
        }
    }


    return 0;
}
