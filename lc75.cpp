#include <stack>
#include <vector>
#include <deque>
using namespace std;

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        int i = -1 , j = n , k = 0;
        if( n == 1 )
            return;
        if( n == 2 ){
            if( nums[0] > nums[1] ){
                int tmp = nums[0];
                nums[0] = nums[1];
                nums[1] = tmp;
            }
            return ;
        }
        while( k < j && i <= j ){
            while( k > i && k < j && nums[k] != 1 ){
                if( nums[k] == 0 ){
                    int tmp = nums[++i];
                    nums[i] = nums[k];
                    nums[k] = tmp;
                }
                if( nums[k] == 2 ){
                    int tmp = nums[--j];
                    nums[j] = nums[k];
                    nums[k] = tmp;
                }
            }
            if( nums[k] == 1 || k == i )
                k++;
        }
    }
};