# Heap and Priority Queue Patterns

## 1. Introduction
A heap is a complete binary tree that maintains an ordering property.

A priority queue allows efficient access to the highest-priority element.

## 2. Types of Heaps
- Max Heap: Largest element at the top
- Min Heap: Smallest element at the top

## 3. C++ Max Heap
```cpp
priority_queue<int> pq;

pq.push(10);
pq.push(30);
pq.push(20);

cout << pq.top();  // 30

pq.pop();
4. C++ Min Heap
priority_queue<int, vector<int>, greater<int>> pq;

pq.push(10);
pq.push(30);
pq.push(20);

cout << pq.top();  // 10
5. Complexity

For a priority queue:

Access top: O(1)
Insert: O(log N)
Remove top: O(log N)
Build heap from N elements: O(N)
6. Important Patterns
Kth largest or smallest element
Top K frequent elements
Merge K sorted lists
Running median
Scheduling problems
Dijkstra's shortest path algorithm
7. Practice Problems
Kth Largest Element in an Array
Top K Frequent Elements
Find Median from Data Stream
Merge K Sorted Lists
Last Stone Weight
K Closest Points to Origin
8. Common Mistakes
Choosing a max heap when a min heap is needed
Keeping too many elements in a fixed-size heap
Forgetting that priority_queue does not support efficient arbitrary deletion
Ignoring duplicate values
9. Key Takeaway

Use a heap when you repeatedly need the smallest or largest element without sorting the entire collection.
