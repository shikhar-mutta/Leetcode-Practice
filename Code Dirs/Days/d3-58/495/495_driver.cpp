#include <bits/stdc++.h>
using namespace std;

#include "495.cpp"

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, duration;
        cin >> n >> duration;
        vector<int> timeSeries(n);
        for (int i = 0; i < n; i++)
            cin >> timeSeries[i];
        Solution sol;
        cout << sol.findPoisonedDuration(timeSeries, duration) << "\n";
    }
    return 0;
}
