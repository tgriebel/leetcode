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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode* splitStartPrev = nullptr;
        ListNode* splitStart = head;

        int pos = 1;
        // Scan up to start of reversal
        while( splitStart != nullptr && pos < left ) {
            splitStartPrev = splitStart;
            splitStart = splitStart->next;
            ++pos;
        }

        ListNode* prev = nullptr;
        ListNode* current = splitStart;

        // Reverse up to the end
        while( current != nullptr && pos <= right ) {
            ListNode* next = current->next;
            current->next = prev;
            prev = current;
            current = next;
            ++pos;
        }

        // Reattach pointers
        if ( splitStartPrev != nullptr ) {
            splitStartPrev->next = prev;
        } else {
            head = prev;
        }
        splitStart->next = current;

        return head;
    }
};
