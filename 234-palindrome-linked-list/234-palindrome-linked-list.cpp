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
        ListNode* cur = head;
			vector <int> vec;
			while(cur!=NULL)
			{
				vec.push_back(cur->val);
				cur = cur->next;
			}
			int n = vec.size();
			int start=0; int end=n-1;
			while(start<=end)
			{
				if(vec[start]==vec[end])
				{
					start++;
					end--;
					continue;
				}
				else
					return 0;
			}
			return 1; 
    }
};