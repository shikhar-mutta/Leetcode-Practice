// Link: https://leetcode.com/problems/count-submatrices-with-equal-frequency-of-x-and-y/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(rows*cols), SC: O(cols)
// Approach: For every top-left-anchored submatrix (0,0)-(r,c), track running
// (X-count - Y-count) and whether any X/Y was seen, via 2D prefix sums
// folded into a packed bitfield struct (`t` biased count, `f` "has any
// letter" flag) combined by adding column-prefix `g[x]` and row-prefix `s`.
// A submatrix is valid iff it contains at least one X/Y and counts are equal
// (t == kBias); count how many of the (r,c) corners satisfy this.
using u16 = uint16_t;
using u32 = uint32_t;

constexpr u32 kMaxW = 1024;
constexpr u32 kBias = kMaxW * kMaxW;

struct Meow {
    u32 t : 31 = kBias;
    u32 f : 1 = 0;

    [[gnu::always_inline]] Meow& operator+=(const Meow& rhs) noexcept {
        f |= rhs.f;
        t += rhs.t - kBias;
        return *this;
    }

    // NOLINTNEXTLINE
    [[gnu::always_inline, nodiscard]] operator bool() const noexcept {
        return f & (t == kBias);
    }
};

class Solution {
public:
    int numberOfSubmatrices(vector<vector<char>>& orig) {
        Meow g[kMaxW];

        const u16 w = static_cast<u16>(orig[0].size());
        std::fill_n(g, w, Meow{});

        u32 r = 0;

        for (auto& row : orig) {
            Meow s{};
            for (u16 x = 0; x != w; ++x) {
                auto& v = g[x];
                char c = row[x];
                bool is_x = c == 'X', is_y = c == 'Y';
                v += s += Meow{
                    .t = kBias + is_x - is_y,
                    .f = is_x || is_y,
                };
                r += !!v;
            }
        }

        return r;
    }
};
