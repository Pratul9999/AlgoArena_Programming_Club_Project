#include <iostream>
#include <map>
#include <algorithm>
using namespace std;
#define ll long long

int main(){
    ll n,m;
    cin>>n;
    cin>>m;
    ll s[n];
    // bool is_s_optimal[n];
    ll changes = 0;
    multimap<ll,ll> mp;
    for(int i=0; i<n; i++){
        cin>>s[i];
        mp.insert(pair<int,int>(s[i],i));
        // is_s_optimal[i] = false;
    }
    // auto itr = mp.begin();
    // while (itr != mp.end()){
    //     ll pos = itr->second;
    //     // if (!is_s_optimal[pos]){
    //     //     is_s_optimal[pos] = true;

    //     // }

    // }
    while (!mp.empty()){
        auto itr = mp.begin();
        ll pos = itr->second;

        // if(pos == 0){
        //     if((s[1]-s[0])>m){
        //         s[0] = s[1]-m;
        //     } else if((s[0]-s[1])>m){
        //         auto it1 = (mp.find(s[1]));
        //         while (it1->second != (1)){
        //             it1++;
        //         }
        //         mp.erase(it1);
        //         s[1] = s[0]-m;
        //     }
        // }
        // else if(pos==(n-1)){
        //     if((s[n-2]-s[n-1])>m){
        //         s[n-1] = s[n-2]-m;
        //     } else if((s[n-1]-s[n-2])>m){
        //         auto it1 = (mp.find(s[n-2]));
        //         while (it1->second != (n-2)){
        //             it1++;
        //         }
        //         mp.erase(it1);
        //         s[n-2] = s[n-1]-m;
        //     }
        // }

        if(pos != (n-1)){
            if((s[pos+1]-s[pos])>m){
                s[pos] = s[pos+1]-m;
            } else if((s[pos]-s[pos+1])>m){
                auto it1 = (mp.find(s[pos+1]));
                while (it1->second != (1)){
                    it1++;
                }
                mp.erase(it1);
                s[pos+1] = s[pos]-m;
            } else {
                auto it1 = (mp.find(s[pos+1]));
                while (it1->second != (1)){
                    it1++;
                }
            }
        }
        else if(pos != 0){
            if((s[pos-1]-s[pos])>m){
                s[pos] = s[pos-1]-m;
            } else if((s[pos]-s[pos-1])>m){
                auto it1 = (mp.find(s[pos-1]));
                while (it1->second != (pos-1)){
                    it1++;
                }
                mp.erase(it1);
                s[pos-1] = s[pos]-m;
            } else {
                auto it1 = (mp.find(s[pos-1]));
                while (it1->second != (pos-1)){
                    it1++;
                }
            }
        }
        // else {
        //     // int max_surr = s[pos-1]>s[pos+1]?s[pos-1]:s[pos+1];
        //     // if (max_surr-s[pos] > m) {
        //     //     s[pos] = max_surr - m;
        //     // }
        // }
        // if(pos!=0) {
        //     auto it1 = (mp.find(s[pos-1]));
        //     while (it1->second != (pos-1)){
        //         it1++;
        //     }
        //     mp.erase(it1);
        //     if ((itr->first - s[pos-1]) > m){
        //         s[pos-1] = s[pos]-m;
        //     } 
        // }
        // if(pos!=(m-1)) {
        //     mp.erase(mp.find(s[pos+1]));
        //     if ((itr->first - s[pos+1]) > m){
        //         s[pos+1] = s[pos]-m;
        //     }
        // }
        mp.erase(itr);
    }
    for(int i=0; i<n; i++){
        cout<<s[i];
        if(i!=(n-1)) cout<<" ";
    }
    return 0;
}