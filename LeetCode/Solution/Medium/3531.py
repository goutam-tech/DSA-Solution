class Solution(object):
    @staticmethod
    def countCoveredBuildings(self, n, buildings):
        buildings = [(x-1, y-1) for x, y in buildings]

    
        row_min, row_max = defaultdict(lambda: n), defaultdict(lambda: -1)
        col_min, col_max = defaultdict(lambda: n), defaultdict(lambda: -1)

        for x, y in buildings:
            row_min[x] = min(row_min[x], y)
            row_max[x] = max(row_max[x], y)
            col_min[y] = min(col_min[y], x)
            col_max[y] = max(col_max[y], x)

        count = 0
        for x, y in buildings:
            if row_min[x] < y < row_max[x] and col_min[y] < x < col_max[y]:
                count += 1

        return count