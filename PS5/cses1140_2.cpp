#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#define ll long long
using namespace std;
struct task {
    ll a;
    ll b;
    ll p;
};

bool compare_b (task t1, task t2){
    return (t1.b < t2.b);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n;
    cin>>n;
    vector<struct task> projects;
    for(ll i=0; i<n; i++){
        struct task temp;
        cin>>temp.a>>temp.b>>temp.p;
        projects.push_back(temp);
    }
    sort(projects.begin(), projects.end(), compare_b);
    ll b_max = projects[n-1].b;
    map<ll,ll> money;
    // ll ans = 0;
    money.insert({projects[0].b,projects[0].p});
    
    for(int i=1; i<n; i++){
        auto itr = money.lower_bound(projects[i].a);
        auto itr2 = money.rbegin();
        ll prev_max = 0;
        if (itr != money.begin()) {
            itr--;
            prev_max = itr->second + projects[i].p;
        } else {
            prev_max = projects[i].p;
        }
        prev_max = prev_max > itr2->second ? prev_max : itr2->second;
        if(itr2->first == projects[i].b) itr2->second = prev_max;
        else money.insert({projects[i].b , prev_max});
    }
    auto itr3 = money.rbegin();
    cout<<(itr3->second);
    return 0;
}