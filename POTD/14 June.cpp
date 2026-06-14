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
    int pairSum(ListNode* head) {
        ListNode* slow = head->next;
        ListNode* fast = head;
        while (fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* prev = NULL;
        ListNode* next = NULL;
        while (slow) {
            next=slow->next;
            slow->next=prev;
            prev=slow;
            slow=next;
        }
        slow=prev;
        int ans=0;
        while(slow){
            ans=max(ans,slow->val+head->val);
            slow=slow->next;
            head=head->next;
        }
        return ans;
    }
};