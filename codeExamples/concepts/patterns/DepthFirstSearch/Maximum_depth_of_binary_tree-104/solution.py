# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def maxDepth(self, root: Optional[TreeNode]) -> int:
        # create a inner function to recursively iterated through each node & each side of each node.

        def dfs(root, depth):
            if not root:
                return depth

            # This will recursively choose the max from whichever path we went down.
            return max(dfs(root.left, depth + 1), dfs(root.right, depth + 1))

        return dfs(root, 0)



