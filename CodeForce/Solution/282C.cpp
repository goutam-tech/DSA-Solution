#include <bits/stdc++.h>
using namespace std;

int main(){
    string a, b;
    cin >> a >> b;

    if(a == b){
        cout << "YES\n";
        return 0;
    }

    if(a.size() != b.size()){
        cout << "NO\n";
        return 0;
    }

    
    bool hasOne_a = false, hasOne_b = false;

    for(char c : a){
        if(c == '1') hasOne_a = true;
    }

    for(char c : b){
        if(c == '1') hasOne_b = true;
    }

    if(!hasOne_a || !hasOne_b){
        cout << "NO\n";
    }

    else cout << "YES\n";
}