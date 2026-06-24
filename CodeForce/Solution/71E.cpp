# include <bits/stdc++.h>
using namespace std;

map<string,int> toNum = {
    {"H",1},{"He",2},{"Li",3},{"Be",4},{"B",5},{"C",6},{"N",7},{"O",8},{"F",9},{"Ne",10},
    {"Na",11},{"Mg",12},{"Al",13},{"Si",14},{"P",15},{"S",16},{"Cl",17},{"Ar",18},{"K",19},{"Ca",20},
    {"Sc",21},{"Ti",22},{"V",23},{"Cr",24},{"Mn",25},{"Fe",26},{"Co",27},{"Ni",28},{"Cu",29},{"Zn",30},
    {"Ga",31},{"Ge",32},{"As",33},{"Se",34},{"Br",35},{"Kr",36},{"Rb",37},{"Sr",38},{"Y",39},{"Zr",40},
    {"Nb",41},{"Mo",42},{"Tc",43},{"Ru",44},{"Rh",45},{"Pd",46},{"Ag",47},{"Cd",48},{"In",49},{"Sn",50},
    {"Sb",51},{"Te",52},{"I",53},{"Xe",54},{"Cs",55},{"Ba",56},{"La",57},{"Ce",58},{"Pr",59},{"Nd",60},
    {"Pm",61},{"Sm",62},{"Eu",63},{"Gd",64},{"Tb",65},{"Dy",66},{"Ho",67},{"Er",68},{"Tm",69},{"Yb",70},
    {"Lu",71},{"Hf",72},{"Ta",73},{"W",74},{"Re",75},{"Os",76},{"Ir",77},{"Pt",78},{"Au",79},{"Hg",80},
    {"Tl",81},{"Pb",82},{"Bi",83},{"Po",84},{"At",85},{"Rn",86},{"Fr",87},{"Ra",88},{"Ac",89},{"Th",90},
    {"Pa",91},{"U",92},{"Np",93},{"Pu",94},{"Am",95},{"Cm",96},{"Bk",97},{"Cf",98},{"Es",99},{"Fm",100}
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;

    vector<string> asym(n), bsym(k);
    vector<int> a(n), b(k);
    for(int i = 0; i < n; i++){ cin >> asym[i]; a[i] = toNum[asym[i]]; }
    for(int i = 0; i < k; i++){ cin >> bsym[i]; b[i] = toNum[bsym[i]]; }

    vector<int> msum(1<<n, 0);
    for(int mask = 1; mask < (1<<n); mask++){
        int bit = __builtin_ctz(mask);
        msum[mask] = msum[mask & (mask-1)] + a[bit];
    }

    vector<int> dp(1<<n, -1);
    vector<int> from(1<<n, -1);
    dp[0] = 0;

    for(int mask = 0; mask < (1<<n); mask++){
        if(dp[mask] < 0) continue;
        int j = dp[mask];
        if(j == k) continue;
        int target = b[j];
        int rem = ((1<<n)-1) ^ mask;
        for(int sub = rem; sub > 0; sub = (sub-1) & rem){
            if(msum[sub] == target && dp[mask|sub] < 0){
                dp[mask|sub] = j+1;
                from[mask|sub] = sub;
            }
        }
    }

    int full = (1<<n)-1;
    if(dp[full] != k){
        cout << "NO\n";
        return 0;
    }

    vector<int> groups(k);
    int cur = full;
    for(int j = k-1; j >= 0; j--){
        groups[j] = from[cur];
        cur ^= from[cur];
    }

    cout << "YES\n";
    for(int j = 0; j < k; j++){
        bool first = true;
        for(int i = 0; i < n; i++){
            if(groups[j] >> i & 1){
                if(!first) cout << "+";
                cout << asym[i];
                first = false;
            }
        }
        cout << "->" << bsym[j] << "\n";
    }
}