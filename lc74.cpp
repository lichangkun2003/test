#include <string>
#include <iostream>
#include <vector>

using namespace std;
bool searchMatrix( vector< vector<int> >& matrix, int target) {
    int m = matrix.size();
    int n = matrix[0].size();
    int l = 0 , r = m - 1 , mid;
    while( l <= r ){
        int mid = ( l + r ) / 2;
        if( matrix[mid][0] <= target && matrix[mid][n - 1] >= target ){
            int l1 = 0 , r1 = n - 1;
            int mid1;
            while( l1 <= r1 ){
                mid1 = ( l1 + r1 ) / 2;
                if( matrix[mid][mid1] == target )
                    return true;
                else if( matrix[mid][mid1] > target )
                    r1 = mid - 1;
                else  
                    l1 = mid + 1;
            }
            break;
        }
        else if( matrix[mid][0] < target )
            l = mid + 1;
        else 
            r = mid - 1;
        }
    return false;
    }
int main(){
    // vector< vector<int> > matrix ( 1 ) ;
    int num = 1;
    printf( "%d" , num );
    scanf( "%d" , &num );
    return 0;
}