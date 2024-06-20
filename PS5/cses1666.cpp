#include <iostream>
#include <vector>
#define ll long long

using namespace std;

void establish_network (int x, vector <vector <int> >& graph, vector<int>& connected, vector<int>& network_established){
    if(graph[x].empty()) {
        network_established[x] = 1;
        return;
    } else if (network_established[x] == 1) {
        return;
    } else {
        auto itr = graph[x].begin();
        network_established[x] = 1;
        while (itr != graph[x].end()){
            connected[(*itr)] = 1;
            if (!graph[(*itr)].empty()) establish_network((*itr), graph, connected, network_established);
            itr++;
        }
    }
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
    bool all_until_now_empty = true;
    vector<int> connected(n+1, 0);
    vector<int> network_established(n+1, 0);
    vector < pair<int,int> > new_roads;
    // bool possible = true;
    for(int i=1; i<=n; i++){
        if (connected[i] == 0) {
            if (all_until_now_empty){
                connected[i] = 1;
                if (graph[i].empty()) {
                    if (i < n) new_roads.push_back({i,i+1});
                }
            }
            else {
                new_roads.push_back({i-1,i});
                connected[i] = 1;
            }
        }
        if (!graph[i].empty()){
            all_until_now_empty = false;
            establish_network(i, graph, connected, network_established);
        }
    }

    cout << new_roads.size() << "\n";
    for (int i=0; i< new_roads.size() ; i++){
        cout << new_roads[i].first << " " << new_roads[i].second;
        if (i!= (new_roads.size() - 1)) cout << "\n";
    }

    return 0;
}