class Solution {
public:

    void backtracking(vector<int>&nums,vector<int>&current,vector<vector<int>>&result,vector<bool>&used){
        if(current.size()==nums.size()){
            result.push_back(current);
            return;
        }
        for(int i=0;i<nums.size();i++){
            if(used[i]){
                continue;
            }
            if(0<i && nums[i]==nums[i-1] && !used[i-1]){
                continue;
            }
            used[i]=true;
            current.push_back(nums[i]);
            backtracking(nums,current,result,used);
            current.pop_back();
            used[i]=false;

        }

    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<int>current;
        vector<vector<int>>result;
        vector<bool>used(nums.size(),false);
        backtracking(nums,current,result,used);
        return result;
        
    }
};