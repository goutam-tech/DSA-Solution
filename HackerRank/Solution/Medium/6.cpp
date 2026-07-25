/*
 * Complete the 'steadyGene' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts STRING gene as parameter.
 */

int steadyGene(string gene)
{
    int n = gene.length();
    int target = n / 4;
    int count[128] = {0};

    for (char c : gene)
    {
        count[(int)c]++;
    }

    if (count['A'] == target && count['C'] == target && count['G'] == target && count['T'] == target)
    {
        return 0;
    }

    int minLen = n;
    int left = 0;

    for (int right = 0; right < n; right++)
    {
        count[(int)gene[right]]--;

        while (count['A'] <= target && count['C'] <= target && count['G'] <= target && count['T'] <= target)
        {
            minLen = min(minLen, right - left + 1);
            count[(int)gene[left]]++;
            left++;
        }
    }

    return minLen;
}