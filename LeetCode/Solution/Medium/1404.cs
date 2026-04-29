using System.Text;
public class Solution {
    public int NumSteps(string s) {
        int steps = 0;
        StringBuilder num = new StringBuilder(s);

        while (num.Length > 1 || num[0] != '1')
        {
            if (num[num.Length - 1] == '0')
            {
                num.Remove(num.Length - 1, 1);
            }
            else
            {
                int i = num.Length - 1;
                while (i >= 0 && num[i] == '1')
                {
                    num[i] = '0';
                    i--;
                }
                if (i < 0)
                    num.Insert(0, '1');
                else
                    num[i] = '1';
            }
            steps++;
        }
        return steps;
    }
}