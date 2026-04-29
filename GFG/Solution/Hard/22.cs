public class Solution {
    public static int[] nextPalindrome(int[] num) {
        int n = num.Length;
        if (n == 0) return num;

        int[] arr = (int[])num.Clone();
        int mid = n / 2;

        Mirror(arr, n);

        bool mirrored = false;
        for (int i = 0; i < n; i++) {
            if (arr[i] > num[i]) { mirrored = true; break; }
            if (arr[i] < num[i]) { break; }
        }

        if (mirrored) return arr;

        if (n % 2 == 1) {
            if (arr[mid] < 9) {
                arr[mid]++;
                return arr;
            }
            arr[mid] = 0;
        }

        if (IncrementLeft(arr, mid - 1)) {
            Mirror(arr, n);
            return arr;
        }

        return AllNinesResult(n);
    }

    private static bool IncrementLeft(int[] arr, int pos) {
        while (pos >= 0) {
            if (arr[pos] < 9) { arr[pos]++; return true; }
            arr[pos] = 0;
            pos--;
        }
        return false;
    }

    private static void Mirror(int[] arr, int n) {
        for (int i = 0; i < n / 2; i++)
            arr[n - 1 - i] = arr[i];
    }

    private static int[] AllNinesResult(int n) {
        int[] res = new int[n + 1];
        res[0] = 1;
        res[n] = 1;
        return res;
    }
}