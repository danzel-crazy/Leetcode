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
        ListNode * start = new ListNode();
        start -> next = head;
        ListNode* first = start;
        ListNode* second = start;
        
        while(second->next != NULL){
            if(n > 0){
                second = second->next;
                n--;
            }
            else{
                second = second->next;
                first  = first->next;
            }
        }
        
        first->next = first->next->next;
        return start -> next;
    }
};