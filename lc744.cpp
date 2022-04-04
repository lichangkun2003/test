#include <numeric>
#include <algorithm>
#include <unordered_set>
#include <vector>

using namespace std;
class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        if( target >= letters.back() )
            return letters[ 0 ];
        int l = 0 , r = letters.size() - 1 , mid ;
        char ans;
        while( l <= r ){
            mid = ( l + r ) / 2;
            if( letters[mid] > target ){
                ans = letters[mid];
                r = mid - 1;
            }
            else
                l = mid + 1;
        }
        return ans;
    }
};
