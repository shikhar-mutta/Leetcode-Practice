#include <bits/stdc++.h>
using namespace std;

#include "88.cpp"


struct TeeBuf : std::streambuf {
    std::streambuf *orig, *echo;
    TeeBuf(std::streambuf* o, std::streambuf* e) : orig(o), echo(e) {}
    int_type uflow() override {
        int_type c = orig->sbumpc();
        if (c != traits_type::eof()) echo->sputc(c);
        return c;
    }
    int_type underflow() override { return orig->sgetc(); }
    std::streamsize xsgetn(char* s, std::streamsize n) override {
        std::streamsize got = orig->sgetn(s, n);
        echo->sputn(s, got);
        return got;
    }
};

int main() {
    int t;
    cin >> t;
    cin.ignore();
    cin.rdbuf(new TeeBuf(cin.rdbuf(), cerr.rdbuf()));
    while (t--) {
        struct Guard { ~Guard() { cerr << "\n---\n"; } } _guard;
        int m, n;
        cin >> m >> n;
        vector<int> nums1(m + n), nums2(n);
        for (int i = 0; i < m; i++) cin >> nums1[i];
        for (int i = 0; i < n; i++) cin >> nums2[i];
        Solution sol;
        sol.merge(nums1, m, nums2, n);
        for (int i = 0; i < m + n; i++) cout << nums1[i] << " \n"[i == m + n - 1];
        cout << "\n";
    }
    return 0;
}
