// @algorithm @lc id=81 lang=cpp
// @title search-in-rotated-sorted-array-ii

#include <iostream>
#include <vector>
#include <string>
#include "algm/algm.h"
#include <bits/stdc++.h>
using namespace std;
// @test([2,5,6,0,0,1,2],0)=true
// @test([2,5,6,0,0,1,2],3)=false
// @test([1,1,1,13,1,1,1,1,1],13)=true

class Solution
{
public:
bool search(vector<int> &nums, int target)
    {
        int i = 0, j = nums.size() - 1, mid = (i + j) / 2;
        while (i <= j)
        {
            mid = (i + j) / 2;
            if (nums[mid] == target)
            {
                return true;
            }
            // this question is upgrade of search in rotated sorted array
            if(nums[mid]==nums[i] && nums[i]==nums[j]){
                i++;
                j--;
                continue;
            }

            // means right side is sorted
            if(nums[mid]<=nums[j] ){
                if(nums[mid] <= target && target <=nums[j]){
                    i=mid+1;
                }else {
                    j=mid-1;
                }
            }else{
                // left side is sorted
                 if(nums[mid] >= target && target >=nums[i]){
                    j=mid-1;
                }else {
                    i=mid+1;
                }
            }

        }
        return false;
    }
};