#include <bits/stdc++.h>
using namespace std;
#define __Mammamia__                ios_base :: sync_with_stdio(false);
#define ll                          long long
#define MAXN                        207

int res = 1, id;

struct node
{
    int EndMark, str_cnt;
    node* Next[4];
    node()
    {
        EndMark = 0; str_cnt = 0;
        for(int i = 0; i < 4; ++i) Next[i] = NULL;
    }
}*root;

void Insert(string &str)
{
    node* cur = root;

    for(int i = 0; i < str.size(); ++i)
    {
        if (str[i] == 'A') id = 0;
        else if (str[i] == 'C') id = 1;
        else if (str[i] == 'G') id = 2;
        else id = 3;

        if(cur -> Next[id] == NULL ) cur -> Next[id] = new node();
        cur = cur -> Next[id];
        cur -> str_cnt++; int len = i + 1;
        res = max(res, cur -> str_cnt * len);
    }
    cur-> EndMark = true;
}

void del(node* cur)
{
    for(int i = 0; i < 4; i++) if(cur -> Next[i]) del(cur -> Next[i]);
    delete(cur);
}

int main(){
    __Mammamia__

    int test_case, case_no = 0; cin >> test_case;
    while(test_case--)
    {
        root = new node(); res = 1;

        int n; cin >> n;
        while(n--)
        {
            string str; cin >> str;
            Insert(str);
        }
        cout << "Case " << ++case_no << ": " << res << endl;
        del(root);
    }

    return 0;
}
