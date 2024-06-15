#include <iostream>
#include <vector>
#include <algorithm>
#define ll long long

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n;
    ll k;
    cin>>n;
    cin>>k;
    ll ans = 0;
    vector <ll> a;
    for(ll i=0; i<k; i++){
        ll x;
        cin>>x;
        if(x==0) continue;
        ll len = a.size();
        a.push_back(x);
        ans += (n/x);
        // cout<<"x - "<<x<<endl;
        for(ll j=0; j<len; j++){
            ll y =(a[j]*x*(-1));
            a.push_back(y);
            // cout<<"y -- "<<y<<endl;
            if(y>0){
                // if(y>n) break;
                ans += (n/y);
            } else {
                y *= (-1);
                // if (y>n) break;
                ans -= (n/y);
            }
        }
    }
    cout<<ans;
    return 0;
}