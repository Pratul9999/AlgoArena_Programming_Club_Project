#include <iostream>
#define ll long long
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    ll query[t];
    ll coins[31];
    coins[0] = 0;
    for(int i=1; i<=30; i++){
        ll min_coins = coins[i-1];
        if(i>2) min_coins = min(min_coins, coins[i-3]);
        if(i>5) min_coins = min(min_coins, coins[i-6]);
        if(i>9) min_coins = min(min_coins, coins[i-10]);
        if(i>14) min_coins = min(min_coins, coins[i-15]);
        
        coins[i] = min_coins+1;
    }
    for(int j=0; j<t; j++){
        cin>>query[j];
        if(query[j] <= 30) cout << coins[query[j]];
        else {
            ll ans = (query[j]/15)-1;
            ans += (coins[(query[j]%15) +15]);
            cout<<ans;
        }
        if(j !=(t-1)) cout<<"\n";
    }
    return 0;
}