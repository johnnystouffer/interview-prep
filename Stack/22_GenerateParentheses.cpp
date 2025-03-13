#include "../libraries.h"

using namespace std;

/**
 * 22. Generating Parentheses
 * 
 * Below was my brute force way of doing this, I know there is a way to do it with a stack
 * but this way felt a lot more intuitive to me, the time complexity is up to 2^n which is REALLY 
 * bad so I will say which one is better.
 */

class Solution {
 public:
    vector<string> generateParenthesis(int n) {
        vector<string> v;
        string curr = "(";
        findPermutations(v, curr, 1, 0, n);    
        return v;    
    }

    void findPermutations(vector<string>& v, string curr, int currOpen, int currClosed, int n) {        
        if (curr.size() == 2*n && currOpen == n && currClosed == n) {
            v.push_back(curr);
            return;
        }
        if (currOpen < n) {
            findPermutations(v, curr + "(", currOpen + 1, currClosed, n);
        }
        if (currClosed < currOpen) {
            findPermutations(v, curr + ")", currOpen, currClosed + 1, n);
        }
    }
};

/**
 * GOOD NEWS IT WAS OPTIMAL WOOOOOOOOOOOO
 * 
 * The only thing I would reccomend for next time is do back track, that way you do not need to allocate more memory
 * to the stack for every little thing that happens. So yeah, that & is very powerful though.
 */

class Solution {
 public:
    vector<string> generateParenthesis(int n) {
        vector<string> v;
        string curr = "(";
        findPermutations(v, curr, 1, 0, n);    
        return v;    
    }

    void findPermutations(vector<string>& v, string& curr, int currOpen, int currClosed, int n) {        
        if (curr.size() == 2*n && currOpen == n && currClosed == n) {
            v.push_back(curr);
            return;
        }
        if (currOpen < n) {
            curr.push_back('(');
            findPermutations(v, curr, currOpen + 1, currClosed, n);
            curr.pop_back();
        }
        if (currClosed < currOpen) {
            curr.push_back(')');
            findPermutations(v, curr, currOpen, currClosed + 1, n);
            curr.pop_back();
        }
    }
};