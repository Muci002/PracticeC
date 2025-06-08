const int N = 1e4+10;

class Solution 
{
public:
    bool isValid(string s) 
    {
        char stk[N];
        int n = 0;
        int len = s.size();
        for(int i = 0; i< len;i++)
        {
            if(s[i] == '(' || s[i] == '{' || s[i] == '[')
            {
                stk[++n] = s[i];
            }
            else if( (s[i] == ']' && stk[n] == '[') || (s[i] == ')' && stk[n] == '(') || (s[i] == '}' && stk[n] == '{') )
            {
                n--;
            }
            else 
            {
                return false;
            }
            
        }
        if(!n) return true;
        return false;
    }
};