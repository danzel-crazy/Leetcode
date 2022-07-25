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
    ListNode *reverse(ListNode *head) {
        ListNode *prev = nullptr, *curr = head, *next;
        while(curr) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
    
    bool isPalindrome(ListNode* head) {
        if (!head || !head->next) return true;
        
        ListNode *slow = head, *fast = head->next;
        while(fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        
        ListNode *temp = slow->next;
        slow->next = nullptr;
        
        ListNode *newHead = reverse(temp);
        while(head && newHead) {
            if (head->val != newHead->val) return 0;
            head = head->next;
            newHead = newHead->next;
        }
        return 1;
    }
};