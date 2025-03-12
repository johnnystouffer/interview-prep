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


/**
 * Quick Select Version:
 * 
 * This way the average will be O(n)
 * technically the worst it will be is O(n^2)
 * but this should be fine
 */

class Solution {
    public:
        int findKthLargest(vector<int>& nums, int k) {
            return quickSelect(nums, k);
        }
    
        int quickSelect(vector<int>& nums, int k) {
            int pivot = nums[rand() % nums.size()];
    
            vector<int> left;
            vector<int> right;
            vector<int> mid;
    
            for (int num : nums) {
                if (num > pivot) {
                    left.push_back(num);
                }
                else if (num < pivot) {
                    right.push_back(num);
                }
                else {
                    mid.push_back(num);
                }
            }
    
            if (k <= left.size()) {
                return quickSelect(left, k);
            }
            
            if (left.size() + mid.size() < k) {
                return quickSelect(right, k - left.size() - mid.size());
            }
    
            return pivot;
        }
    };