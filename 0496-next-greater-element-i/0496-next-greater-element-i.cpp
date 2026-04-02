class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int>nextgreater;
        stack<int>st;
        for(int num:nums2){
            while(!st.empty() && st.top()<num){
                nextgreater[st.top()]=num;
                st.pop();
            }
            st.push(num);
        }
        while(!st.empty()){
            nextgreater[st.top()]=-1;
            st.pop();
        }
        int n=nums1.size();
        vector<int>result(n);
        for(int i=0;i<n;i++){
            result[i]=nextgreater[nums1[i]];
        }
        return result;
        
    }
};