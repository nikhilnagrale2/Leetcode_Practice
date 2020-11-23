//  Naive Solution
//  Time Complexity - O(n)
//  Space Complexity - O(n)

class Solution
{
public:
    bool isValid(string s)
    {
        stack<char> ans;
        ans.push('a');
        for (int i = 0; i < s.length(); i++)
        {
            if (ans.top() == '(' && s[i] == ')' || ans.top() == '[' && s[i] == ']' || ans.top() == '{' && s[i] == '}')
            {
                ans.pop();
            }
            else
            {
                ans.push(s[i]);
            }
        }
        return ans.size() - 1 ? false : true;
    }
};
