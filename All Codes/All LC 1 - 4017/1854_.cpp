// Link: https://leetcode.com/problems/maximum-population-year/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maximumPopulation(vector<vector<int>> &logs)
    {
        vector<int> population(101, 0); // 1950 to 2050
        // Increment the population for birth years and decrement for death years
        for (auto &log : logs)
        {
            population[log[0] - 1950]++;
            population[log[1] - 1950]--;
        }
        // Calculate the cumulative population and find the year with the maximum population
        int maxPopulation = 0;
        int maxYear = 1950;
        int currentPopulation = 0;

        // Iterate through the population array to find the year with the maximum population
        for (int i = 0; i < population.size(); i++)
        { // Update the current population based on the increments and decrements
            currentPopulation += population[i];
            // Check if the current population exceeds the maximum population found so far
            if (currentPopulation > maxPopulation)
            {
                maxPopulation = currentPopulation;
                maxYear = 1950 + i;
            }
        }

        return maxYear;
    }
};
