#include<iostream>
#include<string>
using namespace std;
class node
{   public:
    string name;
    bool vanilla;
    bool butterscotch;
    node *next;
};

class info
{        
    node* head=NULL;
       
    public:
    node* create();
    void insert(string,bool,bool);
    void vnb();
    void vxorb();
    void neither();             
            
};        
node* info:: create()
{
    node* temp;
    temp=new node();
    temp->vanilla=false;
    temp->butterscotch=false;
    temp->next=NULL;
    return temp;
}

void info:: insert(string name,bool v,bool b)
{
    node* t=create();
    t->name=name;
    t->vanilla=v;
    t->butterscotch=b;
    node* p = head;
    if(head==NULL)
    {
        head=t;
    }

    else
    {
        while(p->next!=NULL)
        {
            p=p->next;
        }
        p->next=t;
    }
}

void info::vnb()
{
    cout<<"List of students who like both Vanilla and Butterscotch:\n";
    node* t=head;
    if(head==NULL)
    {
        cout<<"List is empty!\n";
    }
    while(t!=NULL)
    {
        if(t->vanilla==true and t->butterscotch==true)
        {
            cout<<t->name<<endl;
        }
        t=t->next;
    }
}

void info::vxorb()
{
    cout<<"List of students who like either Vanilla or Butterscotch but not both:\n";
    node* t=head;
    if(head==NULL)
    {
        cout<<"List is empty!\n";
    }
    while(t!=NULL)
    {
        if((t->vanilla==true and t->butterscotch==false) || (t->vanilla==false and t->butterscotch==true))
        {
            cout<<t->name<<endl;
        }
        t=t->next;
    }
}

void info::neither()
{
    cout<<"List of students who like neither Vanilla nor Butterscotch:\n";
    node* t=head;
    if(head==NULL)
    {
        cout<<"List is empty!\n";
    }
    while(t!=NULL)
    {
        if(t->vanilla==false and t->butterscotch==false)
        {
            cout<<t->name<<endl;
        }
        t=t->next;
    }
}

 
int main()
  { 
      info obj;
      int i;
      string name;
      bool v,b;
      char ch;
       do
       {
          cout<<"\nMenu-\n";
          cout<<"\n1. Add student data";
          cout<<"\n2. To display the names of students who like vanila or butterscotch";
          cout<<"\n3. To display the names of students who like both vanila and butterscotch ";
          cout<<"\n4. To display the names of students who neither like vanila nor butterscotch";
          cout<<"\n5. Exit\n";
          cout<<"\nEnter choice: ";
          cin>>i;
          switch(i)
          {        
              case 1:   cout<<"Enter name: ";
                        cin>>name;
                        cout<<"Like vanilla ice-cream?(y/n): ";
                        cin>>ch;
                        if(ch=='y' or ch=='Y')
                            v=true;
                        else
                            v=false;
                        
                        cout<<"Like butterscotch ice-cream?(y/n): ";
                        cin>>ch;
                        if(ch=='y' or ch=='Y')
                            b=true;
                        else
                            b=false;
                        
                        obj.insert(name,v,b);
                        break;
         
              case 2:    obj.vnb(); 
                        break;

              case 3:   obj.vxorb();
                        break;

              case 4:   obj.neither();
                        break; 

              case 5:   
                        break;    
                
              default:  cout<<"\n Wrong choice entered, please try again.\n";
          }
       cout<<"--------------------------------------------------------------------\n";
       }while(i!=5);   

return 0;
}