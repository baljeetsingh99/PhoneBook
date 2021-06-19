#include <bits/stdc++.h>
#include <fstream>
#include<string>
#include<windows.h>

using namespace std;

class LoginManager
{
	private:
        string passWord = "toor";
        string userName = "root";
	public:
		string userNameAttempt;
        string passWordAttempt;
        
        void wrongcred()
		{
			LoginManager log;
			cout<<" \t\t\t wrong credentials: \n";
            cout<<" \t\t\t 1. retry\n";
            cout<<" \t\t\t 2. exit\n";
           	cout<<"\t\t\t -----> ";
           	char a;
			cin>>a;
           	cin.ignore();
           	switch(a)
           	{
           		case'1':
				   {	
            			log.login();
				   }
			    case'2':
					{
				        exit(0);
					}
				default:
				    {
						cout<<"\t\t\t Wrong Choice: Exiting...";
						Sleep(1000);
						exit(0);
					}
			}
        }
	
        void login()
		{
            cout <<"\t\t\t *-*-*-*-*-* LOGIN WINDOW *-*-*-*-*-* \n";
            cout<<endl;
			cout<<"\t\t\t USERNAME : ";
			cin >> userNameAttempt;
            if(userNameAttempt==userName)
			{
                cout << "\t\t\t PASSWORD : ";
                cin >> passWordAttempt;
                if(passWordAttempt==passWord)
				{
					cout<<endl;
                    cout << "\t\t\t<< *-*-*-*-*-* YOU ARE LOGGED IN *-*-*-*-*-* \n";
                }
                else
                {
                	wrongcred();
				}
            }
            else
            {
            	wrongcred();
			}
        }
    
};

void start()
{
	system("Color 0A");
	cout<<"\n\n\n\n\n\n\n\n";
	cout<<"\t\t\tPlease wait loading records....";
	char x = 219;
	for(int i=0; i<35; i++)
	{
		cout<<x;
		if(i<10)
		{
			Sleep(800);
		}
		if(i>=10 && i<20)
		{
			Sleep(50);
		}
		if(i>=10)
		{
			Sleep(25);
		}
	
	}
	system("cls");
}



class detail
{
	private:
		string fname;
		string lname;
        string number;
        string email;
        string address;
    public:
    	void add_contact();
    	void view_contact();
    	void search_contact();
    	void delete_contact();
    	void modify_conatct();
    	
		
};
bool check_digits(string);
bool check_numbers(string);


class encdec
{
	int key;
	string fle="Contacts.txt";
	char c;
	public:
		void encrypt();
		void decrypt();
};
void encdec::encrypt()
{
	cout<<"key: ";
	cin>>key;
	ifstream fin;
	ofstream fout;
	fin.open(fle, ios::binary);
	fle = "EncCont.txt";
	fout.open(fle, ios::binary);
	while(!fin.eof())
	{
		fin>>noskipws>>c;
		int temp=(c+key);
		fout<<(char)temp;
	}
	fin.close();
	fout.close();
	
}

void encdec::decrypt()
{
	cout<<"key: ";
	cin>>key;
	ifstream fin;
	ofstream fout;
	fin.open("EncCont.txt", ios::binary);
	fle = "DecCont.txt";
	fout.open(fle, ios::binary);
	while(!fin.eof())
	{
		fin>>noskipws>>c;
		int temp=(c-key);
		fout<<(char)temp;
	}
	fin.close();
	fout.close();
}


bool check_digits(string x)
{
	if(x.length()==10)
	{
		return true;
	}
	else
	{
		return false;
	}
}
bool check_numbers(string x)
{
	bool check=true;
	
	for(int i=0; i<x.length(); i++)
	{
		if(!(int(x[i]) >= 48 && int(x[i]) <= 57 ))
		{
			check = false;
			break;
		}
	}
	if(check==true)
	{
		return true;
	}
	if(check==false)
	{
		return false;
	}
}

void detail::delete_contact()
{
	cout<<"Enter first name : ";
	string nam;
	cin>>nam;
 
 	fstream fle;
	fle.open("Contacts.txt");

	ofstream tmp;
    tmp.open("temp.txt", ios::app);
	
	fle >> fname >> lname >> email >> address >> number;
	
	while(!fle.eof())
	{
		if(fname!=nam)
		{
			tmp <<fname<<" "<<lname<<"\t"<<email<<setw(10)<<address<<setw(15)<<number<<endl;
		}
		else
		{
			cout<<"\t\t\t\t    Searching ";
			char x = 175;
        	for(int i=0; i<25; i++)
        	{
        		cout<<x;
			    if(i<10)
		        {
			        Sleep(800);
		        }
		        if(i>=10 && i<20)
		        {
			        Sleep(50);
		        }
		        if(i>=20)
		        {
			        Sleep(25);
		        }
		    }
		    cout<<"\n \n";
			cout<<"\t\t\t\t*-*-*-*-*-* Record Found *-*-*-*-*-*-*\n";
			cout<<"\n";
			
				cout<<"\t\t\t\t\tDeleting...";
	             x = 219;
				for(int i=0; i<35; i++)
				{
					cout<<x;
					if(i<10)
					{
						Sleep(800);
		            }
		            if(i>=10 && i<20)
	             	if(i>=10)
		            {
			            Sleep(25);
		            }
	            }
	           // system("cls");
			  
			cout<<"\n";
			cout<<"\n\t\t\t\t*-*-*-*-*-* Record Deleted *-*-*-*-*-*\n";
		}
		fle >> fname >> lname >> email >> address >> number;
	}
	tmp.close();
	fle.close();
	
	remove("Contacts.txt");
	/*{
		cout<<"file not removed";
	}
	else
	{
		cout<<"removed file";
	}*/
	rename("temp.txt","Contacts.txt");
	/*{
		cout<<"file not renmaed";
	}
	else
	{
		cout<<"renamed";
	}*/
	
}
void detail::search_contact()
{
	bool found = false;
	ifstream myfile("Contacts.txt");
	string keyword;
	cout<<"enter name : ";
	cin>>keyword;
	while(myfile >> fname >> lname >> email >> address >> number)
	{
		if(keyword == fname || keyword== lname)
		{
			system("cls");
			
			cout<<setw(20)<<"Name"<<setw(20)<<"LastName"<<setw(20)<<"email"<<setw(20)<<"Address"<<setw(20)<<"Number"<<setw(20)<<endl;
			cout<<setw(20)<<fname<<setw(20)<<lname<<setw(20)<<email<<setw(20)<<address<<setw(20)<<number;
			found = true;
			break;
		}
	}
	if(found==false)
	{
		cout<<"no data found";
	}
}

