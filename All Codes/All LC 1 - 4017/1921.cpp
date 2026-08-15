// Link: https://leetcode.com/problems/eliminate-maximum-number-of-monsters/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n) where n is the size of dist
// SC: O(n) where n is the size of dist
// Approach:
//  1. We will create a frequency array of size n+1 to store the frequency of each time it takes for the monsters to reach the city.
//  2. We will iterate through the dist and speed arrays and calculate the time it takes for each monster to reach the city and increment the frequency of that time in the frequency array.
//  3. We will then iterate through the frequency array and keep track of the time and the number of monsters that have reached the city. If the number of monsters that have reached the city is greater than or equal to the time, we will break the loop and return the time. Otherwise, we will increment the time and continue iterating through the frequency array until we reach the end of the array. Finally, we will return the time.
class Solution
{
public:
    int eliminateMaximum(vector<int> &dist, vector<int> &speed)
    {
        int n = dist.size();
        vector<int> timefrequency(n + 1, 0);
        for (int i = 0; i < n; i++)
        {
            timefrequency[min((dist[i] + speed[i] - 1) / speed[i], n)]++;
        }
        int time = 0, itr = 0;
        while (itr <= n)
        {
            if (timefrequency[itr] == 0)
                itr++;
            else if (time == itr)
                break;
            else
            {
                if (timefrequency[itr] >= itr - time)
                {
                    int diff = itr - time;
                    time += diff;
                    timefrequency[itr] -= diff;
                }
                else
                {
                    time += timefrequency[itr];
                    timefrequency[itr] = 0;
                }
            }
        }
        return time;
    }
};