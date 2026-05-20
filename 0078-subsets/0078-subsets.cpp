class Solution {
public:

    void backtracking(vector<int>&nums,vector<int>&path,vector<vector<int>>&result,int index){
        
        result.push_back(path);
        for(int i=index;i<nums.size();i++){
            path.push_back(nums[i]);
            backtracking(nums,path,result,i+1);
            path.pop_back();
        }
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int>path;
        vector<vector<int>>result;
        sort(nums.begin(),nums.end());
        backtracking(nums,path,result,0);
        return result;

        
    }
};