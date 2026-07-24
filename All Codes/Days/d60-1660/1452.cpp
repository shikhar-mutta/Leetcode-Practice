// Link: https://leetcode.com/problems/people-whose-list-of-favorite-companies-is-not-a-subset-of-another-list/description/

#include <bits/stdc++.h>
using namespace std;

#define fastIO                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)

// TC: O(n*m) where n is the number of people and m is the average number of favorite companies per person
// SC: O(n*m) where n is the number of people and m is the average number of favorite companies per person
// Approach:
//   1. Create a hash map to store the bitset representation of each person's favorite companies.
//   2. For each person, create a bitset that represents the intersection of all the bitsets of their favorite companies.
//   3. If the count of set bits in the intersection bitset is 1, it means that the person's list of favorite companies is not a subset of any other person's list, so we add their index to the result vector.
//   4. Return the result vector containing the indices of people whose list of favorite companies is not a subset of another list.
class Solution
{
public:
    vector<int> peopleIndexes(vector<vector<string>> &favoriteCompanies)
    {

        fastIO;
        unordered_map<string, bitset<100>> hsh;
        vector<int> res;

        for (int i = 0; i < favoriteCompanies.size(); i++)
            for (int j = 0; j < favoriteCompanies[i].size(); j++)
                hsh[favoriteCompanies[i][j]][i] = 1;

        for (int i = 0; i < favoriteCompanies.size(); i++)
        {
            bitset<100> temp;
            temp.set();
            for (int j = 0; j < favoriteCompanies[i].size(); j++)
                temp &= hsh[favoriteCompanies[i][j]];
            if (temp.count() == 1)
                res.push_back(i);
        }

        return res;
    }
};