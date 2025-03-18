#include "../libraries.h"

using namespace std;

/**
 * Initial Attempt:
 * 
 * Pretty good actually! I did some things not so well but otherwise I am
 * pretty happy since I only had a little bit of an idea but I ended up not
 * only completing it, but in a good amount of time, and it is pretty optimal!
 */

class Solution {
 public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        // Create the final vector to store all of the valid entries
        // and make the current vector so we can use to get every single entry
        vector<vector<int>> finalVec;
        vector<int> curr;

        // call the recursive back tracking function and then return the final
        currCombination(candidates, curr, finalVec, 0, target);
        return finalVec;
    }
    
    void currCombination(vector<int>& c, vector<int>& curr, vector<vector<int>>& finalVec, int i, int target) {
        // calculate the sum and if it is either A. the target, then we add it and return
        // since it is impossible to add more to get to the target.
        // additionally we see if it is over the target, if so then don't add it to the 
        // vector, just get rid of it.
        int currSum = accumulate(curr.begin(), curr.end(), 0);
        if (currSum == target) { finalVec.push_back(curr); return; } 
        if (currSum > target || i >= c.size()) { return; }

        curr.push_back(c[i]);
        currCombination(c, curr, finalVec, i, target);
        curr.pop_back();
        currCombination(c, curr, finalVec, i+1, target);
    }
};

/**
 * IMPROVED 
 * 
 * The only real differnece is we keep track of the 
 * remaining value, avoiding accumulation and stuff
 */

class Solution {
 public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> finalVec;
        vector<int> curr;
        currCombination(candidates, curr, finalVec, 0, target, target);
        return finalVec;
    }

    void currCombination(vector<int>& c, vector<int>& curr, vector<vector<int>>& finalVec, int i, int target, int remaining) {
        if (remaining == 0) { finalVec.push_back(curr); return; } 
        if (remaining < 0 || i >= c.size()) { return; }

        curr.push_back(c[i]);
        currCombination(c, curr, finalVec, i, target, remaining - c[i]);
        curr.pop_back();
        currCombination(c, curr, finalVec, i+1, target, remaining);
    }
};