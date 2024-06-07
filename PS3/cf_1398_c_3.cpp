#include <iostream>
#include <map>
#include <algorithm>
using namespace std;
#define ll long long

int main(){
    int t;
    cin>>t;
    for (int i=1; i<=t; i++){
        int n;
        cin>>n;
        map <ll,ll> b;
        // int b[n+1];
        // b.push_back(0);
        b[0] = 1;
        ll my_sum = 0;
        for (int j=1; j<=n; j++){
            char c;
            cin>>c;
            ll a = (ll)(c-'0');
            my_sum = my_sum + a - 1;
            b[my_sum]++;
        }

        // for (int x=0; x<=n; x++){
        //     cout << b[i];
        // }
        // cout << endl;
        
        // sort(b.begin(), b.end());
        // for (int x=0; x<=n; x++){
        //     cout << b[i];
        // }
        // cout << endl;
        
        ll ans = 0;
        // long long count = 1;
        auto itr = b.begin();
        while (itr != b.end()){
            ll x = itr->second;
            ans += (x*(x-1))/2;
            itr++;
        }
        cout<<ans;
        if (i!= t) cout << "\n";
    }

    return 0;
}