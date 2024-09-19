// @algorithm @lc id=543 lang=cpp
// @title diameter-of-binary-tree

#include <iostream>
#include <vector>
#include <string>
#include "algm/algm.h"
#include <bits/stdc++.h>
using namespace std;
// @test([1,2,3,4,5])=3
// @test([1,2])=1
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
    int ans = INT_MIN;
    int diameterOfBinaryTree(TreeNode *root)
    {
        height(root);
        return ans;
    }
    int height(TreeNode *root)
    {
        if (!root)
        {
            return 0;
        }
        int leftHeight = height(root->left);
        int rightHeight = height(root->right);

        // store max diameter here
        ans = max(ans, (leftHeight + rightHeight ));
        return max(leftHeight, rightHeight)+1;
    }
};