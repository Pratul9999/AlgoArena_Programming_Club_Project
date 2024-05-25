#include <bits/stdc++.h>
using namespace std;

long long a_pow_b (long long a, long long b){
    if (b==0) return 1;
    if (b==1) return a;
    long long y = a_pow_b(a,b/2);
    // cout << "a_pow_b of "<<a<<" , "<<b/2<<"is : "<<y<<endl;
    // cout << (b&1) << endl;
    if ((b & 1) == 0) {
        return (y*y) % 1000000007;
    }
    else return (((y*y) % 1000000007)*a)%1000000007;
}

int main() {
    int n;
    cin>>n;
    for (int i=1; i<=n; i++){
        long long a,b;
        cin >> a;
        cin >> b;
        long long ans = a_pow_b (a,b);
        cout << ans;
        if (i!=n) cout<<"\n";
    }
    return 0;
}