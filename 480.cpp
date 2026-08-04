// Link: https://leetcode.com/problems/sliding-window-median/description/

#include <bits/stdc++.h>
using namespace std;

// class Solution
// {
// public:
//     vector<double> medianSlidingWindow(vector<int> &nums, int k)
//     {
//         multiset<int> lo, hi; // lo = smaller half (max at rbegin), hi = larger half (min at begin)
//         vector<double> res;

//         // balance the two halves so that their sizes differ by at most 1
//         auto balance = [&]()
//         {
//             while (lo.size() > hi.size() + 1)
//             {
//                 hi.insert(*lo.rbegin());
//                 lo.erase(prev(lo.end()));
//             }
//             while (hi.size() > lo.size())
//             {
//                 lo.insert(*hi.begin());
//                 hi.erase(hi.begin());
//             }
//         };

//         // add a new number
//         for (int i = 0; i < (int)nums.size(); i++)
//         {
//             // add new number to the appropriate half
//             if (lo.empty() || nums[i] <= *lo.rbegin())
//                 lo.insert(nums[i]);
//             else
//                 hi.insert(nums[i]);
//             // balance the two halves
//             balance();

//             // if we have at least k elements, record the median
//             if (i >= k - 1)
//             {
//                 // record the median
//                 if (k % 2)
//                     res.push_back(*lo.rbegin());
//                 else
//                     res.push_back(((double)*lo.rbegin() + *hi.begin()) / 2.0);

//                 // remove the element going out of the sliding window
//                 int out = nums[i - k + 1];
//                 // remove from the appropriate half
//                 if (out <= *lo.rbegin())
//                     lo.erase(lo.find(out));
//                 else
//                     hi.erase(hi.find(out));
//                 balance();
//             }
//         }
//         return res;
//     }
// };

class Solution
{
public:
    vector<double> medianSlidingWindow(vector<int> &input, int k)
    {

        priority_queue<pair<int, int>, vector<pair<int, int>>,
                       less<pair<int, int>>>
            leftQ;
        priority_queue<pair<int, int>, vector<pair<int, int>>,
                       greater<pair<int, int>>>
            rightQ;
        vector<double> result;

        if (k == 1)
        {
            for (auto x : input)
                result.push_back(x);
            return result;
        }

        // Initialize the first window
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

        // Calculate the median for the first window
        if (k % 2 == 0)
            result.push_back(
                (double(leftQ.top().first) + (double)(rightQ.top().first)) /
                2.0);
        else
            result.push_back(leftQ.top().first);

        // Process the rest of the windows
        for (int i = k; i < input.size(); ++i)
        {
            int x = input[i - k];
            int z = input[i];

            if (x <= leftQ.top().first)
            {
                // Remove from leftQ
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
                // Remove from rightQ
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