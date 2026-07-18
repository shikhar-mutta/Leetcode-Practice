// Link: https://leetcode.com/problems/apply-operations-to-make-string-empty/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(n), SC: O(1)
    //  Approach:
    //  1. Create a vector of pairs to store the frequency and last index of each character in the string.
    //  2. Iterate through the string and update the frequency and last index of each character in the vector.
    //  3. Find the maximum frequency of characters in the string.
    //  4. Create a priority queue to store the characters with the maximum frequency and their last index.
    //  5. While the priority queue is not empty, pop the character with the smallest last index and append it to the answer string.
    //  6. Return the answer string.
    string lastNonEmptyString(string s)
    {
        string ans = "";
        vector<pair<int, int>> nums(26);
        int m = 0;
        for (int i = 0; i < s.length(); i++)
        {
            int index = s[i] - 'a';
            nums[index].first++;
            nums[index].second = i;
            m = max(m, nums[index].first);
        }
        priority_queue<pair<int, char>, vector<pair<int, char>>, greater<pair<int, char>>> pq;
        for (int i = 0; i < 26; i++)
        {
            if (nums[i].first < m)
                continue;
            pq.push({nums[i].second, char(i + 'a')});
        }
        while (!pq.empty())
        {
            ans += pq.top().second;
            pq.pop();
        }
        return ans;
    }
};