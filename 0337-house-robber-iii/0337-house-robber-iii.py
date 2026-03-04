class Solution:
    def rob(self, root: Optional[TreeNode]) -> int:
        def dfs(node):
            if not node:
                return (0, 0)

            li, le = dfs(node.left)
            ri, re = dfs(node.right)

            include = node.val + le + re
            exclude = max(li, le) + max(ri, re)

            return (include, exclude)

        inc, exc = dfs(root)
        return max(inc, exc)