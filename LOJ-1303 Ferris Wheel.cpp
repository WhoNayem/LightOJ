#include <bits/stdc++.h>
using namespace std;
#define Bismillah__Kun_Fayakun      ios_base :: sync_with_stdio(false);
#define ll                          long long
#define MAXN                        200007

int main ()
{
    int test_case, case_no = 0; cin >> test_case;
    while(test_case--)
    {
        int n, m; cin >> n >> m;

        queue <int> man, temp;
        queue <pair <int, int> > wheel;
        for (int i = 1; i<=n; ++i) man.push(i);
        for (int i = 1; i<=m; ++i) wheel.push({i, 0});

        int cnt = 0, target = n * m, visited[23][23] = {0}, time = 5;

        while(cnt < target)
        {
            int seat = wheel.front().first;
            if (wheel.front().second != 0) man.push(wheel.front().second), wheel.front().second = 0;
            bool okay = true;
            vector <int> store;
            while(!man.empty())
            {
                if (okay)
                {
                    if (!visited[man.front()][seat])
                    {
                        visited[man.front()][seat] = 1;
                        ++cnt;
                        okay = false;
                        wheel.front().second = man.front();
                        man.pop();
                    }
                }
                if (!man.empty()) store.push_back(man.front()), man.pop();
            }

            if (okay) wheel.front().second = 0;
            for (int i = 0; i < store.size(); ++i) man.push(store[i]);

            time += 5;

            wheel.push({wheel.front().first, wheel.front().second});
            wheel.pop();
        }
        time += 5 * (m -1);
        cout << "Case " << ++case_no << ": " << time << endl;
    }

    return 0;
}
