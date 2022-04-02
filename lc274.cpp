#include <numeric>
#include <algorithm>
#include <unordered_set>
#include <vector>

using namespace std;
class Solution {
public:
    int guessNumber(int n) {
        int left = 1, right = n;
        while (left < right) { 
            int mid = left + (right - left) / 2; 
            if (guess(mid) <= 0) {
                right = mid; 
            } else {
                left = mid + 1; 
            }
        }
        return left;
    }
};
