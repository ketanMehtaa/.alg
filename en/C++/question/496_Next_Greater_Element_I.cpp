// @algorithm @lc id=496 lang=cpp
// @title next-greater-element-i

#include <iostream>
#include <vector>
#include <string>
#include "algm/algm.h"
#include <bits/stdc++.h>

using namespace std;
// @test([4,1,2],[1,3,4,2])=[-1,3,-1]
// @test([2,4],[1,2,3,4])=[3,-1]
class Solution
{
public:
    vector<int> nextGreaterElement(vector<int> &nums1, vector<int> &nums2)
    {
        vector<int> ans;
        //  brute force solution is traverse num2 again and again
        //  time complexity n power 2

        // optimal solution
        // first make a vector with optimal solution all element in nums2
        // using stack approach
        int sizeNums2 = nums2.size();
        stack<int> s;
        // vector<int> greaterNum;
        // greaterNum.push_back(-1);
        s.push(nums2[sizeNums2 - 1]);

        unordered_map<int, int> m;
        m[nums2[sizeNums2 - 1]] = -1;

        int i = sizeNums2 - 2;
        while (i > -1)
        {
            while (!s.empty() && s.top() > nums2[i])
            {
                // greaterNum.push_back(s.top());
                m[nums2[i]] = s.top();

                pushed = true;
                s.pop();
            }
            s.push(nums2[i]);

            if (!pushed)
            {
                // greaterNum.push_back(-1);
                m[nums2[i]] = -1;
                s.push(nums2[i]);
            }

            i--;
        }
    }

    // for (auto it = m.begin(); it != m.end(); ++it)
    // {
    //     std::cout << it->first << " " << it->second << "\n";
    // }

    for (int n : nums1)
    {
        ans.push_back(m[n]);
    }
    // reverse(greaterNum.begin(), greaterNum.end());
    return ans;
}
}
;