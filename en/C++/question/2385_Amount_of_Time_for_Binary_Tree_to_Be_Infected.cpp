// @algorithm @lc id=2461 lang=cpp
// @title amount-of-time-for-binary-tree-to-be-infected

#include <iostream>
#include <vector>
#include <string>
#include "algm/algm.h"
#include <bits/stdc++.h>

using namespace std;
// @test([1,5,3,null,4,10,6,9,2],3)=4
// @test([1],1)=0
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
    int amountOfTime(TreeNode *root, int start)
    {
        // hashmap creation in which child points to parent in hashmap node value
        map<TreeNode *, TreeNode *> parentPointer;

        createParentPointerMap(parentPointer, root, root->left, root->right);

        int time = 0;
        // find start node
        TreeNode *startNode = findStart(root, start);

        map<TreeNode *, bool> visited;

        queue<TreeNode *> q;

        q.push(startNode);
        while (q.size())
        {
            int sz = q.size();
            for (int i = 0; i < sz; i++)
            {
                TreeNode *top = q.front();
                q.pop();

                if (top == NULL || visited.count(top))
                {
                    continue;
                }

                visited[top] = 1;

                if (top->right && visited.count(top->right) == 0)
                    q.push(top->right);

                if (top->left && visited.count(top->left) == 0)
                    q.push(top->left);

                if (parentPointer.count(top) && visited.count(parentPointer[top]) == 0)
                {
                    q.push(parentPointer[top]);
                }
            }
            if (!q.empty())
            {
                time++;
            }
        }

        return time;
    }
    void createParentPointerMap(map<TreeNode *, TreeNode *> &m, TreeNode *root, TreeNode *left, TreeNode *right)
    {
        if (left)
        {
            m[left] = root;
            createParentPointerMap(m, left, left->left, left->right);
        }
        if (right)
        {
            m[right] = root;
            createParentPointerMap(m, right, right->left, right->right);
        }
    }

    TreeNode *findStart(TreeNode *root, int start)
    {
        if (!root)
            return NULL;
        if (root->val == start)
            return root;
        TreeNode *left = findStart(root->left, start);
        TreeNode *right = findStart(root->right, start);
        return left ? left : right;
    }
};