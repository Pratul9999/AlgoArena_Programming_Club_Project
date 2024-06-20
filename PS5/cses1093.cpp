#include <iostream>
#define ll long long
using namespace std;

int score(int n, int x){
    if (x==0) return 1;
    if (n==0 && x>0) return 0;
    if (x > (((n)*(n+1))/2)) return 0;
    if (x == (((n)*(n+1))/2)) return 1;
    int ans = 0;
    for (int i=1; i<=n; i++){
        if (x < i) break;
        if ((x-i) <=  (((i)*(i+1))/2)) ans += score(i-1,x-i);
    }
    return ans;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n;
    cin>>n;
    int x = ((n)*(n+1))/2;
    if(x&1) cout << 0;
    else {
        x = x/2;
        cout << (score (n,x))/2;
    }
    return 0;
}