#include <iostream>
#include <vector>
#include <deque>
#include <queue>
#include <chrono>
#include <cassert>
#include <tuple>

using namespace std;
typedef vector<vector<int> > Grid;
typedef tuple<int, int, int> Move;

const int INF = 1e9 + 7;
const int LIMIT = 500;

int goodness(const Grid& f) {
    int n = f.size(), cnt = 0;
    for (int y = 0; y < n; ++y)
        for (int xr = 0; xr < n; ++xr)
            for (int xl = 0; xl < xr; ++xl)
                cnt += f[y][xl] < f[y][xr];
    for (int x = 0; x < n; ++x)
        for (int yr = 0; yr < n; ++yr)
            for (int yl = 0; yl < yr; ++yl)
                cnt += f[yl][x] < f[yr][x];
    return cnt;
}

Grid rotate(int y, int x, int k, const Grid& f) {
    Grid g = f;
    for (int dy = 0; dy < k; ++dy)
        for (int dx = 0; dx < k; ++dx)
            g[y + dx][x + k - dy - 1] = f[y + dy][x + dx];
    return g;
}

pair<int, int> findCell(const Grid& f, int value) {
    int n = f.size();
    for (int y = 0; y < n; ++y)
        for (int x = 0; x < n; ++x)
            if (f[y][x] == value) return make_pair(y, x);
    assert(false);
    return make_pair(-1, -1);
}

bool isNextFixed(int y, int x, const vector<vector<bool> >& fixed) {
    return (y == 0 || fixed[y - 1][x]) && (x == 0 || fixed[y][x - 1]);
}

void solveFast(int n, Grid& f, vector<Move>& result) {
    vector<vector<bool> > fixed(n, vector<bool>(n, false));
    int nextValue = 1;

    while ((int)result.size() < (int)(LIMIT * 0.96) && nextValue <= n * n) {
        pair<int, int> p = findCell(f, nextValue);
        int py = p.first, px = p.second;

        if (isNextFixed(py, px, fixed)) {
            fixed[py][px] = true;
            ++nextValue;
            continue;
        }

        vector<vector<int> > dist_(n, vector<int>(n, INF));
        vector<vector<Move> > prevMove(n, vector<Move>(n, Move(0, 0, 0)));
        vector<vector<pair<int, int> > > prevCell(n, vector<pair<int, int> >(n, make_pair(0, 0)));
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int> >, greater<tuple<int, int, int> > > pq;

        dist_[py][px] = 0;
        pq.push(make_tuple(0, py, px));

        bool found = false;
        while (!pq.empty()) {
            tuple<int, int, int> top = pq.top(); pq.pop();
            int z = get<0>(top), y = get<1>(top), x = get<2>(top);

            if (isNextFixed(y, x, fixed)) {
                deque<Move> path;
                int cy = y, cx = x;
                while (cy != py || cx != px) {
                    path.push_front(prevMove[cy][cx]);
                    pair<int, int> pc = prevCell[cy][cx];
                    cy = pc.first; cx = pc.second;
                }
                if (result.size() + path.size() <= (size_t)LIMIT) {
                    for (deque<Move>::iterator it = path.begin(); it != path.end(); ++it) {
                        int ry = get<0>(*it), rx = get<1>(*it), rk = get<2>(*it);
                        f = rotate(ry, rx, rk, f);
                        result.push_back(*it);
                    }
                    found = true;
                }
                break;
            }

            for (int k = 2; y + k - 1 < n && x + k - 1 < n && !fixed[y][x]; ++k) {
                int ny = y, nx = x + k - 1;
                if (dist_[ny][nx] == INF) {
                    dist_[ny][nx] = z + 1;
                    prevMove[ny][nx] = Move(y, x, k);
                    prevCell[ny][nx] = make_pair(y, x);
                    pq.push(make_tuple(z + 1, ny, nx));
                }
            }
            for (int k = 2; y + k - 1 < n && x - k + 1 >= 0 && !fixed[y][x - k + 1]; ++k) {
                int ny = y + k - 1, nx = x;
                if (dist_[ny][nx] == INF) {
                    dist_[ny][nx] = z + 1;
                    prevMove[ny][nx] = Move(y, x - k + 1, k);
                    prevCell[ny][nx] = make_pair(y, x);
                    pq.push(make_tuple(z + 1, ny, nx));
                }
            }
            for (int k = 2; y - k + 1 >= 0 && x + k - 1 < n && !fixed[y - k + 1][x]; ++k) {
                int ny = y - k + 1, nx = x;
                if (dist_[ny][nx] == INF) {
                    dist_[ny][nx] = z + 1;
                    prevMove[ny][nx] = Move(y - k + 1, x, k);
                    prevCell[ny][nx] = make_pair(y, x);
                    pq.push(make_tuple(z + 1, ny, nx));
                }
            }
            for (int k = 2; y - k + 1 >= 0 && x - k + 1 >= 0 && !fixed[y - k + 1][x - k + 1]; ++k) {
                int ny = y, nx = x - k + 1;
                if (dist_[ny][nx] == INF) {
                    dist_[ny][nx] = z + 1;
                    prevMove[ny][nx] = Move(y - k + 1, x - k + 1, k);
                    prevCell[ny][nx] = make_pair(y, x);
                    pq.push(make_tuple(z + 1, ny, nx));
                }
            }
        }
        if (!found) break;
    }
}

