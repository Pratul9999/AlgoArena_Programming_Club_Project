#include <iostream>
#define ull unsigned long long

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int q;
    cin>>q;
    while(q--){
        ull n;
        cin>> n;
        int pow_2 = -1;
        while(n>0){
            n = n>>1;
            pow_2++;
            // cout<<"ttch"<<n<<endl;
        }
        ull ans = 1<<pow_2;
        ans--;
        cout<<ans;
        if(q!=0) cout<<"\n";
    }
    return 0;
}