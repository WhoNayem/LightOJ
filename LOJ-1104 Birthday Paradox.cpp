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
        int years, people = 1; cin >> years;
        while(1)
        {
            double Percentage = 1;
            for (int i = years; i > years - people; i--) Percentage *= ((double)i/(double)years);
            Percentage *= 100; Percentage = 100 - Percentage;
            if (Percentage >= 50) break;
            people++;
        }
        cout << "Case " << ++case_no << ": " << --people << endl;
    }


    return 0;
}
