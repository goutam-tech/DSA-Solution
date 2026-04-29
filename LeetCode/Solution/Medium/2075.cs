public class Solution {
    public string DecodeCiphertext(string encodedText, int rows) {
        if(rows == 1) return encodedText;

        int cols = encodedText.Length / rows;
        var sb = new System.Text.StringBuilder();

        for(int c = 0; c < cols; c++){
            int row = 0, col = c;
            while(row < rows && col < cols){
                sb.Append(encodedText[row * cols + col]);
                row++;
                col++;
            }
        }

        int end = sb.Length - 1;
        while(end >= 0 && sb[end] == ' ') end--;

        return sb.ToString(0, end + 1);
    }
}