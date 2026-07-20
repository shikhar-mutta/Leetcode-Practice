// Link: https://leetcode.com/problems/most-popular-video-creator/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(n)
    // SC: O(n)
    //  Approach:
    //  1. Create a map to store the index of each creator in the creators vector
    //  2. Create a vector to store the index of the most popular video for each creator
    //  3. Create a vector to store the popularity of each creator
    //  4. Iterate through the creators vector and update the most popular video and popularity for each creator
    //  5. Find the maximum popularity and return the creators with that popularity and their most popular video
    vector<vector<string>> mostPopularCreator(vector<string> &creators, vector<string> &ids, vector<int> &views)
    {
        int n = creators.size();
        unordered_map<string, int> index_map;
        int index = 0;
        for (auto &creator : creators)
        {
            if (!index_map.contains(creator))
            {
                index_map[creator] = index;
                index++;
            }
        }
        int m = index_map.size();
        vector<int> videos(m, -1);
        vector<long long> popularities(m);
        for (int i = 0; i < n; i++)
        {
            int creator = index_map[creators[i]];
            int &video = videos[creator];
            if (video == -1 || make_pair(views[i], ids[video]) > make_pair(views[video], ids[i]))
            {
                video = i;
            }
            popularities[creator] += views[i];
        }
        long long max_popularity = 0;
        for (long long popularity : popularities)
        {
            max_popularity = max(max_popularity, popularity);
        }
        vector<vector<string>> answer;
        int creator = 0;
        for (long long popularity : popularities)
        {
            if (popularity == max_popularity)
            {
                answer.push_back({creators[videos[creator]], ids[videos[creator]]});
            }
            creator++;
        }
        return answer;
    }
};