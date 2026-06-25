#include <bits/stdc++.h>
using namespace std;

int n, m;
string grid[17][17];

bool checkSquare(int r, int c)
{
    vector<string> cards;
    for (int i = r; i < r + 3; i++)
        for (int j = c; j < c + 3; j++)
            cards.push_back(grid[i][j]);

    bool sameSuit = true;
    char suit = cards[0][1];
    for (auto &s : cards)
        if (s[1] != suit)
        {
            sameSuit = false;
            break;
        }
    if (sameSuit)
        return true;

    set<char> ranks;
    for (auto &s : cards)
        ranks.insert(s[0]);
    return ranks.size() == 9;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;

    set<string> allCards;

    string ranks = "23456789TJQKA";
    string suits = "CDHS";
    for (char r : ranks)
        for (char s : suits)
            allCards.insert({r, s});
    allCards.insert("J1");
    allCards.insert("J2");

    set<string> inGrid;
    vector<pair<int, int>> jokerPos;
    string jokerName[2] = {"", ""};

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
        {
            cin >> grid[i][j];
            inGrid.insert(grid[i][j]);
            if (grid[i][j] == "J1")
                jokerPos.push_back({i, j}), jokerName[0] = "J1";
            if (grid[i][j] == "J2")
                jokerPos.push_back({i, j}), jokerName[1] = "J2";
        }

    vector<string> avail;
    for (auto &c : allCards)
        if (!inGrid.count(c) && c != "J1" && c != "J2")
            avail.push_back(c);

    int numJokers = (int)jokerPos.size();

    pair<int, int> j1pos = {-1, -1}, j2pos = {-1, -1};
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
        {
            if (grid[i][j] == "J1")
                j1pos = {i, j};
            if (grid[i][j] == "J2")
                j2pos = {i, j};
        }

    vector<pair<int, int>> squares;
    for (int i = 0; i + 2 < n; i++)
        for (int j = 0; j + 2 < m; j++)
            squares.push_back({i, j});

    auto tryConfig = [&](string rep1, string rep2) -> bool
    {
        if (j1pos.first != -1)
            grid[j1pos.first][j1pos.second] = rep1;
        if (j2pos.first != -1)
            grid[j2pos.first][j2pos.second] = rep2;

        for (auto &[r1, c1] : squares)
        {
            if (!checkSquare(r1, c1))
                continue;
            for (auto &[r2, c2] : squares)
            {
                if (r1 == r2 && c1 == c2)
                    continue;
                if (abs(r1 - r2) < 3 && abs(c1 - c2) < 3)
                    continue;
                if (!checkSquare(r2, c2))
                    continue;

                cout << "Solution exists.\n";
                if (numJokers == 0)
                {
                    cout << "There are no jokers.\n";
                }
                else if (numJokers == 1)
                {
                    string jname = (j1pos.first != -1) ? "J1" : "J2";
                    string rname = (j1pos.first != -1) ? rep1 : rep2;
                    cout << "Replace " << jname << " with " << rname << ".\n";
                }
                else
                {
                    cout << "Replace J1 with " << rep1 << " and J2 with " << rep2 << ".\n";
                }
                cout << "Put the first square to (" << r1 + 1 << ", " << c1 + 1 << ").\n";
                cout << "Put the second square to (" << r2 + 1 << ", " << c2 + 1 << ").\n";
                return true;
            }
        }

        if (j1pos.first != -1)
            grid[j1pos.first][j1pos.second] = "J1";
        if (j2pos.first != -1)
            grid[j2pos.first][j2pos.second] = "J2";
        return false;
    };

    if (numJokers == 0)
    {
        if (tryConfig("", ""))
            return 0;
    }
    else if (numJokers == 1)
    {
        for (auto &r : avail)
        {
            if (j1pos.first != -1)
            {
                if (tryConfig(r, ""))
                    return 0;
            }
            else
            {
                if (tryConfig("", r))
                    return 0;
            }
        }
    }
    else
    {
        for (int i = 0; i < (int)avail.size(); i++)
        {
            for (int j = 0; j < (int)avail.size(); j++)
            {
                if (i == j)
                    continue;
                if (tryConfig(avail[i], avail[j]))
                    return 0;
            }
        }
    }

    cout << "No solution.\n";
}