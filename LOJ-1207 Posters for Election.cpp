#include <bits/stdc++.h>
using namespace std;
#define Bismillah__Kun_Fayakun      ios_base :: sync_with_stdio(false);
#define ll                          long long
#define MAXN                        200007

vector <ll> vec(MAXN, 0),lazy(3 * MAXN, -1);

void getReady()
{
    int i = 0, j = 0;
    for (; i<3 * MAXN; i += 3,++j){lazy[i] = lazy[i + 1] = lazy[i + 2] = -1;vec[j] = 0;}
}

void clearLazy(ll node, ll b, ll e)
{
    if (b == e) {if (lazy[node] != -1) vec[b] = lazy[node];}
    else if (lazy[node] != -1)
    {
        ll left = node*2;
        ll right = (2*node)+1;
        lazy[left] = lazy[node];
        lazy[right] = lazy[node];
    }
    lazy[node] = -1;
}

void updateRange(ll node, ll b, ll e, ll i, ll j, ll value)
{
    clearLazy(node, b, e);
    if (j<b || i>e) return;
    if (b>=i && e<=j)
    {
        lazy[node] = value;
        clearLazy(node,b,e);
        return;
    }

    ll left = node*2;
    ll right = (2*node)+1;
    ll mid = (b+e)/2;

    updateRange(left, b, mid, i, j, value);
    updateRange(right, mid+1, e, i, j, value);
}

void query(ll node, ll b, ll e, ll ind)
{
    clearLazy(node, b, e);
    if (b>ind || e<ind) return;
    if (b>=ind && e<=ind)
    {
        clearLazy(node, b, e);
        return;
    }

    ll left = 2*node;
    ll right = (2*node)+1;
    ll mid = (b+e)/2;

    query(left,b,mid,ind);
    query(right,mid+1,e,ind);
    return;
}
int main()
{
    Bismillah__Kun_Fayakun

    int test_case, case_no = 0; cin >> test_case;
    while(test_case--)
    {
        getReady();

        int n; cin >> n;
        for(int i = 1; i<=n; ++i)
        {
            int left, right; cin >> left >> right;
            updateRange(1, 1, 2 * n, left, right, i);
        }

        set <int> Set;

        for (int i = 1; i<= 2 * n; ++i)
        {
            query(1, 1, 2 * n, i);
            if (vec[i]) Set.insert(vec[i]);
        }
        int res = Set.size();
        cout << "Case " << ++case_no << ": " << res << endl;
    }

    return 0;
}
