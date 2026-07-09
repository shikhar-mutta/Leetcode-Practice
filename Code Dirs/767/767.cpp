// Link: https://leetcode.com/problems/reorganize-string/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(nlogk), SC: O(n)
    // Approach: Count the frequency of each character using a hash map. Then, use a max heap (priority queue) to store the characters based on their frequency. Pop the top two characters from the heap and append them to the result string. Decrease their frequency and push them back into the heap if they still have a positive frequency. Repeat this process until the heap is empty. If at any point, the frequency of a character exceeds (n + 1) / 2, return an empty string as it is not possible to reorganize the string.
    string reorganizeString(string s)
    {
        int n = s.size();
        vector<int> cnt(26, 0);
        for (char c : s)
            cnt[c - 'a']++;

        priority_queue<pair<int, char>> pq;
        for (int i = 0; i < 26; i++)
        {
            if (cnt[i] > (n + 1) / 2)
                return "";
            if (cnt[i] > 0)
                pq.push({cnt[i], 'a' + i});
        }

        string res;
        pair<int, char> prev = {0, '#'};
        while (!pq.empty())
        {
            auto cur = pq.top();
            pq.pop();
            res += cur.second;
            cur.first--;
            if (prev.first > 0)
                pq.push(prev);
            prev = cur;
        }
        return res;
    }
};
