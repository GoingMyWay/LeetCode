class Solution {
public:
    int calPoints(vector<string>& ops) {
        stack<int> my_stack;
        int sum = 0;
        for (int i = 0; i < ops.size(); i ++) {
            if (ops[i].compare("C") !=0 && ops[i].compare("D") !=0 && ops[i].compare("+") != 0) {
                my_stack.push(atoi(ops[i].c_str()));
                sum += my_stack.top();
            } else if (ops[i].compare("C") == 0) {
                sum -= my_stack.top();
                my_stack.pop();
            } else if (ops[i].compare("D") == 0) {
                my_stack.push(my_stack.top()*2);
                sum += my_stack.top();
            } else if (ops[i].compare("+") == 0) {
                int top_1 = my_stack.top();
                my_stack.pop();
                int top_2 = my_stack.top();
                my_stack.pop();
                my_stack.push(top_2);
                my_stack.push(top_1);
                my_stack.push(top_1+top_2);
                sum += my_stack.top();

            }
        }
        return sum;
    }
};