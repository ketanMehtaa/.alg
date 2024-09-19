// @algorithm @lc id=735 lang=cpp
// @title asteroid-collision

#include <iostream>
#include <vector>
#include <string>
#include "algm/algm.h"
using namespace std;
// @test([5,10,-5])=[5,10]
// @test([8,-8])=[]
// @test([10,2,-5])=[10]
// @test([-2,-1,1,2])=[-2,-1,1,2]
// @test([-2,-2,1,-2])=[-2,-2,-2]
class Solution
{
public:
    vector<int> asteroidCollision(vector<int> &v)
    {
        vector<int> ans;
        for (int i = 0; i < v.size(); i++)
        {
            // + +
            // - -
            // + -
            // - +
            if (ans.size() == 0)
            {
                ans.push_back(v[i]);
            }
            else
            {
                int currentAns = ans.back();
                if (v[i] > 0 && currentAns > 0)
                {
                    ans.push_back(v[i]);
                    continue;
                }
                else if (v[i] < 0 && currentAns < 0)
                {
                    // both negative number
                    ans.push_back(v[i]);
                    continue;
                }
                else if (currentAns < 0 && v[i] > 0)
                {
                    ans.push_back(v[i]);
                    continue;
                }
                // main case current numebr in ans is + and v[i] is negative
                while (ans.size() != 0 && ans.back() > 0 && abs(v[i]) > ans.back())
                    ans.pop_back();
                if (ans.size() && ans.back() < 0)
                {
                    ans.push_back(v[i]);
                    continue;
                }
                if (ans.size() && abs(v[i]) == ans.back())
                {
                    ans.pop_back();
                }
                else if (!ans.size())
                {
                    ans.push_back(v[i]);
                }
            }
        }
        return ans;
    }
};