#include <bits/stdc++.h>
using namespace std;
#define __Mammamia__                ios_base :: sync_with_stdio(false);
#define ll                          long long
#define MAXN                        207

struct node
{
    bool EndMark; int str_cnt;
    node* Next[10];
    node()
    {
        EndMark = false;
        str_cnt = 0;
        for(int i = 0;  i < 10; ++i) Next[i] = NULL;
    }
}*root;

void Insert(string &str)
{
    node* cur = root;

    for(int i = 0; i < str.size(); ++i)
    {
        int id = str[i] - '0';
        if(cur -> Next[id] == NULL ) cur -> Next[id] = new node();
        cur -> str_cnt = cur -> str_cnt + 1;
        cur = cur -> Next[id];
    }
    cur->EndMark = true;
}

bool Search(string &str)
{
    node* cur = root;
    for(int i = 0; i < str.size(); i++)
    {
        int id = str[i] - '0';
        if (cur -> EndMark == true) return true;
        if(cur->Next[id] == NULL) return false;
        cur = cur -> Next[id];
    }
    return cur -> str_cnt;
}

void del(node* cur)
{
    for(int i = 0; i < 10; i++){
        if(cur ->Next[i]) del(cur ->Next[i]);
    }
    delete(cur);
}

int main()
{
    __Mammamia__

    int test_case, case_no = 0; cin >> test_case;
    while(test_case--)
    {
        root = new node();

        int n; cin >> n;
        bool found_match = false;
        while(n--)
        {
            string str; cin >> str;
            if (Search(str)) found_match = true;
            if (!found_match) Insert(str);
        }

        if (found_match) cout << "Case " << ++case_no << ": NO" << endl;
        else cout << "Case " << ++case_no << ": YES" << endl;

        del(root);
    }

    return 0;
}

