#include <bits/stdc++.h>
using namespace std;
#define __Mammamia__                ios_base :: sync_with_stdio(false);
#define ll                          long long
#define MAXN                        57

int main ()
{
    __Mammamia__

    ll test_case, case_no = 0; scanf("%lld", &test_case);
    while(test_case--)
    {
        ll n, l; scanf("%lld %lld", &n, &l);
        vector <ll> res;

        ll num = n - l;
        for (ll i = 1; i * i <= num; ++i)
        {
            if (num % i == 0)
            {
                if (i > l) res.push_back(i);
                if ((num / i != i) && (num / i) > l) res.push_back(num / i);
            }
        }
        printf("Case %lld: ", ++case_no);
        if (res.size())
        {
            sort(res.begin(), res.end());
            for (ll i = 0; i < res.size() - 1; ++i) printf("%lld ", res[i]); printf("%lld\n", res[res.size() - 1]);
        }
        else puts("impossible");
    }
    return 0;
}
