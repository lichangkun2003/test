#include <iostream>
#include <math.h>
#include <queue>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
class Solution {
public:
    vector<double> averageOfLevels(TreeNode* root) {
        if( !root )
            return {};
        queue< TreeNode* > q;
        q.push( root );
        vector<double> ans;
        while( !q.empty() ){
            double tmp = 0;
            int cnt = q.size();
            for( int i = 0 ; i < cnt ; i++ ){
                TreeNode* cur = q.front();
                q.pop();
                tmp += cur->val;
                if( cur->left )
                    q.push( cur->left );
                if( cur->right )
                    q.push( cur->right );
            }
            tmp = tmp / cnt;
            ans.push_back( tmp );
        } 
        return ans;
    }
};