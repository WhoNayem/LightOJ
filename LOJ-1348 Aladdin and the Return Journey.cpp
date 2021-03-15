#include <bits/stdc++.h>
using namespace std;
#define __Mammamia__                            ios_base :: sync_with_stdio(false);
#define ll                                      long long
#define MAXN                                    30007

int n, chainId = 1, pos = 0, parent[MAXN], tree[MAXN * 4];
vector <int> graph[MAXN], vec(MAXN), chain(MAXN), chainHead(MAXN), position(MAXN), rev_position(MAXN), subtree_size(MAXN), level(MAXN);

void init(int n)
{
    chainId = 1, pos = 0, chainHead[1] = 1;
    for (int i = 0; i <= n; ++i)
    {
        graph[i].clear();
        vec[i] = 0;
        chain[i] = 0;
        chainHead[i] = 0;
        position[i] = 0;
        rev_position[i] = 0;
        subtree_size[i] = 0;
        level[i] = 0;
        parent[i] = 0;
    }
    memset(tree, 0, sizeof tree);
}

void update(int node, int b, int e, int idx, int val)
{
    if(b == e)
        tree[node] = val;
    else
    {
        int mid = (b + e) >> 1;
        if(idx <= mid) update(node * 2, b, mid, idx, val);
        else update(node * 2 + 1, mid + 1, e, idx, val);

        tree[node] = tree[node * 2] + tree[node * 2 + 1];
    }
}

void update(int idx, int val)
{
    update(1, 1, n, idx, val);
}

int query(int node, int b, int e, int l, int r)
{
    if(l <= b && e <= r)
        return tree[node];
    if(b > r || e < l)
        return 0;
    int mid = (b + e) >> 1;
    return query(node * 2, b, mid, l, r) + query(node * 2 + 1, mid + 1, e, l, r);
}

int query(int l, int r)
{
    if(l > r) return 0;
    return query(1, 1, n, l, r);
}

int queryUp(int from, int to)
{
    int curr = from, ans = 0;
    while(chain[curr] != chain[to])
    {
        if (level[chainHead[chain[curr]]] < level[chainHead[chain[to]]]) swap(curr, to);
        ans += query(position[chainHead[chain[curr]]], position[curr]);
        curr = parent[chainHead[chain[curr]]];
    }
    if (level[curr] < level[to]) swap(curr, to);
    ans += query(position[to], position[curr]);
    return ans;
}


/*--------------------------------------Heavy-Light Decomposition-----------------------------------------*/

void dfs(int node, int par, int depth)
{
    parent[node] = par;
    subtree_size[node]++; level[node] = depth;

    for (auto x : graph[node])
        if (x != par)
            dfs(x, node, depth + 1), subtree_size[node] += subtree_size[x];
}


void HLD(int node, int par)
{
    int heavyChild = -1, heavySize = 0, heavyEdgeWeight = -1;
    chain[node] = chainId; position[node] = ++pos, rev_position[pos] = node;

    for (auto x : graph[node])
        if (x != par)
            if (subtree_size[x] > heavySize)
                heavySize = subtree_size[x], heavyChild = x;

    if (heavyChild != -1) HLD(heavyChild, node);

    for (auto x : graph[node])
        if (x != par && x != heavyChild)
            chainId++, chainHead[chainId] = x, HLD(x, node);

}

/* -------------------------------------------------------------------*/

int main ()
{
    __Mammamia__

    int test_case, case_no = 0; scanf("%d", &test_case);
    while(test_case--)
    {
        scanf("%d", &n); init(n);

        for (int i = 1; i <= n; ++i)
            scanf("%d", &vec[i]);

        for (int i = 1; i < n; ++i)
        {
            int u, v; scanf("%d %d", &u, &v); ++u, ++v;
            graph[u].push_back(v);
            graph[v].push_back(u);
        }

        dfs (1, -1, 0);
        HLD (1, 0);

        for (int i = 1; i <= n; ++i)
            update(i, vec[rev_position[i]]);

        printf("Case %d:\n", ++case_no);
        int q; scanf("%d", &q);
        for (int i = 1; i <= q; ++i)
        {
            int type; scanf("%d", &type);

            if (type)
            {
                int idx, val; scanf("%d %d", &idx, &val); ++idx;
                update(position[idx], val);
            }
            else
            {
                int left, right; scanf("%d %d", &left, &right); ++left, ++right;
                int res = queryUp(left, right);
                printf("%d\n", res);
            }
        }
    }

    return 0;
}
