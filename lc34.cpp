#include <string>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size() , l = 0 , r = n - 1;
        vector<int> ans= { -1 , -1 };
        while( l <= r ){
            int mid = ( l + r ) / 2;
            if( nums[mid] == target ){
                int tmp = mid;
                tmp++;
                while( tmp < n && nums[tmp] == target )
                    tmp++;
                ans[1] = tmp - 1;
                mid--;
                while( mid >= 0 && nums[mid] == target )
                    mid--;
                ans[0] = mid + 1;
                return ans;
            }
            else if( nums[mid] < target )
                l = mid + 1;
            else
                r = mid - 1;
                
        }
        return ans;

    }
};