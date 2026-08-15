// Link: https://leetcode.com/problems/frequency-tracker/description/

#include <bits/stdc++.h>
using namespace std;

class FrequencyTracker {
    unordered_map<int,int> freq;
    unordered_map<int,int> freqCount;
public:
    FrequencyTracker() {}

    void add(int number) {
        int f = freq[number];
        if (f > 0) freqCount[f]--;
        freq[number] = f + 1;
        freqCount[f+1]++;
    }

    void deleteOne(int number) {
        auto it = freq.find(number);
        if (it == freq.end() || it->second == 0) return;
        int f = it->second;
        freqCount[f]--;
        freq[number] = f - 1;
        if (f - 1 > 0) freqCount[f-1]++;
    }

    bool hasFrequency(int frequency) {
        return freqCount[frequency] > 0;
    }
};
