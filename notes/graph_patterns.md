# Graph Patterns

## 1. Introduction
A graph consists of vertices (nodes) and edges connecting them.

Graphs can be directed or undirected, weighted or unweighted.

## 2. Graph Representation

### Adjacency List
```cpp
int n = 5;
vector<vector<int>> adj(n);

adj[0].push_back(1);
adj[1].push_back(0);

An adjacency list is often space-efficient for sparse graphs.

Adjacency Matrix

A two-dimensional matrix represents whether an edge exists between each pair of vertices.

3. BFS

Breadth-First Search explores vertices level by level using a queue.

It finds shortest paths in unweighted graphs.

4. DFS

Depth-First Search explores as far as possible along a path before backtracking.

It can be implemented recursively or iteratively.

5. Important Patterns
BFS and DFS
Connected components
Cycle detection
Topological sorting
Bipartite graph checking
Shortest paths
Minimum spanning trees
Disjoint Set Union (DSU)
6. Important Algorithms
BFS: Unweighted shortest paths
Dijkstra: Non-negative edge weights
Bellman-Ford: Supports negative edge weights and detects reachable negative cycles
Floyd-Warshall: All-pairs shortest paths
Kruskal: Minimum spanning tree
Prim: Minimum spanning tree
Kahn's Algorithm: Topological sorting
7. Complexity

With an adjacency list:

BFS: O(V + E)
DFS: O(V + E)

V = number of vertices
E = number of edges

8. Practice Problems
Number of Islands
Clone Graph
Course Schedule
Rotting Oranges
Pacific Atlantic Water Flow
Redundant Connection
Network Delay Time
9. Common Mistakes
Forgetting visited tracking
Confusing directed and undirected edges
Incorrectly handling disconnected components
Applying Dijkstra to graphs with negative edge weights
Forgetting to initialize distances
10. Key Takeaway

Identify the graph structure and the required output before choosing the traversal or shortest-path algorithm.
