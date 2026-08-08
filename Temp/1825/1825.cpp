// Link: https://leetcode.com/problems/finding-mk-average/description/

#include <bits/stdc++.h>
using namespace std;

class MKAverage {
public:
    int m, k;
    deque<int> window;
    multiset<int> low, mid, high;
    long long sumMid = 0;

    MKAverage(int m_, int k_) : m(m_), k(k_) {}

    void rebalance() {
        while ((int)low.size() > k) {
            auto it = prev(low.end());
            mid.insert(*it); sumMid += *it; low.erase(it);
        }
        while ((int)high.size() > k) {
            auto it = high.begin();
            mid.insert(*it); sumMid += *it; high.erase(it);
        }
        while ((int)low.size() < k && !mid.empty()) {
            auto it = mid.begin();
            low.insert(*it); sumMid -= *it; mid.erase(it);
        }
        while ((int)high.size() < k && !mid.empty()) {
            auto it = prev(mid.end());
            high.insert(*it); sumMid -= *it; mid.erase(it);
        }
    }

    void addElement(int num) {
        window.push_back(num);
        if ((int)low.size() < k) low.insert(num);
        else if (!low.empty() && num <= *prev(low.end())) low.insert(num);
        else if (!high.empty() && num >= *high.begin()) high.insert(num);
        else { mid.insert(num); sumMid += num; }

        if ((int)window.size() > m) {
            int old = window.front(); window.pop_front();
            if (low.count(old)) low.erase(low.find(old));
            else if (high.count(old)) high.erase(high.find(old));
            else { mid.erase(mid.find(old)); sumMid -= old; }
        }
        rebalance();
    }

    int calculateMKAverage() {
        if ((int)window.size() < m) return -1;
        return (int)(sumMid / (m - 2 * k));
    }
};
