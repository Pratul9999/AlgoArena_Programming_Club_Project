#include <iostream>
#include <iomanip>
#define ll long long
using namespace std;

int main(){
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    ll n;
    cin>>n;
    long double ways[n+1][n+1];
    long double prob[n+1];
    for(int i=1; i<=n; i++){
        cin>>prob[i];
    }
    ways[1][0] = (1-prob[1]);
    ways[1][1] = prob[1];
    long double ans = 0.0;
    // float ans = 0.0;
    if (n==1) ans = prob[1];
    for(int i=2; i<=n; i++){
        for (int j=0; j<=i; j++){
            if(j==0){
                ways[i][j] = ways[i-1][j]*(1.0-prob[i]);
            } else if(j==i){
                ways[i][j] = ways[i-1][j-1]*(prob[i]);
            } else {
                ways[i][j] = ways[i-1][j]*(1.0-prob[i]) + ways[i-1][j-1]*(prob[i]);
            }

            // cout<<i<<" , "<<j<<" "<<ways[i][j]<<endl;
            if(i==n && (j>=((n+1)/2))) ans += ways[i][j];
        }
    }
    cout<< fixed << setprecision(12) <<ans;
    // cout << 
    // printf("%Lf", ans);
    return 0;
}