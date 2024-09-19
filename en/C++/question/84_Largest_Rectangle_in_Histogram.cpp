// @algorithm @lc id=84 lang=cpp 
// @title largest-rectangle-in-histogram


#include <iostream>
#include <vector>
#include <string>
// #include "algm/algm.h"
#include <bits/stdc++.h>
using namespace std;
// @test([2,1,5,6,2,3])=10
// @test([2,4])=4
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        vector<int> rightSmallest,leftSmallest;
        stack<int> s ;
        int i = 0;
        while(i<heights.size()){
            
            while(!s.empty() && heights[s.top()] >= heights[i]){
                s.pop();
            }
            if(s.empty()){
                rightSmallest.push_back(0);
            }else{
                rightSmallest.push_back(s.top()+1);
            }
            s.push(i);
            i++;
        }
        i = heights.size()-1;
        
        while(!s.empty())s.pop();

        while(i>-1){
            
            while(!s.empty() && heights[s.top()] >= heights[i]){
                s.pop();
            }
            if(s.empty()){
                leftSmallest.push_back(heights.size());
            }else{
                leftSmallest.push_back(s.top());
            }
            s.push(i);
            i--;
        }
        reverse(leftSmallest.begin(),leftSmallest.end());
        
        int maxAns = 0;
        
        i = 0;
        while(i < heights.size()){
            maxAns=max (maxAns,(leftSmallest[i]-rightSmallest[i])*heights[i]) ;
            i++;
        }
        return maxAns;
    }
};