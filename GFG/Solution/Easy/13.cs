public class Solution {
    public void Segregate0and1(int[] arr) {
        int left = 0, right = arr.Length - 1;
        while (left < right) {
            while (left < right && arr[left] == 0) left++;
            while (left < right && arr[right] == 1) right--;
            if (left < right) {
                arr[left] = 0;
                arr[right] = 1;
                left++;
                right--;
            }
        }
    }
}