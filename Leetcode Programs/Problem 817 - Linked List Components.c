/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

int numComponents(struct ListNode* head, int* nums, int numsSize) {
    int count = 0;
    int found = 0;
    while (head != NULL) {
        int present = 0;
        for (int i = 0; i < numsSize; i++) {
            if (head->val == nums[i]) {
                present = 1;
                break;
            }
        }
        if (present == 1 && found == 0) {
            count++;
        }
        found = present;
        head = head->next;
    }
    return count;
}