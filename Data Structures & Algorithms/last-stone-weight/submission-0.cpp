class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> maxHeap;
        for (int s : stones) {
            maxHeap.push(s);
        }

        while(maxHeap.size() > 1) {
            int fst = maxHeap.top(); maxHeap.pop();
            int scd = maxHeap.top(); maxHeap.pop();

            maxHeap.push(fst-scd);
        }

        return maxHeap.top();
    }
};
