#include <bits/stdc++.h>
using namespace std;
#define __Mammamia__                ios_base :: sync_with_stdio(false);
#define ll                          long long
#define MAXN                        10007
#define MOD                         100000007

ll n, cnt = 0, vec[107];

int solve(int m, int n )
{
    int table[n+1];
    memset(table, 0, sizeof(table));

    table[0] = 1;

    for(int i = 0; i < m; i++)
        for(int j = vec[i]; j <= n; j++)
            table[j] += table[j - vec[i]], table[j] %= MOD;

    return table[n];
}

int main ()
{
    __Mammamia__

    ll test_case, case_no = 0; scanf("%lld", &test_case);
    while(test_case--)
    {
        ll k; scanf("%lld %lld", &n, &k);
        for (ll i = 0; i < n; ++i) scanf("%lld", &vec[i]);

        ll res = solve(n, k) % MOD;
        printf("Case %lld: %lld\n", ++case_no, res);
    }

    return 0;
}
