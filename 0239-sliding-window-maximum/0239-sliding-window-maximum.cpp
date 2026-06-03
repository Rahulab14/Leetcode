class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int>dp;
        vector<int>result;
        for(int i=0;i<nums.size();i++){
            if(!dp.empty()&&dp.front()==i-k){
                dp.pop_front();
            }
            while(!dp.empty()&&nums[dp.back()]<nums[i]){
                dp.pop_back();
            }
            dp.push_back(i);
            if(i>=k-1){
                result.push_back(nums[dp.front()]);
            }
        }
        return result;
    }
};