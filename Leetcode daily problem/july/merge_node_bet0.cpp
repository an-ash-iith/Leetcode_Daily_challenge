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
    ListNode* mergeNodes(ListNode* head) {

        //its easy only ---

        ListNode* head2=head->next;

        ListNode* ans = new ListNode();
        ListNode* temp = ans;

        int sum=0;

        while(head2!=NULL)
        {
            if(head2->val == 0)
            {
               ans->next= new ListNode(sum);
               ans=ans->next;
               cout<<sum<<endl;
               sum=0;
            }
            else
            {
                sum+=head2->val;
            }

            head2=head2->next;
        }

        return temp->next;
    }
};