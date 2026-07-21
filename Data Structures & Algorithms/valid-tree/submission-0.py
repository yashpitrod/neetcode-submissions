class Solution:
    def validTree(self, n: int, edges: List[List[int]]) -> bool:
        if len(edges) != n - 1:
            return False
            
        parent = list(range(n))
        
        def find(node):
            if parent[node] == node:
                return node
            return find(parent[node])
            
        for u, v in edges:
            leader_u = find(u)
            leader_v = find(v)
            
            if leader_u == leader_v:
                return False
            else:
                parent[leader_u] = leader_v
                
        return True