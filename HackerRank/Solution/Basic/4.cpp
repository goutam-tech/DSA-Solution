/*
 * Complete the 'diagonalDifference' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts 2D_INTEGER_ARRAY arr as parameter.
 */

int diagonalDifference(vector<vector<int>> arr)
{
    int n = arr.size();
    long long primary = 0, secondary = 0;
    for (int i = 0; i < n; i++)
    {
        primary += arr[i][i];
        secondary += arr[i][n - 1 - i];
    }
    return abs(primary - secondary);
}