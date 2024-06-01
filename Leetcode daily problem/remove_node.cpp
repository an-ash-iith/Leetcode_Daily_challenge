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

    ListNode* deleteNode(ListNode* head) {
        // Check if the head is null
        if (!head) return nullptr;

        // Remove leading nodes with value 0
        while (head && head->val == 0) {
            head = head->next;
        }

        // Traverse and remove nodes with value 0
        ListNode* temp = head;
        while (temp && temp->next) {
            if (temp->next->val == 0) {
                temp->next = temp->next->next;
            } else {
                temp = temp->next;
            }
        }

        return head;
    }

    ListNode* removeNodes(ListNode* head) {
        if (!head) return nullptr;

        vector<int> max1;
        ListNode* node = head;

        // Collect all node values in a vector
        while (node) {
            max1.push_back(node->val);
            node = node->next;
        }

        int n = max1.size();

        // Update the max1 array to have the maximum values from right to left
        for (int i = n - 2; i >= 0; i--) {
            max1[i] = max(max1[i], max1[i + 1]);
        }

        node = head;
        int i = 0;

        // Mark nodes for deletion by setting their values to 0
        while (node) {
            if (node->val < max1[i]) {
                node->val = 0;
            }
            node = node->next;
            i++;
        }

        // Delete all the nodes with value 0
        return deleteNode(head);
    }
};
