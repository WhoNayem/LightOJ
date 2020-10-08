#include <bits/stdc++.h>
using namespace std;

#define Bismillah__Kun_Fayakun         ios_base::sync_with_stdio(false);
#define MAXN                           100007
#define ll                             long long

struct Tree
{
    int prop;
    map <int, int> Map;
}tree[4 * MAXN];

void combine(int node)
{
    int left = node * 2, right = (node * 2) + 1;
    tree[node].Map[0] = tree[left].Map[0] + tree[right].Map[0];
    tree[node].Map[1] = tree[left].Map[1] + tree[right].Map[1];
    tree[node].Map[2] = tree[left].Map[2] + tree[right].Map[2];
}

void build(int node, int b, int e)
{
    if(b == e)
    {
        tree[node].Map[0] = 1;
        tree[node].Map[1] = tree[node].Map[2] = tree[node].prop = 0;
        return;
    }

    int mid = (b + e)/2, left = node * 2, right = (node * 2) + 1;

    build(left, b, mid);
    build(right, mid + 1, e);
    combine(node);

    tree[node].prop = 0;
}

void rollOnce(int node)
{
    int Temp = tree[node].Map[2];
    tree[node].Map[2] = tree[node].Map[0];
    tree[node].Map[0] = tree[node].Map[1];
    tree[node].Map[1] = Temp;
}

void rollTwice(int node)
{
    int Temp = tree[node].Map[2];
    tree[node].Map[2] = tree[node].Map[1];
    tree[node].Map[1] = tree[node].Map[0];
    tree[node].Map[0] = Temp;
}

void propagate(int node, int b, int e)
{
    if(tree[node].prop == 0) return;
    int mid = (b + e)/2, left = 2 * node, right = 2 * node + 1;

    if (tree[node].prop == 1) rollOnce(node);
    else if (tree[node].prop == 2) rollTwice(node);

    if(b != e)
    {
        tree[left].prop += tree[node].prop; tree[left].prop %= 3;
        tree[right].prop += tree[node].prop; tree[right].prop %= 3;
    }
    tree[node].prop = 0;
}

void update(int node, int b, int e, int i, int j, int val)
{
    propagate(node, b, e);

    if(b > j || e < i) return;
    else if(b >= i && e <= j)
    {
        tree[node].prop++;
        propagate(node, b, e);
        return;
    }

    int mid = (b + e)/2, left = 2 * node, right = 2 * node + 1;

    update(left, b, mid, i, j, val);
    update(right, mid + 1, e, i, j, val);
    combine(node);
}

int query(int node, int b, int e, int i, int j)
{
    propagate(node,b,e);

    if(b > j || e < i) return 0;
    else if(b >= i && e <= j) return tree[node].Map[0];

    int mid = (b + e)/2, left = 2 * node, right = 2 * node + 1;

    int q1 = query(left, b, mid, i, j);
    int q2 = query(right, mid + 1, e, i, j);
    combine(node);

    return q1 + q2;
}

int main()
{
    Bismillah__Kun_Fayakun

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

            if(!type) update(1, 1, n, ++left, ++right, 1);
            else printf("%d\n", query(1, 1, n, ++left, ++right));
        }
    }
}
