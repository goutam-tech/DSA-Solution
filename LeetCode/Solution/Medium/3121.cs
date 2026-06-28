public class Solution {
    public int NumberOfSpecialChars(string word) {
        int[] lastLower = new int[26];
        int[] firstUpper = new int[26];

        Array.Fill(lastLower, -1);
        Array.Fill(firstUpper, int.MaxValue);

        for(int i = 0; i < word.Length; i++){
            char c = word[i];
            if(c >= 'a' && c <= 'z'){
                lastLower[c - 'a'] = i;
            }
            else if(firstUpper[c - 'A'] == int.MaxValue){
                firstUpper[c - 'A'] = i;
            }
        }

        int count = 0;
        for(int i = 0; i < 26; i++){
            if(lastLower[i] != -1 && firstUpper[i] != int.MaxValue && lastLower[i] < firstUpper[i]){
                count++;
            }
        }

        return count;
    }
}