class MinStack {
private:
    stack<int> st_main;
    stack<int> st_min;
public:
    
    MinStack() {
        
    }
    
    void push(int val) {
        st_main.push(val);
        if (st_min.empty() || st_min.top() >= val) {
            st_min.push(val);
        }
    }
    
    void pop() {
        if (!st_main.empty()) {
            if (!st_min.empty() && st_main.top() == st_min.top()) {
                st_min.pop();
            }
            st_main.pop();
        }
    }
    
    int top() {
        return st_main.top();
    }
    
    int getMin() {
        return st_min.top();
    }
};
