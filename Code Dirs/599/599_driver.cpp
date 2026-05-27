#include <bits/stdc++.h>
using namespace std;

#include "599.cpp"

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        cin.ignore();
        vector<string> list1(n);
        for (int i = 0; i < n; i++) getline(cin, list1[i]);
        int m;
        cin >> m;
        cin.ignore();
        vector<string> list2(m);
        for (int i = 0; i < m; i++) getline(cin, list2[i]);
        Solution sol;
        auto res = sol.findRestaurant(list1, list2);
        for (int i = 0; i < (int)res.size(); i++) {
            if (i) cout << " ";
            cout << res[i];
        }
        cout << "\n";
    }
    return 0;
}
