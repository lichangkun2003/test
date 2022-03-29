#include <numeric>
#include <algorithm>
#include <unordered_set>
#include <vector>

using namespace std;
class Solution {
public:
    int mySqrt(int x) {
        int ans = -1;
        int l = 0 , r = x , mid;
        while( l <= r ){
            mid = ( l + r ) / 2;
            if( (long long ) mid * mid <= x ){
                ans = mid;
                l = mid + 1;
            }
            else
                r = mid - 1;
        }
        return ans;
    }
};