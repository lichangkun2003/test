#include <string>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        if( !n )
            return -1;
        if( n == 1 )
            return nums[0] == target ? 0 : -1;
        int l = 0 , r = n - 1;
        while( l <= r ){
            int mid = ( l + r ) / 2;
            if( target == nums[mid] )
                return mid;
            if( nums[0] < nums[mid] ){
                if( target >= nums[0] && target <= nums[mid] )
                    r = mid -1;
                else
                    l =mid + 1;
            }
            else{
                if( target >= nums[mid] && target <= nums[r] )
                    l = mid + 1;
                else 
                    r = mid - 1;
            }
        }
        return  -1;
    }
};

// class Solution {
// public:
//     int binarysearch( vector<int>& nums , int l , int r , int target ){
//         while( l < r ){
//             int mid = ( l + r ) / 2;
//             if( target == nums[mid] )
//                 return mid;
//             if( target > nums[mid] )
//                 l = mid + 1;
//             else
//                 r = mid;
//         }
//         return -1;
//     }
//     int search(vector<int>& nums, int target) {
//         int n = nums.size();
//         if( n == 1 )
//             return nums[0] == target ? 0 : -1;
//         if( n == 2 )
//             return nums[0] == target ? 0 : ( nums[1] == target ? 1 : -1 );
//         int l = 0 , r = n - 1 , mid = ( l + r ) / 2;
//         while( mid > l && mid < r ){
//             if( nums[mid] >= nums[l] && nums[mid] <= nums[r] )
//                 break;
//             if( nums[mid] < nums[l] )
//                 r = mid;
//             else{
//                 l = mid ;
//             }
//             mid = ( l + r ) / 2;
//         }
//         int begin =  l + 1;
//         r = n - 1 , l = 0;
//         if( target >= nums[begin] && target <= nums[r] ){
//             return binarysearch( nums , begin , r ,target);
//         }
//         else {
//             return binarysearch( nums, l , begin - 1 , target);
//         }
        
//     }
// };
