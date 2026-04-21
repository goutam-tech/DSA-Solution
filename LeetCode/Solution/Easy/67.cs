namespace Easy;

public class Solution {
    public string AddBinary(string a, string b) {
        StringBuilder c = new();
        int n = a.Length - 1, m = b.Length - 1, carry = 0;

        while(n >= 0 || m >= 0 || carry > 0){
            int sum = carry;

            if(n >= 0){
                sum += a[n] - '0';
                n--;
            }
            if(m >= 0){
                sum += b[m] - '0';
                m--;
            }

            c.Insert(0,sum % 2);
            carry = sum / 2;
        }
        return c.ToString();
    }
}