void solveSlow(int n, Grid& f, vector<Move>& result) {
    chrono::high_resolution_clock::time_point start = chrono::high_resolution_clock::now();

    while ((int)result.size() < LIMIT) {
        chrono::high_resolution_clock::time_point now = chrono::high_resolution_clock::now();
        long long elapsedMs = chrono::duration_cast<chrono::milliseconds>(now - start).count();
        if (elapsedMs >= 1900) break;

        int bestY = -1, bestX = -1, bestK = -1;
        int base = goodness(f), best = base;

        for (int y = 0; y < n; ++y)
            for (int x = 0; x < n; ++x)
                for (int k = min(n - y, n - x); k >= 2; --k) {
                    int z = goodness(rotate(y, x, k, f));
                    if (z > best) {
                        best = z;
                        bestY = y; bestX = x; bestK = k;
                    }
                }

        if (best == base) break;
        f = rotate(bestY, bestX, bestK, f);
        result.push_back(Move(bestY, bestX, bestK));
    }
}

vector<Move> solve(int n, Grid f) {
    vector<Move> result;
    solveFast(n, f, result);
    solveSlow(n, f, result);
    return result;
}

int main() {
    int n; cin >> n;
    Grid f(n, vector<int>(n));
    for (int y = 0; y < n; ++y)
        for (int x = 0; x < n; ++x)
            cin >> f[y][x];

    int gBefore = goodness(f);
    int gMax = n * n * (n - 1);
    vector<Move> result = solve(n, f);

    cout << result.size() << "\n";
    assert(result.size() <= (size_t)LIMIT);
    for (size_t i = 0; i < result.size(); ++i) {
        int y = get<0>(result[i]), x = get<1>(result[i]), k = get<2>(result[i]);
        cout << y + 1 << ' ' << x + 1 << ' ' << k << "\n";
        assert(0 <= y && y < n && 0 <= x && x < n && k >= 1 && max(y, x) + k <= n);
        f = rotate(y, x, k, f);
    }

    for (int y = 0; y < n; ++y) {
        for (int x = 0; x < n; ++x) cerr << (f[y][x] <= 9 ? " " : "") << f[y][x] << " ";
        cerr << "\n";
    }
    cerr << "size: " << result.size() << "\n";
    int gAfter = goodness(f);
    cerr << "points: " << (gAfter - gBefore) / double(gMax - gBefore) << "\n";
    return 0;
}