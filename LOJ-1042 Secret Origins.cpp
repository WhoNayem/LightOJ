#include <bits/stdc++.h>
using namespace std;
#define Bismillah__Kun_Fayakun      ios_base :: sync_with_stdio(false);
#define ll                          long long
#define MAXN                        200007

string decToBinary(int n)
{
    string str;
    for (int i = 31; i >= 0; i--)
    {
        int k = n >> i;
        if (k & 1) str += "1";
        else str += "0";
    }
    return str;
}

int binaryToDecimal(string n)
{
    string num = n; int dec_value = 0; int base = 1; int len = num.length();
    for (int i = len - 1; i >= 0; i--)
    {
        if (num[i] == '1') dec_value += base;
        base = base * 2;
    }
    return dec_value;
}

int main ()
{
    Bismillah__Kun_Fayakun

    int test_case, case_no = 0; cin >> test_case;
    while(test_case--)
    {
        int n, idx; cin >> n; bool okay = false, foundOne = false;
        string str, temp = decToBinary(n), t;

        for (int i = 0; i<temp.size(); i++){if (temp[i] == '1') foundOne = true;if (foundOne) str += temp[i];}

        for (int i = str.size() - 1; i > 0; --i) if (str[i] == '1' && str[i - 1] == '0') {okay = true; idx = i - 1; swap(str[i], str[i - 1]); break;}

        cout << "Case " << ++case_no << ": ";

        if (okay)
        {
            string temp;
            for (int i = str.size() - 1; i>idx; --i) temp += str[i];
            sort(temp.rbegin(), temp.rend());

            for (int i = idx; i >= 0; --i) temp += str[i];
            reverse(temp.begin(), temp.end());

            cout << binaryToDecimal(temp) << endl;
        }
        else
        {
            int cnt = 0; string s;
            for (int i = 0; i<str.size(); ++i) if (str[i] == '1') ++cnt;

            s += "1"; --cnt;

            for (int i = 0; i<str.size() - cnt; ++i) s += "0";
            for (int i = 0; i<cnt; ++i) s += "1";

            cout << binaryToDecimal(s) << endl;
        }
    }
    return 0;
}
