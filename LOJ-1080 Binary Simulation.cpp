#include <bits/stdc++.h>
using namespace std;
#define Bismillah__Kun_Fayakun      ios_base :: sync_with_stdio(false);
#define ll                          long long
#define MAXN                        100007

struct info {
    int prop, sum;
} tree[MAXN * 3];

void getReady()
{
    for(int i = 0; i<3 * MAXN; i +=3)
    {
        tree[i].sum = tree[i].prop = 0;
        tree[i + 1].sum = tree[i + 1].prop = 0;
        tree[i + 2].sum = tree[i + 2].prop = 0;
    }
}

void update(int node, int b, int e, int i, int j, int x)
{
    if (i > e || j < b) return;
    if (b >= i && e <= j)
    {
        tree[node].sum += ((e - b + 1) * x);
        tree[node].prop += x;
        return;
    }

    int Left = node * 2;
    int Right = (node * 2) + 1;
    int mid = (b + e) / 2;

    update(Left, b, mid, i, j, x);
    update(Right, mid + 1, e, i, j, x);

    tree[node].sum = tree[Left].sum + tree[Right].sum + (e - b + 1) * tree[node].prop;
}

int query(int node, int b, int e, int i, int j, int carry = 0)
{
    if (i > e || j < b) return 0;

    if (b >= i and e <= j) return tree[node].sum + carry * (e - b + 1);

    int Left = node << 1;
    int Right = (node << 1) + 1;
    int mid = (b + e) >> 1;

    int p1 = query(Left, b, mid, i, j, carry + tree[node].prop);
    int p2 = query(Right, mid + 1, e, i, j, carry + tree[node].prop);

    return p1 + p2;
}

int main()
{
    int test_case, case_no = 0; scanf("%d", &test_case);
    while(test_case--)
    {
        getReady();

        char str[MAXN]; scanf("%s", str); string s = str; int n = s.size();
        int q; scanf("%d", &q);
        printf("Case %d:\n", ++case_no);
        while(q--)
        {
            char type[2]; scanf("%s", type);
            int left, right;

            if (type[0] == 'I')
            {
                scanf("%d %d", &left, &right);
                update(1, 1, n, left, right, 1);
            }
            else
            {
                scanf("%d", &left);
                int res = query(1, 1, n, left, left);
                if (res%2 == 1)
                {
                    if (str[left - 1] == '0') puts("1");
                    else puts("0");
                }
                else
                {
                    if (str[left - 1] == '0') puts("0");
                    else puts("1");
                }
            }
        }
    }
    return 0;
}
