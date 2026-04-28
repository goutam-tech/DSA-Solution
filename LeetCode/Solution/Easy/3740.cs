namespace Easy;

public class Solution {
    public int MinimumDistance(int[] nums) {
        var map = new Dictionary<int, List<int>>();
        for(int i = 0; i < nums.Length; i++){
            if(!map.ContainsKey(nums[i])) map[nums[i]] = new List<int>();
            map[nums[i]].Add(i);
        }

        int result = int.MaxValue;
        foreach(var kvp in map){
            var indices = kvp.Value;
            if(indices.Count < 3) continue;
            for(int i = 0; i <= indices.Count - 3; i++){
                int dist = 2 * (indices[i + 2] - indices[i]);
                if(dist < result) result = dist;
            }
        }

        return result == int.MaxValue ? -1 : result;
    }
}