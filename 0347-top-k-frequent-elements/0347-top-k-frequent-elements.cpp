class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> mp; //using unordered map to store freq
        for(int i:nums){
            mp[i]++;
        }

        priority_queue<pair<int,int>> mxhp;

        for(auto const& [num,count]: mp){ 
            mxhp.push({count,num}); //pushing count first so arrangement happens in the manner of frequency(descending)
        }
        vector<int> ans;

        for(int i=1; i<=k; i++){
            auto[count,num] = mxhp.top();
            mxhp.pop();
            ans.push_back(num);

        }
        return ans;


    }
};