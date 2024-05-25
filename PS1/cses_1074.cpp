#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    vector <long> p;
    for (int i=0; i<n; i++){
        long x;
        cin>>x;
        p.push_back(x);
    }
    sort(p.begin(), p.end());
    int loc=0;
    long cost=0;
    int med=(n+1)/2;
    while(loc<med){
        cost += (p[med] - p[loc]);
        cost += (p[n-loc-1] - p[med]);
        loc++;
    }
    cout<<cost;
    return 0;
}