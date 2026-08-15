// Link: https://leetcode.com/problems/number-of-flowers-in-full-bloom/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(nlogn + mlogm) where n is the number of flowers and m is the number of people
// SC: O(n + m) where n is the number of flowers and m is the number of people
// Approach: We can use a two-pointer approach to solve this problem. We can first sort the start and end times of the flowers. Then, we can sort the arrival times of the people. We can then use two pointers to iterate through the start and end times of the flowers and the arrival times of the people. For each person, we can count the number of flowers that are in full bloom at their arrival time by checking how many flowers have started blooming and how many have ended blooming. Finally, we return the count of flowers in full bloom for each person.
class Solution
{
public:
    vector<int> fullBloomFlowers(vector<vector<int>> &flowers,
                                 vector<int> &people)
    {
        int numFlowers = flowers.size();
        std::vector<int> startTimes(numFlowers), endTimes(numFlowers);
        for (int i = 0; i < flowers.size(); i++)
        {
            startTimes[i] = flowers[i][0];
            endTimes[i] = flowers[i][1];
        }

        std::sort(startTimes.begin(), startTimes.end());
        std::sort(endTimes.begin(), endTimes.end());

        int numPeople = people.size();
        std::vector<std::pair<int, int>> peoplePairs(numPeople);
        for (int i = 0; i < people.size(); i++)
        {
            peoplePairs[i] = {people[i], i};
        }

        std::sort(peoplePairs.begin(), peoplePairs.end());
        std::vector<int> ans(numPeople);

        int curCount = 0;
        auto startTimesIt = startTimes.begin();
        auto endTimesIt = endTimes.begin();
        for (const auto &[arrivalTime, idx] : peoplePairs)
        {
            while (startTimesIt != startTimes.end() &&
                   arrivalTime >= *startTimesIt)
            {
                curCount++;
                startTimesIt++;
            }

            while (endTimesIt != endTimes.end() && arrivalTime > *endTimesIt)
            {
                curCount--;
                endTimesIt++;
            }

            ans[idx] = curCount;
        }

        return ans;
    }
};