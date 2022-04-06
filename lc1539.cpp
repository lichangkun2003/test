#include <numeric>
#include <algorithm>
#include <unordered_set>
#include <vector>

using namespace std;
class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int n = arr.size();
        int l = 0 , r = n - 1 , mid;
        int ans = 1;
        if( arr[0] > k )
            return k;
        while( l <= r ){
            mid = ( l + r ) / 2;
            if( arr[mid] < mid + k + 1 ){
                ans = mid + k + 1;
                l = mid + 1;
            }
            else
                r = mid - 1;
        }
        return ans;
    }
};
