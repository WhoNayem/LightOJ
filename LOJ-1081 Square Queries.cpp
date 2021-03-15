#include <bits/stdc++.h>
using namespace std;
#define __Mammamia__                ios_base :: sync_with_stdio(false);
#define ll                          long long
#define MAXN                        507

int vec[MAXN][MAXN], tree[MAXN][MAXN * 4];

void init(int row, int node, int b, int e)
{
    if (b == e)
    {
        tree[row][node] = vec[row][b];
        return;
    }
    int mid = (b + e) >> 1, left = node * 2, right = node * 2 + 1;
    init(row, left, b, mid);
    init(row, right, mid + 1, e);
    tree[row][node] = max(tree[row][left], tree[row][right]);
}

int query(int row, int node, int b, int e, int i, int j)
{
    if (b > j || e < i) return 0;
    if (b >= i && e <= j) return tree[row][node];
    int mid = (b + e) >> 1, left = node * 2, right = node * 2 + 1;
    return max(query(row, left, b, mid, i, j), query(row, right, mid + 1, e, i, j));
}

int main ()
{
    __Mammamia__

    int test_case, case_no = 0; scanf("%d", &test_case);
    while(test_case--)
    {
        int n, q; scanf("%d %d", &n, &q);

        for (int i = 1; i <= n; ++i)
        {
            for (int j = 1; j <= n; ++j)
                scanf("%d", &vec[i][j]);
            init(i, 1, 1, MAXN);
        }

        printf("Case %d:\n", ++case_no);
        while(q--)
        {
            int x, y, s, res = 0; scanf("%d %d %d", &x, &y, &s);
            for (int i = x; i <= x + s - 1; ++i)
                res = max(res, query(i, 1, 1, MAXN, y, y + s - 1));
            printf("%d\n", res);
        }
    }

    return 0;
}
