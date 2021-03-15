#include <bits/stdc++.h>
using namespace std;
#define __Mammamia__                ios_base :: sync_with_stdio(false);
#define ll                          long long
#define MAXN                        207

struct node
{
    int window_size, left, right;
};
int cnt = 0, node_cnt = 0;
string str;
vector <int> vec;
map <string, int> Map;

bool comp(node a, node b)
{
    if (a.window_size != b.window_size) return a.window_size < b.window_size;
    return a.left < b.left;
}

void init()
{
    cnt = 0, node_cnt = 0;
    vec.clear();
    Map.clear();
}

void extract_string()
{
    for (int i = 0; i < str.size(); ++i)
    {
        string t;
        while(i < str.size() && str[i] >= 97 && str[i] <= 122)
            t += str[i], i++;
        if (t.size())
        {
            if (!Map[t]) Map[t] = ++cnt, vec.push_back(cnt), node_cnt++;
            else vec.push_back(Map[t]);
        }
    }
}

int main ()
{
    __Mammamia__

    int test_case, case_no = 0; cin >> test_case;
    while(test_case--)
    {
        init();

        while(getline(cin, str) && str != "END") extract_string();

        vector <node> res;
        vector <int> occ_cnt(node_cnt + 7, 0);

        int i = 0, j = 0, in_this_window = 0;
        while(i < vec.size())
        {
            while(j < vec.size() && in_this_window < node_cnt)
            {
                if (!occ_cnt[vec[j]]) in_this_window++;
                occ_cnt[vec[j]]++;
                j++;
            }

            while(i < j && in_this_window == node_cnt)
            {
                occ_cnt[vec[i]]--;
                if (!occ_cnt[vec[i]]) in_this_window--;

                if (in_this_window < node_cnt)
                {
                    res.push_back(node{j - i + 1, i + 1, j});
                    break;
                }
                i++;
            }
            i++;
        }

        sort(res.begin(), res.end(), comp);
        cout << "Case " << ++case_no << ": " << res[0].left << " " << res[0].right << endl;
    }

    return 0;
}
