#84. Largest Rectangle in Histogram (Python3) - 732ms/98.74% 27.3MB/86.25%
class Solution:
    def largestRectangleArea(self, heights: List[int]) -> int:
        lastindex = dict()
        sortstack = [-1]
        largest_area = 0
        for i, height in enumerate(heights):
            li = i
            while True:
                test = sortstack[-1]
                if test > height:
                    testi = lastindex[test]
                    li = min(li, testi)
                    sortstack.pop()
                    largest_area = max(largest_area, (i-testi)*test)
                elif test < height:
                    sortstack.append(height)
                    lastindex[height] = li
                    break
                else:
                    # Equal, so don't update lastindex
                    break

        length = len(heights)
        sortstack.pop(0) # Remove -1 from front of list
        for h in sortstack:
            largest_area = max(largest_area, (length-lastindex[h])*h)
        return largest_area