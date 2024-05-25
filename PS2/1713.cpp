#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin>>n;
    for (int i=1; i<=n; i++){
        int x;
        cin>>x;
        int j=2, divisors=2;
        for (;j*j<x;j++){
            if (x%j == 0) divisors += 2;
        }
        if (j*j == x) divisors++;
        cout<< divisors;
        if (i!=n) cout<<"\n";
    }
    return 0;
}