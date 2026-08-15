// Link: https://leetcode.com/problems/longest-happy-string/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n) where n is the sum of a, b and c.
// SC: O(1) as we are using constant space for the priority queue.
// Approach:
//   1. We will use a priority queue to store the counts of a, b and c along with their corresponding characters.
//   2. We will pop the top element from the priority queue and check if the last two characters in the result string are the same as the character of the popped element. If they are the same, we will pop the next element from the priority queue and add it to the result string. If they are not the same, we will add the character of the popped element to the result string and push it back to the priority queue with its count decremented by 1. We will repeat this process until the priority queue is empty or we cannot add any more characters to the result string.
//   3. We will return the result string.
class Solution
{
public:
    string longestDiverseString(int a, int b, int c)
    {
        priority_queue<pair<int, char>> pq;
        if (a)
            pq.push({a, 'a'});
        if (b)
            pq.push({b, 'b'});
        if (c)
            pq.push({c, 'c'});

        string res;
        while (!pq.empty())
        {
            auto [cnt1, ch1] = pq.top();
            pq.pop();
            int n = res.size();
            if (n >= 2 && res[n - 1] == ch1 && res[n - 2] == ch1)
            {
                if (pq.empty())
                    break;
                auto [cnt2, ch2] = pq.top();
                pq.pop();
                res += ch2;
                if (--cnt2)
                    pq.push({cnt2, ch2});
                pq.push({cnt1, ch1});
            }
            else
            {
                res += ch1;
                if (--cnt1)
                    pq.push({cnt1, ch1});
            }
        }
        return res;
    }
};