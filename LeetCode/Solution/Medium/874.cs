public class Solution {
    public int RobotSim(int[] commands, int[][] obstacles) {
        var obstacleSet = new HashSet<(int, int)>();
        foreach(var obs in obstacles){
            obstacleSet.Add((obs[0], obs[1]));
        }

        int[] dx = {0, 1, 0, -1};
        int[] dy = {1, 0, -1, 0};
        int dir = 0, x = 0, y = 0, ans = 0;

        foreach(var cmd in commands){
            if(cmd == -2) dir = (dir + 3) % 4;
            else if(cmd == -1) dir = (dir + 1) % 4;
            else{
                for(int i = 0; i < cmd; i++){
                    int nx = x + dx[dir], ny = y + dy[dir];
                    if(!obstacleSet.Contains((nx, ny))) {x = nx; y = ny;}
                    else break;
                }

                ans = Math.Max(ans, x * x + y * y);
            }
        }

        return ans;
    }
}