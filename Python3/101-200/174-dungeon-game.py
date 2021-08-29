#174. Dungeon Game (Python3) - 72ms/75.97% 15MB/97.91%
class Solution:
    def calculateMinimumHP(self, dungeon: List[List[int]]) -> int:
        rows = len(dungeon)
        cols = len(dungeon[0])
        mem = [[[0]]*cols]*rows
        for i in range(rows-1, -1, -1):
            for j in range(cols-1, -1, -1):
                net_change = dungeon[i][j]
                if (i == rows-1 and j == cols-1):
                    pass
                elif (i == rows-1):
                    net_change += mem[i][j+1]
                elif (j == cols-1):
                    net_change += mem[i+1][j]
                else:
                    net_change += max(mem[i+1][j], mem[i][j+1])
                mem[i][j] = min(0, net_change)
        return 1 - mem[0][0]