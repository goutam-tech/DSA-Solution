public class Solution {
    public string GetHappyString(int n, int k) {
        int total = 3 * (1 << (n - 1));
        if(k > total) return "";

        char[] result = new char[n];
        char[] chars = {'a', 'b', 'c'};

        k--;

        int perFirst = 1 << (n - 1);
        result[0] = chars[k / perFirst];
        k %= perFirst;

        for(int i = 1; i < n; i++){
            int perChar = 1 << (n - 1 - i);
            int idx = k / perChar;
            k %= perChar;

            int chosen = 0;
            int count = 0;
            for(int j = 0; j < 3; j++){
                if(chars[j] != result[i - 1]){
                    if(count == idx) { chosen = j; break; }
                    count++;
                }
            }
            result[i] = chars[chosen];
        }

        return new string(result);
    }
}