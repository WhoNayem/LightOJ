#include <bits/stdc++.h>
using namespace std;

#define Bismillah__Kun_Fayakun         ios_base::sync_with_stdio(false);
#define MAXN                           1000007
#define ll                             long long

struct Tree
{
    int sum, prop;
}tree[4 * MAXN];

void build(int node, int b, int e)
{
    if(b == e)
    {
        tree[node].sum = tree[node].prop = 0;
        return;
    }

    int mid = (b + e)/2, left = 2 * node, right = 2 * node + 1;

    build(left, b, mid);
    build(right, mid + 1, e);

    tree[node].sum = tree[node].prop = 0;
}

void propagate(int node, int b, int e)
{
    if(tree[node].prop == -1) return;

    int mid = (b + e)/2, left = 2 * node, right = 2 * node + 1;
    tree[node].sum = (e - b + 1) * tree[node].prop;

    if(b != e)
    {
        tree[left].prop = tree[node].prop;
        tree[right].prop = tree[node].prop;
    }
    tree[node].prop = -1;
}

void update(int node, int b, int e, int i, int j, int val)
{
    propagate(node, b, e);

    if(b > j || e < i) return;
    else if(b >= i && e <= j)
    {
        tree[node].prop = val;
        propagate(node, b, e);
        return;
    }

    int mid = (b + e)/2, left = 2 * node, right = 2 * node + 1;

    update(left, b, mid, i, j, val);
    update(right, mid + 1, e, i, j, val);

    tree[node].sum = tree[left].sum+tree[right].sum;
}

int query(int node, int b, int e, int i, int j)
{
    propagate(node,b,e);

    if(b > j || e < i) return 0;
    else if(b >= i && e <= j) return tree[node].sum;

    int mid = (b + e)/2, left = 2 * node, right = 2 * node + 1;

    int q1 = query(left, b, mid, i, j);
    int q2 = query(right, mid + 1, e, i, j);

    return q1 + q2;
}

int main()
{
    int test_case,case_no = 0; scanf("%d",&test_case);
    while(test_case--)
    {
        int n, q, type, left, right, value;

        scanf("%d %d",&n, &q);

        build(1, 1, n);

        printf("Case %d:\n", ++case_no);
        for(int i = 0; i<q; ++i)
        {
            scanf("%d %d %d", &type, &left, &right);

            if(type == 2)
            {
                int sum = query(1, 1, n, ++left, ++right);
                int totalIndex = (right - left + 1);
                int gcd = __gcd(sum, totalIndex);

                sum /= gcd , totalIndex /= gcd;

                if(sum%totalIndex) printf("%d/%d\n", sum, totalIndex);
                else printf("%d\n", sum / totalIndex);
            }
            else
            {
                scanf("%d", &value);
                update(1, 1, n, ++left, ++right, value);
            }
        }
    }
}
