public class Solution {
    public int LongestAlternating(int[] nums) {
        int n = nums.Length;
        if (n == 1) return 1;

        int[] fwd = new int[n];
        int[] bwd = new int[n];

        fwd[n - 1] = 1;
        for (int i = n - 2; i >= 0; i--) {
            int cur = int.Sign(nums[i + 1] - nums[i]);
            if (cur == 0) { fwd[i] = 1; continue; }
            if (fwd[i + 1] == 1) {
                fwd[i] = 2;
            } else {
                int nextCur = int.Sign(nums[i + 2] - nums[i + 1]);
                fwd[i] = (cur == -nextCur) ? fwd[i + 1] + 1 : 2;
            }
        }

        bwd[0] = 1;
        for (int i = 1; i < n; i++) {
            int cur = int.Sign(nums[i] - nums[i - 1]);
            if (cur == 0) { bwd[i] = 1; continue; }
            if (bwd[i - 1] == 1) {
                bwd[i] = 2;
            } else {
                int prevCur = int.Sign(nums[i - 1] - nums[i - 2]);
                bwd[i] = (cur == -prevCur) ? bwd[i - 1] + 1 : 2;
            }
        }

        int result = 0;

        for (int i = 0; i < n; i++)
            result = Math.Max(result, Math.Max(fwd[i], bwd[i]));

        for (int i = 0; i < n; i++) {
            if (i > 0 && i < n - 1) {
                int bridge = int.Sign(nums[i + 1] - nums[i - 1]);
                if (bridge != 0) {
                    bool bwdOk = true;
                    if (bwd[i - 1] > 1) {
                        int bwdLastSign = int.Sign(nums[i - 1] - nums[i - 2]);
                        bwdOk = (bridge == -bwdLastSign);
                    }

                    bool fwdOk = true;
                    if (fwd[i + 1] > 1) {
                        int fwdFirstSign = int.Sign(nums[i + 2] - nums[i + 1]);
                        fwdOk = (bridge == -fwdFirstSign);
                    }

                    if (bwdOk && fwdOk)
                        result = Math.Max(result, bwd[i - 1] + fwd[i + 1]);
                    else if (bwdOk)
                        result = Math.Max(result, bwd[i - 1] + 1);
                    else if (fwdOk)
                        result = Math.Max(result, 1 + fwd[i + 1]);
                } else {
                    result = Math.Max(result, Math.Max(bwd[i - 1], fwd[i + 1]));
                }
            }
            if (i == 0) result = Math.Max(result, fwd[1]);
            if (i == n - 1) result = Math.Max(result, bwd[n - 2]);
        }

        return result;
    }
}