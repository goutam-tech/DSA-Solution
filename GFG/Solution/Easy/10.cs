class Solution {
<<<<<<< Updated upstream
    public int maxProfit(int[] prices) {
        int minPrice = int.MaxValue;
        int maxProfit = 0;
        
        foreach(int price in prices){
            if(price<minPrice)
              minPrice = price;
            else
              maxProfit = Math.Max(maxProfit,price-minPrice);
        }
        
        return maxProfit;
    }
}

/* 
1. Complexity Analysis
    a. Time Complexity:
        - 𝑂(𝑛), where 𝑛 is the length of prices array.
        - Single pass through the array with constant-time operations.
    b. Space Complexity:
        - 𝑂(1) auxiliary space.
        - Only uses two variables regardless of input size.

2. Edge Cases to Consider
    a. Empty array → returns 0 (no transaction possible).
    b. Single price → returns 0 (cannot buy/sell).
    c. Non-increasing prices → returns 0 (no profit possible).
    d. All prices equal → returns 0.
    e. Decreasing then increasing → correctly finds valley-peak profit.

3. Implementation
    a. Initialize minPrice = INT_MAX, maxProfit = 0.
    b. For each price in prices:
       - If price < minPrice, update minPrice (new buying opportunity).
       - Else, calculate potential profit = price - minPrice.
       - Update maxProfit if current profit is larger.
    c. Return maxProfit after processing all prices.
*/
=======
    public string largestSwap(string s) {
        char[] chars = s.ToCharArray();
        int n = chars.Length;

        for (int i = 0; i < n - 1; i++)
        {
            char maxChar = chars[i];
            for (int j = i + 1; j < n; j++)
                if (chars[j] > maxChar) maxChar = chars[j];

            if (maxChar <= chars[i]) continue;
            for (int j = n - 1; j > i; j--)
            {
                if (chars[j] == maxChar)
                {
                    (chars[i], chars[j]) = (chars[j], chars[i]);
                    return new string(chars);
                }
            }
        }
        return s;
    }
}
>>>>>>> Stashed changes
