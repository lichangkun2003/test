#include <iostream>
#include <vector>
#include <time.h>

using namespace std;


class Solution {
public:
    int partition( vector<int>& nums , int l , int r ){
        int x = nums[r] , i = l - 1;
        for( int j = l ; j < r ; ++j ){
            if( nums[j] < x ){
                ++i ;
                swap( nums[i] , nums[j] );
            }
        }
        swap( nums[i+1] , nums[r] );
        return i + 1;
    }
    int randomPartition( vector<int>& nums , int l , int r ){
        int i = rand() % ( r - l + 1 ) + l ;
        swap( nums[i] , nums[r] );
        return partition( nums , l , r );
    }
    int quickSelect( vector<int>& nums , int l , int r , int index ){
        int q = randomPartition( nums , l , r );
        if( q == index )
            return nums[q];
        else{
            return q < index ? quickSelect( nums , q + 1 , r , index ) : quickSelect( nums , l , q - 1 , index );
        }
    }

    int findKthLargest(vector<int>& nums, int k) {
        srand(time(0));
        return quickSelect( nums , 0 , nums.size() - 1 , nums.size() - k );
    }
};