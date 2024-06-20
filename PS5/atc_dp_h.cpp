#include <iostream>
#define ll long long
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll h,w;
    cin>>h>>w;
    ll ways[h][w];
    for(int i=0; i<h; i++){
        for (int j=0; j<w; j++){
            char sq;
            cin>>sq;
            if(sq == '#') ways[i][j] = 0;
            else {
                if(i==0 && j==0) ways[0][0] = 0;
                else if (i==0 && j==1) ways[0][1] = 1;
                else if (i==1 && j==0) ways[1][0] = 1;
                else if (i==0) ways[0][j] = ways[0][j-1];
                else if (j==0) ways[i][0] = ways[i-1][0];
                else ways[i][j] = (ways[i][j-1] + ways[i-1][j])%(1000000007);

                // cout<<" ways["<<i<<"]["<<j<<"] = "<<ways[i][j];
            }
            // cout<<endl;
        }
    }
    cout<<ways[h-1][w-1];
    return 0;
}