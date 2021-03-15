#include <bits/stdc++.h>
using namespace std;
#define __Mammamia__                ios_base :: sync_with_stdio(false);
#define ll                          long long
#define MAXN                        1000007

int n, vec[MAXN], tree[MAXN];

void update(int idx)
{
    while(idx < MAXN)
    {
        tree[idx]++;
        idx += idx & (-idx);
    }
}

ll query(int idx)
{
    ll res = 0;
    while(idx > 0)
    {
        res += tree[idx];
        idx -= idx & (-idx);
    }
    return res;
}

int main ()
{
    __Mammamia__

    int test_case, case_no = 0; scanf("%d", &test_case);
    while(test_case--)
    {
        scanf("%d", &n); memset(tree, 0, sizeof tree);

        for (int i = 0; i < n; ++i)
            scanf("%d", &vec[i]);

        sort(vec, vec + n);

        ll res = 0;

        for (int i = n - 1; i >= 0; --i)
        {
            for (int j = 0; j < i; ++j)
            {
                for (int k = j + 1; k < i; ++k)
                {
                    int t = vec[i] + vec[j] + vec[k];
                    res += query(t - 1);
                }
            }

            for (int j = i + 1; j < n; ++j)
            {
                for (int k = j + 1; k < n; ++k)
                {
                    int t = vec[k] - vec[i] - vec[j];
                    if (t <= 0) t = 1;
                    update(t);
                }
            }
        }

        printf("Case %d: %lld\n", ++case_no, res);

    }

    return 0;
}
