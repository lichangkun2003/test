#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
public:
    int sumOfUnique(vector<int>& nums) {
        int flag[101] = {0};
        int res = 0;
        for( int i = 0 ; i < nums.size() ; ++i ){
            //若flag为0 ， 说明未出现，相加
            if( !flag[ nums[i] ] ){
                flag[ nums[i] ] = 1;
                res += nums[i];
            }
            //flag为1，已出现过
            else if( flag[ nums[i] ] == 1 ){
                res -= nums[i];
                flag[ nums[i] ] ++;
            }
        }
        return res;
    }
};