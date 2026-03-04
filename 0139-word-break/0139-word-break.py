class Solution:
    def wordBreak(self, s: str, wordDict: list[str]) -> bool:
        wordSet = set(wordDict)
        n = len(s)

        dp = [False] * (n + 1)
        dp[0] = True

        for i in range(1, n + 1):
            for j in range(0, i):
                left = dp[j]
                right = s[j:i] in wordSet
                if left and right:
                    dp[i] = True
                    break

        return dp[n]