// Link: https://leetcode.com/problems/most-frequent-ids/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n log n), SC: O(n + maxVal)
// Approach: Track each id's latest running frequency in a direct-index
// array (lazy-deletion max-heap alongside it). Push the updated frequency
// for the current id each step; before reading the answer, pop any heap-top
// entries whose stored frequency no longer matches the id's latest value
// (stale states from earlier pushes).
class Solution {
public:
    vector<long long> mostFrequentIDs(vector<int>& nums, vector<int>& freq) {
        // std::unordered_map<int, long long> latestFrequences;

        auto max = *std::max_element(nums.begin(), nums.end());
        std::vector<long long> latestFrequences(max + 1, 0);

        auto cmpLesser = [](const pair<int, long long>& l,
                            const pair<int, long long>& r) {
            return l.second < r.second;
        };
        std::priority_queue<std::pair<int, long long>,
                            std::vector<std::pair<int, long long>>,
                            decltype(cmpLesser)>
            maxHeap(cmpLesser);

        auto N = nums.size();

        std::vector<long long> ans;
        ans.reserve(N);

        for (int i = 0; i < N; ++i) {
            latestFrequences[nums[i]] += freq[i];

            // make sure to delete stale states
            while (!maxHeap.empty() &&
                   latestFrequences[maxHeap.top().first] != maxHeap.top().second) {
                maxHeap.pop();
            }

            if (latestFrequences[nums[i]] != 0)
                maxHeap.emplace(nums[i], latestFrequences[nums[i]]);
            if (!maxHeap.empty())
                ans.push_back(maxHeap.top().second);
            else
                ans.push_back(0);
        }

        return ans;
    }
};
