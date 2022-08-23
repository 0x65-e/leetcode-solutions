//#234. Palindrome Linked List (C++) - 257ms/90.01% 110.3MB/95.62%
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
        // Challenge: O(n) time and O(1) space
        // Find lenght of the list
        int n = 0;
        for (ListNode* curr = head; curr != nullptr; curr = curr->next) n++;
        // Reverse the first half of the list
        ListNode* curr = head, *prev = nullptr;
        for (int i = 0; i < n / 2; i++) {
            ListNode* temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }
        if (n % 2) curr = curr->next;
        for (int i = 0; i < n / 2; i++) {
            if (prev->val != curr->val) return false;
            prev = prev->next;
            curr = curr->next;
        }
        return true;
    }
};