public class Solution {
    public int[] SeparateDigits(int[] nums) {
        var result = new List<int>();
        foreach(int num in nums){
            var digits = new List<int>();
            int n = num;
            while(n > 0){
                digits.Add(n % 10);
                n /= 10;
            }

            digits.Reverse();
            result.AddRange(digits);
        }

        return result.ToArray();
    }
}