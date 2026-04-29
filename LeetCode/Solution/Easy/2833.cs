namespace Easy;

public class Solution {
    public int FurthestDistanceFromOrigin(string moves) {
        int L = 0, R = 0, blank = 0;
        foreach (char c in moves) {
            if (c == 'L') L++;
            else if (c == 'R') R++;
            else blank++;
        }
        return Math.Abs(L - R) + blank;
    }
}