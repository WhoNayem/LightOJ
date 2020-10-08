#include <bits/stdc++.h>
using namespace std;
#define ll  long long
#define MAXN 1e5 + 7

vector <int> vec(MAXN), ASC(MAXN), DEC(MAXN), tree(4 * MAXN);

void build(int node, int b, int e)
{
    if (b == e)
    {
        tree[node] = ASC[b];
        return;
    }

    int mid = (b + e) / 2;
    int left = node * 2;
    int right = (node * 2) + 1;

    build(left, b, mid);
    build(right, mid + 1, e);

    tree[node] = max(tree[left], tree[right]);
}

int query(int node, int b, int e, int i, int j)
{
    if (i > e || j < b) return 0;
    if (b >= i && e <= j) return tree[node];

    int mid = (b + e) / 2;
    int left = node * 2;
    int right = (node * 2) + 1;

    int q1 = query(left, b, mid, i, j);
    int q2 = query(right, mid + 1, e, i, j);

    return max(q1, q2);
}

int main()
{
    int test_case, case_no = 0; scanf("%d", &test_case);
    while(test_case--)
    {
        int n, c, q; scanf("%d %d %d", &n, &c, &q);

        for (int i = 1; i<=n; ++i) {scanf(" %d", &vec[i]); ASC[i] = 1; if (vec[i] == vec[i - 1]) ASC[i] += ASC[i - 1];}
        DEC[n] = 1;
        for (int i = n - 1; i >= 1; --i) {DEC[i] = 1; if (vec[i] == vec[i + 1]) DEC[i] += DEC[i + 1];}

		build(1, 1, n);

		printf("Case %d:\n", ++case_no);

		while(q--)
		{
			int left, right; scanf("%d %d", &left, &right);

			int Max = 0;
			if (ASC[left] != 1) {Max = min(DEC[left], right - left + 1); left += Max;}
			if (left <= right) Max = max(Max, query(1, 1, n, left, right));
			printf("%d\n", Max);
		}
    }

    return 0;
}
