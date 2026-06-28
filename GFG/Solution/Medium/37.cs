class Solution {
    public List<string> generateIp(string s) {
        List<string> result = new List<string>();
        
        if (s.Length < 4 || s.Length > 12)
            return result;
        
        Backtrack(s, 0, new List<string>(), result);
        return result;
    }
    
    private void Backtrack(string s, int index, List<string> parts, List<string> result) {
        if (parts.Count == 4 && index == s.Length) {
            result.Add(string.Join(".", parts));
            return;
        }
        
        if (parts.Count == 4 || index == s.Length)
            return;
        
        for (int len = 1; len <= 3; len++) {
            if (index + len > s.Length)
                break;
            
            string segment = s.Substring(index, len);
            
            if (segment.Length > 1 && segment[0] == '0')
                break;
            
            if (int.Parse(segment) > 255)
                break;
            
            parts.Add(segment);
            Backtrack(s, index + len, parts, result);
            parts.RemoveAt(parts.Count - 1);
        }
    }
}