#36. Valid Sudoku (Python3) - 169ms/6.05% 14.2MB/70.04%
class Solution:
    def isValidSudoku(self, board: List[List[str]]) -> bool:
        squares = [[set(), set(), set()] for _ in range(0, 3)]
        cols = [set() for _ in range(0, 9)]
        for i, row in enumerate(board):
            rowset = set()
            for j, num in enumerate(row):
                if num != ".":
                    if num in rowset:
                        return False
                    if num in cols[j]:
                        return False
                    if num in squares[i//3][j//3]:
                        return False
                    rowset.add(num)
                    cols[j].add(num)
                    squares[i//3][j//3].add(num)
        return True
