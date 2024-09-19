// @algorithm @lc id=239 lang=cpp
// @title sliding-window-maximum

#include <iostream>
#include <vector>
#include <string>
#include "algm/algm.h"
#include <bits/stdc++.h>
using namespace std;
// @test([1,3,-1,-3,5,3,6,7],3)=[3,3,5,5,6,7]
// @test([1],1)=[1]
class Solution
{
public:
    vector<int> maxSlidingWindow(vector<int> &nums, int k)
    {
        deque<int> dq;
        vector<int> ans;
        // first need to create the dq
        int i = 0;
        while (i < nums.size())
        {
            // remove out of index element
            while (dq.size() && dq.front() < i - k + 1)
            {
                // index out of window remove
                dq.pop_front();
            }
            // now pushing this element
            while (dq.size() && nums[dq.back()] < nums[i])
            {
                dq.pop_back();
            }
            if (dq.size() && nums[dq.back()] >= nums[i])
            {
                dq.push_back(i);
            }

            dq.push_back(i);

            if (i >= k - 1)
                ans.push_back(nums[dq.front()]);

            i++;
        }
        return ans;
        // dequeue ready
    }
};