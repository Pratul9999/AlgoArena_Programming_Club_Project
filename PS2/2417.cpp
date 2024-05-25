#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin>>n;
    vector<int> num;
    int pairs = 0;
    for (int i=0; i<n; i++){
        int x;
        cin>>x;
        for(int j=0; j<i;j++){
            if (__gcd(num[j], x) == 1) pairs++;
        }
        num.push_back(x);
    }
    cout<<pairs;
    return 0;
}