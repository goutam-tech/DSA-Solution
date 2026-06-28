#include <bits/stdc++.h>
using namespace std;
 
int main() {
    int n;
    cin >> n;
    cin.ignore();
 
    vector<string> path;
 
    while (n--) {
        string line;
        getline(cin, line);
 
        if (line == "pwd") {
            if (path.empty()) {
                cout << "/\n";
            } else {
                for (auto& d : path) cout << "/" << d;
                cout << "/"; 
                cout << "\n";
            }
        } else {
            string param = line.substr(3);
 
            if (param[0] == '/') {
                path.clear();
                param = param.substr(1);
            }
 
            stringstream ss(param);
            string token;
            while (getline(ss, token, '/')) {
                if (token == "..") {
                    if (!path.empty()) path.pop_back();
                } else if (!token.empty()) {
                    path.push_back(token);
                }
            }
        }
    }
    return 0;
}