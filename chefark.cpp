
#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define in(x) scanf("%lld", &x)
#define mp(x, y) make_pair(x, y)
#define ld long double
#define mod 1000000007

ll power(ll a, ll m)
{
    ll ans = 1;
    while(m > 0)
    {
        if(m % 2 == 1)
        {
            ans = ans * a;
            ans = ans % mod;
        }
        a = a * a;
        a = a % mod;
        m = m / 2;
    }
    return ans;
}
int main()
{

    ll Test;
    in(Test);
    for (int i = 0; i < Test ; ++i)
    {
        // cout<<"NEXT TEST CASE"<<endl;
        ll N, K;
        in(N);
        in(K);
        vector<ll> V(N);
        ll countZero= 0;
        for (ll j = 0; j < N ; ++j)
        {
            in(V[j]);
            if(!V[j])
                ++countZero;
        }

        ll MAX = 1000000 + 10;
        vector<ll> Factorials(MAX);
        Factorials[0]  = 1;
        for (ll j = 1; j < MAX ; ++j)
        {
            Factorials[j] = Factorials[j - 1] * j;
            Factorials[j] %= mod;
        }

        if(countZero)
        {
            vector<ll> A;
            for (ll j = 0; j < N ; ++j)
            {
                if(V[j])
                    A.push_back(V[j]);
            }
            V = A;
            countZero = 1;
            N = V.size();
        }


        vector<ll> Helper(K + 1, 0);

        Helper[0] = 1;
        //  cout<<"HELLO"<<endl;
        //   cout<<"Starting loop"<<endl;
        for (ll j = 1; j <= K && j <= N ; ++j)
        {
            Helper[j] = Factorials[N] % mod;
            ll temp = Factorials[N - j] * Factorials[j];
            temp = temp % mod;
            temp = power(temp, mod - 2) % mod;
            Helper[j] = Helper[j] * temp;
            Helper[j] = Helper[j] % mod;
            //  cout<<Helper[j]<<" ";
        }
        //  cout<<endl;

        ll ans = 0;

        if(countZero)
        {
            for (ll j = 0; j <= K ; ++j)
            {
                ans += Helper[j];
                ans =  ans % mod;
            }
        } else
        {
            if(K % 2 == 0)
            {
                for (ll j = 0; j <=K ; j+=2)
                {
                    ans += Helper[j];
                    ans = ans % mod;
                }
            } else
            {
                for (ll j = 1; j <=K ; j+=2)
                {
                    ans += Helper[j];
                    ans = ans % mod;
                }
            }
        }

        printf("%lld\n", ans);

    }

    return 0;
}