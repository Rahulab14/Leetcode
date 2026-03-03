#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> result(n, -1);
        stack<int> st;  // stores indices
        
        for (int i = 2*n - 1; i >= 0; i--) {
            int idx = i % n;
            
            while (!st.empty() && nums[st.top()] <= nums[idx]) {
                st.pop();
            }
            
            if (i < n) {  
                if (!st.empty()) {
                    result[idx] = nums[st.top()];
                }
            }
            
            st.push(idx);
        }
        
        return result;
    }
};