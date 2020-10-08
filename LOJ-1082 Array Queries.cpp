#include <bits/stdc++.h>
using namespace std;
#define Bismillah__Kun_Fayakun      ios_base :: sync_with_stdio(false);
#define ll                          long long
#define MAXN                        200007

int arr[MAXN], tree[MAXN * 3];
void init(int node, int b, int e)
{
    if (b == e) {
        tree[node] = arr[b];
        return;
    }

    int Left = node * 2;
    int Right = node * 2 + 1;
    int mid = (b + e) / 2;

    init(Left, b, mid);
    init(Right, mid + 1, e);

    tree[node] = min(tree[Left], tree[Right]);
}
int query(int node, int b, int e, int i, int j)
{
    if (i > e || j < b) return 1e7;
    if (b >= i && e <= j) return tree[node];

    int Left = node * 2;
    int Right = node * 2 + 1;
    int mid = (b + e) / 2;

    int p1 = query(Left, b, mid, i, j);
    int p2 = query(Right, mid + 1, e, i, j);

    return min(p1, p2);
}

int main()
{
    int test_case, case_no = 0; scanf("%d", &test_case);
    while(test_case--)
    {
        int n, q; scanf("%d %d", &n, &q);
        for (int i = 1; i<=n; ++i) scanf("%d", &arr[i]);

        init(1, 1, n);

        printf("Case %d:\n", ++case_no);
        while(q--)
        {
            int left, right; scanf("%d %d", &left, &right);
            printf("%d\n", query(1, 1, n, left, right));
        }

    }
    return 0;
}
