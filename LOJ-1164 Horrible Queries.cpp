#include <bits/stdc++.h>
using namespace std;
#define Bismillah__Kun_Fayakun      ios_base :: sync_with_stdio(false);
#define ll                          long long
#define MAXN                        200007

struct info {
    ll prop, sum;
} tree[MAXN * 3];

void getReady(){
    for (ll i = 0; i<MAXN * 3; i += 3){
        tree[i].sum = 0, tree[i].prop = 0;
        tree[i + 1].sum = 0, tree[i + 1].prop = 0;
        tree[i + 2].sum = 0, tree[i + 2].prop = 0;
    }
}

void update(ll node, ll b, ll e, ll i, ll j, ll x)
{
    if (i > e || j < b) return;
    if (b >= i && e <= j)
    {
        tree[node].sum += ((e - b + 1) * x);
        tree[node].prop += x; return;
    }

    ll Left = node * 2;
    ll Right = (node * 2) + 1;
    ll mid = (b + e) / 2;

    update(Left, b, mid, i, j, x);
    update(Right, mid + 1, e, i, j, x);

    tree[node].sum = tree[Left].sum + tree[Right].sum + (e - b + 1) * tree[node].prop;
}

ll query(ll node, ll b, ll e, ll i, ll j, ll carry = 0)
{
    if (i > e || j < b) return 0;

    if (b >= i and e <= j) return tree[node].sum + carry * (e - b + 1);

    ll Left = node << 1;
    ll Right = (node << 1) + 1;
    ll mid = (b + e) >> 1;

    ll p1 = query(Left, b, mid, i, j, carry + tree[node].prop);
    ll p2 = query(Right, mid + 1, e, i, j, carry + tree[node].prop);

    return p1 + p2;
}

int main ()
{
    Bismillah__Kun_Fayakun

    int test_case, case_no = 0; cin >> test_case;
    while(test_case--)
    {
        getReady();
        cout << "Case " << ++case_no << ":" << endl;

        ll n, q; cin >> n >> q;
        while(q--)
        {
            ll Type, left, right, value; cin >> Type >> left >> right;

            if (!Type)
            {
                cin >> value;
                if(value) update(1, 1, n, ++left, ++right, value);
            }
            else cout << query(1, 1, n, ++left, ++right) << endl;
        }
    }

    return 0;
}
