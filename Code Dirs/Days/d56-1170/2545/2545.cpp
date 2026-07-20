// Link: https://leetcode.com/problems/sort-the-students-by-their-kth-score/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(nlogn)
    // SC: O(1)
    // Approach:
    // 1. Use the sort function to sort the score vector based on the k-th score
    // 2. Use a lambda function to compare the k-th score of two students
    // 3. Return the sorted score vector
    vector<vector<int>> sortTheStudents(vector<vector<int>> &score, int k)
    {
        sort(score.begin(), score.end(), [&](const vector<int> &a, const vector<int> &b)
             { return a[k] > b[k]; });
        return score;
    }
};
