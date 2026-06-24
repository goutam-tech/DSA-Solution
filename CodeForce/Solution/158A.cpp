#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, k;
    cin >> n >> k;
    vector<int> a(n);

    for(auto &x : a){
        cin >> x;
    }

    int threshold = a[k - 1];
    int count = 0;

    for(int x : a){
        if((x >= threshold) && (x > 0)) count++;
    }

    cout << count;
    return 0;
}