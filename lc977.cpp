#include <stack>
#include <vector>
#include <deque>
using namespace std;

class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size();
        int i = -1;
        while( nums[ i + 1 ] < 0 )
            ++i;
        if( i < 0 )
            return nums;
        int j = i + 1 , k = -1;
        vector<int> ans(n);
        while( i >= 0 && j < n ){
            if( nums[i] * nums[i] <= nums[j] * nums[j] ){
                ans[++k] = nums[i] * nums[i];
                i--;
            }
            else{
                ans[++k] = nums[j] * nums[j];
                j++;
            }  
        }
        while( i >= 0 ){
            ans[++k] = nums[i] * nums[i];
            --i;
        }
        while( j < n ){
            ans[++k] = nums[j] * nums[j]; 
            j++;
        }
        return ans;
    }
};