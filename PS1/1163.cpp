#include <iostream>
#include <set>
// #include <algorithm>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int x,n;
    cin>>x;
    cin>>n;
    multiset <int> passage_lengths;
    // multiset <int, greater<int> > passage_lengths;
    multiset <int> position_of_lamps;
    position_of_lamps.insert(0);
    position_of_lamps.insert(x);
    passage_lengths.insert(x);

    for(int i=0; i<n; i++){
        int a;
        cin>> a;
        position_of_lamps.insert(a);
        // auto itr = position_of_lamps.upper_bound(a);
        auto itr = position_of_lamps.find(a);
        int dist1 = *(next(itr)) - *(itr);
        int dist2 = *itr - *(prev(itr));
        // auto itr2 = passage_lengths.find(dist1+dist2);
        passage_lengths.insert(dist1);
        passage_lengths.insert(dist2);
        passage_lengths.erase(passage_lengths.find(dist1+dist2));
        // passage_lengths.erase(dist1+dist2);
        // auto itr3 = passage_lengths.end();
        cout<< *(passage_lengths.rbegin());
        if (i != (n-1)) cout<< " ";
    }

    return 0;
}
