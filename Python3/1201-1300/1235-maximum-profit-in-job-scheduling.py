#1235. Maximum Profit in Job Scheduling (Python3) - 900ms/15.73% 60.1MB/12.50%
class Solution:
    def jobScheduling(self, startTime: List[int], endTime: List[int], profit: List[int]) -> int:
        jobs = sorted(zip(startTime, endTime, profit))
        dp = [0] * jobs[-1][0]
        max_profit, prev = 0, jobs[-1][0]
        while (jobs):
            start, end, pro = jobs.pop()
            for i in range(prev-1,start-1,-1):
                dp[i] = max_profit
            test_profit = pro + (dp[end-1] if end <= len(dp) else 0)
            if test_profit > max_profit:
                max_profit = test_profit
            prev = start
        return max_profit
