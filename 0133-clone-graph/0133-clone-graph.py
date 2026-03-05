from typing import Optional

class Solution:
    def cloneGraph(self, node: Optional['Node']) -> Optional['Node']:
        if not node:
            return None
        
        visited = {}

        def dfs(n):
            if n in visited:
                return visited[n]
            
            copy = Node(n.val)
            visited[n] = copy
            
            for neighbor in n.neighbors:
                copy.neighbors.append(dfs(neighbor))
            
            return copy
        
        return dfs(node)