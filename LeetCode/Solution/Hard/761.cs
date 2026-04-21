namespace Hard;

public class Solution {
    public string MakeLargestSpecial(string s) {
        var parts = new List<string>();
        int count = 0;
        int start = 0;

        for(int i = 0; i < s.Length; i++){
            count += s[i] == '1' ? 1 : -1;
            if(count == 0){
                string inner = MakeLargestSpecial(s.Substring(start + 1, i - start -1));
                parts.Add("1" + inner + "0");
                start = i + 1;
           }
        }

        parts.Sort((a,b) => string.Compare(b,a, StringComparison.Ordinal));

        return string.Join("", parts);
    }
}