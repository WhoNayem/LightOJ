#include <bits/stdc++.h>
using namespace std;
#define __Mammamia__                ios_base :: sync_with_stdio(false);
#define ll                          long long
#define MAXN                        1e18

int n, vec[20][3], dp[20][3];

int solve(int node, int state)
{
    if (node == n) return 0;
    if (dp[node][state] != -1) return dp[node][state];

    int Min = INT_MAX;
    if (state != 0) Min = min(Min, vec[node][state] + solve(node + 1, 0));
    if (state != 1) Min = min(Min, vec[node][state] + solve(node + 1, 1));
    if (state != 2) Min = min(Min, vec[node][state] + solve(node + 1, 2));

    return dp[node][state] = Min;
}

int main ()
{
    __Mammamia__

    int test_case, case_no = 0; cin >> test_case;
    while(test_case--)
    {
        memset(dp, -1, sizeof dp);

        cin >> n;

        for (int i = 0; i < n; ++i)
            cin >> vec[i][0] >> vec[i][1] >> vec[i][2];

        int Min = INT_MAX;
        Min = min(Min, solve(0, 0));
        Min = min(Min, solve(0, 1));
        Min = min(Min, solve(0, 2));

        cout << "Case " << ++case_no << ": " << Min << endl;
    }

    return 0;
}
