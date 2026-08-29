class Solution {
public:
    bool isValid(string s) {
        stack<char> cur_stack;
        for (char ch : s) {
            if (ch == '(' || ch == '[' || ch == '{') {
                cur_stack.push(ch);
            } else {
                if (cur_stack.empty()) {
                    return false;
                }
                char prev = cur_stack.top();
                cur_stack.pop();
                if (ch == ')' && prev != '(') return false;
                if (ch == '}' && prev != '{') return false;
                if (ch == ']' && prev != '[') return false;
            }
            
        }
        return cur_stack.empty();
    }
};