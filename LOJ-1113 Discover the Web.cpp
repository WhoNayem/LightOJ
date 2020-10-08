#include <bits/stdc++.h>
using namespace std;
#define Bismillah__Kun_Fayakun      ios_base :: sync_with_stdio(false);
#define ll                          long long
#define MAXN                        200007

int main ()
{
    Bismillah__Kun_Fayakun

    int test_case, case_no = 0; cin >> test_case;
    while(test_case--)
    {
        deque <string> Backward, Forward; string str;
        Backward.push_back("http://www.lightoj.com/");

        cout << "Case " << ++case_no << ":" << endl;
        while(cin >> str && str != "QUIT")
        {
            if (str == "BACK")
            {
                if (Backward.size() < 2) cout << "Ignored" << endl;
                else
                {
                    Forward.push_front(Backward.back());
                    Backward.pop_back();
                    cout << Backward.back() << endl;
                }
                continue;
            }
            if (str == "FORWARD")
            {
                if (Forward.empty()) cout << "Ignored" << endl;
                else
                {
                    Backward.push_back(Forward.front());
                    Forward.pop_front();
                    cout << Backward.back() << endl;
                }
                continue;
            }

            string add; cin >> add;
            Forward.clear(); Backward.push_back(add);
            cout << add << endl;
        }
    }
    return 0;
}
