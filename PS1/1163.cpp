#include<bits/stdc++.h>
using namespace std;

int main(){
    set <int> lamps;
    int x,n;
    cin>>x;
    cin>>n;
    lamps.insert(0);
    lamps.insert(x);
    auto pos1 = lamps.begin();
    // cout<< *pos1;
    // pos1 ++;
    // cout<< *pos1;

    int y;
    cin>> y;
    lamps.insert(y);
    auto pos2 = lamps.find(y);
    int dist1 = *(++pos1) - *(--pos1);
    int dist2 = *(++pos2) - *(--pos2);
    if (dist1<dist2){
        int temp = dist1;
        dist1 = dist2;
        dist2 = temp;
        auto temp_ptr = pos1;
        pos1 = pos2;
        pos2 = temp_ptr;
    }
    cout<<dist1;
    if (n==1) return 0;

    for (int i=1; i<n; i++){
        int y;
        cin>> y;
        lamps.insert(y);
        auto pos_new = lamps.find(y);
        auto pos_prev = pos_new-;
        if((pos_prev) == (pos1)){
            int dist_a = *(pos_new) - *(pos_prev);
            int dist_b = *(++pos_new) - *(--pos_new);
            if (dist_a>dist_b){
                if (dist_b>dist2){
                    pos2 = pos_new;
                    dist1 = dist_a;
                    dist2 = dist_b;
                } else if (dist2>dist_a)
            }
        }
    }
    return 0;
}