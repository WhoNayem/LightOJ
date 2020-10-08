#include <bits/stdc++.h>
using namespace std;
#define Kun_Fayakun                 ios_base :: sync_with_stdio(false);
#define ll                          long long
#define MAXN                        200007

int main ()
{
    Kun_Fayakun

    int test_case, case_no = 0; cin >> test_case;
    while(test_case--)
    {
        int n, m, k; cin >> n >> m >> k;
        double p, temp = 0; cin >> p;
        temp = n * p; temp *= k;

        cout << "Case " << ++case_no << ": " << temp << endl;
    }
    return 0;
}
