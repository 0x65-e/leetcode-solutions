//#23. Merge k Sorted Lists (C++) - 37ms/61.59% 13.2MB/76.29%
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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        auto compare = [](ListNode* a, ListNode* b) { return a->val > b->val; };
        priority_queue<ListNode*, vector<ListNode*>, decltype(compare)> pq(compare);
        // Populate the queue and filter out empty lists
        for (auto node : lists) {
            if (node) pq.push(node);
        }
        ListNode dummy;
        ListNode* curr = &dummy;
        while (!pq.empty()) {
            // Get the min value
            ListNode* min = pq.top();
            pq.pop();
            curr->next = min;
            curr = min;
            // Break early if there is only one list left, otherwise continue
            if (min->next != nullptr && !pq.empty()) pq.push(min->next);
        }
        return dummy.next;
    }
};