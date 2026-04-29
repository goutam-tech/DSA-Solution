public class Solution {
    public IList<int> SolveQueries(int[] nums, int[] queries) {
        int n = nums.Length;

        var indexMap = new Dictionary<int, List<int>>();
        for(int i = 0; i < n; i++){
            if(!indexMap.ContainsKey(nums[i])){
                indexMap[nums[i]] = new List<int>();
            }
            indexMap[nums[i]].Add(i);
        }

        int[] answer = new int[queries.Length];

        for(int q = 0; q < queries.Length; q++){
            int queryIdx = queries[q];
            int val = nums[queryIdx];
            List<int> indices = indexMap[val];

            if(indices.Count == 1){
                answer[q] = -1;
                continue;
            }

            int pos = BinarySearch(indices, queryIdx);
            int minDist = int.MaxValue;

            int[] offsets = {
                pos - 1, pos + 1
            };

            foreach(int offset in offsets){
                int neighborPos = (offset + indices.Count) % indices.Count;
                int neighborIdx = indices[neighborPos];

                if(neighborIdx == queryIdx) continue;

                int linearDist = Math.Abs(neighborIdx - queryIdx);
                int circularDist = Math.Min(linearDist, n - linearDist);
                minDist = Math.Min(minDist, circularDist);
            }

            answer[q] = minDist;
        }

        return answer;
    }

    private int BinarySearch(List<int> list, int target){
        int lo = 0, hi = list.Count - 1;
        while(lo < hi){
            int mid = (lo + hi) / 2;
            if(list[mid] < target) lo = mid + 1;
            else hi = mid; 
        }

        return lo;
    }
}