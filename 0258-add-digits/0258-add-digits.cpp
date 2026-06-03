class Solution {
public:
    int addDigits(int num) {
        while(10<=num){
            int sum=0;
            while(0<num){
                sum+=num%10;
                num/=10;
            }
            num=sum;
        }
        return num;
        
    }
};