// PROGRAMME
class Solution
{
public:
    bool isValid(string s)
    {
        stack<char> t; // stack for storing opening parentheses
        int i;         // variable i to travel

        for (auto i : s) // travel into whole string
        {
            // if any opening parentheses, push into stack
            if (i == '(' || i == '{' || i == '[')
            {
                t.push(i);
            }
            else
            {
                // check condition for false
                if (t.empty() || (t.top() == '(' && i != ')') || (t.top() == '{' && i != '}') || (t.top() == '[' && i != ']'))
                {
                    return false;
                }

                t.pop(); // else pop from stack
            }
        }

        return t.empty(); // if stack is empty then it is valid, otherwise no
    }
};
// MY PROGRAMME
class Solution
{
public:
    bool isValid(string s)
    {
        stack<char> st;
        int i;
        for (i = 0; i < s.size(); i++)
        {
            if (s[i] == '{' || s[i] == '[' || s[i] == '(')
                st.push(s[i]);
            else
            {
                if (st.empty() || (st.top() == '(' && s[i] != ')') || (st.top() == '[' && s[i] != ']') || (st.top() == '{' && s[i] != '}'))
                    return false;
                st.pop();
            }
        }

        return st.empty();
    }
};

// ENONCé
/*Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

An input string is valid if:

Open brackets must be closed by the same type of brackets.
Open brackets must be closed in the correct order.
Every close bracket has a corresponding open bracket of the same type.


Example 1:

Input: s = "()"
Output: true
Example 2:

Input: s = "()[]{}"
Output: true
Example 3:

Input: s = "(]"
Output: false*/

// EXPLICATION
/*Let's take an example not given-
Suppose our string given to us as, s = "(({{[[]]}}))"

so, the answer should return true.*/

/*Suppose our string given to us as, s = "(({{[[]]}}))"

Intially, our stack is empty, and looks like, t = [],

s = "( ( { { [ [ ]  ] } } ) )"
     ↑
     we met an opening bracket, we will say their is a probaility of meeting same closing bracket in future, so push into stack,
     now stack looks like, t = ['(']
                                 ↑ t.top()

s = "( ( { { [ [ ]  ] } } ) )"
       ↑
       we met an opening bracket, we will say their is a probaility of meeting same closing bracket in future, so push into stack,
      now stack looks like, t = ['(', '(']
                                       ↑ t.top()*/
/*s = "( ( { { [ [ ]  ] } } ) )"
                 ↑
           Now, we met an closing bracket, so we say our parentheses will valid only if it encounter the last same opening parentheses of this type,
           and how we encounter our last opening parentheses, for that we are using stack
           our current stack looks like, t =  ['(', '(', '{', '{', '[', '[']
                                                                         ↑ t.top()
            so, yes our current bracket is ']' and top of stack is '[', so they are valid,
            therefore move forward and pop the top from stack,
                 t =  ['(', '(', '{', '{', '[']
                                            ↑ t.top()

s = "( ( { { [ [ ] ] } } ) )"
                   ↑
           Now, we met an closing bracket, so we say our parentheses will valid only if it encounter the last same opening parentheses of this type,
           and how we encounter our last opening parentheses, for that we are using stack
           our current stack looks like, t =  ['(', '(', '{', '{', '[']
                                                                    ↑ t.top()*/

/*so, yes our current bracket is ')' and top of stack is '(', so they are valid,
            therefore move forward and pop the top from stack,
                 t =  [ ]

Since, we are on the last index and our stack is empty,
therefore it is valid.
Time Complexity --> O(n) // where n is the size of the array
Space Complexity --> O(maximum number of opening parentheses)

It paases [ 91 / 91] in built test cases*/

// programme
