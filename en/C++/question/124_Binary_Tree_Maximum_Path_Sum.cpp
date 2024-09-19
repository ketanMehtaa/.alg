// @algorithm @lc id=124 lang=cpp
// @title binary-tree-maximum-path-sum

#include <iostream>
#include <vector>
#include <string>
#include "algm/algm.h"
#include <bits/stdc++.h>
using namespace std;
// @test([1,2,3])=6
// @test([-10,9,20,null,null,15,7])=42
// @test([2,-1])=2
// @test([2,-1,-2])=2
// @test([9,6,-3,null,null,-6,2,null,null,2,null,-6,-6,-6])=16
// @test([-3])=-3
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
    int maxPathSum(TreeNode *root)
    {
        maxPathThroughNode(root,ans);
        return ans;
    }
    int maxPathThroughNode(TreeNode *node, int &ans)
    {
        if (!node)
            return 0;

        // Recursively get the maximum path sums for left and right subtrees
        int left = max(maxPathThroughNode(node->left, ans), 0);
        int right = max(maxPathThroughNode(node->right, ans), 0);

        // Calculate the maximum path sum with the current node as the highest node
        int currentPathSum = node->val + left + right;

        // Update the global maximum path sum
        ans = max(ans, currentPathSum);

        // Return the maximum path sum including the current node and one of its subtrees
        return node->val + max(left, right);
    }
};