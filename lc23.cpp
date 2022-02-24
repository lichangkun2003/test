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
    ListNode* mergeTwoLists( ListNode* a , ListNode* b){
        if ( (!a) || (!b) )
            return a ? a : b;
        ListNode head , *tail = &head , *pa = a , *pb = b;
        while( pa && pb ){
            if( pa->val <= pb->val ){
                tail->next = pa;
                pa = pa->next;
            }
            else{
                tail->next = pb;
                pb = pb->next;
            }
            tail = tail->next;
        }
        tail->next = ( pa ? pa : pb );
        return head.next;
    }
    ListNode* merge( vector<ListNode*>& lists , int l , int r ){
        if( l == r )
            return lists[l];
        if( l > r )
            return nullptr;
        int mid = ( r + l ) / 2;
        // ListNode* p1 = merge( lists , l , mid );
        // ListNode* p2 = merge( lists , mid + 1 , r );
        return mergeTwoLists( merge( lists , l , mid ) , merge( lists , mid + 1 , r ) );
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        return merge( lists , 0 , lists.size() - 1 );
    }
};