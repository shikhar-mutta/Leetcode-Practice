// Link: https://leetcode.com/problems/online-election/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n + q * log n), where n is the number of votes and q is the number of queries.
// SC: O(n), where n is the number of votes.
// Approach:
//   1. We maintain two vectors: times and leaders. The times vector stores the times at which votes were cast, and the leaders vector stores the leading candidate at each corresponding time.
//   2. In the constructor, we iterate through the persons and times vectors to populate the leaders vector. We use an unordered_map to keep track of the vote count for each candidate and update the leader whenever a candidate receives a vote that makes them the new leader or ties with the current leader.
//   3. In the q function, we use binary search (upper_bound) to find the index of the largest time that is less than or equal to the given time t. We then return the leader at that index from the leaders vector.
class TopVotedCandidate
{
    vector<int> times;
    vector<int> leaders;

public:
    TopVotedCandidate(vector<int> &persons, vector<int> &times)
    {
        this->times = times;
        unordered_map<int, int> count;
        int leader = -1;
        for (int i = 0; i < (int)persons.size(); i++)
        {
            count[persons[i]]++;
            if (leader == -1 || count[persons[i]] >= count[leader])
                leader = persons[i];
            leaders.push_back(leader);
        }
    }

    int q(int t)
    {
        int idx = upper_bound(times.begin(), times.end(), t) - times.begin() - 1;
        return leaders[idx];
    }
};
