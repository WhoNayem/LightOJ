#include <bits/stdc++.h>
using namespace std;
#define Bismillah__Kun_Fayakun      ios_base :: sync_with_stdio(false);
#define ll                          long long
#define MAXN                        200007

int block;

struct Query {
	int L, R, index, result;
};

bool compare(Query x, Query y)
{
	if (x.L / block != y.L / block) return x.L / block < y.L / block;
	return x.R < y.R;
}

bool compare1(Query x, Query y)
{
	return x.index < y.index;
}

void printResults(vector <Query> q)
{
	sort(q.begin(), q.end(), compare1);
	for (int i = 0; i < q.size(); i++) printf("%d\n", q[i].result);
}

void queryResults(vector <int> a, int n, vector <Query> q, int m)
{
	block = (int)sqrt(n);
	sort(q.begin(), q.end(), compare);

	int currL = 0, currR = 0,  curr_Diff_elements = 0, freq[MAXN] = {0};

	for (int i = 0; i < m; i++)
    {
		int left = q[i].L, right = q[i].R;
		while (currL < left)
        {
			freq[a[currL]]--;
			if (freq[a[currL]] == 0) curr_Diff_elements--;
			currL++;
		}
		while (currL > left)
		{
			freq[a[currL - 1]]++;
			if (freq[a[currL - 1]] == 1) curr_Diff_elements++;
			currL--;
		}
		while (currR <= right)
		{
			freq[a[currR]]++;
			if (freq[a[currR]] == 1) curr_Diff_elements++;
			currR++;
		}
		while (currR > right + 1)
		{
			freq[a[currR - 1]]--;
			if (freq[a[currR - 1]] == 0) curr_Diff_elements--;
			currR--;
		}
		q[i].result = curr_Diff_elements;
	}
	printResults(q);
}


int main()
{
    Bismillah__Kun_Fayakun

	int test_case, case_no = 0; scanf("%d", &test_case);
	while(test_case--)
    {
        int n, q; scanf("%d %d", &n, &q);
        vector <int> vec(n);
        vector <Query> queries(q);
        for (int i = 0; i<n; ++i) scanf("%d", &vec[i]);
        for (int i = 0; i<q; ++i)
        {
            int left, right; scanf("%d %d", &left, &right);
            queries[i].L = --left; queries[i].R = --right;
            queries[i].index = i; queries[i].result = 0;
        }

        printf("Case %d:\n", ++case_no);
        queryResults(vec, n, queries, q);
    }
	return 0;
}
