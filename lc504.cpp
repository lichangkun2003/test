#include <string>
#include <algorithm>
#include <cmath>

using namespace std;

class Solution {
public:
    string convertToBase7(int num) {
        if( num == 0 )
            return "0";
        bool negative = num < 0;
        num = abs( num );
        string ans;
        while( num ){
            ans.push_back( num % 7 + '0' );
            num /= 7;
        }
        if( negative )
            ans.push_back( '-' );
        reverse( ans.begin() , ans.end() );
        return ans;
    }
};