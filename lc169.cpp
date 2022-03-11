#include <string>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        sort( nums.begin() , nums.end() );
        int n = nums.size();
        int mid = n / 2 ;
        if( n == 1 )
            return nums[0];
        return nums[mid - 1 ] == nums[mid] ? nums[mid] : nums[mid+1];
    }
};