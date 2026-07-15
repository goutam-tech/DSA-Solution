# include <bits/stdc++.h>
using namespace std;

void removeR(){
    int n;
    string s;
    cin >> n >> s;

    int c = 0;
    for(int i = 0; i < n - 1; i++){
        if(s[i] != s[i + 1]) c++;
    }

    cout << (c == 1 ? 2 : 1) << '\n';
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--)
        removeR();

    return 0;
}