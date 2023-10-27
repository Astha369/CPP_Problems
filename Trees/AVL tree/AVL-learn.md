
# AVL Tree - Detailed Explanation

### AVL Tree Requirements:

#### 1. **Binary Search Tree (BST) Property:**
   - An AVL tree must maintain the Binary Search Tree property. In a BST, for any node:
     - All nodes in its left subtree have values less than the node.
     - All nodes in its right subtree have values greater than the node.

#### 2. **Balance Factor:**
   - The balance factor of a node is the difference between the height of its left subtree and the height of its right subtree.
   - Balance factor (BF) = Height of Left Subtree - Height of Right Subtree.

#### 3. ** AVL Tree should be BALANCED:**
   - An AVL tree is balanced if every node in the tree has a balance factor of -1, 0, or 1.
   - If the balance factor of any node is less than -1 or greater than 1, rotations need to be performed to rebalance the tree.

#### 4. **Balancing Operations:**
   - There are four types of rotations used to balance AVL trees:
     - **Left Rotation:** Used when the right subtree of a node is higher by 2 levels.
     - **Right Rotation:** Used when the left subtree of a node is higher by 2 levels.
     - **Left-Right Rotation:** Used when a node has a left child with a right-heavy subtree.
     - **Right-Left Rotation:** Used when a node has a right child with a left-heavy subtree.

#### 5. **Updating Balance Factors:**
   - After an insertion or deletion operation, balance factors of the affected nodes need to be recalculated.
   - If the balance factor of a node becomes -2 or 2, rotations are performed to rebalance the tree.
   - After rotations, balance factors of nodes involved in rotations are updated.

#### 6. **Recursive AVL Property:**
   - The AVL property must be recursively maintained for all nodes in the tree. This means that every subtree of an AVL tree is also an AVL tree.

#### 7. **Height-Balanced Tree:**
   - An AVL tree is a height-balanced binary search tree in which the height of the left and right subtrees of every node differ by at most 1.

#### 8. **Complexity:**
   - The operations (insertion, deletion, search) in an AVL tree have a time complexity of O(log N), ensuring efficient data retrieval and manipulation.

#### Balance Factor Calculation Example:
   - For a node:
     - Left Subtree Height = 3
     - Right Subtree Height = 2
   - Balance Factor (BF) = 3 - 2 = 1

## Insertion Process

When a new node is inserted into an AVL tree, it might become unbalanced. The following steps are taken to maintain the balance property:

1. **Insertion:** Follows the standard binary search tree insertion process.

2. **Updating Heights:** After insertion, the height of the current node is updated. Then, the heights of its ancestors are checked.

3. **Rotation Cases:**

    - **Left-Left Rotation (LL Rotation):** If balance > 1 and the new node is inserted into the left subtree of the left child, perform right rotation.
    
    - **Right-Right Rotation (RR Rotation):** If balance < -1 and the new node is inserted into the right subtree of the right child, perform left rotation.
    
    - **Left-Right Rotation (LR Rotation):** If balance > 1 and the new node is inserted into the right subtree of the left child, perform left rotation on the left child, then right rotation on the current node.
    
    - **Right-Left Rotation (RL Rotation):** If balance < -1 and the new node is inserted into the left subtree of the right child, perform right rotation on the right child, then left rotation on the current node.

4. **Balancing Continues:** Balancing continues up the tree until the root is reached.

## Specific Requirements in the CPP Code

1. **Node Structure:**

    ```cpp
    struct AVLNode {
        int data;
        AVLNode* left;
        AVLNode* right;
        int height;
    };
    ```

2. **Rotation Functions:** `leftRotate`, `rightRotate`, `leftRightRotate`, `rightLeftRotate`.

3. **Height Calculation:** A function to accurately calculate the height of each node.

4. **Balance Factor Calculation:** A function to calculate the balance factor of a node.

5. **Insertion Function:** `insert` function to handle BST insertion and AVL balancing.

6. **Preorder Traversal:** A function for preorder traversal (`preOrderTraversal`) to demonstrate the final structure.

## Handling Duplicates

Decide whether duplicates are allowed. Modify the insertion process accordingly.

## Time and Space Complexity

- **Time Complexity:** O(log N) for average and worst-case scenarios.
- **Space Complexity:** O(log N).

## Benefits of AVL Trees

- Efficient search, insertion, and deletion operations.
- Guaranteed O(log N) time complexity for operations.

## Visual Representation

Consider visualizing the AVL tree at various stages of insertion. Diagrams or animations can illustrate how the tree maintains balance through rotations after each insertion.

### AVL Tree Insertion Example

For instance, consider the following insertion sequence: `10, 20, 5, 6, 12`. Visualize the AVL tree after inserting each element to see how the rotations maintain balance.

1) **Insert `10`:**

&nbsp;&nbsp;&nbsp;10

2)  **Insert `20`:**

10
&nbsp;&nbsp;&nbsp;&nbsp; \  
&nbsp;&nbsp;&nbsp;&nbsp; 20


3) **Insert `5`:**

&nbsp;&nbsp;&nbsp;10
&nbsp;/&nbsp;&nbsp;&nbsp; \  
5&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; 20

4) **Insert `6`:**

&nbsp;&nbsp;&nbsp;10
&nbsp;/&nbsp;&nbsp;&nbsp; \  
5&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; 20
&nbsp;&nbsp;\
&nbsp;&nbsp;&nbsp;&nbsp;6 

5) **Insert `12`:**

&nbsp;&nbsp;&nbsp;10
&nbsp;/&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; \  
5&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; 20
&nbsp;&nbsp;\&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;/
&nbsp;&nbsp;&nbsp;6 &nbsp;&nbsp;12

## Check this online website for insertion and deletion in AVL tree in animation for easy visualization.
#### *https://www.cs.usfca.edu/~galles/visualization/AVLtree.html*
###### This website belongs to *University of San Francisco* ,  Credits goes to them for the nice animation in insertion in various tree in data structures.


## Conclusion

Understanding AVL tree insertion is crucial for efficient data management. With balanced trees, operations like search, insertion, and deletion remain logarithmic, ensuring optimal performance.

By following the explained concepts and the provided CPP code, developers can implement AVL trees in various applications. Visualizing the tree's structure during insertion aids in comprehending the balancing process.

This guide equips you with the knowledge needed to implement and comprehend AVL tree insertion. Experiment with different insertion sequences to reinforce your understanding.

For further learning, consider exploring AVL tree deletion, a topic that extends AVL tree operations and is equally important in real-world applications.

Happy coding!
