#include <bits/stdc++.h>
using namespace std;
#define __Mammamia__                ios_base :: sync_with_stdio(false);
#define ll                          long long
#define MAXN                        107

vector <int> vec(MAXN, 0);
double dp[MAXN];

int main()
{
    int test_case, case_no =0; cin >> test_case;
    while(test_case--)
    {
        memset(dp, 0, sizeof(dp));

        int n; cin >> n;
        for(int i = 1; i <= n; ++i) cin >> vec[i];

        dp[n] = vec[n];
        for(int i = n - 1; i >= 1; --i)
        {
            dp[i] = vec[i];
            int k = min(6, n - i);
            for(int j = 1; j <= k; ++j) {
                dp[i] += dp[i + j] * 1.0 / k;
            }
        }
        printf("Case %d: %.7lf\n", ++case_no, dp[1]);
    }
    return 0;
}
