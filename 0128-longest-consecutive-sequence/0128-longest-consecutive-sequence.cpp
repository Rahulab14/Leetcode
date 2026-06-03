class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> numset(nums.begin(), nums.end());
        int maxlength = 0;
        int n = nums.size();
        for (int num : numset) {
            if (numset.find(num - 1) == numset.end()) {
                int currentnum = num;
                int currentstreak = 1;
                while (numset.find(currentnum + 1) != numset.end()) {
                    currentnum += 1;
                    currentstreak += 1;
                }
                maxlength = max(maxlength, currentstreak);
            }
        }
        return maxlength;
    }
};