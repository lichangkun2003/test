#include <vector>
#include <algorithm>
#include <string>
using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size() , MAX = 0 ;
        for( int i = 0 ; i < n ; ++i ){
            if( MAX < i )
                return false;
            MAX = max( MAX , nums[i] + i );
            if( MAX >= n - 1 )
                return true;
        }
        return false;
    }
};