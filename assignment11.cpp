#include <iostream>
#define MAX 20
#include<string>
using namespace std;

class queuedata
{   
	public:
	string data[MAX];
	int front,rear;
};

class Queue
{    queuedata q;
   public:
      Queue()
      {
          q.front=q.rear=-1;
      }
      int isempty();
      int isfull();
      void addtoqueue(string);
      string delqueue();
      void display();
};
int Queue::isempty()
{
	return(q.front==q.rear)?1:0;
}
int Queue::isfull()
{    return(q.rear==MAX-1)?1:0;}

void Queue::addtoqueue(string x)
{
	q.data[++q.rear]=x;
	cout<<"Added job \""<<x<<"\" to queue successfully!\n";
}

string Queue::delqueue()
{
	string re=q.data[q.front+1];
	q.front++;
	return re;

}

void Queue::display()
{   int i;
    cout<<"\n";
    for(i=q.front+1;i<=q.rear;i++)
	     cout<<q.data[i]<<" ";
}
int main()
{   Queue obj;
	int ch;
    string x;
	do{    cout<<"\n1.insert job\n2.delete job\n3.display\n4.Exit\nEnter your choice: ";
	       cin>>ch;
	switch(ch)
	{  case 1: if (!obj.isfull())
		   {   cout<<"\nEnter job name/description :";
			cin>>x;
			obj.addtoqueue(x);
		   }
	          else
		      cout<< "Queue is overflow";
	           break;
	   case 2: if(!obj.isempty())
			    cout<<"\nDeleted job (from front): "<<obj.delqueue();
		    else
			{   cout<<"\nQueue is underflow";  }

		    cout<<"\nRemaining jobs :";
		    obj.display();
	           break;
	  case 3: if (!obj.isempty())
	        {  cout<<"\nQueue contains:\n";
		       obj.display();
               cout<<"\n--------------------------------------------------\n";
	        }
	        else
		         cout<<"\nQueue is empty, try adding new jobs.\n";
	       break;
	  case 4: cout<<"\nExit";
        }
      }while(ch!=4);
return 0;
}