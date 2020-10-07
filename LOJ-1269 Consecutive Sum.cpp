#include <bits/stdc++.h>
using namespace std;
#define __Mammamia__                ios_base :: sync_with_stdio(false);
#define ll                          long long
#define MAXN                        207

struct node
{
    bool EndMark;
    node* Next[2];
    node()
    {
        EndMark = false;
        for(ll i = 0;  i < 2; ++i) Next[i] = NULL;
    }
}*root;

void Insert(ll x)
{
    node* cur = root;

    for (ll i = 31; i >= 0; --i)
    {
        ll id = (x >> i) & 1;
        if(cur -> Next[id] == NULL ) cur -> Next[id] = new node();
        cur = cur -> Next[id];
    }
    cur->EndMark = true;
}

ll SearchMin(ll x)
{
    node* cur = root; ll res = 0;

    for (ll i = 31; i >= 0; --i)
    {
        ll id = (x >> i) & 1;
        if (cur -> Next[id] == NULL)
        {
            res |= (1 << i);
            cur = cur -> Next[!id];
        }
        else cur = cur -> Next[id];
    }
    return res;
}

ll SearchMax(ll x)
{
    node* cur = root; ll res = 0;

    for (ll i = 31; i >= 0; --i)
    {
        ll id = (x >> i) & 1;
        if (cur -> Next[!id] != NULL)
        {
            res |= (1 << i);
            cur = cur -> Next[!id];
        }
        else cur = cur -> Next[id];
    }
    return res;
}

void del(node* cur)
{
    for(int i = 0; i < 2; i++)
        if(cur ->Next[i])
            del(cur ->Next[i]);

    delete(cur);
}

int main()
{
    __Mammamia__

    int test_case, case_no = 0; cin >> test_case;
    while(test_case--)
    {
        root = new node(); Insert(0);

        ll n, Xor = 0, Min = INT_MAX, Max = 0; cin >> n;

        while(n--)
        {
            ll x; cin >> x; Xor ^= x;

            Min = min(Min, SearchMin(Xor));
            Max = max(Max, SearchMax(Xor));

            Insert(Xor);
        }
        cout << "Case " << ++case_no << ": " << Max << " " << Min << endl;
        del(root);
    }
    return 0;
}
