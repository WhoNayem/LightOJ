#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 100007

int main() {
    int caseno = 0, test_case; cin >> test_case;
    while(test_case-- )
    {
        ll i = 1, temp, time, Max = 1, Mid, round = 1, row, col; cin  >> time;
        if (time == 1) {cout << "Case " << ++caseno << ": " << 1 << " " << 1 << endl; continue;}

        round = ceil(sqrt(time));
        Max = round * round; temp = (round - 1) * (round - 1);

        Mid = Max - ((Max - temp) / 2);

        row = round, col = round;

        if (time > Mid && round%2 == 0) col-= (time - Mid);
        else if (time > Mid) row -= (time - Mid);

        if (time < Mid && round%2 == 0) row -= (Mid - time);
        else if (time < Mid) col -= (Mid - time);

        cout << "Case " << ++caseno << ": " << row << " " << col << endl;


    }
    return 0;
}
