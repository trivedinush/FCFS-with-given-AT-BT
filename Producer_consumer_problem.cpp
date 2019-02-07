#include<iostream>
using namespace std;
int S,E,F,a[5],n=0;
void wait(int &s)
{
    --s;
}
void signal(int &s)
{
    ++s;
}
void producer()
{
	cout<<"Producing mode..\n";
	wait(E);
	wait(S);
	cout<<"E:"<<E<<"\nS:"<<S<<"\nF:"<<F;
	int item;
	cout<<"\nEnter the value to be entered:";
	cin>>item;
	a[n]=item;
	n++;
	signal(S);
	signal(F);	
	cout<<"E:"<<E<<"\nS:"<<S<<"\nF:"<<F;
	cout<<"\nExiting Producing mode....";
}
void consumer()
{
	cout<<"Consumption mode..\n";
	wait(F);
	wait(S);
	cout<<"E:"<<E<<"\nS:"<<S<<"\nF:"<<F;
	n--;
	cout<<"\nThe value has been removed...\n";
	signal(S);
	signal(E);
	cout<<"E:"<<E<<"\nS:"<<S<<"\nF:"<<F<<"\n";
	cout<<"\nExiting Consumption mode...";
}
void traverse()
{
	cout<<"\nthe buffer is: ";
	for(int i=0;i<n;i++)	cout<<a[i]<<"  "; 
	cout<<endl; 
}
int main()
{
	S=1,E=5,F=0;
	int ch;
	while(1)
	{
		cout<<"1.Produce\n2.Consume\n3.Exit\nEnter choice:";
		cin>>ch;
		switch(ch)
		{
			case 1:if(S==1&&E!=0)	producer();
			       else cout<<"\nBuffer is full\n";
			       break;
			case 2:if(S==1&&F!=0)	consumer();
			       else cout<<"\nBuffer is empty\n";       
			       break;
			default:exit(0);       
		}
		if(n==0)
		{
			E=5;
			F=0;
		}
		else
		{  
		   traverse();
	    }
	    //cout<<"After Passing:";
	    //cout<<"\nE:"<<E<<"\nS:"<<S<<"\nF:"<<F;
	}
}
