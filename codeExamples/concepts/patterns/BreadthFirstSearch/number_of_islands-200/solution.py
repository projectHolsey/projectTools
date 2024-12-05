class Solution:

    def numIslands(self, grid: List[List[str]]) -> int:
        """
        to find the islands, you need to mkae sure all vertical & horizontal adjacent items
        have 0's in them

        This problem is a BFS solution

        The way the solution works is to visit each node starting from node 1.
        You need a way to mark if the node has been visited or not.
        If all the visited nodes have no new node to visit (parts of the island) then that's a complete island.
        We continue through the rest of the items in the list of lists to make sure we've visited every node.
        """

        # Settings length and width
        rows, cols = len(grid), len(grid[0])

        islands = 0

        visited = set()

        # From google:
        """
        Python's deque is a low-level and highly optimized double-ended queue that's useful for implementing elegant,  
        efficient, and Pythonic queues and stacks, which are the most common list-like data types in computing.
        """
        queue = deque()

        def bfs(row, column):
            # Appending the row and column as a tuple
            queue.append((row, column))

            while queue:
                # We pop the item at the front of the queue
                pos = queue.popleft()

                # get it's row and column
                r, c = pos[0], pos[1]

                # Check that we're not looking for items beyond our boundaries
                # or that we have already visited said items
                for row_offset, col_offset in [[1, 0], [0, 1], [-1, 0], [0, -1]]:
                    if (r + row_offset < 0 or
                            r + row_offset >= rows or
                            c + col_offset < 0 or
                            c + col_offset >= cols or
                            grid[r + row_offset][c + col_offset] != '1' or
                            (r + row_offset, c + col_offset) in visited):
                        continue

                    # if we're here, we've found a section that is an island, so we should append this to the queue
                    visited.add((r + row_offset, c + col_offset))
                    queue.append((r + row_offset, c + col_offset))

        # Traverse each element of the list passed to us
        for row in range(rows):
            for col in range(cols):
                # Check if the item == 1
                # also check that the tuple has not been visited
                if grid[row][col] == '1' and (row, col) not in visited:
                    # if we're here, we've found a section of 1's that don't have any other 1's on the outer edges
                    islands += 1
                    bfs(row, col)

        return islands