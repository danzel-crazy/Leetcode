/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        map <ListNode *, ListNode *> a;
        // if(head == nullptr || head->next == nullptr) return NULL;
        ListNode *temp;
        while(head != nullptr && head->next != nullptr){
            ListNode *temp = head->next;
            if(a.count(temp)){
                return temp;
            }
            else a[head] = temp;
            head = head->next;
        }
        return NULL;
    }
};