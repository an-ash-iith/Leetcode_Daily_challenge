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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        
        //its wasy only just keep three variable min and max and count

        ListNode * temp = head->next;
        int prev= head->val;
        int curr,next;
        int index=1;
        vector<int> ans;

        while(temp->next!=NULL)
        {
            curr= temp->val;
            next= temp->next->val;

            if((curr>prev && curr>next) || (curr<prev && curr<next ))
            {
                ans.push_back(index);
            }
            temp=temp->next;
            prev=curr;

            index++;
        }

        int n = ans.size();
        int mini=INT_MAX;

        if(n<2) return {-1,-1};

        for(int i =1;i<n;i++)
        {
            mini = min(mini,ans[i]-ans[i-1]);
        }
       
        return {mini, ans[n-1]-ans[0],};


    }
};