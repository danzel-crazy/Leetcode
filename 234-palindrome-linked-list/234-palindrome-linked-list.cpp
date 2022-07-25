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
    bool isPalindrome(ListNode* head) {
        string a = "";
        while(head != NULL){
            a +=  '0' + head->val;
            head = head -> next;
        }
        
        string b = a;
        reverse(b.begin(), b.end());
        // cout << a << endl;
        // cout << b << endl;
        if(a == b){
            return true;
        }
        else{
            return false;
        }
    }
};