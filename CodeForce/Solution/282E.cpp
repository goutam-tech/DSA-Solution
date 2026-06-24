#include <bits/stdc++.h>
using namespace std;

struct Trie{
    int ch[2];
    Trie(){
        ch[0] = ch[1] = -1;
    }
};

vector<Trie> trie;

void insert(long long val){
    int node = 0;
    for(int i = 39; i >= 0; i--){
        int bit = (val >> i) & 1;
        if(trie[node].ch[bit] == -1){
            trie[node].ch[bit] = trie.size();
            trie.push_back(Trie());
        }
        node = trie[node].ch[bit];
    }
}

long long query(long long val){
    int node = 0;
    long long res = 0;
    for(int i = 39; i >= 0; i--){
        int bit = (val >> i) & 1;
        int want = 1 - bit;
        if(trie[node].ch[want] != -1){
            res |= (1LL << i);
            node = trie[node].ch[want];
        }
        else if(trie[node].ch[bit] != -1){
            node = trie[node].ch[bit];
        }
        else{
            break;
        }
    }
    return res;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    vector<long long> a(n);

    for(int i = 0; i < n; i++){
        cin >> a[i];
    }

    vector<long long> pre(n + 1, 0);
    for(int i = 0; i < n; i++){
        pre[i + 1] = pre[i] ^ a[i];
    }

    vector<long long> suf(n + 1, 0);
    for (int i = n - 1; i >= 0; i--)
    {
        suf[i] = suf[i + 1] ^ a[i];
    }
    
    trie.push_back(Trie());
    for(int i = 0; i <= n; i++){
        insert(pre[i]);
    }

    long long ans = 0;
    for(int i = 0; i <= n; i++){
        ans = max(ans, query(suf[i]));
    }

    cout << ans << "\n";
}