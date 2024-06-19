// this proble is just basic knapsack problem in other words

#include <iostream>
#define ll long long

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,x;
    cin>>n;
    cin>>x;
    int dp[x+1];
    int h[n], s[n];
    for(int i=0; i<=x; i++){
        dp[i] = 0;
    }
    for(int i=0; i<n; i++){
        cin>>h[i];
    }
    for(int i=0; i<n; i++){
        cin>>s[i];
    }
    for(int i=0; i<n; i++){
        for(int j=x-h[i]; j>0;j--){
            if (dp[j] != 0) dp[j+h[i]] = (dp[j]+s[i])>dp[j+h[i]] ? (dp[j]+s[i]) : dp[j+h[i]];
        }
        if (h[i] <= x) dp[h[i]] = (s[i])>dp[h[i]] ? (s[i]) : dp[h[i]];
    }
    int max = 0;
    for(int i=1; i<=x; i++){
        max = max>dp[i] ? max : dp[i];
    }
    cout<<max;
    return 0;
}