/*
 * Complete the 'climbingLeaderboard' function below.
 *
 * The function is expected to return an INTEGER_ARRAY.
 * The function accepts following parameters:
 *  1. INTEGER_ARRAY ranked
 *  2. INTEGER_ARRAY player
 */

vector<int> climbingLeaderboard(vector<int> ranked, vector<int> player)
{
    vector<int> unique;
    for (int i = 0; i < (int)ranked.size(); i++)
    {
        if (unique.empty() || unique.back() != ranked[i])
        {
            unique.push_back(ranked[i]);
        }
    }

    vector<int> result(player.size());
    int i = unique.size() - 1;
    for (int j = 0; j < (int)player.size(); j++)
    {
        while (i >= 0 && unique[i] <= player[j])
            i--;
        result[j] = i + 2;
    }
    return result;
}