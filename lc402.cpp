#include <vector>
#include <algorithm>
#include <string>
using namespace std;

class Solution {
public:
    string removeKdigits(string num, int k) {
        vector<char> stk;
        for( auto& digit : num ){
            while( stk.size() > 0 && stk.back() > digit && k ){
                stk.pop_back();
                k--;
            }
            stk.push_back( digit );
        }
        for( ; k > 0 ; k-- )
            stk.pop_back();
        string ans = "";
        bool isleadingzero = true;
        for( auto & digit : stk ){
            if( isleadingzero && digit == '0' )
                continue;
            isleadingzero = false;
            ans += digit;
        }
        return ans == "" ? "0" : ans;
    }
};