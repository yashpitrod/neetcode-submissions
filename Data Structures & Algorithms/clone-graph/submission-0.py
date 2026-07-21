"""
# Definition for a Node.
class Node:
    def __init__(self, val = 0, neighbors = None):
        self.val = val
        self.neighbors = neighbors if neighbors is not None else []
"""

class Solution:
    # Optional in python for node or None value 
    def cloneGraph(self, node: Optional['Node']) -> Optional['Node']:
        if not node:
            return None
        
        # For infinite loop - track of clones 
        notebook = {}

        def dfs(curr_node):
            if curr_node in notebook:
                return notebook[curr_node]

            Clone = Node(curr_node.val)

            notebook[curr_node] = Clone

            for ne in curr_node.neighbors:
                Clone.neighbors.append( dfs(ne) )

            return Clone 

        return dfs(node)