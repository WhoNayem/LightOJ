#include <bits/stdc++.h>
using namespace std;
#define __Mammamia__                ios_base :: sync_with_stdio(false);
#define ll                          long long
#define MAXN                        150007

int n, q, vec[MAXN], tree[MAXN];

void update(int idx, int val)
{
    while(idx < MAXN)
    {
        tree[idx] += val;
        idx += idx & (-idx);
    }
}

int query(int idx)
{
    int res = 0;
    while(idx > 0)
    {
        res += tree[idx];
        idx -= idx & (-idx);
    }
    return res;
}

int BinarySearch(int idx)
{
    int low = 0, high = MAXN;

    while(low < high)
    {
        int mid = (low + high) >> 1;
        int t = query(mid);
        if (t >= idx) high = mid;
        else low = mid + 1;
    }
    return low;
}

int main ()
{
    __Mammamia__

    int test_case, case_no = 0; scanf("%d", &test_case);
    while(test_case--)
    {
        scanf("%d %d", &n, &q); memset(tree, 0, sizeof tree);

        unordered_map <int, int> id; int cnt = 0, node = n;

        for (int i = 0; i < n; ++i)
        {
            scanf("%d", &vec[i]);
            id[++cnt] = vec[i];
            update(cnt, 1);
        }

        printf("Case %d:\n", ++case_no);
        while(q--)
        {
            getchar();
            char str[2]; int idx; scanf("%s%d", str, &idx);

            if (str[0] == 'a')
            {
                id[++cnt] = idx;
                update(cnt, 1);
                node++;
            }
            else
            {
                if (node < idx) printf("none\n");
                else
                {
                    int res = BinarySearch(idx);
                    printf("%d\n", id[res]);
                    update(res, -1);
                    node--;
                }
            }
        }
    }
    return 0;
}

