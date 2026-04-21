namespace Hard;

public class Solution {
    public string GenerateString(string str1, string str2) {
        int n = str1.Length, m = str2.Length;
        int len = n + m - 1;
        char[] word = InitializeWord(len);

        PlaceTrueSegments(str1, str2, word);
        EnsureFalseSegments(str1, str2, word);

        return new string(word);
    }

    private char[] InitializeWord(int len) {
        char[] word = new char[len];
        for (int i = 0; i < len; i++) {
            word[i] = 'a';
        }
        return word;
    }

    private void PlaceTrueSegments(string str1, string str2, char[] word) {
        int n = str1.Length, m = str2.Length;
        for (int i = 0; i < n; i++) {
            if (str1[i] == 'T') {
                for (int j = 0; j < m; j++) {
                    word[i + j] = str2[j];
                }
            }
        }
    }

    private void EnsureFalseSegments(string str1, string str2, char[] word) {
        int n = str1.Length, m = str2.Length;
        for (int i = 0; i < n; i++) {
            if (str1[i] == 'F' && !IsAlreadyDifferent(word, str2, i)) {
                MakeSegmentDifferent(word, str2, i);
            }
        }
    }

    private bool IsAlreadyDifferent(char[] word, string str2, int pos) {
        for (int j = 0; j < str2.Length; j++) {
            if (word[pos + j] != str2[j]) {
                return true;
            }
        }
        return false;
    }

    private void MakeSegmentDifferent(char[] word, string str2, int pos) {
        int m = str2.Length;
        for (int j = m - 1; j >= 0; j--) {
            if (word[pos + j] == str2[j]) {
                word[pos + j] = GetDifferentChar(str2[j]);
                break;
            }
        }
    }

    private char GetDifferentChar(char c) {
        return c == 'a' ? 'b' : 'a';
    }
}
                    char alt = (needed == 'a') ? 'b' : 'a';
                    bool fixable = true;
                    for(int k = 0; k < n; k++){
                        if(str1[k] == 'T' && i + j >= k && i + j < k + m && str2[i + j - k] != alt){
                            fixable = false;
                            break;
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