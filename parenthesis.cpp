#include<iostream>
using namespace std;
#include<string.h>
#define n 20
char push(char);
char pop();
int top=-1;
int stack[20];
main()
{
  char s[20],temp;
  cout<<"enter expression"<<endl;
  cin>>s;
  int x=1,i;
  for(i=0;i<strlen(s);i++)
  {
  	if(s[i]=='('||s[i]=='{'||s[i]=='[')
  	push(s[i]);
  	if(s[i]==')'||s[i]=='}'||s[i]==']')
  	{
  		if(top==-1)
  		x=0;
  		else
  		{
  			temp=pop();
  			if(s[i]==')'&&(temp=='{'||temp=='['))
  			x=0;
  			if(s[i]=='}'&&(temp=='('||temp=='['))
  			x=0;
  			if(s[i]==']'&&(temp=='{'||temp=='('))
  			x=0;
		  }
	  }
	  
	  }
	  if(top>=0)
	  x=0;
	  if(x==0)
	  cout<<"invalid\n";
	  else
	  cout<<"valid\n";	
}
char push(char a)
{
	if(top==n-1)
	cout<<"stack overflow"<<endl;
	else
	{
		top++;
		stack[top]=a;
	}
}
char pop()
{
	if(top==-1)
	cout<<"stack underflow"<<endl;
	else
	{
		return(stack[top--]);
	}
}

