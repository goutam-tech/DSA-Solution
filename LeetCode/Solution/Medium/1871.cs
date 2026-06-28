public class Solution {
    public bool CanReach(string s, int minJump, int maxJump) {
        int n = s.Length;
        if(s[n - 1] == '1') return false;

        var dp = new bool[n];
        dp[0] = true;
        int prefixSum = 0;

        for(int i = 1; i < n; i++){
            if(i >= minJump) prefixSum += dp[i - minJump] ? 1 : 0;
            if(i > maxJump) prefixSum -= dp[i - maxJump - 1] ? 1 : 0;
            dp[i] = prefixSum > 0 && s[i] == '0';
        }

        return dp[n - 1];
    }
}