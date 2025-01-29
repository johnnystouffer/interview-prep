/**
 * 19. Remove nth node in Linked List
 * 
 * Read comments for a good explanation
 */

 // Definition for singly-linked list.
 struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
 };

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        // Dummy node, commonly used so that removing the head is easier
        // and do not have to worry about saving the head either
        ListNode dummy = ListNode(-1);

        dummy.next = head;
        ListNode* fast = &dummy;
        ListNode* slow = &dummy;

        // FAST use this to n times keeping an n distance from slow
        for (int i = 0; i < n; i++) {
            fast = fast->next;
        }

        // while the next one still exists keep going till you hit
        // the end, when you do then slow will be end - n away, 
        // getting you to the correct node
        while (fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next;
        }

        // when we get there we remove it from the list but making the
        // pointer point to the one after it instead
        ListNode* toDel = slow->next;
        slow->next = slow->next->next;
        delete toDel;

        // IMPORTANT cannot 'return head' CAUSE HEAD MAY BE REMOVED
        return dummy.next;
    }
};