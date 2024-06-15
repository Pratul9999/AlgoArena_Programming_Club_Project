#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int q;
    cin>>q;
    while(q--){
        int n;
        cin>> n;
        string s;
        cin>>s;
        if((n==2) && (s[0]>=s[1])) cout<<"NO";
        else {
            cout << "YES";
            cout<<"\n"<<2<<"\n"<<s[0]<<" ";
            for(int i=1; i<n; i++){
                cout<<s[i];
            }
        }

        if(q) cout<<"\n";
    }
    return 0;
}