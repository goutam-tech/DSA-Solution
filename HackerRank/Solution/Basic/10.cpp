/*
 * Complete the 'staircase' function below.
 *
 * The function accepts INTEGER n as parameter.
 */

void staircase(int n) {
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < n - i; j++)
            cout << " ";
        for (int j = n - i; j < n; j++)
            cout << "#";
        cout << '\n';
    }
}