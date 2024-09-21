/*
100. Same Tree
Solved
Easy
Topics
Companies
Given the roots of two binary trees p and q, write a function to check if they are the same or not.

Two binary trees are considered the same if they are structurally identical, and the nodes have the same value.

 

Example 1:


Input: p = [1,2,3], q = [1,2,3]
Output: true
Example 2:


Input: p = [1,2], q = [1,null,2]
Output: false
Example 3:


Input: p = [1,2,1], q = [1,1,2]
Output: false
 

Constraints:

The number of nodes in both trees is in the range [0, 100].
-104 <= Node.val <= 104


*/

/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
// Definition for a binary tree node.

#include <iostream>
 struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
   TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

     TreeNode(int x, TreeNode* l, TreeNode* r) : val(x), left(l), right(r) {}
};
 bool isSameTree(TreeNode* p, TreeNode* q) {
     if (p == nullptr && q == nullptr)
        return true;

      if (p == nullptr || q == nullptr)
        return false;

     if (p->val != q->val)
        return false;
    return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
}

 int main() {
     TreeNode* tree1 = new TreeNode(1);
    tree1->left = new TreeNode(2);
    tree1->right = new TreeNode(3);

    TreeNode* tree2 = new TreeNode(1);
    tree2->left = new TreeNode(2);
    tree2->right = new TreeNode(3);

     bool result = isSameTree(tree1, tree2);
    std::cout << "Are the trees the same? " << (result ? "Yes" : "No") << std::endl;

     TreeNode* tree3 = new TreeNode(1);
    tree3->right = new TreeNode(2);

     bool result2 = isSameTree(tree1, tree3);
    std::cout << "Are tree1 and tree3 the same? " << (result2 ? "Yes" : "No") << std::endl;
 
    delete tree1->left;
    delete tree1->right;
    delete tree1;
    delete tree2->left;
    delete tree2->right;
    delete tree2;
    delete tree3->right;
    delete tree3;

    return 0;
}



/*Leetcode required Code 

 Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 
public class TreeNode {
    int val;
    TreeNode left;
    TreeNode right;
    TreeNode() {}
    TreeNode(int val) { this.val = val; }
    TreeNode(int val, TreeNode left, TreeNode right) {
        this.val = val;
        this.left = left;
        this.right = right;
    }
}

class Solution {
    public boolean isSameTree(TreeNode p, TreeNode q) {
         if (p == null && q == null) {
            return true;
        }
         if (p == null || q == null) {
            return false;
        }
         if (p.val != q.val) {
            return false;
        }
         return isSameTree(p.left, q.left) && isSameTree(p.right, q.right);
    }
}


*/