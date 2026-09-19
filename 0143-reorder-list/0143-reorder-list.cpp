class Solution {
public:
    void reorderList(ListNode* head) {
        if (head == NULL || head->next == NULL)
            return;

        ListNode* left = head;

        while (left != NULL && left->next != NULL) {

            // Last node find karo
            ListNode* right = head;
            ListNode* temp = NULL;

            while (right->next != NULL) {
                temp = right;
                right = right->next;
            }

            // Agar left aur last adjacent hain
            if (left == right || left->next == right)
                break;

            // Last node ko remove karo
            temp->next = NULL;

            // Last node ko left ke baad insert karo
            right->next = left->next;
            left->next = right;

            // Next node par move karo
            left = right->next;
        }
    }
};