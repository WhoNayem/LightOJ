#include <bits/stdc++.h>
using namespace std;
#define __Mammamia__                ios_base :: sync_with_stdio(false);
#define ll                          long long
#define MAXN                        1000007

ll fact[MAXN], dp[MAXN], MOD = 1000003;

void MODularInverse(ll n)
{
    dp[0] = dp[1] = 1;
    for (ll i = 2; i <= n; i++)
        dp[i] = dp[MOD % i] *
               (MOD - MOD / i) % MOD;

    fact[0] = 1;
    for (ll i = 1; i <= n; ++i)
        fact[i] = (fact[i - 1] * i) % MOD;
}

ll nCr (ll n, ll r)
{
    return (fact[n] * dp[fact[r]] % MOD * dp[fact[n - r]] % MOD) % MOD;
}

int main ()
{
    __Mammamia__

    ll test_case, case_no = 0; scanf("%lld", &test_case); MODularInverse(MAXN);
    while(test_case--)
    {
        ll n, r; scanf("%lld %lld", &n, &r);
        printf("Case %lld: %lld\n", ++case_no, nCr(n, r));
    }

    return 0;
}
