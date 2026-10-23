#define MIN_NUM -100000
#define MAX_NUM 100000

class MedianFinder {
    priority_queue<int, vector<int>, greater<int>> max_q;
    priority_queue<int> min_q;
public:
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        
        int max_bound = (max_q.size() > 0) ? max_q.top() : MAX_NUM;
        int min_bound = (min_q.size() > 0) ? min_q.top() : MIN_NUM;
        int max_size = max_q.size();
        int min_size = min_q.size();

        if (num > min_bound && max_size <= min_size) {
            max_q.push(num);
        } else if (num < max_bound && min_size <= max_size) {
            min_q.push(num);
        } else if (num > min_bound) {
            int transfer = max_q.top();
            max_q.pop();
            min_q.push(transfer);
            max_q.push(num);
        } else {
            int transfer = min_q.top();
            min_q.pop();
            max_q.push(transfer);
            min_q.push(num);
        }
    }
    
    double findMedian() {

        int max_size = max_q.size();
        int min_size = min_q.size();

        if (min_size == max_size) {
            return static_cast<double>((max_q.top() + min_q.top())) / 2;
        } else if (min_size < max_size) {
            return max_q.top();
        } else {
            return min_q.top();
        }
    }
};
