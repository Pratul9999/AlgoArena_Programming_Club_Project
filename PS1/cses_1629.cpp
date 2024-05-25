
#include<bits/stdc++.h>
using namespace std;


// bool sortbysec(const pair<int,int> &a, const pair<int,int> &b)
// {
// 	return (a.second < b.second);
// }

int main()
{
	int n;
    cin>>n;
    vector< pair <int, int> > timings;

	for (int i=0; i<n; i++){
        int x ,y;
        cin >> x;
        cin >> y;
		timings.push_back( make_pair(y,x) );
    }
	// sort(timings.begin(), timings.end(), sortbysec);
    sort(timings.begin(), timings.end());
    int curr_end_time = 0;
    int movies = 0;
    for (int i=0; i<n; i++){
        if (timings[i].second >= curr_end_time){
            movies++;
            curr_end_time = timings[i].first;
        }
    }
    cout<< movies;

	return 0;
}
