#include <vector>

using namespace std;

/**
 * 704. Binary Search
 * 
 * This vs Python is almost the exact same
 * like very little syntax difference at all
 * so this felt very intuitive.
 */

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0, r = nums.size()-1;
        int mid;

        while (l <= r) {
            mid = l + (r-l) / 2;

            if (nums[mid] == target) {
                return mid;
            }
            else if (nums[mid] > target) {
                r = mid - 1;
            }
            else {
                l = mid + 1;
            }
        }
        return -1;
    }
};