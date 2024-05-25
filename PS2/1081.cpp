#include <iostream>
#include <set>
#include <algorithm>

using namespace std;

int main(){
    int n;
    cin>>n;
    multiset <int> x;
    int max = 1;
    for (int i=0; i<n; i++){
        int a;
        cin>> a;
        x.insert(a);
    }
    auto itr_slow = x.rend();
    itr_slow ++;
    // auto itr_fast = x.rend();
    // itr_fast++;
    // itr_fast ++;
    auto itr = itr_slow;
    itr ++;
    auto start = x.begin();
    auto el2 = start;
    el2++;
    max = __gcd(*(start), *(el2));
    // cout << *itr_fast << *itr_slow<< *itr;

    while ((*(itr_slow) > max) && (*(itr_slow) > *(el2))) {
        while ((*(itr)> max) && (*(itr) > *(start))) {
            int a = __gcd(*(itr_slow), *(itr));
            max = max > a ? max : a;
            itr++;
        }
        itr_slow ++;
        itr = itr_slow;
        itr++;
    }
    cout << max;
    return 0;
}





// int main(){
//     int n;
//     cin>>n;
//     vector <int> x;
//     int max = 1;
//     for (int i=0; i<n; i++){
//         int a;
//         cin>> a;
//         if (a>max) {
//             x.push_back(a);
//             int l=x.size();
//             for (int j=0; j<l;){
//                 if (x[j]>max) {
//                     int b = __gcd(x[l], x[j]);
//                     max = max>b? max:b;
//                     j++;
//                 } else {
//                     auto itr = x.begin();
//                     itr +=j;
//                     x.erase(itr);
//                 }
//             }
//         }
//     }
//     cout<<max;
//     return 0;
// }

// int main(){
//     int n;
//     cin>>n;
//     vector <int> x;
//     int max = 1;
//     for (int i=0; i<n; i++){
//         int a;
//         cin>> a;
//         x.push_back(a);
//         for (int j=0; j<i;j++){
//             int b = __gcd(x[i], x[j]);
//             max = max>b? max:b;
//         }
//     }
//     cout << max;
//     return 0;
// }