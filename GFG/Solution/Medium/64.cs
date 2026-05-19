class Solution {
    public static string firstNonRepeating(string s) {
        int[] freq = new int[26];
        Queue<char> q = new Queue<char>();
        char[] result = new char[s.Length];
        
        for (int i = 0; i < s.Length; i++)
        {
            char ch = s[i];
            freq[ch - 'a']++;
            q.Enqueue(ch);

            while (q.Count > 0 && freq[q.Peek() - 'a'] > 1)
            {
                q.Dequeue();
            }

            result[i] = q.Count > 0 ? q.Peek() : '#';
        }
        
        return new string(result);
    }
}