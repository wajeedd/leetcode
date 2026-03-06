class Solution:
    def minPartitions(self, n: str) -> int:
        ans = 0
        for c in n:
            if c == '9':
                return 9
            ans = max(ans, int(c))
        return ans