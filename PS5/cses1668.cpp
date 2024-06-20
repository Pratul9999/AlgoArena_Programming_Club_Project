#include <iostream>
#include <vector>
#include <set>
#define ll long long

using namespace std;

bool assign_team (int x, vector <vector <int> >& graph, vector<int>& team){
    // cout<<x<<" - "<<team[x]<<endl;
    auto itr = graph[x].begin();
    while (itr != graph[x].end()){
        if(team[(*itr)] != 0){
            if(team[x] == team[(*itr)]) return false;
            // else continue;
        } else {
            team[(*itr)] = 3 - team[x];
            bool possible = assign_team((*itr), graph,team);
            if(!possible) return false;
        }
        itr++;
    }
    return true;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m;
    cin>>n;
    cin>>m;
    vector <vector <int> > graph(n+1);
    for(int i=0; i<m; i++){
        int a,b;
        cin>>a>>b;
        // if (a>b){
        //     a = a+b;
        //     b = a-b;
        //     a = a-b;
        // } // now a<b always
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    vector<int> team(n+1, 0);
    // int i=1;
    // while(graph[i].empty()){
    //     team[i] = 1;
    //     i++;
    // }
    // team[i] =1;

    bool possible = true;
    for(int i=1; i<n; i++){
        if(graph[i].empty()) team[i] = 1;
        else if (team[i] == 0){
            team[i] = 1;
            possible = assign_team(i,graph,team);
        }
    }

    if (possible){
        for(int i=1; i<=n; i++){
            cout << team[i] << " ";
        }
    } else {
        cout << "IMPOSSIBLE";
    }
    return 0;
}