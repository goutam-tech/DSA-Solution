void matrixRotation(vector<vector<int>> matrix, int r)
{
    int m = matrix.size();
    int n = matrix[0].size();
    int layers = min(m, n) / 2;

    for (int layer = 0; layer < layers; layer++)
    {
        int rowStart = layer, rowEnd = m - 1 - layer;
        int colStart = layer, colEnd = n - 1 - layer;

        vector<int> elements;
        for (int j = colStart; j <= colEnd; j++)
            elements.push_back(matrix[rowStart][j]);
        for (int i = rowStart + 1; i <= rowEnd; i++)
            elements.push_back(matrix[i][colEnd]);
        for (int j = colEnd - 1; j >= colStart; j--)
            elements.push_back(matrix[rowEnd][j]);
        for (int i = rowEnd - 1; i > rowStart; i--)
            elements.push_back(matrix[i][colStart]);

        int len = elements.size();
        int rotation = r % len;

        vector<int> rotated(len);
        for (int i = 0; i < len; i++)
        {
            rotated[i] = elements[(i + rotation) % len];
        }

        int idx = 0;
        for (int j = colStart; j <= colEnd; j++)
            matrix[rowStart][j] = rotated[idx++];
        for (int i = rowStart + 1; i <= rowEnd; i++)
            matrix[i][colEnd] = rotated[idx++];
        for (int j = colEnd - 1; j >= colStart; j--)
            matrix[rowEnd][j] = rotated[idx++];
        for (int i = rowEnd - 1; i > rowStart; i--)
            matrix[i][colStart] = rotated[idx++];
    }

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << matrix[i][j];
            if (j != n - 1)
                cout << " ";
        }
        cout << "\n";
    }
}