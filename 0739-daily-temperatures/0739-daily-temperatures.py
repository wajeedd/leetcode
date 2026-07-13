class Solution:
    def dailyTemperatures(self, temperatures: List[int]) -> List[int]:
        n = len(temperatures)
        ans = [0] * n
        st = []

        for i in range(n):
            while st and temperatures[i] > temperatures[st[-1]]:
                idx = st.pop()
                ans[idx] = i - idx
            st.append(i)

        return ans