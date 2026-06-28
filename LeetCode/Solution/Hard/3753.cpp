class Solution {
    string digits;
    int N;
    unordered_map<long long, pair<long long,long long>> memo;

    pair<long long,long long> dp(int pos, int lastDig, int prevRel, int waveAcc, bool tight, bool started) {
        if (pos == N)
            return {1, started ? waveAcc : 0};

        long long key = ((long long)pos << 40) | ((long long)lastDig << 32) | ((long long)prevRel << 28) |
                        ((long long)waveAcc << 20) | ((long long)tight << 4) | (long long)started;

        auto it = memo.find(key);
        if (it != memo.end()) return it->second;

        int limit = tight ? (digits[pos] - '0') : 9;
        long long totalCnt = 0, totalWsum = 0;

        for (int d = 0; d <= limit; d++) {
            bool newTight = tight && (d == limit);

            if (!started && d == 0) {
                auto [c, s] = dp(pos+1, 0, 0, 0, newTight, false);
                totalCnt += c;
                totalWsum += s;
            } else {
                int newWave = waveAcc;
                int newRel = 0;

                if (started) {
                    if (d > lastDig)      newRel = 1;
                    else if (d < lastDig) newRel = 2;
                    else                  newRel = 3;

                    if      (prevRel == 1 && newRel == 2) newWave++;
                    else if (prevRel == 2 && newRel == 1) newWave++;
                }

                auto [c, s] = dp(pos+1, d, started ? newRel : 0, newWave, newTight, true);
                totalCnt += c;
                totalWsum += s;
            }
        }

        return memo[key] = {totalCnt, totalWsum};
    }

    long long solve(long long num) {
        if (num <= 0) return 0;
        digits = to_string(num);
        N = digits.size();
        memo.clear();
        return dp(0, 0, 0, 0, true, false).second;
    }

public:
    long long totalWaviness(long long num1, long long num2) {
        return solve(num2) - solve(num1 - 1);
    }
};