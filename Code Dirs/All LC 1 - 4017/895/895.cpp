// Link: https://leetcode.com/problems/maximum-frequency-stack/description/

#include <bits/stdc++.h>
using namespace std;

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
