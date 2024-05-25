#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<int> entry, exit;
    for (int i=0; i<n; i++){
        int x,y;
        cin>>x;
        cin>>y;
        entry.push_back(x);
        exit.push_back(y);
    }
    sort(entry.begin(), entry.end());
    sort(exit.begin(), exit.end());
    int curr_people=0, max_people=0;
    int entry_loc=0, exit_loc=0;
    while(entry_loc<n && exit_loc<n){
        if (entry[entry_loc]<exit[exit_loc]){
            curr_people++;
            entry_loc++;
            max_people = max_people>curr_people?max_people:curr_people;
        } else if (entry[entry_loc] = exit[exit_loc]) {
            entry_loc++;
            exit_loc++;
        } else{
            curr_people--;
            exit_loc++;
        }
    }
    cout<<max_people;
    return 0;
}