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
    ListNode* doubleIt(ListNode* head) {

     stack<ListNode*> st;

     ListNode * node = head;

     while(node)
     {
        st.push(node);
        node=node->next;
     }   

     int carry =0;

     ListNode* prev = NULL;

     while(!st.empty())
     {
        ListNode * top1 = st.top(); 
        st.pop();

       int val1 = 2*top1->val+carry;
         
        carry = val1/10;
        ListNode* temp = new ListNode(val1%10);
        temp->next= prev;
        prev= temp;

     }

     if(carry!=0)
     {
        ListNode* temp = new ListNode(carry);
        temp->next= prev;
        prev= temp;
     }
     return prev;
    }
};