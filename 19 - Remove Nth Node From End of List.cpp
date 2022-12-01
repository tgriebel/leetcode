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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* current = head;
        ListNode* previous = nullptr;

        // Pass 0: Find length
        int counter = 0;
        while( current != nullptr ) {
            current = current->next;
            ++counter;
        }
        
        // Pass 1: Find target node
        current = head;
        int target = ( counter - n );      
        for( int i = 0; i < target; ++i ) {
            previous = current;
            current = current->next;
        }
        
        // Pas 2: Remove
        if( previous != nullptr ) {
            previous->next = current->next;
            delete current;
            return head;
        } else {
            previous = current->next;
            delete current;
            return previous;
        }
    }
};
