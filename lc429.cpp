#include <numeric>
#include <algorithm>
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
    vector<vector<int>> levelOrder(Node* root) {
        if( root == nullptr )
            return {};
        queue< Node * > q;
        vector< vector<int> > ans;
        int cnt;
        q.push( root );
        while( !q.empty() ){
            int cnt = q.size();
            vector<int> tmp;
            for( int i = 0 ; i < cnt ; i++ ){
                Node* cur = q.front();
                q.pop();
                tmp.push_back( cur->val );
                for( Node* child : cur->children )
                    q.push( child );
            }
            ans.push_back( move(tmp) );
        }
        return ans;
    }
};


