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
        bool accessGranted;
	public:
		string userNameAttempt;
        string passWordAttempt;
	
        void login()
		{
            cout <<"\t\t\t"<<" *-*-*-*-*-*-*-* LOGIN WINDOW *-*-*-*-*-*-*-* \n";
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
                    cout << "\t\t\t<<"<<" *-*-*-*-*-*-*-* YOU ARE LOGGED IN *-*-*-*-*-*-*-* \n";
                }
            }
        }
    
};
void start()
{
	system("Color 0A");
	cout<<"\n\n\n\n\n\n\n\n";
	cout<<"\t\t\t\t\tLOADING....";
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
        			 f<<setw(10)<<fname<<" "<<lname<<"\t"<<email<<setw(10)<<address<<setw(15)<<number<<endl;
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
                         | |          cout<<"4.  Delete Contact: ";                      | |
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
		  //  case'4':
			    {
			    	char n;
			    	cin>>n;
				    det.delete_contact();
				    break;
			    }
		/*case'5':
			{
				modcont();
				break
			}*/
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
				    cout<<"Wrong Inpur!!";
				    return 0;
				    exit(0);
			    }		    
	   }
	  
   }
    while(true);
}
