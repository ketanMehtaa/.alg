// @algorithm @lc id=105 lang=cpp
// @title construct-binary-tree-from-preorder-and-inorder-traversal

#include <iostream>
#include <vector>
#include <string>
#include "algm/algm.h"
#include <bits/stdc++.h>

using namespace std;

// @test([3,9,20,15,7],[9,3,15,20,7])=[3,9,20,null,null,15,7]
// @test([-1],[-1])=[-1]
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
    map<int, int> indexInorder;
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
    {
        for (int i = 0; i < inorder.size(); i++)
        {
            indexInorder[inorder[i]] = i;
        }
        return createTree(preorder, inorder, 0, preorder.size() - 1, 0, inorder.size() - 1);
    }
    TreeNode *createTree(vector<int> &preorder, vector<int> &inorder, int i, int j, int k, int l)
    {
        if (i > j || k > l)
        {
            return NULL;
        }
        TreeNode *root = new TreeNode(preorder[i]);

        int mainIndex = indexInorder[preorder[i]];
        int leftTreeSize=mainIndex-k;
    
        root->left = createTree(preorder, inorder, i+1 , i+leftTreeSize , k, mainIndex-1);

        root->right = createTree(preorder, inorder,  i + leftTreeSize + 1, j, mainIndex+1, l);

        return root;
    }
};