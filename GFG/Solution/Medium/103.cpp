class Solution
{
public:
    int getCount(int n)
    {
        // code here
        int oddDivisors = 0;
        for (int i = 1; (long long)i * i <= n; i++)
        {
            if (n % i == 0)
            {
                int j = n / i;
                if (i & 1)
                    oddDivisors++;
                if (j != i && (j & 1))
                    oddDivisors++;
            }
        }
        return oddDivisors - 1;
    }
};