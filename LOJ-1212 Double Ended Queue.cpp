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
        deque <int> dq;
        int n, m; cin >> n >> m;
        cout << "Case " << ++case_no << ":" << endl;
        while(m--)
        {
            string str; cin >> str;
            if (str == "popLeft")
            {
                if (dq.empty()) cout << "The queue is empty" << endl;
                else {cout << "Popped from left: " << dq.front() << endl; dq.pop_front();}
            }
            else if (str == "popRight")
            {
                if (dq.empty()) cout << "The queue is empty" << endl;
                else {cout << "Popped from right: " << dq.back() << endl; dq.pop_back();}
            }
            else if (str == "pushLeft")
            {
                int val; cin >> val;
                if (dq.size() == n) cout << "The queue is full" << endl;
                else {cout << "Pushed in left: " << val << endl; dq.push_front(val);}
            }
            else
            {
                int val; cin >> val;
                if (dq.size() == n) cout << "The queue is full" << endl;
                else {cout << "Pushed in right: " << val << endl; dq.push_back(val);}
            }
        }
    }
    return 0;
}
