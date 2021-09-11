#63. Unique Paths II (Python3) - 40ms/82.97% 14.3MB/60.81%
class Solution:
    def uniquePathsWithObstacles(self, obstacleGrid: List[List[int]]) -> int:
        if obstacleGrid[len(obstacleGrid)-1][len(obstacleGrid[0])-1] == 1:
            return 0
        for i, row in enumerate(obstacleGrid):
            for j, num in enumerate(row):
                if num == 1:
                    obstacleGrid[i][j] = -1
                elif i == 0 and j == 0:
                    obstacleGrid[i][j] = 1
                else:
                    total = 0
                    if i > 0:
                        total += obstacleGrid[i-1][j] if obstacleGrid[i-1][j] > 0 else 0
                    if j > 0:
                        total += obstacleGrid[i][j-1] if obstacleGrid[i][j-1] > 0 else 0
                    obstacleGrid[i][j] = total
        return obstacleGrid[len(obstacleGrid)-1][len(obstacleGrid[0])-1]
