#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define in(x) scanf("%lld", &x)
#define mp(x, y) make_pair(x, y)
#define ld long double


int main()
{

    ll Test;
    in(Test);
    for (ll i = 0; i < Test ; ++i)
    {
        ll N;
        in(N);
        vector<ll> V(N);

        string s;
        cin>>s;
        for (ll j = 0; j < N; ++j)
        {
            in(V[j]);
            if(V[j] == 0)
            {
                V[j] = 0;
            }
            else if (V[j] % 2 == 0)
            {
                V[j] = 2;
            }
            else
            {
                V[j] = 1;
            }
        }
        char won = 'p';
        string chance = s;

        if(N == 1 && V[0] % 2 == 0 && chance == "Dee")
        {
            printf("Dee\n");
            continue;
        }

        while(won == 'p')
        {
            if(chance == "Dee")
            {
                chance = "Dum";
                bool f = false;
                for (int j = 0; j < N ; ++j)
                {
                    if(V[j] == 2)
                    {
                        f = true;
                        //  V[j] = 0;
                        break;
                    }
                }

                if(!f)
                {
                    won = 'u';
                }
            } else
            {
                chance = "Dee";
                bool f = false;
                for (int j = 0; j < N ; ++j)
                {
                    if(V[j] == 2)
                    {
                        V[j] = 1;
                        f = true;
                        break;
                    }
                }

                if(!f)
                {
                    for (int j = 0; j < N ; ++j)
                    {
                        if(V[j] == 1)
                        {
                            // V[j] = 0;
                            f = true;
                            break;
                        }
                    }
                }

                if(!f)
                {
                    won = 'e';
                }

            }

        }

        if(won == 'e')
            printf("Dee\n");
        else
            printf("Dum\n");

    }
    return 0;
}