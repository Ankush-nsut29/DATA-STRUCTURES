# --- Graph Node States (Color Coding) ---
# WHITE: Node has not been visited yet.
# GREY:  Node has been discovered (added to queue/recursion stack) but its neighbors aren't fully explored.
# BLACK: Node and all of its neighbors have been fully explored.
WHITE = 0
GREY = 1
BLACK = 2

n = 4
# Adjacency matrix representing the edges between the 'n' nodes in the graph
matrix = [
    [0, 1, 1, 0], 
    [0, 0, 1, 0], 
    [1, 0, 0, 1], 
    [0, 0, 0, 1]
]

# --- Breadth-First Search (BFS) ---
# Explores the graph level by level, starting from a given node.
def bfs(start_node):
    # Initialize all nodes as unvisited (WHITE)
    color = [WHITE] * n
    queue = []
    
    # Mark the start node as discovered (GREY) and enqueue it
    color[start_node] = GREY
    queue.append(start_node)
    
    while queue:
        # Dequeue the front node and process/print it
        u = queue.pop(0)
        print(u, end=' ')
        
        # Check all possible neighbors of node 'u'
        for v in range(n):
            # If there is a directed edge from 'u' to 'v', and 'v' is unvisited
            if matrix[u][v] == 1 and color[v] == WHITE:
                # Mark 'v' as discovered and add it to the queue
                color[v] = GREY
                queue.append(v)
        # Once all neighbors of 'u' are added to the queue, mark 'u' as fully explored (BLACK)
        color[u] = BLACK
    print()

# --- Depth-First Search (DFS) ---
# Explores as deep as possible along each branch before backtracking.
def dfs():
    # Initialize all nodes as unvisited (WHITE)
    color = [WHITE] * n
    
    # Recursive helper function to perform the deep traversal
    def dfs_visit(u):
        # Mark the current node as discovered (GREY) and process it
        color[u] = GREY
        print(u, end=' ')
        
        # Check all possible neighbors of node 'u'
        for v in range(n):
            # If there is an edge and the neighbor is unvisited, recursively visit it
            if matrix[u][v] == 1 and color[v] == WHITE:
                dfs_visit(v)
        # After returning from all recursive calls, mark 'u' as fully explored (BLACK)
        color[u] = BLACK

    # Main loop: Iterates over all nodes in the graph to ensure we visit
    # disconnected sub-graphs that wouldn't be reached from a single starting node.
    for i in range(n):
        if color[i] == WHITE:
            dfs_visit(i)
    print()

# Run BFS starting from node index 2
bfs(2)
# Run DFS for the entire graph
dfs()