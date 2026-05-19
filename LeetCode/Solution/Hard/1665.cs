public class Solution {
    public int MinimumEffort(int[][] tasks) {
        Array.Sort(tasks, (a, b) => (b[1] - b[0]).CompareTo(a[1] - a[0]));

        int minEnergy = 0;
        int current = 0;

        foreach(var task in tasks){
            int actual = task[0], minimum = task[1];
            if(current < minimum){
                minEnergy += minimum - current;
                current = minimum; 
            }
            current -= actual;
        }

        return minEnergy;
    }
}