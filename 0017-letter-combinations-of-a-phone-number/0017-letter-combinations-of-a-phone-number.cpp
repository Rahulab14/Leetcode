class Solution {
public:

    void backtracking(string digits,string&path,vector<string>&result,vector<string>&mapping,int index){
        if(index==digits.length()){
            result.push_back(path);
            return;
        }
        string letters=mapping[digits[index]-'0'];
        for(char letter:letters){
            path.push_back(letter);
            backtracking(digits,path,result,mapping,index+1);
            path.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        if(digits.length()==0){
            return {};
        }
        string path;
        vector<string>result;
        vector<string>mapping={
            "","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"
        };
        backtracking(digits,path,result,mapping,0);
        return result;
        
    }
};