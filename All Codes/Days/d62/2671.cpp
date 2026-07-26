// Link: https://leetcode.com/problems/frequency-tracker/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(1) amortized per op
// SC: O(n) for the value->freq and freq->count maps
// Approach: track each number's current frequency (freq), and a reverse count
// of how many numbers currently sit at each frequency level (freq_cnt).
// add/deleteOne move a number's frequency by 1, decrementing the old bucket
// (erasing it if it hits 0) and incrementing the new one. hasFrequency is then
// just an O(1) lookup into freq_cnt.
class FrequencyTracker {
    unordered_map<int,int> freq;
    unordered_map<int,int> freq_cnt;
    void remove_freq(int f){
        if(--freq_cnt[f] == 0) freq_cnt.erase(f);
    }
public:
    FrequencyTracker() {

    }

    void add(int number) {
        if(!freq.count(number)){
            freq[number] = 1;
            ++freq_cnt[1];
        }
        else{
            int &f = freq[number];
            remove_freq(f);
            ++f;
            ++freq_cnt[f];
        }
    }

    void deleteOne(int number) {
        if(!freq.count(number)) return;
        int &f = freq[number];
        remove_freq(f);
        if(--f == 0) freq.erase(number);
        else ++freq_cnt[f];
    }

    bool hasFrequency(int frequency) {
        return freq_cnt.count(frequency);
    }
};
