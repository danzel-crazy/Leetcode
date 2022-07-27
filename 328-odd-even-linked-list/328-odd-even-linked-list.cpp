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
    ListNode* oddEvenList(ListNode* head) {
        ListNode *first = head;
        if(first == NULL) return head;
        ListNode *second = head->next;
        ListNode *odd = first;
        ListNode *even = second;
        
        while(odd->next != NULL && even->next != NULL){
            odd->next = even->next;
            even->next = odd->next->next;
            
            odd =odd->next;
            even = even->next;
        }
        
        if(odd != NULL){
            odd->next = second;
        }
        
        return head;
    }
};