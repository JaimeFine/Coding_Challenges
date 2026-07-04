/*
32. Longest Valid Parentheses
Solved in 31'27''
Hard

Given a string containing just the characters '(' and ')', return the length of the longest valid (well-formed) parentheses substring.

 

Example 1:

Input: s = "(()"
Output: 2
Explanation: The longest valid parentheses substring is "()".
Example 2:

Input: s = ")()())"
Output: 4
Explanation: The longest valid parentheses substring is "()()".
Example 3:

Input: s = ""
Output: 0
 

Constraints:

0 <= s.length <= 3 * 104
s[i] is '(', or ')'.
*/

class Solution {
public:
    int longestValidParentheses(string s) {
        std::stack<int> stk;
        int length = 0;
        stk.push(-1);

        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '(') {
                stk.push(i);
            } else {
                stk.pop();
                if (stk.empty()) {
                    stk.push(i);
                } else {
                    length = max(length, i - stk.top());
                }
            }
        }

        return length;
    }
};

// AI's cleaner answer:
class Solution {
public:
    int longestValidParentheses(string s) {
        int left = 0;
        int right = 0;
        int ans = 0;

        for (char c : s) {
            if (c == '(')
                left++;
            else
                right++;

            if (left == right)
                ans = max(ans, 2 * right);

            if (right > left)
                left = right = 0;
        }

        left = right = 0;

        for (int i = s.size() - 1; i >= 0; i--) {
            if (s[i] == '(')
                left++;
            else
                right++;

            if (left == right)
                ans = max(ans, 2 * left);

            if (left > right)
                left = right = 0;
        }

        return ans;
    }
};