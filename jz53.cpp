#include <string>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int l = 0 , r = n - 1;
        if( n == 1 )
            return nums[0] == 0 ? 1 : 0;
        if( nums[0] != 0 )
            return 0;
        while( l <= r ){
            int mid = ( l + r ) / 2;
            if( nums[mid] == mid )
                l = mid + 1;
            else if(  nums[mid - 1] == mid - 1 )
                return mid;
            else 
                r = mid - 1;
        }
        return l;
    }
};