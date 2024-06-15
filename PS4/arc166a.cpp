#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// bool check(int loc, int n, string& x, string& y){
//     if(loc == n) return true;
//     if (x[loc] == y[loc]) return check(loc+1,n,x,y);
//     if((y[loc] == 'C')&&(x[loc] != 'C')) return false;
//     if((x[loc] == 'B')&&(y[loc] == 'A')) return false;
//     if((y[loc] == 'A')&&(x[loc] == 'C')) return check(loc+1, n, x, y);
//     if((y[loc] == 'B')&&(x[loc] == 'C')) {
//         if (check(loc+1,n,x,y)) return true;
//         else {
//             x[loc] = 'A';
//             bool ans = check(loc,n,x,y);
//             x[loc] = 'C';
//             return ans;
//         }
//     }


    
// }

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int q;
    cin>>q;
    while(q--){
        int n;
        cin>> n;
        string x,y;
        cin>>x;
        cin>>y;
        // bool can_coincide = check(0,n,x,y);
        int ax = 0;
        int ay = 0;
        int cx = 0;
        bool ans = true;
        for(int i=0; i<n; i++){
            if(y[i]=='C'){
                if(x[i] != 'C') {
                    ans = false;
                    break;
                } else if((ax+cx)<ay) {
                    ans = false;
                    break;
                } else if(ax>ay){
                    ans = false;
                    break;
                } else {
                    ax=0;
                    ay=0;
                    cx=0;
                }
            } else{
                if(y[i]=='A') ay++;
                if(x[i]=='A') ax++;
                if(x[i]=='C') cx++;
                if(ay>(ax+cx)) {
                    ans = false;
                    break;
                }
            }
        }
        if((ay>(ax+cx))||(ax>ay)) {
            ans = false;
        }
        if(ans) cout<<"Yes";
        else cout<<"No";
        if(q) cout<<"\n";
    }
    return 0;
}