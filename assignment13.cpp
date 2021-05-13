#include <iostream>
#define MAX 5
#include<string>
using namespace std;

class Queue
{    string data[MAX];
	int front,rear;
   public:
      Queue()
      {
          front=-1;
          rear=-1;
      }
      bool isempty();
      bool isfull();
      void addtoqueue(string);
      void delqueue();
      void display();
};
bool Queue::isempty()
{
	return(rear==front == -1)?1:0;
}
bool Queue::isfull()
{    return((front==0 and rear==MAX-1)or (front==rear+1))?1:0;}

void Queue::addtoqueue(string x)
{
    if(isfull())
    {   
        cout<<"Queue is full!"<<endl;
        return;
    }


    string ch;
    cout<<"Insert at front or rear(f/r)? : ";
    cin>>ch;
    if(ch=="F"||ch=="f"||ch=="r"||ch=="R")
    {
        if(ch=="r" ||ch=="R")
        {
            if (front == -1) { 
                front = 0; 
                rear = 0; 
            } 
            else if (rear == MAX-1)               // rear is at last position of queue
                rear = 0; 
            else                            // increment rear by 1 position 
                rear = rear+1; 
            
            data[rear]=x;
            cout<<"Added data \""<<x<<"\" to queue successfully at rear!\n";
        }
        else if(ch=="F"||ch=="f")
        {
            if (front == -1)  { 
                front = 0; 
                rear = 0; 
            } 
            else if (front == 0)              // front is first position of queue 
                front = MAX - 1 ; 
            else // decrement front 1 position 
                front = front-1;
            data[front]=x;
            cout<<"Added data \""<<x<<"\" to queue successfully at front!\n";
        }
    }
    
}

void Queue::delqueue()
{
    string ch;
    if(isempty())
    {
        cout<<"Queue is empty!"<<endl;
        return;
    }
    cout<<"Delete at front or rear(f/r)? : ";
    cin>>ch;
    if(ch=="F"||ch=="f"||ch=="r"||ch=="R")
    {
        if(ch=="r" ||ch=="R")
        {
            if (front == rear) 
                { 
                    front = -1; 
                    rear = -1; 
                } 
            else if (rear == 0) 
                rear = MAX-1; 
            else
                rear = rear-1;
            
        }
        else if(ch=="F"||ch=="f")
        {   
            if (front == rear) 
                { 
                    front = -1; 
                    rear = -1; 
                } 
            else
            {
        // back to initial position 
                if (front == MAX -1) 
                    front = 0; 
   
            else // remove current front value from Deque;increment front by 1
                front = front+1; 
            }
        }
    }
}

void Queue::display()
{  
    cout<<"\n";
    if (isempty())
{
cout << "\n\t Deque is Empty...!!!" << endl;
return;
}
int i = front;
while( i != rear )
{
cout << data[i] << " ";
i = (i+1)%(MAX);
}
cout << data[i];
    cout<<"\n";
}
int main()
{   
    Queue obj;
    int ch;
    string x;
	do{    
            cout<<"<Max. Size of Dequeue has been set to 5>"<<endl;
           cout<<"1.insert data\n2.delete data\n3.display data\n4.Exit\nEnter your choice: ";
	       cin>>ch;
	switch(ch)
	{  case 1: 
		            cout<<"\nEnter data to be stored :";
			        cin>>x;
			        obj.addtoqueue(x);
	          
	          break;
	   case 2: if(!obj.isempty())
                {
			        cout<<"\n Deleting data: "<<endl;
                    obj.delqueue();
                }
		       else
			    {   cout<<"\nQueue is in underflow";  }
	           break;
	  case 3: if (!obj.isempty())
	        {  cout<<"\nQueue contains:\n";
		       obj.display();
               cout<<"\n--------------------------------------------------\n";
	        }
	        else
		         cout<<"\nQueue is empty, try adding new data.\n";
                 
	       break;
	  case 4: cout<<"\nExit";
    }
    }while(ch!=4);

    return 0;
}