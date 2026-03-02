class Solution(object):
    def lengthOfLIS(self, nums):
        dp = []
        
        import bisect
        
        for num in nums:
            i = bisect.bisect_left(dp, num)
            if i == len(dp):
                dp.append(num)
            else:
                dp[i] = num
        
        return len(dp)