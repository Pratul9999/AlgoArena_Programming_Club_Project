#include <bits/stdc++.h>
// #include <iostream>
using namespace std;
int main() {
    long m,n,k;
    cin >> n;
    cin >> m;
    cin >> k;
    long a[n];
    long b[m];
    for (long i = 0; i < n; i++)
    {
        /* code */
        cin >> a[i];
    }
    for (long j = 0; j < m; j++)
    {
        /* code */
        cin >> b[j];
    }
    sort(a,a+n);
    sort(b,b+m);
    
    int a_loc=0, b_loc=0;
    int count = 0;
	while (a_loc<n && b_loc<m){
        if (a[a_loc]-b[b_loc] > k){
            b_loc++;
        } else if (b[b_loc]-a[a_loc] > k)
        {
            a_loc++;
        } else {
            a_loc++;
            b_loc++;
            count++;
        }
    }
    cout<<count;
    return 0;
}