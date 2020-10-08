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
        double tigers, deers; cin >> tigers >> deers;
        if (tigers == 0) {cout << "Case " << ++case_no << ": " << 1.000000 << endl; continue;}
        if ((int)tigers%2 == 1) {cout << "Case " << ++case_no << ": " << 0.000000 << endl; continue;}
        else
        {
            double res = 1 - (tigers / (tigers + 1));
            cout << "Case " << ++case_no << ": " << fixed << setprecision(6) << res << endl;
        }
    }
    return 0;
}
