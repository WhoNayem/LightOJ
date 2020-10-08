#include <bits/stdc++.h>
using namespace std;
#define __Mammamia__                ios_base :: sync_with_stdio(false);
#define ll                          long long
#define MAXN                        1000

vector <pair <int, int> > numDiv;

bool comp(pair <int, int> a, pair <int, int> b)
{
    if (a.second != b.second) return a.second < b.second;
    return a.first > b.first;
}

void findNumOfDivisor()
{
    for (int i = 1; i <= MAXN; ++i)
    {
        int div = 0;
        for (int j = 1; j * j <= i; ++j)
        {
            if (i % j == 0)
            {
                div++;
                if (i / j != j) div++;
            }
        }
        numDiv.push_back({i, div});
        //cout << "I : " << i << " Div : " << div << endl;
    }
    sort(numDiv.begin(), numDiv.end(), comp);
}

int main ()
{
    __Mammamia__

    int test_case, case_no = 0; cin >> test_case; findNumOfDivisor();
    while(test_case--)
    {
        int n; cin >> n;
        cout << "Case " << ++case_no << ": " << numDiv[n - 1].first << endl;
    }


    return 0;
}
