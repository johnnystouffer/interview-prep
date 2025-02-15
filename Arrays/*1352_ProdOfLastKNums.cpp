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
    