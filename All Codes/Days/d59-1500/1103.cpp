// Link: https://leetcode.com/problems/distribute-candies-to-people/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(n) where n is the number of candies
    // SC: O(n) where n is the number of people
    //  Approach:
    //   1. We will use a while loop to distribute the candies to the people
    //   2. We will keep track of the number of candies to give to the current person and the index of the current person
    //   3. We will use the min function to ensure that we do not give more candies than we have left
    //   4. We will update the number of candies left and the index of the current person
    //   5. We will increment the number of candies to give to the next person
    //   6. Finally, we will return the result vector containing the number of candies given to each person
    vector<int> distributeCandies(int candies, int num_people)
    {
        vector<int> result(num_people, 0);
        int give = 1, idx = 0;
        while (candies > 0)
        {
            int amount = min(give, candies);
            result[idx] += amount;
            candies -= amount;
            idx = (idx + 1) % num_people;
            give++;
        }
        return result;
    }
};
