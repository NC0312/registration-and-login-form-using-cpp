#include <bits/stdc++.h>
#include <fstream>

using namespace std;

void login();
void registration();
void forgot();

int main()
{
	int c;  //choice of the user whether he want to login,or register as a new user,or forgot the pwd...
	cout<<"\t\t\t____________________________________________________\n\n\n";
	cout<<"\t\t\t             Welcome To The Login Page              \n\n\n";
	cout<<"\t\t\t_______________         MENU        ________________\n\n\n";
	cout<<"                                                            \n\n";
	cout<<"\t\t\t\t | Press 1 to Login                   |"<<endl;
	cout<<"\t\t\t\t | Press 2 to Register as a new user  |"<<endl;
	cout<<"\t\t\t\t | Press 3 if you forgot your password|"<<endl;
	cout<<"\t\t\t\t | Press 4 to exit                    |"<<endl;
	cout<<"\n\n\t\t\t\t Please enter your choice: ";
	cin>>c;
	cout<<endl;
	
	switch(c){
		case 1:
			login();
			break;
		
		case 2:
			registration();
			break;
	    
	    case 3:
	    	forgot();
	    	break;
	    case 4:
	    	cout<<"\n\n\t\t\t\t\t Thank You!! \n\n";
	    	break;
	    
		default:
			system("cls");//this will clear screen after execution 
	    	cout<<"\t\t\t Please select from the options given above \n\n"<<endl;
	    	main();
	}
}


//User already have an account and trying to log in...
void login()
{
	int count;
	string userId,password,id,pass;
	
	system("cls");
	cout<<"\t\t\t\t Please Enter Username and password: "<<endl;
	cout<<"\t\t\t\t Username: ";
	cin>>userId;
	cout<<"\t\t\t\t Password: ";
	cin>>password;
	
	//ifstream class is used to read the data from the file...
	ifstream input("records.txt");  //records.txt is the file here which has all the info of registered user and will verify login info from there...
	
	while(input>>id>>pass)   //Here we are reading using file handling operations...
	{
		if(id==userId && pass==password)  //if credentials are correct...
		{
			count=1;
			system("cls");
		}
	}
	input.close(); //After verifying close the file...
	
	if(count==1)  //Login Success!!
	{
	   cout<<userId<<"\n Your LOGIN is successfull \n Thanks for logging in! \n";
	   main();	
	}
	else{     //Login FAIL...
		cout<<"\n LOGIN ERROR \n Please check again your username or password \n";
		main();
	}
}

//User don't have an account and registring as a new user...
void registration()
{
	string ruserId,rpassword,rid,rpass;
	system("cls");
	
	cout<<"\t\t\t\t Enter The Username: ";
	cin>>ruserId;
	cout<<"\t\t\t\t Enter The Password: ";
	cin>>rpassword;
	
	//ofstream class is used to write inside the file...
	ofstream f1("records.txt",ios::app);  //f1 is the object name and using ios::app we are using the app mode...
	f1<<ruserId<<' '<<rpassword<<endl;  //writing in the file...
	system("cls");
	cout<<"\n\n\t\t\t\t Registration is Successfull \n";
	main();
}

//If user forogot the password...
void forgot()
{
	int option;
	system("cls");
	
	cout<<"\n\t\t\t\t You forgot the password?? No Worries \n";
	cout<<"\n\t\t\t\t Press 1 to search your id by username"<<endl;
	cout<<"\n\t\t\t\t Press 2 to go back to main menu"<<endl;
	
	cout<<"\n\t\t\t\t Enter Your Choice: ";
	cin>>option;
	
	switch(option)
	{
		case 1:    //searching the id using username...
		{
			int count=0;
			string suserId,sId,spass;  //suserId is the username user is searching for... 
			cout<<"\n\t\t\t\t Enter the username that you remembered ";
			cin>>suserId;
			
			ifstream f2("records.txt");   //Reading the records.txt file...
			while(f2>>sId>>spass)
			{
				if(sId==suserId){
					count=1;
				}
			}
			f2.close();  //After getting the credentials close the file...
			
			if(count==1)   //Credentials Found...
			{
				cout<<"\n\t\t\t\t Your Account Is Found!! \n";
				cout<<"\n\t\t\t\t Your Password Is: "<<spass;
				main();
			}
			else{
				cout<<"\n\t\t\t\t Sorry!!Your Account Is Not Found \n";
				main();
			}
			break;
		}
		case 2:
		{    //Taking back to main menu...
			main();
		}
		default:
			cout<<"\n\t\t\t\t Wrong Choice!! Please Try Again..."<<endl;
			forgot();
	}
}









