#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;

#define Bismillah__Kun_Fayakun      ios_base :: sync_with_stdio(false);
#define ll                          long long
#define MAXN                        200007

#define orderedSet  tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>

int main ()
{
    Bismillah__Kun_Fayakun

    int idx = 1;
    orderedSet os;
    for (int i = 1; i<=1429431; i += 2) os.insert(i);

    while(idx <os.size())
    {
        int itemToRemove = *os.find_by_order(idx);
        if (itemToRemove <= os.size())
        {
            itemToRemove--;

            os.erase(os.find_by_order(itemToRemove));

            int tobeAdded = itemToRemove; itemToRemove += itemToRemove;
            while(itemToRemove < os.size())
            {
                os.erase(os.find_by_order(itemToRemove));
                itemToRemove += tobeAdded;
            }
        }
        else break;
        idx++;
    }

    int test_case, case_no = 0; scanf("%d", &test_case);
    while(test_case--)
    {
        int idx; scanf("%d", &idx); --idx;
        printf("Case %d: %d\n", ++case_no, *os.find_by_order(idx));
    }


    return 0;
}
