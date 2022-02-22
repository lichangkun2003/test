#include <stack>
#include <vector>
#include <deque>
using namespace std;




struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next( nullptr ) {}
};

class Solution {
public:
    vector<int> reversePrint(ListNode* head) {
        int n = 0;
        ListNode *cur = head;
        while( cur ){
            n++;
            cur = cur->next;
        }
        n++;
        vector<int> ans( n );
        cur = head;
        n--;
        while( cur ){
            ans[n] = cur->val;
            cur = cur->next;
            n--;
        }
        return ans;
    }
};