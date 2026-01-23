class Solution {
public:
    void isfound(string s,int& start,int& end,int left,int right){
        while(0<=left && right<s.length() && s[left]==s[right]){
            left--;
            right++;
        }
        int maxlen=right-left-1;
        if(end<maxlen){
            start=left+1;
            end=maxlen;
        }
    }
    string longestPalindrome(string s) {
        if(s.length()==0)return {};
        int start=0,end=0;
        for(int i=0;i<s.length();i++){
            isfound(s,start,end,i,i);
            isfound(s,start,end,i,i+1);

        }
        return s.substr(start,end);
        
    }
};