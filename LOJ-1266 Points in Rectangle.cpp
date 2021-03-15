#include <bits/stdc++.h>
using namespace std;
#define __Mammamia__                ios_base :: sync_with_stdio(false);
#define ll                          long long
#define MAXN                        1007

int n, q, tree[MAXN][MAXN], exist[MAXN][MAXN];

void update(int x, int y)
{
    int i = x, j = y;
    while(i <= MAXN)
    {
        j = y;
        while(j <= MAXN)
        {
            tree[i][j]++;
            j += j & (-j);
        }
        i += i & (-i);
    }
}

int query(int x, int y)
{
    int i = x, j = y, res = 0;
    if (x <= 0 || y <= 0) return 0;
    while(i > 0)
    {
        j = y;
        while(j > 0)
        {
            res += tree[i][j];
            j -= j & (-j);
        }
        i -= i & (-i);
    }
    return res;
}

int query(int x1, int y1, int x2, int y2)
{
    return query(x2, y2) - query(x1 - 1, y2) - query(x2, y1 - 1) + query(x1 - 1, y1 - 1);
}

int main ()
{
    __Mammamia__

    int test_case, case_no = 0; scanf("%d", &test_case);
    while(test_case--)
    {
        memset(tree, 0, sizeof tree);
        memset(exist, 0, sizeof exist);

        printf("Case %d:\n", ++case_no);

        int q; scanf("%d", &q);
        while(q--)
        {
            int type; scanf("%d", &type);

            if (type == 0)
            {
                int x, y; scanf("%d %d", &x, &y); ++x, ++y;
                if (!exist[x][y])
                    update(x, y), exist[x][y] = 1;
            }
            else
            {
                int x1, y1, x2, y2; scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
                ++x1, ++y1, ++x2, ++y2;
                printf("%d\n", query(x1, y1, x2, y2));
            }
        }
    }
    return 0;
}
