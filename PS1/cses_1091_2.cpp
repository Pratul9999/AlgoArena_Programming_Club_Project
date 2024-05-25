#include <bits/stdc++.h>

using namespace std;

bool sortbyprice (const pair<int, pair<int,int> > &a, const pair<int, pair<int,int> > &b) {
    return (a.second.first < b.second.first);
}

int main(){
    vector<int> tickets;
    int n,m;
    cin >> n>>m;
    for (int i=0; i<n; i++){
        int x;
        cin>>x;
        tickets.push_back(x);
    }
    vector <pair<int, pair<int,int> > > bids;
    for(int j=0; j<m; j++){
        int y;
        cin>>y;
        bids.push_back(make_pair(j,make_pair(y,-1)));
    }

    sort(tickets.begin(), tickets.end());
    sort(bids.begin(), bids.end(), sortbyprice);

    int tic_loc = n-1;
    int bid_loc = m-1;

    while (tic_loc>=0 && bid_loc>=0){
        if(bids[bid_loc].second.first >= tickets[tic_loc]){
            bids[bid_loc].second.second = tickets[tic_loc];
            bid_loc--;
            tic_loc--;
        }
        else {
            tic_loc--;
        }
    }
    sort(bids.begin(), bids.end());
    for(int k=0; k<m; k++){
        cout<<bids[k].first <<" "<< bids[k].second.first <<" "<< bids[k].second.second<< endl;
        // cout<<bids[k].second.second<< "\n";
    }
    return 0;
}