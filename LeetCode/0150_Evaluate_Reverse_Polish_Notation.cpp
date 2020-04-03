class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> operands;
        for (const string token : tokens) {
            if (token == "+" || token == "-" || token == "*" || token == "/") {
                int first = 0;
                int second = 0;
                second = operands.top();
                operands.pop();
                first = operands.top();
                operands.pop();
                if (token == "+") {
                    operands.push(first + second);
                } else if (token == "-") {
                    operands.push(first - second);
                } else if (token == "*") {
                    operands.push(first * second);
                } else if (token == "/") {
                    operands.push(first / second);
                }
            } else {
                operands.push(stoi(token));
            }
        }
        return operands.top();
    }
};
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> nums;
        for (const string& token : tokens) {
            if (token == "+" || token == "-" || token == "*" || token == "/") {
                int num2 = nums.top();
                nums.pop();
                int num1 = nums.top();
                nums.pop();
                if (token == "+") {
                    nums.push(num1 + num2);
                } else if (token == "-") {
                    nums.push(num1 - num2);
                } else if (token == "*") {
                    nums.push(num1 * num2);
                } else if (token == "/") {
                    nums.push(num1 / num2);
                }
            } else {
                nums.push(stoi(token));
            }
        }
        return nums.top();
    }
};

//Stack. 99% 100%
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> s;
        for (const string token : tokens) {
            if (token == "+" || token == "-" || token == "*" || token == "/") {
                int r = s.top();
                s.pop();
                int l = s.top();
                s.pop();
                switch(token[0]) {
                    case '+':
                        s.push(l + r);
                        break;
                    case '-':
                        s.push(l - r);
                        break;
                    case '*':
                        s.push(l * r);
                        break;
                    case '/':
                        s.push(l / r);
                        break;
                }
            } else {
                s.push(stoi(token));
            }
        }
        return s.top();
    }
};
