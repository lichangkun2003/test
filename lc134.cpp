#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size() , i = 0;
        while( i < n ){
            int sumofGas = 0 , sumofCost = 0;
            int cnt = 0;
            while( cnt < n ){
                int j  = ( i + cnt ) % n;
                sumofGas += gas[j];
                sumofCost += cost[j];
                if( sumofGas < sumofCost )
                    break;
                else
                    cnt++;
            }
            if( cnt == n )
                return i;
            else
                i += cnt + 1;
        }
        return -1;
    }
};