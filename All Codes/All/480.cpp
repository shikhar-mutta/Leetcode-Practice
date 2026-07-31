// Link: https://leetcode.com/problems/sliding-window-median/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n log k)  SC: O(k)
//  Approach: maintain two heaps, one max-heap for the smaller half and one min-heap for the larger half. When a new element is added, it is placed in the appropriate heap based on its value. The median is then calculated as the average of the top elements of the two heaps.
class Solution
{
public:
    vector<double> medianSlidingWindow(vector<int> &input, int k)
    {

        priority_queue<pair<int, int>, std::vector<pair<int, int>>,
                       std::less<std::pair<int, int>>>
            leftQ;
        priority_queue<pair<int, int>, std::vector<pair<int, int>>,
                       std::greater<std::pair<int, int>>>
            rightQ;
        vector<double> result;

        if (k == 1)
        {
            for (auto x : input)
                result.push_back(x);
            return result;
        }

        for (int i = 0; i < k; ++i)
        {
            auto x = input[i];
            if (i < (k + 1) / 2)
            {
                leftQ.push({x, i});
                continue;
            }
            if (x < leftQ.top().first)
            {
                pair<int, int> t = leftQ.top();
                leftQ.pop();
                rightQ.push(t);
                leftQ.push({x, i});
            }
            else
            {
                rightQ.push({x, i});
            }
        }

        if (k % 2 == 0)
            result.push_back(
                (double(leftQ.top().first) + (double)(rightQ.top().first)) /
                2.0);
        else
            result.push_back(leftQ.top().first);

        for (int i = k; i < input.size(); ++i)
        {
            int x = input[i - k];
            int z = input[i];

            // cout << "x " << x "; leftQ top = " << leftQ.top() << " rightQ top
            // = " << rightQ.top() << endl;
            if (x <= leftQ.top().first)
            {
                while (rightQ.top().second <= i - k)
                    rightQ.pop();
                if (z < rightQ.top().first)
                    leftQ.push({z, i});
                else
                {
                    leftQ.push(rightQ.top());
                    rightQ.pop();
                    rightQ.push({z, i});
                }
            }
            else
            {
                while (leftQ.top().second <= i - k)
                    leftQ.pop();
                if (z >= leftQ.top().first)
                    rightQ.push({z, i});
                else
                {
                    rightQ.push(leftQ.top());
                    leftQ.pop();
                    leftQ.push({z, i});
                }
            }

            while (rightQ.top().second <= i - k)
                rightQ.pop();
            while (leftQ.top().second <= i - k)
                leftQ.pop();
            if (k % 2 == 0)
                result.push_back(
                    (double(leftQ.top().first) + rightQ.top().first) / 2.0);
            else
                result.push_back(leftQ.top().first);
        }

        return result;
    }
};