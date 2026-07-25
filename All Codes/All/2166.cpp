// Link: https://leetcode.com/problems/design-bitset/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(1) for fix/unfix/flip/all/one/count (all() and one() are checks
//     against maintained counters, not scans); O(n) for toString
// SC: O(n)
// Approach: maintain the "real" 0/1 string plus a lazy global flips parity
// and running cnt0/cnt1 counts. flip() just toggles the parity flag in
// O(1) instead of touching every bit. fix/unfix on the underlying str only
// need to act when the OTHER logical value is already stored (accounting
// for the current flip parity), keeping cnt0/cnt1 in sync; all queries
// (all/one/count/toString) reinterpret cnt0/cnt1/str through the current
// flip parity to report the logical bitset state.
class Bitset {
public:
    string str = "";
    int flips = 0, cnt0, cnt1;
    Bitset(int size) {
        for (int i = 0; i < size; i++)
            str += '0';
        cnt0 = size;
        cnt1 = 0;
    }

    void fix(int idx) {
        if (flips == 0) {
            if (str[idx] == '0') {
                cnt1++;
                cnt0--;
                str[idx] = '1';
            }
        } else {
            if (str[idx] == '1') {
                str[idx] = '0';
                cnt1--;
                cnt0++;
            }
        }
    }

    void unfix(int idx) {
        if (flips == 0) {
            if (str[idx] == '1') {
                cnt1--;
                cnt0++;
                str[idx] = '0';
            }
        } else {
            if (str[idx] == '0') {
                str[idx] = '1';
                cnt1++;
                cnt0--;
            }
        }
    }

    void flip() { flips = (flips + 1) % 2; }

    bool all() {
        if (flips == 0) {
            if (cnt1 == str.size())
                return true;
            return false;
        } else {
            if (cnt0 == str.size())
                return true;
            return false;
        }
    }

    bool one() {
        if (flips == 0) {
            if (cnt1 > 0)
                return true;
            return false;
        } else {
            if (cnt0 > 0)
                return true;
            return false;
        }
    }

    int count() {
        if (flips == 0)
            return cnt1;
        return cnt0;
    }

    string toString() {
        if (flips == 0)
            return str;
        string ans = "";
        for (int i = 0; i < str.size(); i++) {
            if (str[i] == '0')
                ans += '1';
            else
                ans += '0';
        }
        return ans;
    }
};
