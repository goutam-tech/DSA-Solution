class Solution:
    @staticmethod
    def noOfWays(self, m,n,x):
        dp = [0] * (x + 1)
        dp[0] = 1
        
        for i in range(1, n + 1):
            new_dp = [0] * (x + 1)
            for j in range(i, x + 1):
                for face in range(1, min(m,j) + 1):
                    new_dp[j] += dp[j - face]
            dp = new_dp
        
        return dp[x]