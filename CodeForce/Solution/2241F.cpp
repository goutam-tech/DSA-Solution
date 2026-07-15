# include <bits/stdc++.h>
using namespace std;

void bitOdd(){
    int n;
    string s;
    cin >> n >> s;

    bool allSame = true;
    for(int i = 1; i < n; i++){
        if(s[i] != s[0]) allSame = false;
    }

    if(allSame){
        cout << "Bob\n";
        return;
    }

    bool aliceWins = false;
    
    int ones = 0;
    for(int i = 0; i < n; i++){
        if(s[i] == '0'){
            if(ones % 2 == 1) aliceWins = true;
        }
        else{
            ones++;
        }
    }

    int zeroSuffix = 0;
    for(int i = n - 1; i >= 0; i--){
        if(s[i] == '1'){
            if(zeroSuffix % 2 == 1) aliceWins = true;
        }
        else{
            zeroSuffix++;
        }
    }

    cout << (aliceWins ? "Alice" : "Bob") << '\n';
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while(t--){
        bitOdd();
    }

    return 0;
}