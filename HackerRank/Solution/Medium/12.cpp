/*
 * Complete the 'almostSorted' function below.
 *
 * The function accepts INTEGER_ARRAY arr as parameter.
 */

void almostSorted(vector<int> arr)
{
    int n = (int)arr.size();
    int l = -1, r = -1;

    for (int i = 0; i + 1 < n; i++)
    {
        if (arr[i] > arr[i + 1])
        {
            l = i;
            break;
        }
    }

    if (l == -1)
    {
        cout << "yes" << endl;
        return;
    }

    for (int i = n - 1; i > 0; i--)
    {
        if (arr[i] < arr[i - 1])
        {
            r = i;
            break;
        }
    }

    swap(arr[l], arr[r]);
    if (is_sorted(arr.begin(), arr.end()))
    {
        cout << "yes" << endl;
        cout << "swap " << l + 1 << " " << r + 1 << endl;
        return;
    }
    swap(arr[l], arr[r]);

    reverse(arr.begin() + l, arr.begin() + r + 1);
    if (is_sorted(arr.begin(), arr.end()))
    {
        cout << "yes" << endl;
        cout << "reverse " << l + 1 << " " << r + 1 << endl;
        return;
    }

    cout << "no" << endl;
}