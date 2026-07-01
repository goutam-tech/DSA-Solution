#include <bits/stdc++.h>
using namespace std;

#define N 100005

char str[2*N];
int H = 0, Bucket[2*N], nBucket[2*N], index1[2*N];

struct Suffix {
    int idx;
    bool operator<(const Suffix suff) const {
        if (H == 0)
            return str[idx] < str[suff.idx];
        else if (Bucket[idx] == Bucket[suff.idx])
            return Bucket[idx+H] < Bucket[suff.idx+H];
        else
            return Bucket[idx] < Bucket[suff.idx];
    }
    bool operator==(const Suffix suff) const {
        return !(*this < suff) && !(suff < *this);
    }
} Pos[2*N];

int UpdateBucket(int l) {
    int start = 0, c = 0, id = 0;
    for (int i = 0; i < l; i++) {
        if (i != 0 && !(Pos[i] == Pos[i-1])) {
            start = i;
            id++;
        }
        if (i != start) c = 1;
        nBucket[Pos[i].idx] = id;
    }
    memcpy(Bucket, nBucket, sizeof(Bucket));
    return c;
}

void suffixSort(int l) {
    int c;
    H = 0;
    for (int i = 0; i < l; i++) Pos[i].idx = i;
    sort(Pos, Pos+l);
    c = UpdateBucket(l);
    for (H = 1; c; H = H*2) {
        sort(Pos, Pos+l);
        c = UpdateBucket(l);
    }
}

void solve() {
    scanf("%s", str);
    int len1 = strlen(str);
    str[len1] = 'z';
    scanf("%s", str+len1+1);
    int len2 = strlen(str+len1+1);
    str[len1+len2+1] = 'z';
    str[len1+len2+2] = '$';
    str[len1+len2+3] = '\0';
    len2++;
    int l = len1 + len2;
    suffixSort(len1+len2+3);
    for (int i = 0; i <= l+1; i++) {
        index1[Pos[i].idx] = i;
    }
    int i = 0, j = len1+1;
    while (i < len1 && j < l) {
        if (index1[i] < index1[j]) {
            printf("%c", str[i]);
            i++;
        } else {
            printf("%c", str[j]);
            j++;
        }
    }
    while (i < len1) { printf("%c", str[i]); i++; }
    while (j < l)    { printf("%c", str[j]); j++; }
    printf("\n");
}

int main() {
    int test;
    scanf("%d", &test);
    while (test--) solve();
    return 0;
}