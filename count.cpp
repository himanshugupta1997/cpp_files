#include <bits/stdc++.h>
using namespace std;

#define in(x) scanf("%d", &x)
#define ll long long int
#define mod 1000000007
#define limit 1000010
bool * IsPrime;
vector<int> Primes;

struct Node
{
    vector<int> Factors;
    vector<int> Cumulative;
    int leftLimit;
    int rightLimit;
};

void GetFactors(vector<int> &F, vector<int> &C,  int N)
{
    int sum = 0;
    int temp = N;
    if(IsPrime[temp])
    {
        F.push_back(temp);
        sum += 1;
        C.push_back(sum);
        return;
    }
    int k = 0;
    int e;
    while(temp > 1)
    {
        e = 0;
        while(temp % Primes[k] == 0)
        {
            temp = temp / Primes[k];
            ++e;
        }
        if( e != 0)
        {
            sum += e;
            F.push_back(Primes[k]);
            C.push_back(sum);
        }
        ++k;
        if(IsPrime[temp])
        {
            F.push_back(temp);
            sum += 1;
            C.push_back(sum);
            break;
        }
    }
    return;
}

void AddFactors(vector<int> &SF, vector<int> &SC, vector<int> &F1, vector<int> &C1, vector<int> &F2, vector<int> &C2)
{
    int i, j;
    i = 0;
    j = 0;
    int freq;
    vector<int> Frequency;
    while ( (i < F1.size()) && (j < F2.size()))
    {
        if(F1[i] == F2[j])
        {
            SF.push_back(F1[i]);
            freq = 0;

            if(i == 0)
                freq += C1[i];
            else
                freq += C1[i] - C1[i - 1];

            if(j == 0)
                freq += C2[j];
            else
                freq += C2[j] - C2[j - 1];

            Frequency.push_back(freq);

            //S.push_back(make_pair(F1[i].first, (F1[i].second + F2[j].second)));
            ++i;
            ++j;
            continue;
        }
        if(F1[i] < F2[j])
        {
            SF.push_back(F1[i]);
            freq = 0;
            if(i == 0)
                freq += C1[i];
            else
                freq += C1[i] - C1[i - 1];
            Frequency.push_back(freq);
            ++i;
            continue;
        }
        SF.push_back(F2[j]);
        freq = 0;
        if(j == 0)
            freq += C2[j];
        else
            freq += C2[j] - C2[j - 1];
        Frequency.push_back(freq);
        ++j;
    }

    while (i <F1.size())
    {
        SF.push_back(F1[i]);
        // freq = 0;
        if(i == 0)
            freq = C1[i];
        else
            freq = C1[i] - C1[i - 1];
        Frequency.push_back(freq);
        ++i;
    }

    while(j < F2.size())
    {
        SF.push_back(F2[j]);
       // freq = 0;
        if(j == 0)
            freq = C2[j];
        else
            freq = C2[j] - C2[j - 1];
        Frequency.push_back(freq);
        ++j;
    }

    SC.push_back(Frequency[0]);
    for (i = 1; i < Frequency.size() ; ++i)
    {
        SC.push_back(SC[i - 1] + Frequency[i]);
    }
    return;
}


void ConstructSegmentTreeUtil(int TreeIndex, int start, int end, Node * Tree, int V[])
{
    if(start == end)
    {
        Tree[TreeIndex].rightLimit = end;
        Tree[TreeIndex].leftLimit = start;
        GetFactors(Tree[TreeIndex].Factors , Tree[TreeIndex].Cumulative, V[start]);
        return;
    }

    int mid = (start + end)/2;
    ConstructSegmentTreeUtil(2 * TreeIndex + 1, start, mid, Tree, V);
    ConstructSegmentTreeUtil(2 * TreeIndex + 2, mid + 1, end, Tree, V);
    Tree[TreeIndex].rightLimit = end;
    Tree[TreeIndex].leftLimit = start;
    AddFactors(Tree[TreeIndex].Factors, Tree[TreeIndex].Cumulative, Tree[2 * TreeIndex + 1].Factors, Tree[2 * TreeIndex + 1].Cumulative, Tree[2 * TreeIndex + 2].Factors, Tree[2 * TreeIndex + 2].Cumulative);
    return;
}


void ConstructSegmentTree( Node * Tree, int V[], int N)
{
    ConstructSegmentTreeUtil(0, 0, N - 1, Tree, V);
    return;
}

int GetNumberOfElements( vector<int> &F, vector<int> &C,  int X, int Y) {

    auto lower = lower_bound(F.begin(), F.end(), X);
    auto upper = upper_bound(F.begin(), F.end(), Y);
    long long int l_index = (lower - F.begin());
    long long int u_index = (upper - F.begin());
    int l , u;
    if(l_index <= 0)
        l = 0;
    else
        l = C[l_index - 1];

    -- u_index;
    if(u_index < 0)
        u = 0;
    else
        u = C[u_index];

    return (u - l);
}

int GetQueryUtil(int TreeIndex, int L, int R, int X, int Y, Node * Tree)
{
    int left = Tree[TreeIndex].leftLimit;
    int right = Tree[TreeIndex].rightLimit;

    if(left > R  || right < L)
        return 0;

    if(left>= L && right <= R)
    {
        //<<"Hello "<<TreeIndex<<endl;
        return GetNumberOfElements(Tree[TreeIndex].Factors, Tree[TreeIndex].Cumulative, X, Y);
    }

    return (GetQueryUtil(2 * TreeIndex + 1, L ,R, X, Y, Tree)) + (GetQueryUtil(2 * TreeIndex + 2, L, R, X, Y, Tree));
}

void Sieve()
{
    IsPrime[0] = IsPrime[1] = false;
    int S = sqrt(limit) + 1;
    for (int i = 2; i <=S ; ++i)
    {
        if(IsPrime[i])
        {
            for (int j = i * 2; j < limit ; j = j + i)
            {
                IsPrime[j] = false;
            }
        }
    }

    for (int i = 0; i < limit ; ++i)
    {
        if(IsPrime[i])
            Primes.push_back(i);
    }

    return;
}


int main()
{
    IsPrime = new bool[limit];

    for (int i = 0; i < limit ; ++i) {
        IsPrime[i] = true;
    }
    Sieve();

    int N;
    scanf("%d", &N);
    int * V = new int[N];
    for (int i = 0; i < N ; ++i) {
        scanf("%d", &V[i]);
    }

    long long int S  = (long long int)(ceil(log2(N)));
    S = (2 * (long long int)(pow(2, S))) - 1;
    Node * Tree = new Node[S];
    ConstructSegmentTree(Tree, V, N);
    int Q;
    scanf("%d", &Q);
    int L, R, X, Y;
    int ans;
    for (int i = 0; i < Q ; ++i)
    {
        scanf("%d", &L);
        scanf("%d", &R);
        scanf("%d", &X);
        scanf("%d", &Y);
        --L;
        --R;
        ans = GetQueryUtil(0, L ,R, X, Y, Tree);
        printf("%d\n", ans);
    }

    return 0;
}

/*
 4
2 3 4 5
2
1 3 2 3
1 4 2 5

 */