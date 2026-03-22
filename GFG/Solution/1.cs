/* 
1. Complexity Analysis
    a. Time Complexity:
        - 𝑂(𝑛), where 𝑛 is the length of the strings.
        - You iterate once through both strings, performing constant-time dictionary operations.
    b. Space Complexity:
        - 𝑂(𝑛) in the worst case.
        - Two dictionaries may store up to 𝑛 unique character mappings.

2. Edge Cases to Consider
    a. Strings of different lengths → immediately return false.

    b. Empty strings → should return true (both are trivially isomorphic).

    c. Strings with repeated characters mapping inconsistently → return false.

    d. Unicode or non-ASCII characters → works fine since char in C# supports Unicode.

3. Implementation
    a. Initialize two dictionaries to store the mappings from s1 to s2 and from s2 to s1.
        - Initialize two dictionaries to store the mappings from s1 to s2 and from s2 to s1.
        - Iterate through the strings and check if the mappings are consistent.
        - If the mappings are not consistent, return false.
        - If the mappings are consistent, return true.
    b. Return true if the strings are isomorphic.
*/

// & Solution
namespace GFG.Solution;

class Solution {
    public bool areIsomorphic(string s1, string s2) {
        if(s1.Length != s2.Length)
            return false;
            
        Dictionary<char,char> s1Tos2 = new Dictionary<char,char>();
        Dictionary<char,char> s2Tos1 = new Dictionary<char,char>();
        
        for(int i = 0; i < s1.Length; i++){
            char c1 = s1[i];
            char c2 = s2[i];
            
            if(s1Tos2.TryGetValue(c1, out var mapped1)){
                if(mapped1 != c2)
                    return false;
            }
            else{
                s1Tos2[c1] = c2;
            }
            
            if(s2Tos1.TryGetValue(c2, out var mapped2)){
                if(mapped2 != c1)
                    return false;
            }
                else{
                    s2Tos1[c2] = c1;
                }
            }
            
            return true;
        }
    }
}