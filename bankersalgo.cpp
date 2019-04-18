#include<iostream>
using namespace std;
int main()
{
	int p;
	cout<<"Enter the number of processes: ";	cin>>p;
	int r;
	cout<<"Enter number of resources: ";	cin>>r;
	int ca[p][r],ma[p][r],a[r],need[p][r];
	cout<<"Enter current allocation status: \n";
	for(int i=0;i<p;i++)
	{
		for(int j=0;j<r;j++)
		cin>>ca[i][j];
	}
	cout<<"Enter max allocation status: \n";
	for(int i=0;i<p;i++)
	{
		for(int j=0;j<r;j++)
		cin>>ma[i][j];
	}
	cout<<"Enter availability status: ";
		for(int j=0;j<r;j++)
		cin>>a[j];
	for(int i=0;i<p;i++)
	{
		for(int j=0;j<r;j++)
		{
			need[i][j]=ma[i][j]-ca[i][j];
		}
	}
	cout<<"Need matrix: \n";
	for(int i=0;i<p;i++)
	{
		for(int j=0;j<r;j++)
		{
			cout<<need[i][j];
		}
		cout<<endl;
	}
	int total[p],count=p,ans=0;
	while(count!=0)
		{
			for(int i=0;i<p;i++)
			{   int flag=0;
				for(int j=0;j<r;j++)
				{
					if(a[j]>=need[i][j]&&total[i]!=1)
					{
						flag++;
					}
				}
				if(flag==r)
				{
					for(int j=0;j<r;j++)
					a[j]+=ma[i][j];		
					total[i]=1;
					ans++;
					
				} if(flag==r) break;
			}count--;
		}
		
		if(ans==p) cout<<"\nsafe\n";
		else	cout<<"\nunsafe\n";
		
		cout<<"\nAvailability status at last\n";
		for(int i=0;i<r;i++) cout<<a[i]<<" ";
		cout<<endl;
} 
