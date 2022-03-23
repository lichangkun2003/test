#include <string>
#include <algorithm>
#include <unordered_set>

using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int l = 0 , r = n - 1 , mid = ( l + r ) / 2;
        if( n == 0 )
            return 0;
        while( l <= r ){
            mid = ( l + r ) / 2;
            if( nums[mid] == target )
                break;
            else if( nums[mid] < target )
                l = mid + 1;
            else  
                r = mid - 1;
        }
        int ans = 0;
        if( nums[mid] == target ){
            int index = mid;
            while( index < n && nums[index] == target ){
                ans++;
                index++;
            }
            index = mid - 1;
            while( index >= 0 && nums[index] == target ){
                ans++;
                index--;
            }
        }
        return ans;
    }
};