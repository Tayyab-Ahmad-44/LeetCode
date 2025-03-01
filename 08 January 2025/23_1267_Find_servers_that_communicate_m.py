from typing import List

def countServers(grid: List[List[int]]) -> int:
    connectedServerIndexes = set()
    
    m, n = len(grid), len(grid[0])
    
    for i in range(m):
        serverInRow = False
        temp = (-1, -1)
        for j in range(n):
            if grid[i][j] == 1: 
                if not serverInRow:
                    temp = (i, j)
                    serverInRow = True
                else:
                    connectedServerIndexes.add((i, j))
                    connectedServerIndexes.add(temp)

    for i in range(n):
        serverInCol = False
        temp = (-1, -1)
        for j in range(m):
            if grid[j][i] == 1:
                if not serverInCol:
                    temp = (j, i)
                    serverInCol = True
                else:
                    connectedServerIndexes.add((j, i))
                    connectedServerIndexes.add(temp)
                    
    print(connectedServerIndexes)

    return len(connectedServerIndexes)

grid = [[1,0],[1,1]]
# grid = [[1,1,0,0],[0,0,1,0],[0,0,1,0],[0,0,0,1]]

print(countServers(grid))


"""
1267. Count Servers that Communicate
Medium

You are given a map of a server center, represented as a m * n integer matrix grid, where 1 means that on that cell there is a server and 0 means that it is no server. Two servers are said to communicate if they are on the same row or on the same column.

Return the number of servers that communicate with any other server.

Example 1:
Input: grid = [[1,0],[0,1]]
Output: 0
Explanation: No servers can communicate with others.

Example 2:
Input: grid = [[1,0],[1,1]]
Output: 3
Explanation: All three servers can communicate with at least one other server.

Example 3:
Input: grid = [[1,1,0,0],[0,0,1,0],[0,0,1,0],[0,0,0,1]]
Output: 4
Explanation: The two servers in the first row can communicate with each other. The two servers in the third column can communicate with each other. The server at right bottom corner can't communicate with any other server.

Constraints:

m == grid.length
n == grid[i].length
1 <= m <= 250
1 <= n <= 250
grid[i][j] == 0 or 1
"""