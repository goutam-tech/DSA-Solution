class Solution {
    public List<string> graycode(int n) {
        // code here
        List<string> result = new List<string>();
        int total = 1 << n;
        for(int i = 0; i < total; i++){
            int gray = i ^ (i >> 1);
            result.Add(Convert.ToString(gray, 2).PadLeft(n, '0'));
        }
        
        return result;
    }
}