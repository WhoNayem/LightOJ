#include <bits/stdc++.h>
using namespace std;
#define Bismillah__Kun_Fayakun      ios_base :: sync_with_stdio(false);
#define ll                          long long
#define MAXN                        100007

int arr[MAXN], treeForMin[MAXN * 3], treeForMax[MAXN * 3];

void init(int node, int b, int e)
{
    if (b == e) {
        treeForMin[node] = arr[b];
        treeForMax[node] = arr[b];
        return;
    }
    int Left = node * 2;
    int Right = node * 2 + 1;
    int mid = (b + e) / 2;

    init(Left, b, mid);
    init(Right, mid + 1, e);

    treeForMin[node] = min(treeForMin[Left], treeForMin[Right]);
    treeForMax[node] = max(treeForMax[Left], treeForMax[Right]);
}

int queryForMin(int node, int b, int e, int i, int j, bool type)
{
    if (i > e || j < b) {if (type) return 1e9; else return 0;}
    if (b >= i && e <= j) {if (type) return treeForMin[node]; else return treeForMax[node];}

    int Left = node * 2;
    int Right = node * 2 + 1;
    int mid = (b + e) / 2;

    int p1, p2;
    if (type) p1 = queryForMin(Left, b, mid, i, j, true);
    else p1 = queryForMin(Left, b, mid, i, j, false);
    if (type) p2 = queryForMin(Right, mid + 1, e, i, j, true);
    else p2 = queryForMin(Right, mid + 1, e, i, j, false);

    if (type) return min(p1, p2);
    else return max(p1, p2);
}

int main()
{
    int test_case, case_no = 0; cin >> test_case;
    while(test_case--)
    {
        int n, d, res = 0; cin >> n >> d;
        for (int i = 1; i<=n; ++i) cin >> arr[i];

        init(1, 1, n);

        for (int i = 1; i<=n; i++)
        {
            int Max = queryForMin(1, 1, n, i, min(i + d - 1, n), false);
            int Min = queryForMin(1, 1, n, i, min(i + d - 1, n), true);
            res = max(res, Max - Min);
        }
        cout << "Case " << ++case_no << ": " << res << endl;
    }

    return 0;
}
