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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* it1 = list1;
        ListNode* it2 = list2;

        ListNode* merged = nullptr;
        ListNode* head;
        
        while( ( it1 != nullptr ) || ( it2 != nullptr ) ) {
            ListNode* nextNode;
            if( it1 == nullptr ) {
                nextNode = new ListNode( it2->val );
                it2 = it2->next;
            } else if( it2 == nullptr ) {
                nextNode = new ListNode( it1->val );
                it1 = it1->next;
            } else {
                if( it1->val < it2->val ) {
                    nextNode = new ListNode( it1->val );
                    it1 = it1->next;
                } else {
                    nextNode = new ListNode( it2->val );
                    it2 = it2->next;
                }
            }
            if( merged == nullptr ) {
                merged = nextNode;
                head = merged;
            } else {
                merged->next = nextNode;
                merged = merged->next;
            }
        }
        return head;
    }
};
