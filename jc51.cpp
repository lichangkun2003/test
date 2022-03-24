#include <string>
#include <algorithm>
#include <vector>

using namespace std;
class Solution {
public:
    int mergesort( vector<int>& nums , vector<int>& tmp , int l , int r ){
        if( l >= r )
            return 0;
        int mid = ( l + r ) / 2;
        int count = mergesort( nums , tmp , l , mid ) + mergesort( nums,  tmp , mid + 1 , r);
        int i = l , j = mid + 1 , index = l ;
        while( i <= mid && j <= r ){
            if( nums[i] <= nums[j] ){
                tmp[index] = nums[i];
                ++i;
                count += (j - (mid + 1));
            }
            else{
                tmp[index] = nums[j];
                ++j;
            }
            index++;
        }
        for( int k = i ; k <= mid ; ++k ){
            tmp[index++] = nums[k];
            count += (j - (mid + 1));
        }
        for( int k = j ; k <= r ; ++k )
            tmp[index++] = nums[k];
        copy( tmp.begin() + l , tmp.begin() + r + 1 , nums.begin() + l );
        return count;
    }
    int reversePairs(vector<int>& nums) {
        int n = nums.size();
        vector<int> tmp( n );
        return mergesort( nums , tmp , 0 , n - 1 );
    }
};