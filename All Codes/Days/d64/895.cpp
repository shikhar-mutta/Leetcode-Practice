// Link: https://leetcode.com/problems/maximum-frequency-stack/description/

#include <bits/stdc++.h>
using namespace std;

// Added
// TC: O(1) amortized per op  SC: O(n)
// Approach: track freq[val] and, for each frequency level, a stack of
// values that reached that frequency (group[freq]) in push order, plus
// the current max frequency. push increments freq and appends to the
// new frequency's group; pop removes from the top group at maxFreq,
// decrementing maxFreq if that group becomes empty.
class FreqStack {
    unordered_map<int,int> freq;
    unordered_map<int, vector<int>> group;
    int maxFreq = 0;
public:
    FreqStack() {}

    void push(int val) {
        int f = ++freq[val];
        maxFreq = max(maxFreq, f);
        group[f].push_back(val);
    }

    int pop() {
        int val = group[maxFreq].back();
        group[maxFreq].pop_back();
        freq[val]--;
        if (group[maxFreq].empty()) maxFreq--;
        return val;
    }
};
