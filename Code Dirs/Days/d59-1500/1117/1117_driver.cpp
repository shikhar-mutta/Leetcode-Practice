#include <bits/stdc++.h>
using namespace std;
#include "1117.cpp"

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        string water;
        getline(cin, water);
        if (!water.empty() && water.front()=='"' && water.back()=='"')
            water = water.substr(1, water.size()-2);

        H2O h2o;
        mutex outMtx;
        string result;
        vector<thread> threads;
        threads.reserve(water.size());
        for (char c : water) {
            if (c == 'H') {
                threads.emplace_back([&]() {
                    h2o.hydrogen([&]() {
                        lock_guard<mutex> lock(outMtx);
                        result += 'H';
                    });
                });
            } else {
                threads.emplace_back([&]() {
                    h2o.oxygen([&]() {
                        lock_guard<mutex> lock(outMtx);
                        result += 'O';
                    });
                });
            }
        }
        for (auto& th : threads) th.join();

        bool ok = result.size() == water.size();
        for (size_t i = 0; ok && i + 3 <= result.size(); i += 3) {
            int h = 0, o = 0;
            for (int k = 0; k < 3; k++) {
                if (result[i+k] == 'H') h++; else o++;
            }
            if (h != 2 || o != 1) ok = false;
        }
        cout << (ok ? "PASS" : "FAIL") << "\n";
    }
    return 0;
}
