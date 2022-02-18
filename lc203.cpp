#include <stack>
#include <vector>
#include <deque>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* dummyhead = new ListNode(-1);
        dummyhead->next = head;
        ListNode* cur = dummyhead , *pre = dummyhead;
        while( cur ){
            if( cur->val == val )
                pre->next = cur->next;
            else 
                pre = cur;
            cur = cur->next;
        }
        return dummyhead->next;
    }
};