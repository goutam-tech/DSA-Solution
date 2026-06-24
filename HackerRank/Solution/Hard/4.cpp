#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

long long sequenceGoodness(const vector<int> &seq, int minVal, int rangeSize, vector<int> &fenwick)
{
    int n = seq.size();
    vector<int> touched(n);
    long long good = 0;
    for (int idx = 0; idx < n; idx++)
    {
        int r = seq[idx] - minVal + 1;
        int cnt = 0;
        for (int x = r - 1; x > 0; x -= x & (-x))
            cnt += fenwick[x];
        good += cnt;
        for (int x = r; x <= rangeSize; x += x & (-x))
            fenwick[x]++;
        touched[idx] = r;
    }
    for (int idx = 0; idx < n; idx++)
    {
        int r = touched[idx];
        for (int x = r; x <= rangeSize; x += x & (-x))
            fenwick[x]--;
    }
    return good;
}

void rotateClockwise(vector<vector<int>> &g, int i0, int j0, int k)
{
    vector<vector<int>> temp(k, vector<int>(k));
    for (int r = 0; r < k; r++)
        for (int c = 0; c < k; c++)
            temp[r][c] = g[i0 + r][j0 + c];
    for (int r = 0; r < k; r++)
        for (int c = 0; c < k; c++)
            g[i0 + c][j0 + k - 1 - r] = temp[r][c];
}

long long affectedGoodness(vector<vector<int>> &g, int n, int i0, int j0, int k, int minVal, int rangeSize, vector<int> &fenwick)
{
    long long total = 0;
    for (int r = i0; r < i0 + k; r++)
        total += sequenceGoodness(g[r], minVal, rangeSize, fenwick);
    vector<int> col(n);
    for (int c = j0; c < j0 + k; c++)
    {
        for (int r = 0; r < n; r++)
            col[r] = g[r][c];
        total += sequenceGoodness(col, minVal, rangeSize, fenwick);
    }
    return total;
}

long long applyMove(vector<vector<int>> &g, int n, int i0, int j0, int k, int minVal, int rangeSize, vector<int> &fenwick)
{
    long long before = affectedGoodness(g, n, i0, j0, k, minVal, rangeSize, fenwick);
    rotateClockwise(g, i0, j0, k);
    long long after = affectedGoodness(g, n, i0, j0, k, minVal, rangeSize, fenwick);
    return after - before;
}

bool hillClimbScan(vector<vector<int>> &g, int n, int minVal, int rangeSize, vector<int> &fenwick,
                   vector<array<int, 3>> &moves, long long &running, long long &bestGoodness,
                   vector<array<int, 3>> &bestMoves, int moveBudget,
                   chrono::steady_clock::time_point startTime, double timeLimitSeconds, mt19937 &rng)
{
    vector<array<int, 3>> candidates;
    for (int k = 2; k <= n; k++)
        for (int i0 = 0; i0 + k <= n; i0++)
            for (int j0 = 0; j0 + k <= n; j0++)
                candidates.push_back({i0, j0, k});
    shuffle(candidates.begin(), candidates.end(), rng);
    for (auto &cand : candidates)
    {
        double elapsed = chrono::duration<double>(chrono::steady_clock::now() - startTime).count();
        if (elapsed > timeLimitSeconds || (int)moves.size() >= moveBudget)
            return false;
        int i0 = cand[0], j0 = cand[1], k = cand[2];
        long long before = affectedGoodness(g, n, i0, j0, k, minVal, rangeSize, fenwick);
        rotateClockwise(g, i0, j0, k);
        long long after = affectedGoodness(g, n, i0, j0, k, minVal, rangeSize, fenwick);
        if (after > before)
        {
            running += (after - before);
            moves.push_back({i0, j0, k});
            if (running > bestGoodness)
            {
                bestGoodness = running;
                bestMoves = moves;
            }
            return true;
        }
        else
        {
            for (int r = 0; r < 3; r++)
                rotateClockwise(g, i0, j0, k);
        }
    }
    return false;
}

void solvePuzzle(vector<vector<int>> &puzzle, int n)
{
    if (n <= 1)
    {
        cout << 0 << "\n";
        return;
    }
    int minVal = puzzle[0][0], maxVal = puzzle[0][0];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
        {
            minVal = min(minVal, puzzle[i][j]);
            maxVal = max(maxVal, puzzle[i][j]);
        }
    int rangeSize = maxVal - minVal + 1;
    vector<int> fenwick(rangeSize + 2, 0);
    int moveBudget = n * n;
    auto startTime = chrono::steady_clock::now();
    const double timeLimitSeconds = 9.0;
    mt19937 rng(12345);

    vector<vector<int>> grid = puzzle;
    vector<array<int, 3>> moves;
    long long running = 0;
    {
        vector<int> col(n);
        for (int i = 0; i < n; i++)
            running += sequenceGoodness(grid[i], minVal, rangeSize, fenwick);
        for (int j = 0; j < n; j++)
        {
            for (int i = 0; i < n; i++)
                col[i] = grid[i][j];
            running += sequenceGoodness(col, minVal, rangeSize, fenwick);
        }
    }
    long long bestGoodness = running;
    vector<array<int, 3>> bestMoves = moves;

    while (true)
    {
        double elapsed = chrono::duration<double>(chrono::steady_clock::now() - startTime).count();
        if (elapsed > timeLimitSeconds || (int)moves.size() >= moveBudget)
            break;
        bool improved = hillClimbScan(grid, n, minVal, rangeSize, fenwick, moves, running,
                                      bestGoodness, bestMoves, moveBudget, startTime, timeLimitSeconds, rng);
        if (improved)
            continue;

        elapsed = chrono::duration<double>(chrono::steady_clock::now() - startTime).count();
        if (elapsed > timeLimitSeconds || (int)moves.size() >= moveBudget)
            break;

        int k = 2 + (int)(rng() % (n - 1));
        int i0 = (int)(rng() % (n - k + 1));
        int j0 = (int)(rng() % (n - k + 1));
        long long delta = applyMove(grid, n, i0, j0, k, minVal, rangeSize, fenwick);
        running += delta;
        moves.push_back({i0, j0, k});
        if (running > bestGoodness)
        {
            bestGoodness = running;
            bestMoves = moves;
        }
    }

    cout << bestMoves.size() << "\n";
    for (auto &m : bestMoves)
    {
        cout << (m[0] + 1) << " " << (m[1] + 1) << " " << m[2] << "\n";
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string n_temp;
    getline(cin, n_temp);

    int n = stoi(ltrim(rtrim(n_temp)));

    vector<vector<int>> puzzle(n);

    for (int i = 0; i < n; i++)
    {
        puzzle[i].resize(n);

        string puzzle_row_temp_temp;
        getline(cin, puzzle_row_temp_temp);

        vector<string> puzzle_row_temp = split(rtrim(puzzle_row_temp_temp));

        for (int j = 0; j < n; j++)
        {
            int puzzle_row_item = stoi(puzzle_row_temp[j]);

            puzzle[i][j] = puzzle_row_item;
        }
    }

    solvePuzzle(puzzle, n);

    return 0;
}

string ltrim(const string &str)
{
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace))));

    return s;
}

string rtrim(const string &str)
{
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end());

    return s;
}

vector<string> split(const string &str)
{
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos)
    {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}