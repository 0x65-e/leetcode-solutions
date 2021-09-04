#155. Min Stack (Python3) - 48ms/99.26% 18.1MB/81.12%
class MinStack:
    
    def __init__(self):
        self._stack = list()
        self._mins = [float("inf")]
    
    def push(self, val: int) -> None:
        self._stack.append(val)
        if val <= self._mins[-1]:
            self._mins.append(val)
    
    def pop(self) -> None:
        rv = self._stack.pop()
        if rv == self._mins[-1]:
            self._mins.pop()
        return rv
    
    def top(self) -> int:
        return self._stack[-1]
    
    def getMin(self) -> int:
        return self._mins[-1]
