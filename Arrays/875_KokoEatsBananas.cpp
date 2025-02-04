#include <algorithm>
#include <vector>

using namespace std;

/**
 * 875. Koko Eats Bananas
 * 
 * One of the more difficult Binary Search Problems
 * but I think I got it.
 */

class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        if (h == piles.size()) {
            return *max_element(piles.begin(), piles.end());
        }

        int l = 1, r = *max_element(piles.begin(), piles.end());
        
        while (l < r) {
            int mid = (l + r) / 2;

            int count = 0;
            // for each pile check how many hours it will take
            for (auto bananas : piles) {
                // calculate the ceiling and add it to count
                count += bananas / mid;
                int left = bananas % mid;

                count = left > 0 ? count + 1 : count;
            }
            // if we hit the hours OR it takes less hours
            // then Koko may have more time to eat bananas
            if (count <= h) {
                r = mid;
            }
            // otherwise if she takes to long she needs to eat fast
            else {
                l = mid + 1;
            }
        }
        return l;
    }
};