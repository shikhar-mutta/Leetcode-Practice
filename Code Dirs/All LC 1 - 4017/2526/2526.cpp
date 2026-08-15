// Link: https://leetcode.com/problems/find-consecutive-integers-from-a-data-stream/description/

#include <bits/stdc++.h>
using namespace std;

class DataStream {
    int value, k;
    deque<int> window;
    int matchCount;
public:
    DataStream(int value, int k) : value(value), k(k), matchCount(0) {}

    bool consec(int num) {
        window.push_back(num);
        if (num == value) matchCount++;
        if ((int)window.size() > k) {
            if (window.front() == value) matchCount--;
            window.pop_front();
        }
        return (int)window.size() == k && matchCount == k;
    }
};
