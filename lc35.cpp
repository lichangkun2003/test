#include <string>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int n = nums.size() , l = 0 , r = n - 1;
        while( l <= r ){
            int mid = ( l + r ) / 2;
            if( nums[mid] == target )
                return mid;
            else if( nums[mid] < target )
                l = mid ;
            else
                r = mid - 1;
        }
        return nums[l] < target ? l + 1 : l - 1;
    }
};