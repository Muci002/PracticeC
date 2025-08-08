//P1098
#include <iostream>
#include <algorithm>

using namespace std;

string s;
string ret;
int p1, p2, p3, n;

//digis()判断是否是数字字符 
bool digis(char ch)
{
	return ch >= '0' && ch <= '9';
}
//dilet()判断是否是小写字母
 bool dilet(char ch)
 {
 	return ch >= 'a' && ch <= 'z';
 }
 //add()展开
 void add(char left, char right)
 {
 	string t;
 	for(char ch = left+1; ch < right; ch++)
 	{
 		char tmp = ch;
 		
 		if(p1 == 2 && dilet(tmp)) tmp -= 32;
 		
 		else if(p1 == 3) tmp = '*';
 		for(int i = 0; i < p2; i++)
 		{
 			t += tmp;
		 }
	 }
	 if(p3 == 2) reverse(t.begin(), t.end());
	 ret += t;
  } 
 
int main()
{
	cin >> p1 >> p2 >> p3 ;
	cin >> s;
	n = s.size();
	for(int i = 0; i < n; i++)
	{
		char ch = s[i];
		
		if(s[i] != '-' || i == 0 || i == n-1) ret += ch;
		else
		{
			char left = s[i-1], right = s[i+1];     
			//是否合法 
		 if((digis(left) && digis(right) && left < right) ||
				 (dilet(left) && dilet(right) && left < right)) 
		{
			//展开
			add(left, right); 
		}
		else ret += ch;
		}
		
		
	
	}
		cout << ret;
	return 0;
}