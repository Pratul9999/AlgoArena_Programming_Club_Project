#include <iostream>
#include <set>
using namespace std;

int main(){
    int n,m;
    cin>>n;
    cin>>m;
    multiset <int> price;
    for (int i=0; i<n; i++){
        int x;
        cin>>x;
        price.insert(x);
    }
    for (int j=1; j<=m; j++){
        int y;
        cin>>y;
        if (price.empty()) {cout << "-1";}
        else {
            auto itr = price.upper_bound(y);
            if ((itr == price.begin())) cout << "-1";
            else {
                itr--;
                cout << *(itr);
                price.erase(itr);
            }
        }
        
        if (j!= m) cout<<"\n";
    }
    return 0;
}
