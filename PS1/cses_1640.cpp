#include <bits/stdc++.h>
using namespace std;

int main(){
    long n,x;
    cin>>n;
    cin>>x;
    vector<pair<int,int> > num;
    for (int i=1; i<=n; i++){
        int y;
        cin>>y;
        num.push_back(make_pair(y,i));
    }
    sort(num.begin(), num.end());
    int front=0, end =n-1;
    bool possible = 0;
    while (front<end){
        if(num[front].first + num[end].first == x){
            cout<< num[front].second <<" "<< num[end].second;
            possible = 1;
            break;
        } else if (num[front].first + num[end].first < x){
            front++;
        } else {
            end--;
        }
    }
    if (!possible){
        cout<<"IMPOSSIBLE";
    }
    return 0;
}