#include <stack>
#include <vector>
#include <deque>
using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int l = 0 , r = height.size() - 1;
        int ret = 0;
        while( l < r ){
            int ans = min( height[l] , height[r] ) * ( r - l );
            ret = max( ret , ans );
            if( height[l] > height[r] )
                --r;
            else
                ++l;
        }
        return ret;
    }
};