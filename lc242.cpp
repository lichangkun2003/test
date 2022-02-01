#include <iostream>
#include <algorithm>
using namespace std;


class Solution {
public:
    bool isAnagram( string s, string t) {
       if( s.length() != t.length() )
           return false;
        sort( s.begin() , s.end() );
        sort( t.begin() , t.end() );
        return s == t;
    }
};

// using namespace std;
// int main()
// {
//     cout << "hello world !" << endl;
//     system( "pause" );
//     return 0;
// }