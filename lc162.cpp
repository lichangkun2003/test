#include <numeric>
#include <algorithm>
#include <unordered_set>
#include <vector>

using namespace std;
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();
        int l = 0 , r = n - 1 , mid ;
        auto get = [&]( int i ) ->pair<int , int >{
            if( i == -1 || i == n )
                return { 0 , 0 };
            else
                return{ 1 , nums[i] };
        };
        while( l <= r ){
            mid = ( l + r ) / 2;
            if( get(mid) > get( mid + 1 ) && get( mid ) > get( mid - 1 ) )
                break;
            if( get( mid ) < get( mid + 1)  )
                l = mid + 1;
            else
                r = mid - 1;
        }
        return mid;
    }
};