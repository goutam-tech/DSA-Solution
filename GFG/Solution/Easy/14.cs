class Solution {
    public bool canFormPalindrome(string s) {
        // code here
        var odd = new HashSet<char>();

        foreach (char c in s) {
            if (!odd.Add(c))
                odd.Remove(c);
        }

        return odd.Count <= 1;
    }
}