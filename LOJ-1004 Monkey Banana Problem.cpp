#include <bits/stdc++.h>
using namespace std;
#define __Mammamia__                ios_base :: sync_with_stdio(false);
#define ll                          long long
#define MAXN                        10507
#define MOD                         100000007

int main()
{
    __Mammamia__

    ll test_case; cin>>test_case;
    for (int t = 1; t <= test_case; ++t)
    {
        ll n, sum = 0, arr[500][500];
        cin >> n;

        arr[0][1] = 0;

        for (int i = 1; i <= n; ++i)
        {
            for (int j = 1; j <= i; ++j)
            {
                cin >> arr[i][j];
                if (j == 1) arr[i][j] += arr[i - 1][j];
                else if (i == j) arr[i][j] += arr[i - 1][j - 1];
                else arr[i][j] += max(arr[i - 1][j], arr[i - 1][j - 1]);
            }
        }
        for (int i = n + 1; i <= (2 * n) - 1; ++i)
        {
            for (int j = 1; j <= (2 * n) - i; ++j)
            {
                cin >> arr[i][j];
                arr[i][j] += max(arr[i - 1][j], arr[i - 1][j + 1]);
            }
        }
        cout << "Case " << t << ": " << arr[(2 * n) - 1][1] <<endl;

    }
    return 0;
}
