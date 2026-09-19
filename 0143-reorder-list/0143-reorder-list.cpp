class Solution {
public:
    void reorderList(ListNode* head) {
        if (head == NULL || head->next == NULL)
            return;

        vector<ListNode*> nodes;

        ListNode* temp = head;

        // Saare nodes store karo
        while (temp != NULL) {
            nodes.push_back(temp);
            temp = temp->next;
        }

        int left = 0;
        int right = nodes.size() - 1;

        // Teri approach:
        // left -> left side se
        // right -> last side se
        while (left < right) {

            // left ke baad right lagao
            nodes[left]->next = nodes[right];

            left++;

            // Agar cross ho gaye
            if (left == right)
                break;

            // right ke baad next left lagao
            nodes[right]->next = nodes[left];

            right--;
        }

        // Last node ka next NULL
        nodes[left]->next = NULL;
    }
};