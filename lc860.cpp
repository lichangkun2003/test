#include <stack>
#include <vector>
#include <deque>
#include <unordered_map>
using namespace std;

class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int n = bills.size();
        int count[2] = { 0 , 0 };
        for( int i = 0 ; i < n ; ++i ){
            if( bills[i] == 5 )
                count[0]++;
            else if( bills[i] == 10 ){
                if( count[0] == 0 )
                    return false;
                count[1]++;
                count[0]--;
            }
            else{
                //20块
                if( count[1] != 0 && count[0] != 0 ){
                    count[1]--;
                    count[0]--;
                }
                else if( count[1] == 0 && count[0] >= 3 )
                        count[0] -= 3;
                else 
                    return false;
            }
        }
        return true;
    }
};