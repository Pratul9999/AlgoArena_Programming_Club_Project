#include <iostream>
using namespace std;

int main(){
    int t;
    cin>>t;
    for (int x=0; x<t; x++){
        int n;
        cin>>n;
        int a[n];
        // int max = 0;
        for(int i=0; i<n; i++){
            cin>>a[i];
            // max = max>a[i]? max:a[i];
        }
        // int 
        int streak = 0;
        int max_streak = 0;
        for(int i=0; i<21;i++){
            for (int j=0; j<n; j++){
                if (((a[j]>>i)&1)==0){
                    streak++;
                } else {
                    if (streak != n){
                        max_streak = max_streak>streak? max_streak:streak;
                        streak = 0;
                    }
                }
            }
            streak = 0;
        }
        cout<<max_streak+1;
        if(x!=(t-1)) cout<<"\n";
    }
    return 0;
}