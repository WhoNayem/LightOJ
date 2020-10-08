#include <bits/stdc++.h>
using namespace std;
#define __Mammamia__                ios_base :: sync_with_stdio(false);
#define ll                          long long
#define MAXN                        107

vector <int> primes(1, 2), Prime(MAXN, 1), base, power;

void SOE()
{
    for (int i = 2; i * i <= MAXN; ++i)
        if (Prime[i] == true)
            for (int j = i * i; j <= MAXN; j += i)
                Prime[j] = false;

    for (int i = 3; i <= MAXN; i += 2)
       if (Prime[i])
          primes.push_back(i);
}

void factorization(int n)
{
    for (int i = 0; i < primes.size() && primes[i] <= n; ++i)
    {
        int p = primes[i], freq = 0;
        while(n / p)
        {
            freq += n / p;
            p *= primes[i];
        }
        base.push_back(primes[i]); power.push_back(freq);
    }
}

int main ()
{
    __Mammamia__

    SOE();

    int test_case, case_no = 0; cin >> test_case;
    while(test_case--)
    {
        int n; cin >> n; base.clear(); power.clear();

        factorization(n);

        cout << "Case " << ++case_no << ": " << n << " = ";
        for (int i = 0; i < base.size() - 1; ++i)
            cout << base[i] << " (" << power[i] << ") * ";
        cout << base[base.size() - 1] << " (" << power[power.size() - 1] << ")" << endl;
    }

    return 0;
}
