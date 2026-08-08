// Link: https://leetcode.com/problems/statistics-from-a-large-sample/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<double> sampleStats(vector<int>& count) {
        double minVal = -1, maxVal = -1;
        long long total = 0;
        double sum = 0;
        for (int i = 0; i < 256; i++) {
            if (count[i] == 0) continue;
            if (minVal == -1) minVal = i;
            maxVal = i;
            total += count[i];
            sum += (double)i * count[i];
        }
        double mean = sum / total;

        int mode = 0;
        for (int i = 0; i < 256; i++) if (count[i] > count[mode]) mode = i;

        long long half = total / 2;
        double median;
        if (total % 2 == 1) {
            long long acc = 0;
            for (int i = 0; i < 256; i++) {
                acc += count[i];
                if (acc > half) { median = i; break; }
            }
        } else {
            long long acc = 0;
            int first = -1, second = -1;
            for (int i = 0; i < 256; i++) {
                acc += count[i];
                if (first == -1 && acc >= half) first = i;
                if (acc >= half + 1) { second = i; break; }
            }
            median = (first + second) / 2.0;
        }

        return {minVal, maxVal, mean, median, (double)mode};
    }
};
