THE COMMENT LINES SHOWS THE CONCEPT USED IN THE FOLLOWING PROGRAM
/*1.SCOPE RESOLUTION OPERATOR USED
  2.CLASSES AND OBJECTS
  3.FRIEND FUNCTIONS
  4.CONSTRUCTOR AND DESTRUCTOR(USE OF CONSTRUCTOR,CONSTRUCTOR OVERLOADING )
  5.INHERITANCE(VIRTUAL CLASSES,MULTIPLE INHERITANCE AND HYBRID INHERITANCE)
  6.OPERATOR OVERLOADING
  7.POLYMORPHISM(FUNCTION OVERLOADING)
  8.EXCEPTION HANDLING
*/
#include<iostream>
#include<string.h>
using namespace std;
class Football //CLASS IMPLEMENTATION
{
	protected: //ACCESS SPECIFIER
    	char Nationality[20]; //DATA MEMBER
	public:
	    Football();   //CONSTRUCTOR
		Football(char Nat[])  //PARAMETRISED CONSTRUCTOR
		{
			for(int i=0;i<strlen(Nat);i++)
			{
				Nationality[i]=Nat[i];
			}
		}
		  
};
Football::Football()           //SCOPE RESOLUTION OPERATOR
{
	cout<<"ENTER NATIONALITY: ";
	cin>>Nationality;
}
class Player:virtual public Football   //VIRTUAL CLASS AND INHERITANCE
{
	protected:
	    char Name[10];
	    int Age;
	public:
		void getdata()        //MEMBER FUNCTION
		{
			cout<<"ENTER NAME: ";
			cin>>Name;
			cout<<"ENTER AGE: ";
			cin>>Age;
		}
};
class Stats:virtual public Football 
{
	protected:
     	int Goals;
	    int Assists;
	public:
		void getgoals()
		{
			cout<<"ENTER GOALS: ";
			cin>>Goals;
		}
		void getassist()
		{
			cout<<"ENTER ASSISTS: ";
			cin>>Assists;
		}
		void checkgoal()
		{
			cout<<"ENTER GOALS: ";
			cin>>Goals;
			try                  //EXCEPTION HANDLING...
			{
			    if(Goals<0)
			    {
				    throw Goals;
			    }
		    }
			catch(int g)
			{
				cout<<"\nEXCEPTION OCCURED---GOALS CAN'T BE NEGATIVE "<<endl;
				cout<<"THE EXPECTION NUMBER IS "<<Goals<<endl;
			}
		}
};
class Overall:public Player,public Stats //MULTIPLE INHERITANCE
{
    int Salary;
    int NetWorth;
	public:
		void get()   
		{
			cout<<"ENTER SALARY: ";
			cin>>Salary;
			cout<<"ENTER NETWORTH: ";
			cin>>NetWorth;
		}
		void get(int Sal,int Net)  //FUNCTION OVERLOADING
		{
			Salary=Sal;
			NetWorth=Net;
		}
		void Display()
		{
			cout<<"NAME: "<<Name<<endl;
			cout<<"AGE: "<<Age<<endl;
			cout<<"NATIONALITY: "<<Nationality<<endl;
			cout<<"NUMBER OF GOALS: "<<Goals<<endl;
			cout<<"NUMBER OF ASSISTS: "<<Assists<<endl;
			cout<<"SALARY: "<<Salary<<endl;
			cout<<"NETWORTH: "<<NetWorth<<endl;
		}
		void operator==(class Overall&); //OPERATOR OVERLOADING
		friend void compnet(class Overall&,class Overall&); //USE OF FRIEND FUNCTION
};
void Overall::operator==(class Overall& n)
{
	if(Goals!=n.Goals)
	{
		if(Goals>n.Goals)
		{
			cout<<n.Name<<" HAS PERFORMED BETTER."<<endl;
		}
		else
		{
			cout<<n.Name<<" HAS PERFORMED BETTER."<<endl;
		}
	}
	else
	{
		if(Assists>n.Assists)
		{
			cout<<Name<<" HAS PERFORMED BETTER."<<endl;
		}
		else
		{
			cout<<n.Name<<" HAS PERFORMED BETTER."<<endl;
		}
	}
}
void compnet(class Overall&m,class Overall&n)
{
	if(m.NetWorth>n.NetWorth)
	{
		cout<<m.Name<<" HAS MORE NETWORTH.."<<endl;
	}
	else if(m.NetWorth>n.NetWorth)
	{
		cout<<m.Name<<" AND "<<n.Name<<" HAVE SAME NETWORTH.."<<endl;
	}
	else
	{
		cout<<n.Name<<" HAS MORE NETWORTH.."<<endl;
	}
}
template<class T>  //TEMPLATE IMPLEMENTATION
class Performance  //TEMPLATE CLASS
{
	T p[10];
	int size;
	public:
		Performance()
		{
			size=0;
		}
		void AddPer()
		{
			int i,ch;
			T value;
			do
			{
				cout<<"\nENTER THE VALUE: ";
				cin>>value;
				p[size]=value;
				size++;
				cout<<"\nDO YOU WANT TO ADD ELEMENTS? ";
				cin>>ch;
			}while(ch==1);
		}
		void modify()
		{
			int k;
			T n;
			cout<<"\nENTER INDEX FOR MODIFICATION: ";
			cin>>k;
			cout<<"\nENTER NUMBER OF GOALS: ";
			cin>>n;
			p[k]=n;
		}
		void display()
		{
			cout<<"\nGOAL SCORED IN "<<size<<" MATCHES ARE: "<<endl;
			cout<<"[";
			for(int i=0;i<size;i++)
			{
				cout<<p[i]<<",";
			}
			cout<<"]";
		}
};
int main()
{
	Overall p;   //OBJECT
	Overall *q;  //POINTER TO CLASS
	Overall r;
	p.getdata();   //"." OPERATOR
	p.getgoals();
	p.getassist();
	p.get();
	p.Display();
	r.getdata();  
	r.getgoals();
	r.getassist();
	r.get(200000,3000000);
	r.Display();
	p==r;
	compnet(p,r);
	int c;
	Performance<int>obj;
	do
	{
		cout<<"\n 1.CREATE \n 2.MODIFY \n 3.DISPLAY \n";
		cout<<"ENTER CHOICE: ";
		cin>>c;
		switch(c)
		{
			case 1:
				obj.AddPer();
				break;
			case 2:
				obj.modify();
				break;
			case 3:
				obj.display();
				break;
			default:
				cout<<"\nINVALID.";
				break;
	    }
	}while(c!=0);
	Stats s;
	s.checkgoal();
}
