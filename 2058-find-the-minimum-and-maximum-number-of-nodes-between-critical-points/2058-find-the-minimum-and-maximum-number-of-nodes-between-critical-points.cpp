class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {

        vector<int> ans = {-1, -1};

        // Kam se kam 3 nodes hone chahiye
        if(head == nullptr || head->next == nullptr || head->next->next == nullptr)
            return ans;

        ListNode* prev = head;
        ListNode* curr = head->next;

        int index = 1;

        int first = -1;
        int last = -1;

        int minDistance = INT_MAX;

        while(curr->next != nullptr) {

            bool isCritical =
                (curr->val > prev->val && curr->val > curr->next->val) ||
                (curr->val < prev->val && curr->val < curr->next->val);

            if(isCritical) {

                if(first == -1) {
                    first = index;
                }
                else {
                    minDistance = min(minDistance, index - last);
                }

                last = index;
            }

            prev = curr;
            curr = curr->next;
            index++;
        }

        if(first == -1 || first == last)
            return ans;

        int maxDistance = last - first;

        ans[0] = minDistance;
        ans[1] = maxDistance;

        return ans;
    }
};