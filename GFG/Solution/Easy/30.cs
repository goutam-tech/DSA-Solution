// User function Template for C#
class Solution {
    // Complete this function
    // Function to check whether a number is palindrome or not.
    public int isPallindrome(long N) {
        // Your code here
        string binary = Convert.ToString(N, 2);
        string reversed = new string(binary.Reverse().ToArray());
        return binary == reversed ? 1 : 0;
    }
}