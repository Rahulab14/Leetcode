class Solution {
public:
void backtracking(string digits,string&path,vector<string>&result,vector<string>&board,int index){
    if(index==digits.length()){
        result.push_back(path);
        return;
    }
    string letters=board[digits[index]-'0'];
    for(char letter:letters){
        path.push_back(letter);
        backtracking(digits,path,result,board,index+1);
        path.pop_back();
    }
}
    vector<string> letterCombinations(string digits) {
        if(digits.length()==0)return {};
        string path;
        vector<string>result;
        vector<string>board={
            "","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"
        };
        backtracking(digits,path,result,board,0);
        return result;
    }
};