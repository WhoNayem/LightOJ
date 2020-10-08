#include <bits/stdc++.h>
using namespace std;
#define Bismillah__Kun_Fayakun      ios_base :: sync_with_stdio(false);
#define ll                          long long
#define MAXN                        200007

int main()
{
    int test_case, case_no = 0; scanf("%d", &test_case);
    while(test_case--)
    {
        int n, Max = 0; scanf("%d", &n);
        vector <int> vec(n);
        for (int  i = 0; i<n; ++i) scanf("%d", &vec[i]);

        for (int i = 0; i<n; ++i)
        {
            int left = i - 1, right = i + 1, cnt = 1;
            while(left >= 0 && vec[left] >= vec[i]) ++cnt, --left;
            while(right <= n - 1 && vec[right] >= vec[i]) ++cnt, ++right;

            //cout << "Left : " << left << " Right : " << right << " cnt : " << cnt << endl;
            Max = max(Max, cnt * vec[i]);
        }
        printf("Case %d: %d\n", ++case_no, Max);
    }
    return 0;
}
