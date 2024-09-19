// @algorithm @lc id=621 lang=cpp
// @title task-scheduler

#include <iostream>
#include <vector>
#include <string>
#include "algm/algm.h"
#include <bits/stdc++.h>
using namespace std;
// @test(["A","A","A","B","B","B"],2)=8
// @test(["A","C","A","B","D","B"],1)=6
// @test(["A","A","A","B","B","B"],3)=10
// @test(["A","A","A","B","B","B", "C","C","C", "D", "D", "E"], 2)=12
class Solution
{
public:
    int leastInterval(vector<char> &tasks, int n)
    {
        std::priority_queue<int> pq;
        queue<pair<int, int>> q;

        // make priority queue
        vector<int> freq(26, 0);
        for (int i = 0; i < tasks.size(); i++)
        {
            freq[tasks[i] - 'A']++;
        }
        for (int i = 0; i < freq.size(); i++)
        {
            if (freq[i])
                pq.push(freq[i]);
        }

        int time = 0;
        while (q.size() || pq.size())
        {
            time++;
            // q has value
            // if (q has value and value in q second time is passed)
            if (q.size() && q.front().second < time)
            {

                auto qtop = q.front();
                q.pop();
                if (qtop.first > 0)
                {
                    pq.push(qtop.first);

                    // q.push({qtop.first - 1, time + n});
                }
                time--;

                continue;
            }

            // priority queue we need to get to fill
            if (pq.size())
            {
                int pqTop = pq.top();
                pq.pop();
                pqTop--;
                if (pqTop)
                {
                    q.push({pqTop, time + n});
                }
            }
        }
        return time;
    }
};