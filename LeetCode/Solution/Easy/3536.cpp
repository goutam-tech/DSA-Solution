class Solution
{
public:
    int maxProduct(int n)
    {
        int first = -1, second = -1;
        while (n > 0)
        {
            int d = n % 10;
            n /= 10;
            if (d > first)
            {
                second = first;
                first = d;
            }
            else if (d > second)
            {
                second = d;
            }
        }
        return first * second;
    }
};