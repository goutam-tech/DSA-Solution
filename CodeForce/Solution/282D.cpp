#include <bits/stdc++.h>
using namespace std;

const int M = 300;
int dp2[M][M];
int dp3[M][M][M];
bool hasLose2_a[M][M];
bool hasLose2_b[M][M];
bool hasLose2_diag[M][M];

void precompute2(){
    for(int a = 0; a < M; a++){
        for(int b = 0; b < M; b++){
            bool win = false;

            if(a>0&&hasLose2_a[a-1][b]) win=true;

            if(!win&&b>0&&hasLose2_b[a][b-1]) win=true;

            if(!win&&a>0&&b>0&&hasLose2_diag[a-1][b-1]) win=true;
            
            dp2[a][b] = win;
            hasLose2_a[a][b] = (a > 0 ? hasLose2_a[a-1][b] : false) || (!win);
            hasLose2_b[a][b] = (b > 0 ? hasLose2_b[a][b-1] : false) || (!win);
            hasLose2_diag[a][b] = (a > 0 && b > 0 ? hasLose2_diag[a-1][b-1] : false) || (!win);
        }
    }
}


void precompute3(){
    static bool hA[M][M][M],hB[M][M][M],hC[M][M][M],hD[M][M][M];

    for(int a = 0; a < M; a++){
        for(int b = 0; b < M; b++){
            for(int c = 0; c < M; c++){
                bool win = false;

                if(!win && a > 0 && hA[a-1][b][c]) win=true;
                if(!win && b > 0 && hB[a][b-1][c]) win=true;
                if(!win && c > 0 && hC[a][b][c-1]) win=true;
                if(!win && a > 0 && b > 0 && c > 0 && hD[a-1][b-1][c-1]) win=true;
                dp3[a][b][c] = win;
                hA[a][b][c] = (a > 0 ? hA[a-1][b][c] : false) || (!win);
                hB[a][b][c] = (b > 0 ? hB[a][b-1][c] : false) || (!win);
                hC[a][b][c] = (c >0 ? hC[a][b][c-1] : false) || (!win);
                hD[a][b][c] = (a > 0 && b > 0 && c > 0 ? hD[a-1][b-1][c-1] : false) || (!win);
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;

    if(n == 1){
        int a;
        cin >> a;
        cout << (a > 0 ? "BitLGM" : "BitAryo") << "\n";
    }
    else if(n == 2){
        precompute2();
        int a, b;
        cin >> a >> b;
        cout << (dp2[a][b] == 1 ? "BitLGM" : "BitAryo") << "\n";
    }
    else{
        precompute3();
        int a, b, c;
        cin >> a >> b >> c;
        cout << (dp3[a][b][c] == 1 ? "BitLGM" : "BitAryo") << "\n";
    }
}