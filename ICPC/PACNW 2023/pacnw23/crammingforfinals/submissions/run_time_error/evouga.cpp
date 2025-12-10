#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <array>
#include <algorithm>
#include <utility>
#include <map>
#include <queue>
#include <set>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <functional>
#include <numeric>
#include <unordered_set>
#include <cassert>
#include <sstream>
#include <queue>
#include <bitset>
#include <random>

struct Node
{
    Node(int64_t ll, int64_t rr, int64_t bb, int64_t tt) : l(ll), r(rr), b(bb), t(tt)
    {
        left = right = NULL;
        overlaps = 0;
    }

    ~Node()
    {
        delete left;
        delete right;
    }

    void split()
    {
        assert(r - l > 0 || t - b > 0);
        if (r - l > t - b)
        {
            int64_t mid = l + (r - l) / 2;
            left = new Node(l, mid, b, t);
            right = new Node(mid + 1, r, b, t);
        }
        else
        {
            int64_t mid = b + (t - b) / 2;
            left = new Node(l, r, b, mid);
            right = new Node(l, r, mid + 1, t);
        }
    }

    void rasterize(int64_t x, int64_t y, int64_t D)
    {
        int engulfed = 0;
        if ((x - l) * (x - l) + (y - b) * (y - b) <= D * D)
            engulfed++;
        if ((x - l) * (x - l) + (y - t) * (y - t) <= D * D)
            engulfed++;
        if ((x - r) * (x - r) + (y - b) * (y - b) <= D * D)
            engulfed++;
        if ((x - r) * (x - r) + (y - t) * (y - t) <= D * D)
            engulfed++;
        if (engulfed == 4)
        {
            if (D == 0)
                overlaps += 5000; // infinity, to prevent placing beads on occupied squares
            else
                overlaps++;
        }
        else
        {
            bool isect = engulfed;
            if (l <= x && x <= r)
            {
                if (y <= t + D && y >= b - D)
                    isect = true;
            }
            if (b <= y && y <= t)
            {
                if (x <= r + D && x >= l - D)
                    isect = true;
            }
            if (isect)
            {
                if (!left)
                    split();
                left->rasterize(x, y, D);
                right->rasterize(x, y, D);
            }
        }
    }

    int countMinOverlaps()
    {
        if (!left)
            return overlaps;
        else
            return overlaps + std::min(left->countMinOverlaps(), right->countMinOverlaps());
    }

    int64_t l, r, b, t;
    Node* left, * right;
    int overlaps;
};

int fewestOverlaps(int64_t W, int64_t H, int64_t D, const std::vector<std::pair<int64_t, int64_t> >& beads)
{
    Node* root = new Node(1, W, 1, H);
    for (auto b : beads)
    {
        root->rasterize(b.first, b.second, D);
        root->rasterize(b.first, b.second, 0);
    }
    return root->countMinOverlaps();
}

int main()
{
    int64_t W, H;
    int64_t D;
    int N;
    std::cin >> W >> H >> D >> N;
    std::vector<std::pair<int64_t, int64_t> > beads(N);
    for (int i = 0; i < N; i++)
        std::cin >> beads[i].first >> beads[i].second;
    std::cout << fewestOverlaps(W, H, D, beads) << std::endl;
}
