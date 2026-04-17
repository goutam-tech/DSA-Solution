public class Solution {
    public string GenerateString(string str1, string str2) {
        int n = str1.Length, m = str2.Length;
        int len = n + m - 1;
        char[] word = new char[len];
        for(int i = 0; i < len; i++) word[i] = 'a';

        for(int i = 0; i < n; i++){
            if(str1[i] == 'T'){
                for(int j = 0; j < m; j++){
                    word[i + j] = str2[j];
                }
            }
        }

        for(int i = 0; i < n; i++){
            if(str1[i] == 'F'){
                bool alreadyDiff = false;
                for(int j = 0; j < m; j++){
                    if(word[i + j] != str2[j]){
                        alreadyDiff = true;
                        break;
                    }
                }
                if(!alreadyDiff){
                    bool changed = false;
                    for(int j = m - 1; j >= 0; j--){
                        char needed = str2[j];
                        char alt = (needed == 'a') ? 'b' : 'a';
                        bool fixable = true;
                        for(int k = 0; k < n; k++){
                            if(str1[k] == 'T' && i + j >= k && i + j < k + m){
                                if(str2[i + j - k] != alt){
                                    fixable = false;
                                    break;
                                }
                            }
                        }
                        if(fixable){
                            word[i + j] = alt;
                            changed = true;
                            break;
                        }
                    }
                    if(!changed) return "";
                }
            }
        }

        for(int i = 0; i < n; i++){
            if(str1[i] == 'T'){
                for(int j = 0; j < m; j++){
                    if(word[i + j] != str2[j]) return "";
                }
            }
            else{
                bool diff = false;
                for(int j = 0; j < m; j++){
                    if(word[i + j] != str2[j]){
                        diff = true;
                        break;
                    }
                }
                if(!diff) return "";
            }
        }

        return new string(word);
    }
}