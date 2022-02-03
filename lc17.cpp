#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
public:
    string tmp;
    vector<string> res;
    vector<string> board = { "" , "" , "abc" , "def" , "ghi" , "jkl" , "mno" , "pqrs" , "tuv" , "wxyz" };
    void dfs( string & digits , int flag ){
        if( flag == digits.size() ){
            res.push_back(tmp);
            return ;
        }
        int num = digits[flag] - '0';
        for( int i = 0 ; i < board[num].size() ; ++i ){
            tmp.push_back( board[num][i] );
            dfs( digits , flag + 1 );
            tmp.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        if( digits.empty() )
            return res;
        dfs( digits , 0 );
        return res;
    }
};