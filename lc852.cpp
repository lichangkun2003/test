#include <numeric>
#include <algorithm>
#include <unordered_set>
#include <vector>

using namespace std;
class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int n = arr.size();
        int l = 0 , r = n - 1 , mid;
        while( l <= r ){
            mid = l + ( r - l ) / 2;
            if( mid == 0 || mid == n - 1 )
                return mid == 0 ? 1 : n - 2;
            if( arr[mid - 1] < arr[mid] && arr[mid] > arr[mid + 1] )
                return mid;
            else if( arr[mid - 1] < arr[mid] && arr[mid] < arr[mid + 1] )
                l = mid + 1;
            else if( arr[mid - 1] > arr[mid] && arr[mid] > arr[mid + 1] )
                r = mid - 1;
        }
        return mid;
    }
};