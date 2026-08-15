// Link: https://leetcode.com/problems/online-election/description/

#include <bits/stdc++.h>
using namespace std;

class TopVotedCandidate {
    vector<int> times;
    vector<int> leaders;
public:
    TopVotedCandidate(vector<int>& persons, vector<int>& times_) : times(times_) {
        unordered_map<int,int> count;
        int leader = -1;
        for (int p : persons) {
            count[p]++;
            if (leader == -1 || count[p] >= count[leader]) leader = p;
            leaders.push_back(leader);
        }
    }

    int q(int t) {
        int idx = upper_bound(times.begin(), times.end(), t) - times.begin() - 1;
        return leaders[idx];
    }
};
