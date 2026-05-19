class Solution {
    public List<List<int>> permuteDist(int[] arr) {
        List<List<int>> res = new List<List<int>>(); 
        Backtrack(arr, 0, res); 
        return res;
    }
    private void Backtrack(int[] arr, int start, List<List<int>> res) { 
        if (start == arr.Length) { 
            res.Add(new List<int>(arr)); 
            return; 
        } 
        for (int i = start; i < arr.Length; i++) { 
            Swap(arr, start, i); 
            Backtrack(arr, start + 1, res); 
            Swap(arr, start, i); 
        } 
    }
    private void Swap(int[] arr, int i,int j){
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
}