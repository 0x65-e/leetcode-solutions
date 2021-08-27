#121. Best Time to Buy and Sell Stock (Python3) - 1004ms/69.44% 25.2MB/11.49%
class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        lowest_price, max_profit = prices[0], 0
        for price in prices[1:]:
            if price < lowest_price:
                lowest_price = price
            else:
                max_profit = max(price - lowest_price, max_profit)
        return max_profit