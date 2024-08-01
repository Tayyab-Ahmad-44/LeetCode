# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
class Solution:
    def isSameTree(self, p: Optional[TreeNode], q: Optional[TreeNode]) -> bool:
        val = true
        def dfs(node1, node2):            
            if node1 == None and node2 == NOne:
                return
            if node1 == None or node2 == None:
                val = False
                return

            if node1.val != node2.val:
                val = False
                return
            
            dfs(node1.left, node2.left)
            dfs(node1.right, node2.right)

            return

        dfs(p, q)

        return val