#include <iostream>
#include <math.h>
#include <queue>
#include <vector>

using namespace std;

class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};

class Solution {
public:
    int maxDepth(Node* root) {
        if( !root )
            return 0;
        int ans = 0;
        queue< Node* > q;
        q.push( root );
        while( !q.empty() ){
            int cnt = q.size();
            ans++;
            for( int i = 0 ; i < cnt ; ++i ){
                Node* cur = q.front();
                q.pop();
                for( Node* next : cur->children )
                    if( next )
                        q.push( next );   
            }
        }
        return ans;
    }
};