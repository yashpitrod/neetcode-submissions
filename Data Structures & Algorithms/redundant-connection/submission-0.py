class Solution:
    def findRedundantConnection(self, edges: List[List[int]]) -> List[int]:
        # Number of Nodes 
        n = len(edges)

        # Empty parent array
        parent = []
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
                return [u,v]

            else:
                parent[leader_u] = leader_v
            
