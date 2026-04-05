namespace LeetCode.Solution.Medium {
    public class Solution {
        public bool CheckStrings(string s1, string s2) {
            int[] even1 = new int[26], odd1 = new int[26];
            int[] even2 = new int[26], odd2 = new int[26];

            for(int i = 0; i < s1.Length; i++){
                if(i % 2 == 0){
                    even1[s1[i] - 'a']++;
                    even2[s2[i] - 'a']++;
                }
                else{
                    odd1[s1[i] - 'a']++;
                    odd2[s2[i] - 'a']++;
                }
            }

            for(int i = 0; i < 26; i++){
                if(even1[i] != even2[i] || odd1[i] != odd2[i]) return false;
            }

            return true;
        }
    }
}