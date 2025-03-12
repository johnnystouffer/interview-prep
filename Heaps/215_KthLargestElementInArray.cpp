#include "../libraries.h"

using namespace std;

/**
 * 215. Kth Largest Element in an Array
 * 
 * This one the first intuition was a HEAP, so that is what I implemented 
 * below, however a better way (on average) is actually QuickSelect
 */

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int> q;
        for (int num : nums) {
            q.push(num);
        }
        int finalVar;
        for (int i = 0; i < k; i++) {
            finalVar = q.top(); 
            q.pop();
        }
        return finalVar;
    }
};

