/*
 * Complete the 'birthdayCakeCandles' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts INTEGER_ARRAY candles as parameter.
 */

int birthdayCakeCandles(vector<int> candles)
{
    map<int, int> mcandles;
    int max = 0;
    for (int i = 0; i < candles.size(); i++)
    {
        int c = candles[i];
        if (mcandles.find(c) != mcandles.end())
            mcandles[c] += 1;
        else
        {
            mcandles.insert({c, 1});
        }

        if (max < c)
            max = c;
    }
    return mcandles[max];
}