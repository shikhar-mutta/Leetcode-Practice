// Link: https://leetcode.com/problems/average-waiting-time/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(n) where n is the number of customers.
    // SC: O(1) as we are using constant space.
    // Approach:
    //    1. Initialize two variables, free and total, to keep track of the time when the chef is free and the total waiting time of all customers.
    //    2. Iterate through each customer in the customers vector.
    //    3. For each customer, update the free time to be the maximum of the current free time and the arrival time of the customer, plus the time taken to prepare the order.
    //    4. Calculate the waiting time for the current customer as the difference between the free time and the arrival time, and add it to the total waiting time.
    //    5. After processing all customers, return the average waiting time by dividing the total waiting time by the number of customers.
    double averageWaitingTime(vector<vector<int>> &customers)
    {
        long long free = 0, total = 0;
        for (auto &c : customers)
        {
            free = max(free, (long long)c[0]) + c[1];
            total += free - c[0];
        }
        return (double)total / customers.size();
    }
};