void detail::view_contact()
{
	Sleep(2000);
	string line;
	ifstream f;
	f.open("Contacts.txt");
	if(f.is_open())
	{
		
		cout<<setw(10)<<"Name"<<" "<<"LastName"<<setw(15)<<"email"<<setw(15)<<"Address"<<setw(15)<<"Number"<<endl;
		
		while(getline(f, line))
		{
			cout<<setw(60)<<line<<endl;
		}
		f.close();
	}
	else
	{
		cout<<"***** File can't open *****";
	}
	
}


void detail::add_contact()
{
		ofstream f;
        f.open("Contacts.txt", ios::app);
	
		cout << "First Name : ";
        getline(cin,fname);
        
        cout<<"last name: ";
        getline(cin,lname);
    
        cout << "E-mail : ";
        getline(cin,email);
    
        cout << "Address : ";
        getline(cin,address);
        
		cout << "Mobile Number : ";
        getline(cin,number);
        
        if(check_digits(number)==true)
        {
        	if(check_numbers(number)==true)
        	{
        		if(f.is_open())
        		{
        			 f<<fname<<" "<<lname<<"\t"<<email<<setw(10)<<address<<setw(15)<<number<<endl;
				}
        	
			}
			else
			{
				cout<<"contain numbers only";
			}
		}
		else
		{
			cout<<"write coreect number";
		}
       
        f.close();
}
void detail::modify_conatct()
{
	//////////////////////////////////////////////////////////
}


int main()
{
	LoginManager log;
	log.login();
    start();
    cout<<R"(
                _____    __    __    ______   .__   __.  _______ .______     ______     ______    __  ___ 
              |   _  \  |  |  |  |  /  __  \  |  \ |  | |   ____||   _  \   /  __  \   /  __  \  |  |/  / 
              |  |_)  | |  |__|  | |  |  |  | |   \|  | |  |__   |  |_)  | |  |  |  | |  |  |  | |  '  /  
              |   ___/  |   __   | |  |  |  | |  . `  | |   __|  |   _  <  |  |  |  | |  |  |  | |    <   
              |  |      |  |  |  | |  `--'  | |  |\   | |  |____ |  |_)  | |  `--'  | |  `--'  | |  .  \  
              | _|      |__|  |__|  \______/  |__| \__| |_______||______/   \______/   \______/  |__|\__\ 
                                                                                                   
                         .-----------------------------------------------------------------.
                         | .-------------------------------------------------------------. |
                         | |                                                             | |
                         | |                                                             | | 
                         | |          cout<<"1. Add contact: ";                          | |
                         | |          cout<<"2. View All Contacts:";                     | |
                         | |          cout<<"3. Search for contact:";                    | |
                         | |          cout<<"4. Delete Contact: ";                       | |
                         | |          cout<<"5. Modify contact: ";                       | |
                         | |          cout<<"6. Encrypt contacts file:";                 | |
                         | |          cout<<"7. Decrypt contacts file";                  | |
                         | |          cout<<"8. exit";                                   | |
                         | |                                                             | |                            
                         | |_____________________________________________________________| |
                         |_________________________________________________________________|                                     
)";
    detail det;
    encdec enc;
	char c;
	do
	{
		cout<<"\n";
		cout<<"Enter Your Choice : -> ";
		cin>>c;
		cin.ignore();
		switch(c)
		{
			case '1':
				{
					det.add_contact();
				    break;
                }
            case '2':
            	{
        		    det.view_contact();
        		    break;
			    }
		    case '3':
			    {
				    det.search_contact();
				    break;
			    }
		    case'4':
			    {
			    	
				    det.delete_contact();
				    break;
			    }
		case'5':
			{
				det.modify_conatct();
				break;
			}
		    case'6':
			    {
				    enc.encrypt();
				    break;
			    }
		    case'7':
			    {
				    enc.decrypt();
				    break;
			    }
		    case'8':
			    {
				    return 0;
				    exit(0);
				    break;
			    }
		    default:
			    {
				    cout<<"Wrong Input!!";
				    return 0;
				    exit(0);
			    }		    
	   }
	  
   }
    while(true);
}
