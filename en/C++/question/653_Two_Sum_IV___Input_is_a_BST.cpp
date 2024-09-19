// @algorithm @lc id=653 lang=cpp
// @title two-sum-iv-input-is-a-bst

#include <iostream>
#include <vector>
#include <string>
#include "algm/algm.h"
using namespace std;
// @test([5,3,6,2,4,null,7],9)=true
// @test([5,3,6,2,4,null,7],28)=false
// @test([2,1,3], 4)=true
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
    bool findTarget(TreeNode *root, int k)
    {
        return check(root, k, 0);
    }
    bool check(TreeNode *root, int k, int taken)
    {
        if (!root)
            return false;
        if (taken == 1 && root->val == k)
        {
            return true;
        }
        // take root and call right left
        // dont take root and call right and left

        // if already taken we can only find one more

        if (taken)
        {
            if (k < root->val)
            {
                return check(root->left, k, taken);
            }
            return check(root->right, k, taken);
        }
        else
        {
            // not taken yet so fresh
            // we can take and we can not take
            bool leftWithRoot = check(root->left, k - root->val, 1);
            bool rightWithRoot = check(root->right, k - root->val, 1);

            bool left = check(root->left, k, 0);
            bool right = check(root->right, k, 0);

            return left || right || leftWithRoot || rightWithRoot;
        }
    }
};