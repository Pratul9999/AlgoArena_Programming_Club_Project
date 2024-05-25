#include <bits/stdc++.h>
// #include <iostream>
using namespace std;
int main() {
    long n,x;
    cin >> n;
    cin >> x;
    long p[n];
    for (long i = 0; i < n; i++)
    {
        /* code */
        cin >> p[i];
    }
    sort(p,p+n);
    
    int front=0, back=n-1;
    int count = 0;
	while (front <= back){
        if (p[front] + p[back] <= x){
            count++;
            front++;
            back--;
        } else {
            count++;
            back--;
        }
    }
    cout<<count;
    return 0;
}