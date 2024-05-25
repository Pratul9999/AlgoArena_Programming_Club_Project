#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    vector < pair<int,int> > p;
    for (int i=0; i<n; i++){
        long x;
        cin>>x;
        p.push_back(make_pair(x,i));
    }
    sort(p.begin(), p.end());
    int rounds=1;
    for (int i=0; i<n-1; i++){
        if (p[i].second > p[i+1].second) rounds++;
    }
    cout<<rounds;

    return 0;
}