// @algorithm @lc id=42 lang=cpp
// @title trapping-rain-water

#include <iostream>
#include <vector>
#include <string>
#include "algm/algm.h"
using namespace std;
// @test([0,1,0,2,1,0,1,3,2,1,2,1])=6
// @test([4,2,0,3,2,5])=9
class Solution
{
public:
    int trap(vector<int> &height)
    {
        int l = 0, r = height.size() - 1;
        int lmax = 0, rmax = 0;
        int ans = 0;
        while (l <= r)
        {
            if (height[l] <= height[r])
            {
                if (lmax > height[l])
                {
                    ans += lmax - height[l];
                }
                else
                {
                    lmax = height[l];
                }
                l++;
            }
            else
            {
                if (rmax > height[r])
                {
                    ans +=rmax- height[r];
                }
                else
                {
                    rmax = height[r];
                }
                r--;
            }
        }
        return ans;
    }
};