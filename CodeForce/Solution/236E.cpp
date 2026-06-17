#include<bits/stdc++.h>
using namespace std;

struct SAM{
    struct State{
        int len, link;
        map<char, int> next;
        long long cnt;
    };
    vector<State> st;
    int last;

    void init(){
        st.clear();
        st.push_back({0, -1, {}, 0});
        last = 0;
    }

    void extend(char c){
        int cur = st.size();
        st.push_back({st[last].len + 1, -1, {}, 1});
        int p = last;
        while(p != -1 && !st[p].next.count(c)){
            st[p].next[c] = cur;
            p = st[p].link;
        }
        if(p == -1){
            st[cur].link = 0;
        }
        else{
            int q = st[p].next[c];
            if(st[p].len + 1 == st[q].len){
                st[cur].link = q;
            }
            else{
                int clone = st.size();
                st.push_back({st[p].len + 1, st[q].link, st[q].next, 0});
                while(p != -1 && st[p].next.count(c) && st[p].next[c] == q){
                    st[p].next[c] = clone;
                    p = st[p].link;
                }
                st[q].link = st[cur].link = clone;
            }
        }
        last = cur;
    }

    void build(){
        int n = st.size();
        vector<int> order(n);
        iota(order.begin(), order.end(), 0);
        sort(order.begin(), order.end(), [&](int a, int b){
            return st[a].len > st[b].len;
        });
        for(int v : order){
            if(st[v].link != -1){
                st[st[v].link].cnt += st[v].cnt;
            }
        }
    }
} sam;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    cin >> s;
    sam.init();
    for(char c : s){
        sam.extend(c);
    }
    sam.build();

    int n;
    cin >> n;
    while(n--){
        string x;
        cin >> x;
        int m = x.size();

        int cur = 0, len = 0;
        long long ans = 0;
        set<int> visited;
        
        for(int i = 0; i < 2 * m - 1; i++){
            char c = x[i % m];
            while(cur != 0 && !sam.st[cur].next.count(c)){
                cur = sam.st[cur].link;
                len = sam.st[cur].len;
            }
            if(sam.st[cur].next.count(c)){
                cur = sam.st[cur].next[c];
                len++;
            }
            if(len > m){
                while(sam.st[sam.st[cur].link].len >= m){
                    cur = sam.st[cur].link;
                }
                len = m;
            }
            if(len == m && i >= m - 1){
                if(!visited.count(cur)){
                    visited.insert(cur);
                    ans += sam.st[cur].cnt;
                }
            }
        }
        cout << ans << "\n";
    }
}