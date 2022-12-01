/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* allocs[ 101 ];
        for( int i = 0; i < 101; ++i ) {
            allocs[ i ] = new ListNode( 0 );
        }
        ListNode* head = allocs[ 0 ];
        ListNode* l3 = head;
        ListNode* node = NULL;
        int carry = 0;
        int allocIx = 1;
        while( ( l1 != NULL ) || ( l2 != NULL ) ) {
            int sum = 0;
            sum += ( l1 != NULL ) ? l1->val : 0;
            sum += ( l2 != NULL ) ? l2->val : 0;
            sum += carry;
            carry = sum / 10;
            sum = sum % 10;

            l3->next = allocs[ allocIx++ ];
            l3->next->val = sum;
            l3 = l3->next;
            
            l1 = ( l1 != NULL ) ? l1->next : NULL;
            l2 = ( l2 != NULL ) ? l2->next : NULL;
        }
        if( carry > 0 ) {
            l3->next = allocs[ allocIx++ ];
            l3->next->val = carry;
        }
        return head->next;
    }
};
