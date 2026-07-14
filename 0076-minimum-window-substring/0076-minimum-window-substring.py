class Solution:
    def minWindow(self, s: str, t: str) -> str:
        if not t or not s:
            return ""

        need = {}
        for c in t:
            need[c] = need.get(c, 0) + 1

        have = {}
        formed = 0
        required = len(need)

        l = 0
        min_len = float('inf')
        start = 0

        for r in range(len(s)):
            ch = s[r]
            have[ch] = have.get(ch, 0) + 1

            if ch in need and have[ch] == need[ch]:
                formed += 1

            while formed == required:
                if r - l + 1 < min_len:
                    min_len = r - l + 1
                    start = l

                left_char = s[l]
                have[left_char] -= 1

                if left_char in need and have[left_char] < need[left_char]:
                    formed -= 1

                l += 1

        return "" if min_len == float('inf') else s[start:start + min_len]