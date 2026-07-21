class Solution:
    def countComponents(self, n: int, edges: List[List[int]]) -> int:
        # Empty parent array
        parent = []
        components = n
        for i in range(n + 1):
            parent.append(i)

        def find(node):
            #agr ultimate parent root khud hai tab 
            if parent[node] == node:
                return node

            # Ultimate parent find krne ke liye
            return find(parent[node])

        for u,v in edges:
            leader_u = find(u)
            leader_v = find(v)

            if leader_u == leader_v:
                pass
            else:
                parent[leader_u] = leader_v
                components = components - 1 

        return components
            
