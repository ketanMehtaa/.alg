// @algorithm @lc id=450 lang=cpp
// @title delete-node-in-a-bst

#include <iostream>
#include <vector>
#include <string>
#include "algm/algm.h"
using namespace std;
// @test([5,3,6,2,4,null,7],3)=[5,4,6,2,null,null,7]
// @test([5,3,6,2,4,null,7],0)=[5,3,6,2,4,null,7]
// @test([],0)=[]
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution
{
public:
    TreeNode *deleteNode(TreeNode *root, int key)
    {
        return deleteValue(root, key);
    }
    TreeNode *deleteValue(TreeNode *root, int key)
    {
        if (!root)
            return NULL;
        if (root->val == key)
        {
            // simple base case when one side is there
            if (root->right && !root->left)
            {
                root = root->right;
                return root;
            }
            else if (root->left && !root->right)
            {
                root = root->left;
                return root;
            }
            else if (!root->left && !root->right)
            {
                return NULL;
            }
            else
            {
                // main case root has both left and right
                // we need to put the smallest right subtree value
                // and then delete that value
                TreeNode *smallestInRight = findSmallest(root->right);
                // put the left of root and right of root into smallest
                smallestInRight->right = root->right;
                smallestInRight->left = deleteNode(root->right, smallestInRight->val);
                return smallestInRight
            }
        }
        root->left = deleteNode(root->left, key);
        root->right = deleteNode(root->right, key);
        return root;
    }
    TreeNode *findSmallest(TreeNode *root)
    {
        if (!root)
            return NULL;
        if (!root->left)
        {
            return root;
        }
        return findSmallest(root->left);
    }

    // TreeNode *findKey(TreeNode *root, int key)
    // {
    //     if (!root)
    //     {
    //         return NULL;
    //     }
    //     if (root->val == key)
    //     {
    //         return root;
    //     }
    //     if (root->val < key)
    //     {
    //         return findKey(root->right, key);
    //     }

    //     return findKey(root->left, key);
    // }
    // find which one to delete
    // delete that and put the left smallest at his place
    // now delete that left smallest
};