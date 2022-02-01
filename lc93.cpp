#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
private:
    static constexpr int SEG_COUNT = 4;
    vector<string> ans;
    vector<int> segments;

public:
    void dfs(const string s , int segld , int segStart ){
        if( segld == SEG_COUNT ){
            if( segStart == s.size() ){
                string ipAddr;
                for( int i = 0 ; i < SEG_COUNT ; ++i ){
                    ipAddr += to_string( segments[i] );
                    if( i != SEG_COUNT - 1 )
                        ipAddr += ".";
                }
                ans.push_back( move(ipAddr) );
            }
            return ;
        }
        
        if( segStart == s.size() )
            return ;
        
        if( s[segStart] == '0' ){
            segments[segld] = 0;
            dfs( s , segld + 1 , segStart + 1 );
        }

        int addr = 0;
        for( int segEnd = segStart ; segEnd < s.size() ; ++ segEnd ){
            addr = addr * 10 + ( s[segEnd] - '0' );
            if( addr > 0 && addr <= 0xFF ){
                segments[segld] = addr;
                dfs( s , segld + 1 , segEnd + 1 );
            }
            else
                break;
        }
    }
    
    vector<string> restoreIpAddresses(string s) {
        segments.resize(SEG_COUNT);
        dfs( s , 0 , 0 );
        return ans;
    }
};