#include<iostream>
#include<string>
using namespace std;
int main()
{
	string ss;
	int count = 1;
	cout << "Enter the string: ";
	getline(cin, ss);
	int len = ss.length();
	for (int i = 0; i < len; i++)
	{
		if (ss[i] == ' ')
		{
			count = count + 1;
			
		}
	}
	if (ss[0] == ' ')
		count = count - 1;
	if (ss[len - 1] == ' ')
		count = count - 1;
	cout << "word count: " << count;
}