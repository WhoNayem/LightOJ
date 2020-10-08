#include <bits/stdc++.h>
using namespace std;
#define __Mammamia__                ios_base :: sync_with_stdio(false);
#define ll                          long long
#define MAXN                        100007

ll check(ll x)
{
    ll ans = 0;
    while(x)
    {
        ans += x / 5;
        x /= 5;
    }
    return ans;
}

ll findNum(ll n)
{
    if (n == 1) return 5;
    ll low = 0, high = 5 * n, res = -1;

    while (low <= high)
    {
        ll mid = (low + high) / 2, ans = check(mid);
        if (ans == n) res = mid, high = mid - 1;
        else if (ans > n) high = mid - 1;
        else low = mid + 1;
    }
    if (res == -1) return 0;
    return res;
}

int main ()
{
    __Mammamia__

    ll test_case, case_no = 0; cin >> test_case;
    while(test_case--)
    {
        ll n; cin >> n;
        ll res = findNum(n);
        if (res) cout << "Case " << ++case_no << ": " << res << endl;
        else cout << "Case " << ++case_no << ": impossible" << endl;
    }

    return 0;
}
