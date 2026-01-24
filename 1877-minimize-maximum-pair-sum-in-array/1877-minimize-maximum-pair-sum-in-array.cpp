class Solution {
public:
    int minPairSum(vector<int>& arr) {
        sort(arr.begin(),arr.end());
        int i=0;
        int j=arr.size()-1;

        int sum=0;
        while(i<j){
            int pair=arr[i]+arr[j];
            sum=max(sum,pair);
            i++;
            j--;
        }   
        return sum;
    }
};