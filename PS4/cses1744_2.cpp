#include <iostream>
#include <vector>
#include <algorithm>
#define ll long long

using namespace std;
int memo[501][501];
// vector<vector<int>> memo;

int func(int a, int b){
    if(a<b){
        a = a+b;
        b = a-b;
        a = a-b;
    }
    if(memo[a][b] != -1) return memo[a][b];

    int ans = (a-1)*(b-1);
    for(int i=1; i<((a/2)+1); i++){
        int curr = 1 + func(i,b) + func(a-i,b);
        ans = ans>curr ? curr : ans;
    }
    for(int i=1; i<((b/2)+1); i++){
        int curr = 1 + func(a,i) + func(a,b-i);
        ans = ans>curr ? curr : ans;
    }
    memo[a][b] = ans;
    return ans;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int a,b;
    cin>>a;
    cin>>b;
    if(a<b){
        a = a+b;
        b = a-b;
        a = a-b;
    }
    // implies a>b
    for(int i=1; i<=a; i++){
        memo[i][1] = i-1;
    }
    for(int i=2; i<=b; i++){
        for (int j=i+1; j<=a; j++){
            memo[j][i] = -1;
        }
        memo[i][i] = 0;
    }

    if(a!=b) memo[a][b] = func(a,b);
    int steps = memo[a][b];
    cout<<steps;

    // for(int i=1; i<=b; i++){
    //     for (int j=1; j<=a; j++){
    //         cout<< " memo["<<i<<"]["<<j<<"] = "<< memo[j][i];
    //     }
    //     cout<<"\n";
    // }
    return 0;
}
