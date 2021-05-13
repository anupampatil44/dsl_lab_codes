#include<string>
#include<iostream>
using namespace std;
const int MAX=20;
class Stack
{
	char str[MAX];
	int top;
	public:
		Stack()
		{
			top=-1;
		}
		void push(char ch);
		char pop();
		bool isEmpty();
		bool isFull();
		
};
bool Stack::isEmpty()
{
	if(top==-1)
		return 1;
	else return 0;
}

bool Stack::isFull()
{
	if(top==MAX-1)
		return 1;
	else
		return 0;
}


void Stack::push(char ch)
{
	if(!isFull())
	{
		top++;
		str[top]=ch;
	}
}

char Stack::pop()
{
	if(!isEmpty())
	{
		char ch=str[top];
		top--;
		return ch;
	}
	else
	{
		return '\0';
	}
}

void checkParenthesis(string str)
{
	Stack s;
	char ch;
	bool flag=0;
	for(int i=0;str[i]!='\0';i++)
	{
		if(str[i]=='(' || str[i]=='[' || str[i]=='{')
			s.push(str[i]);
		if(str[i]==')'||str[i]==']'||str[i]=='}')
		{
			ch=s.pop();
			if((str[i]==')'&& ch!='(') ||(str[i]==']'&& ch!='[')||(str[i]=='}'&& ch!='{'))
			{
				cout<<"\nNot parenthesized At "<<i<<" = "<<str[i];
				flag=1;
				break;
			}
		}
	}
	if(s.isEmpty()==1 && flag==0)
		cout<<"\nCode Parenthesis are Balanced\n";
	else
		cout<<"\nCode Parenthesis are Not Balanced\n";
}

int main()
{

	int choice;
	do
	{
		Stack s;
		cout<<"\nEnter Expression: ";
		string st;
		cin>>st;
		checkParenthesis(st);
		cout<<"\nDo you want to continue?{1/0)";
		cin>>choice;
	}while(choice!=0);

	return 0;
}