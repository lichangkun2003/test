#include <stack>
#include <vector>
using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        stack<int> stk;
        int n = height.size() , ans = 0;
        for( int i = 0 ; i < n ; ++i ){
            while( !stk.empty() && height[i] > height[stk.top()] ){
                int top = stk.top();
                stk.pop();
                if( stk.empty() )
                    break;
                int left = stk.top();
                int width = i - left - 1;
                int heigh = min( height[i] , height[left] ) - height[top];
                ans += width * heigh;
            }
            stk.push( i );
        }
        return ans;
    }
};