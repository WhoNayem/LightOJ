#include <bits/stdc++.h>
using namespace std;
#define __Mammamia__                ios_base :: sync_with_stdio(false);
#define ll                          long long
#define MAXN                        31

ll n, dp[MAXN][MAXN][907];

ll solve(ll n, ll m, ll k)
{
    if (k == 0) return 1;
    if (k > n || k > m) return 0;

    if (dp[n][m][k] != -1) return dp[n][m][k];

    return dp[n][m][k] = n * solve(n - 1, m - 1, k - 1) + solve (n, m - 1, k);
}

int main ()
{
    __Mammamia__

    ll test_case, case_no = 0; cin >> test_case;
    while(test_case--)
    {
        memset(dp, -1, sizeof dp);

        ll n, k; cin >> n >> k;
        cout << "Case " << ++case_no << ": " << solve(n, n, k) << endl;
    }
    return 0;
}
