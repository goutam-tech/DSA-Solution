class Solution {
public:
    char processStr(string s, long long k) {
        int n = s.size();
        const long long CAP = 2e15;
        vector<long long> lens(n + 1, 0);
        vector<int> flips(n + 1, 0);

        for (int i = 0; i < n; i++) {
            char c = s[i];
            lens[i + 1] = lens[i];
            flips[i + 1] = flips[i];
            if (c >= 'a' && c <= 'z') lens[i + 1] = min(lens[i] + 1, CAP);
            else if (c == '*') lens[i + 1] = max(lens[i] - 1, 0LL);
            else if (c == '#') lens[i + 1] = min(lens[i] * 2, CAP);
            else if (c == '%') flips[i + 1] ^= 1;
        }

        if (k < 0 || k >= lens[n]) return '.';

        long long pos = k;

        for (int i = n - 1; i >= 0; i--) {
            char c = s[i];
            long long cur = lens[i + 1], prev = lens[i];
            int curFlip = flips[i + 1], prevFlip = flips[i];

            if (c == '%') {
                pos = prev - 1 - pos;
            } else if (c == '#') {
                if (pos >= prev) pos -= prev;
            } else if (c >= 'a' && c <= 'z') {
                if (cur > prev && pos == prev) return c;
            }
        }

        return '.';
    }
};