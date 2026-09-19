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
    void reorderList(ListNode* head) {
        if (!head || !head->next) {
            return;
        }
        // get two lists
        ListNode* fast = head;
        ListNode* slow = head;
        ListNode* prev = nullptr;
        while (fast != nullptr && fast->next) {
            fast = fast->next->next;
            prev = slow;
            slow = slow->next;
        }
        prev->next = nullptr;

        // now we have two lists, prev and head

        // let's reverse the second
        ListNode* node = slow;
        ListNode* prev2 = nullptr;
        while (node != nullptr) {
            ListNode* next = node->next;
            node->next = prev2;
            prev2 = node;
            node = next;
        }

        // let's merge them
        ListNode* first = head;
        ListNode* second = prev2;
        while (second) {
            ListNode* tmp1 = first->next;
            ListNode* tmp2 = second->next;

            first->next = second;
            if (!tmp1) {
                break;
            }
            second->next = tmp1;
           

            first = tmp1;
            second = tmp2;
        }

    }
};