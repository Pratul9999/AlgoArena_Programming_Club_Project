#include <iostream>
// #include <queue>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

bool sort_by_a (const pair<int, pair<int,int> > &a, const pair<int, pair<int,int> > &b) {
    return (a.second.first <b.second.first);
}

int main(){
    int n;
    cin>>n;
    // priority_queue < int, vector<int>, greater<int> > rooms;
    vector <pair <int, pair<int,int> > > requests; //(index, (arr_date, dep_date))
    vector <pair <int,int> > bookings; // (index, room_no)
    multimap <int,int> rooms;
    int min_rooms_needed = 0;


    for (int j=0; j<n; j++){
        int a,b;
        cin>>a;
        cin>>b;
        requests.push_back(make_pair(j, make_pair(a,b)));
    }
    sort(requests.begin(), requests.end(), sort_by_a);


    for (int i=0; i<n; i++){
        int a = requests[i].second.first;
        int b = requests[i].second.second;
        int curr_index = requests[i].first;
        if (rooms.empty()){
            min_rooms_needed = 1;
            rooms.insert(pair<int,int> (b,1));
            bookings.push_back(make_pair(curr_index,1));
        } else {
            auto itr = rooms.begin();
            if ((itr->first) < a) {
                int dep_date = itr->first;
                int curr_room = itr->second;
                rooms.erase(itr);
                rooms.insert(pair<int,int> (b, curr_room));
                bookings.push_back(make_pair(curr_index,curr_room));
            } else {
                min_rooms_needed++;
                rooms.insert(pair<int,int> (b,min_rooms_needed));
                bookings.push_back(make_pair(curr_index,min_rooms_needed));
            }
        }
    }
    sort(requests.begin(), requests.end());
    sort(bookings.begin(), bookings.end());
    cout<<min_rooms_needed<<"\n";
    for (int i=0; i<n; i++){
        cout << bookings[i].second;
        if (i!= (n-1)) cout<< " ";
    }
    return 0;
}
