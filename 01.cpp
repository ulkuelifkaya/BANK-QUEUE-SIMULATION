// •	User enters the number of counters between (1≤N≤5).
// •	There are two transactions: Append and Serve. 
// •	Each transaction occurs after a time interval (Ex: 5 seconds). 
// •	No user intervention is allowed except the program termination (CRTL-Z)
// •	The counter should be closed when there is no client in the queue. It should be reopened when an append operation occurs.  

#include <iostream>
#include <vector>
#include "d_bqueue.h"
#include "d_except.h"
#include "d_random.h"
#include <Windows.h>
#include <conio.h>

using namespace std;

template <typename T>
void write( vector<T>& t,const int n ){
	int i=0;
	vector<T> v;

	v=t;
	for( i=0 ; i<n ; i++ ){
	
		if( !v[i].empty() )
				cout<<"Counter"<<i+1<<" : ";

		while( !v[i].empty() ){
					cout<<"M"<<i+1<<" -"<<v[i].front()<<" ";
					v[i].pop();
				}
				cout<<endl;
	}	
}

int main()
{
	int i=0;
	int n;
	int counter,r;
	randomNumber rnd;
	vector<int> client;
	vector<bqueue<int>> v;
	int time=0;

	cout<<"Please Enter Number of Counters: ";
	cin>>n;
	system("cls");

	v.resize(n);
	client.resize(n);

	while(1){

		r=rnd.random(2);
		counter=rnd.random(n);

		if( r==0 ){
			cout<<"Incoming Transaction: APPEND "<<endl;
			cout<<"Counter No:"<<counter+1<<endl;
			client[counter]++;	
			v[counter].push(client[counter]);
		}
		else{
			cout<<"Incoming Transaction: SERVE "<<endl;

			if( v[counter].empty() )
				cout<<"No any waiting clients in Counter-"<<counter+1<<"!!!"<<endl;
			else{
				cout<<"Counter No:"<<counter+1<<endl;
				v[counter].pop();
					if( v[counter].empty() )
						client[counter]=0;
			}
		}

			cout<<endl;	
				write(v,n);
			cout<<endl;

		cout<<"Time : "<<time<<" seconds"<<endl;
		time+=5;


		 if(kbhit())
        {
			char ch;
			ch=cin.get();
			cout<<"Simulation is terminated !!!"<<endl;
			system("pause");
            return 0;
        }

		Sleep(5000);
		system("cls"); //clear screen

	}//while

	system("pause");
	return 0;
}