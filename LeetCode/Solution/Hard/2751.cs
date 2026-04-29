namespace Hard;

public class Solution {
    public IList<int> SurvivedRobotsHealths(int[] positions, int[] healths, string directions) {
        int n = positions.Length;
        int[] indices = new int[n];
        for (int i = 0; i < n; i++) indices[i] = i;
        Array.Sort(indices, (a, b) => positions[a] - positions[b]);
        
        Stack<int> stack = new Stack<int>();
        int[] health = (int[])healths.Clone();
        bool[] removed = new bool[n];
        
        foreach (int i in indices) {
            if (directions[i] == 'R') {
                stack.Push(i);
            } else {
                while (stack.Count > 0) {
                    int top = stack.Peek();
                    if (health[top] > health[i]) {
                        health[top]--;
                        removed[i] = true;
                        break;
                    } else if (health[top] < health[i]) {
                        health[i]--;
                        removed[top] = true;
                        stack.Pop();
                    } else {
                        removed[top] = true;
                        removed[i] = true;
                        stack.Pop();
                        break;
                    }
                }
            }
        }
        
        List<int> result = new List<int>();
        for (int i = 0; i < n; i++)
            if (!removed[i]) result.Add(health[i]);
        
        return result;
    }
}