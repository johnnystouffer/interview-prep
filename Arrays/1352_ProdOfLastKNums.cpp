#include "../libraries.h"

using namespace std;

/**
 * 1382. Product of Last K Numbers
 * 
 * TODO: Review prefix and postfix
 * 
 * Very challenging but a good problem
 * I actually was mind blown by the solution lmao
 * TRY THIS ONE AGAIN
 */

class ProductOfNumbers {
public:
    int prod = 1;
    vector<int> imScared;
    ProductOfNumbers() {
    
    }
    
    void add(int num) {
        if (num == 0) {
            vector<int> restart;
            imScared = restart;
            prod = 1;
            return;
        }
        prod = prod * num;
        imScared.push_back(prod);
    }
    
    int getProduct(int k) {
        if (imScared.size() < k) { return 0; }
        int currProd = imScared[imScared.size() - 1];
        if (imScared.size() == k) { return currProd; }
        currProd /= imScared[imScared.size() - 1 - k];
        return currProd;
    }
};
    

/**
 * Second time is the charm!
 * 
 * I did not get it first try at first
 * however when debugging it and attempting
 * to figure it out.
 */

class ProductOfNumbers {
public:
    vector<int> nums;
    int prod = 1;
    ProductOfNumbers() {
    }
    
    void add(int num) {
        prod *= num;
        nums.push_back(prod);
        if (num == 0) {
            vector<int> newVector;
            nums = newVector;
            prod = 1;
        }
    }
    
    int getProduct(int k) {
        if (k > nums.size()) return 0;
        if (k == nums.size()) return nums[nums.size() - 1];
        int last = nums[nums.size() - 1];
        int first = nums[nums.size() - k - 1];
        return last / first;
    }
};
    
    /**
     * Your ProductOfNumbers object will be instantiated and called as such:
     * ProductOfNumbers* obj = new ProductOfNumbers();
     * obj->add(num);
     * int param_2 = obj->getProduct(k);
     */