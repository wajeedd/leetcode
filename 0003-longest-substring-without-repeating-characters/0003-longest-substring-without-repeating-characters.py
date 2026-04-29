class Solution(object):
    def lengthOfLongestSubstring(self, s):
        left = 0
        seen = {}
        max_len = 0

        for right in range(len(s)):
            if s[right] in seen and seen[s[right]] >= left:
                left = seen[s[right]] + 1
            seen[s[right]] = right
            max_len = max(max_len, right - left + 1)

        return max_len