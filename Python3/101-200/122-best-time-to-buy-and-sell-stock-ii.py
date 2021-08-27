#122. Best Time to Buy and Sell Stock II (Python3) - 112ms/5.35% 15.1MB/64.99%
class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        last, profit = prices[0], 0
        for price in prices[1:]:
            if price > last:
                profit += price - last
            last = price
        return profit