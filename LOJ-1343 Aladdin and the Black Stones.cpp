#include <bits/stdc++.h>
using namespace std;
#define __Mammamia__                ios_base :: sync_with_stdio(false);
#define ll                          long long
#define MAXN                        507

struct node
{
    int x, y, val;
};

int n, vec[MAXN], tree[MAXN][MAXN];
vector <node> q;

bool comp(node a, node b)
{
    if (a.val != b.val) return a.val < b.val;
    if (a.x != b.x) return a.x < b.x;
    return a.y > b.y;
}

void update(int x, int y, unsigned int val)
{
    for (int i = x; i < MAXN; i += i & (-i))
        for (int j = y; j < MAXN; j += j & (-j))
            tree[i][j] += val;
}

unsigned int query(int x, int y)
{
    unsigned int res = 0;

    for (int i = x; i > 0; i -= i & (-i))
        for (int j = y; j > 0; j -= j & (-j))
            res += tree[i][j];

    return res;
}

unsigned int query(int x, int y, int t)
{
    return query(MAXN - 1, y - 1) - query(x, y - 1);
}

void init()
{
    memset(tree, 0, sizeof tree);
    q.clear();
}

int main ()
{
    __Mammamia__

    int test_case, case_no = 0; scanf("%d", &test_case);
    while(test_case--)
    {
        scanf("%d", &n); init();
        for (int i = 1; i <= n; ++i)
        {
            scanf("%d", &vec[i]);
            for (int j = 1; j < i; ++j)
                q.emplace_back(node{j, i, vec[i] + vec[j]});
        }

        sort(q.begin(), q.end(), comp);

        unsigned int res = 0;

        for (int i = 0; i < q.size(); ++i)
        {
            int x = q[i].x, y = q[i].y;
            unsigned t = query(x, y, MAXN) + 1;
            res += t;
            update(x, y, t);
        }

        printf("Case %d: %u\n", ++case_no, res);

    }

    return 0;
}
