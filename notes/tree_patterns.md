# Tree Patterns

## 1. Introduction
A tree is a hierarchical data structure consisting of nodes connected by edges.

A binary tree allows each node to have at most two children.

## 2. Important Terminology
- Root: The topmost node
- Leaf: A node without children
- Height: The longest downward path, measured in edges
- Depth: Distance from the root
- Subtree: A node and its descendants

## 3. Tree Traversals

### Inorder
Left → Root → Right

### Preorder
Root → Left → Right

### Postorder
Left → Right → Root

### Level Order
Visit nodes level by level using a queue.

## 4. Recursive Inorder Traversal
```cpp
void inorder(TreeNode* root) {
    if (root == nullptr)
        return;

    inorder(root->left);
    cout << root->val << " ";
    inorder(root->right);
}
5. Important Patterns
Recursive DFS
Iterative DFS
BFS using a queue
Height and depth calculations
Diameter of a binary tree
Lowest Common Ancestor
Balanced tree validation
Binary Search Tree properties
6. Complexity

For a tree with N nodes:

Traversal time: O(N)
Recursive auxiliary space: O(H)
H is the height of the tree

For a balanced tree, H is generally O(log N).
For a skewed tree, H can be O(N).

7. Practice Problems
Maximum Depth of Binary Tree
Invert Binary Tree
Diameter of Binary Tree
Balanced Binary Tree
Lowest Common Ancestor
Binary Tree Level Order Traversal
Validate Binary Search Tree
8. Common Mistakes
Forgetting the null base case
Confusing depth and height
Incorrectly updating global answers
Assuming every tree is balanced
Misunderstanding BST ordering rules
9. Key Takeaway

Most tree problems become easier when you identify the traversal and the information each recursive call must return.
