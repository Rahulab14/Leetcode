class Solution {
public:
    int maxValue(int n, int index, int maxSum) {
        int res=1;
        maxSum-=n;
        int left=0,right=0;
        int leftmax=index,rightmax=n-index-1;
        while(0<maxSum){
            res++;
            int leftmin=min(left,leftmax);
            int rightmin=min(right,rightmax);
            left++;
            right++;
            maxSum-=(leftmin+rightmin+1);
            if(leftmin==leftmax && rightmin==rightmax)break;


        }
        if(0<maxSum){
            res+=maxSum/n;
        }
        return (maxSum<0)?res-1:res;
        
    }
};