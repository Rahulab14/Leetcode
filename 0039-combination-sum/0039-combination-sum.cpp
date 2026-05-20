class Solution {
public:

    void backtracking(vector<int>&candidates,int target,vector<int>&path,vector<vector<int>>&result,int index){
        if(target==0){
            result.push_back(path);
            return;
        }
        for(int i=index;i<candidates.size();i++){
            if(target<candidates[i]){
                continue;
            }
            path.push_back(candidates[i]);
            backtracking(candidates,target-candidates[i],path,result,i);
            path.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int>path;
        vector<vector<int>>result;
        backtracking(candidates,target,path,result,0);
        return result;
        
    }
};