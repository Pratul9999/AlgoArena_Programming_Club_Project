#include <iostream>
#define ll long long
using namespace std;

ll max_score(int start_loc, int end_loc, ll* dp, ll* x, int* is_modified, ll sum, ll n){
    if((*((is_modified+ n*start_loc) + end_loc)) == 1) return *((dp+ n*start_loc) + end_loc);
    ll a = max_score(start_loc+1, end_loc, dp, x, is_modified,(sum-x[start_loc]),n);
    ll b = max_score(start_loc, end_loc-1, dp, x, is_modified,(sum-x[end_loc]),n);
    if (a>b){
        *((dp+ n*start_loc) + end_loc) = sum - b;
    } else {
        *((dp+ n*start_loc) + end_loc) = sum - a;
    }
    *((is_modified+ n*start_loc) + end_loc) = 1;
    return *((dp+ n*start_loc) + end_loc);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n;
    cin>>n;
    ll x[n];
    ll sum = 0;
    for(int i=0; i<n; i++){
        cin>>x[i];
        sum+=x[i];
    }
    ll dp[n][n];
    int is_modified[n][n];
    for(ll i=0; i<n; i++){
        dp[i][i] = x[i];
        is_modified[i][i] = 1;
        for(ll j=i+1; j<n; j++){
            dp[i][j] = 0;
            is_modified[i][j] = 0;
        }
    }
    cout<< max_score(0,n-1,(ll*)dp,(ll*)x,(int*)is_modified,sum,n);
    return 0;
}