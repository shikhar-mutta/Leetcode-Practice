// Link: https://leetcode.com/problems/reward-top-k-students/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(nlogn) where n is the number of reviews.
// SC: O(n) where n is the number of reviews.
// Approach:
//  1. Create a hash map to store the scores of the positive and negative words.
//  2. For each review, calculate the score by checking each word in the review against the hash map.
//  3. Store the score and student id in a vector of pairs.
//  4. Sort the vector of pairs based on the score in descending order and student id in ascending order.
//  5. Return the top k student ids from the sorted vector.
class Solution
{
public:
    vector<int> topStudents(vector<string> &po, vector<string> &ne, vector<string> &re, vector<int> &stu, int k)
    {
        typedef unsigned long long ull;
        unordered_map<ull, int> m;
        int n = re.size(), idx = 0;
        vector<pair<int, int>> v;
        for (auto &p : po)
        {
            ull hash = 0;
            for (auto &c : p)
            {
                hash *= 31;
                hash += c;
            }
            m[hash] = 3;
        }
        for (auto &p : ne)
        {
            ull hash = 0;
            for (auto &c : p)
            {
                hash *= 31;
                hash += c;
            }
            m[hash] = -1;
        }
        for (auto &r : re)
        {
            int s = r.size();
            int score = 0;
            ull temp = 0;
            for (int i = 0; i < s; i++)
            {
                if (r[i] == ' ')
                {
                    if (temp > 0)
                    {
                        if (m.find(temp) != m.end())
                            score += m[temp];
                    }
                    temp = 0;
                }
                else
                {
                    temp *= 31;
                    temp += r[i];
                }
            }
            if (temp > 0)
            {
                if (m.find(temp) != m.end())
                    score += m[temp];
            }
            v.push_back({score, stu[idx++]});
        }

        sort(v.begin(), v.end(), [](const auto &a, const auto &b)
             {
            if(a.first == b.first) {
                return a.second < b.second;
            }
            return a.first > b.first; });
        vector<int> ans;
        idx = 0;
        while (k--)
            ans.push_back(v[idx++].second);

        return ans;
    }
};