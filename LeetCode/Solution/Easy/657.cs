namespace Easy;

public class Solution {
    public bool JudgeCircle(string moves) {
        int x = 0, y = 0;
        foreach(char move in moves){
            if(move == 'R') x++;
            else if(move == 'L') x--;
            else if(move == 'U') y++;
            else if(move == 'D') y--;
        }

        return x == 0 && y == 0;
    }
}