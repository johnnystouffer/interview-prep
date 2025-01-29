#include <vector>
using namespace std;

/**
 * 153. Find Minimum in Rotated Sorted Array
 * 
 * This one stumped me at first, however I
 * realized you can also look at the values
 * of r and l and NOT just m, game changer 
 * fr.
 */

class Solution {
public:
    int findMin(vector<int>& nums) {
        // get the size of the nums and mid
        int n = nums.size();
        int l = 0, r = n - 1;
        int m;

        // loop through (binary search)
        while (l < r) {
            // find the middle value
            m = l + (r - l) / 2;
            
            if (nums[m] <= nums[r]) {
                r = m;
            }
            else {
                l = m + 1;
            }
        }
        return nums[l];
    }
};