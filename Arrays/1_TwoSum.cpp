#include <vector>
#include <unordered_map>

using namespace std;

/**
 * 1. Two Sum
 * 
 * I have decided to start using C++ as my leetcode language!
 * Why would I do such a thing? Well the truth is although python
 * is more intuitive, C++ actually makes the harder problems easier
 * thanks to the STL.
 * 
 * Also because I want to be a cracked dev, and cracked devs do not
 * use python.
 * 
 * Overall we all know Two Sum, I just wanted to do this to start going
 * in C++. Wish me luck!
 */

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // make local variables for answer and the hashmap to store
        vector<int> answer;
        unordered_map<int, int> hashMap;

        // loop through each item and its index
        for (int i = 0; i < nums.size(); i++) {

            // see what the complement is
            int newSum = target - nums[i];

            // if the complement is in the hashtable we found the pair
            if (hashMap.find(newSum) != hashMap.end()) {
                answer.push_back(hashMap[newSum]);
                answer.push_back(i);
                return answer;
            }
            else {
                hashMap[nums[i]] = i;
            }   
        }
        return answer;
    }
};

/**
 * Second try
 */

class Solution {
    public:
        vector<int> twoSum(vector<int>& nums, int target) {
            vector<int> answer;
            unordered_map<int, int> hashMap;
    
            for (int i = 0; i < nums.size(); i++) {
                int complement = target - nums[i];
                if (hashMap.find(complement) != hashMap.end()) {
                    answer.push_back(hashMap[complement]);
                    answer.push_back(i);
                    return answer;
                }
                hashMap[nums[i]] = i;
            }
            return answer;
        }
    };