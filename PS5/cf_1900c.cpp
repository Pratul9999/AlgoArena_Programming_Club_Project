#include <iostream>
#include <vector>
#define ll long long
using namespace std;

ll calc_changes(ll x, vector< pair<ll,ll> >& child, string& s, ll* min_changes){
    if((*(min_changes + x)) != -1) return (*(min_changes + x));
    if (s[x-1] == 'L'){
        // cout << x << " - L"<<endl;
        if (child[x].first == 0) {
            (*(min_changes + x)) = (1+calc_changes(child[x].second,child,s,min_changes));
        }
        else {
            ll a = (calc_changes(child[x].first,child,s,min_changes));
            ll b = (1+calc_changes(child[x].second,child,s,min_changes));
            (*(min_changes + x)) = min(a,b);
        }
    } else if (s[x-1] == 'R'){
        // cout << x << " - R"<< endl;
        if (child[x].second == 0) {
            (*(min_changes + x)) = (1+calc_changes(child[x].first,child,s,min_changes));
        }
        else {
            ll a = (1+calc_changes(child[x].first,child,s,min_changes));
            ll b = (calc_changes(child[x].second,child,s,min_changes));
            (*(min_changes + x)) = min(a,b);
        }
    } else if (s[x-1] == 'U'){
        // cout << x << " - U"<< endl;
        ll a = (1+calc_changes(child[x].first,child,s,min_changes));
        ll b = (1+calc_changes(child[x].second,child,s,min_changes));
        (*(min_changes + x)) = a<b ? b : a;
    }
    // cout << x << " - " << (*(min_changes + x)) << endl;
    return (*(min_changes + x));
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    for(int j=0; j<t; j++){
        ll n;
        cin>>n;
        string s;
        cin>>s;
        ll min_changes[n+1];
        for(int i=0; i<=n; i++) {
            min_changes[i] = -1;
        }
        vector< pair<ll,ll> > child(n+1,{-1,-1});
        for(int i=1; i<=n; i++){
            cin >> child[i].first;
            cin >> child[i].second;
            if(child[i].first==0 && child[i].second==0) min_changes[i] = 0;
        }
        ll ans = calc_changes(1,child,s,min_changes);
        cout<<ans;
        if(j !=(t-1)) cout<<"\n";
    }
    return 0;
}