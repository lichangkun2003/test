#include <string>
#include <algorithm>
#include <vector>

using namespace std;
class Solution {
public:
    int trailingZeroes(int n) {
        int ans = 0;
        while( n ){
            n /= 5;
            ans += n;
        }
        return ans;
    }
};