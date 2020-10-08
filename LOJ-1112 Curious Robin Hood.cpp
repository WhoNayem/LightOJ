#include <bits/stdc++.h>
using namespace std;
#define Bismillah__Kun_Fayakun      ios_base :: sync_with_stdio(false);
#define ll                          long long
#define MAXN                        200007

int arr[MAXN], tree[MAXN * 3];

void init(int node, int b, int e)
{
    if (b == e) {tree[node] = arr[b]; return;}

    int Left = node * 2;
    int Right = node * 2 + 1;
    int mid = (b + e) / 2;

    init(Left, b, mid);
    init(Right, mid + 1, e);

    tree[node] = tree[Left] + tree[Right];
}

int query(int node, int b, int e, int i, int j)
{
    if (i > e || j < b) return 0;
    if (b >= i && e <= j) return tree[node];

    int Left = node * 2;
    int Right = node * 2 + 1;
    int mid = (b + e) / 2;

    int p1 = query(Left, b, mid, i, j);
    int p2 = query(Right, mid + 1, e, i, j);

    return p1 + p2;
}

void update(int node, int b, int e, int i, int newvalue)
{
    if (i > e || i < b) return;
    if (b >= i && e <= i) {tree[node] = newvalue;return;}

    int Left = node * 2;
    int Right = node * 2 + 1;
    int mid = (b + e) / 2;

    update(Left, b, mid, i, newvalue);
    update(Right, mid + 1, e, i, newvalue);

    tree[node] = tree[Left] + tree[Right];
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
            int Type, i, value; scanf("%d %d", &Type, &i); ++i;

            if (Type == 1)
            {
                int toBeRemoved = query(1, 1, n, i, i);
                update(1, 1, n, i, 0);
                printf("%d\n", toBeRemoved);
            }
            else if (Type == 2)
            {
                scanf("%d", &value);
                int have = query(1, 1, n, i, i);
                update(1, 1, n, i, have + value);
            }
            else
            {
                scanf("%d", &value); ++value;
                printf("%d\n", query(1, 1, n, i, value));
            }
        }
    }


    return 0;
}
