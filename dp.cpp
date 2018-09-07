#include <iostream>
using namespace std;

int fib(int n,int *dp){
    if(n==0||n==1){
        dp[n] = n;
        return n;
    }
    if( dp[n]!=-1){
        return dp[n];
        
    }
    else{
    int f1 = fib(n-1,dp);
    int f2 = fib(n-2,dp);
    dp[n] = f1 + f2;
        return dp[n];
    }
}

int bottomUpFib(int n){
    int dp[100];
    
    dp[0] = 0;
    dp[1] = 1;
    
    for(int i=2;i<=n;i++){
        dp[i] = dp[i-1] + dp[i-2];
    }
    return dp[n];
}

int ways(int n,int k,int *dp){
    if(n==0){
        return 1;
    }
    if(n<0){
        return 0;
    }
    if(dp[n]!=-1){
        return dp[n];
    }
    
    int ans = 0;
    for(int i=1;i<=k;i++){
        ans += ways(n-i,k,dp);
    }
    dp[n] = ans;
    return dp[n];
}

int bottomUpDp(int n,int k){
    int dp[100];
    
    dp[0] = 1;
    for(int i=1;i<=n;i++){
        dp[i] = 0;
        
        for(int j=1;j<=k;j++){
            if(i-j>=0){
            dp[i] += dp[i-j];
            }
        }
        
    }
    return dp[n];
}
int knapsack(int n,int prices[],int wts[],int W){
    
    if(n==0|| W==0){
        return 0;
    }
    if(wts[n-1]>W){
        return knapsack(n-1,prices, wts,W);
    }
    else{
        int lelo = prices[n-1] + knapsack(n-1,prices,wts,W-wts[n-1]);
        int matlo = knapsack(n-1, prices, wts,W);
        return max(lelo,matlo);
    }
    
}

int bottomUpKnapSack(int N,int wts[],int prices[],int W){
    
    int dp[100][100]={0};
    
    for(int n=1;n<=N;n++){
        for(int w=1;w<=W;w++){
            
            dp[n][w] = 0;
            if( wts[n-1] > w){
                ///Exclude
                dp[n][w] = dp[n-1][w];
            }
            else{
                //Include or Exclude
                int lelo = prices[n-1] + dp[n-1][w-wts[n-1]];
                int matlo = dp[n-1][w];
                
                dp[n][w] = max(lelo,matlo);
            }
            
            
        }
    }
    
    return dp[N][W];
    
    
    
}

int main(int argc, const char * argv[]) {
    
    /*
    int dp[100];
    for(int i=0;i<100;i++){
        dp[i] = -1;
    }
    cout<<fib(5,dp)<<endl;
    cout<<bottomUpFib(6)<<endl;
    */
    int wts[] = {9,3,4,6};
    int prices[] = {25,5,20,10};
    
    cout<<knapsack(4, prices,wts,10)<<endl;
    cout<<bottomUpKnapSack(4,wts,prices,10)<<endl;
    
    
    return 0;
}
