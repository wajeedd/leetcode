class Solution(object):
    def canPartition(self, nums):
        total = sum(nums)
        if total % 2 != 0:
            return False
        
        target = total // 2
        dp = set([0])
        
        for num in nums:
            new_dp = set(dp)
            for s in dp:
                if s + num == target:
                    return True
                new_dp.add(s + num)
            dp = new_dp
        
        return target in dp