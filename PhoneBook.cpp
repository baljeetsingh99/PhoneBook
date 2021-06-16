#include <bits/stdc++.h>
#include <fstream>
#include<string>
#include<windows.h>

using namespace std;


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

void sercont()
{
	int count=0;
	fstream file;
	string name;
	string arrow;
	string namee;
    string number;
    string email;
    string address;
	cout<<"name: ";
	
    getline(cin,namee);
	file.open("Contacts.txt",ios::in);    //ios::out - write ios::in - read
	file >>name>>number>>email>>address;   //<<write //>>read
	while(!file.eof())
	{
		if(namee==name)
		{
			cout<<name<<number<<email<<address;
			count++;
			break;
		}
		file>>name>>number>>email>>address;
	}
	file.close();
	if(count==0)
	cout<<"record not found";
}

void viewcont()
{
	
	string line;
	ifstream file("Contacts.txt");
	if(file.is_open())
	{
		while(getline(file, line))
		{
			cout<<line<<'\n';
		}
		file.close();
	}
	else
	{
		cout<<"***** File can't open *****";
	}
	
}

void addcont()
{
	string name;
    string number;
    string email;
    string address;
	string quit = "y";
	ofstream File;
    File.open("Contacts.txt", ios::app);
    while(quit!="n")
	{
		cout << "Full Name : ";
        getline(cin, name);
    
        cout << "Mobile Number : ";
        getline(cin, number);
    
        cout << "E-mail : ";
        getline(cin, email);
    
        cout << "Address : ";
        getline(cin, address);
    
	    File << name <<" "<<number<<" "<<email<<" "<<address<<endl;
        cout << "Add New Contact (y/n)? ";
        
		getline(cin, quit);
    }
    File.close();
}

int main()
{
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
                         | |                                                             | |
                         | |                                                             | |                            
                         | |_____________________________________________________________| |
                         |_________________________________________________________________|                                     
)";
    cout<<"Enter Your Choice : -> ";
    char c;
	cin>>c;
    cin.ignore();
	switch(c)
    {
    	case '1':
    		{
    			addcont();
				break;
            }
        case '2':
        	{
        		viewcont();
        		break;
			}
		case '3':
			{
				sercont();
				break;
			}
		/*case'4':
			{
				sercont();
				break;
			}
		case'5':
			{
				modcont();
				break
			}*/
		case'6':
			{
				encdec enc;
				enc.encrypt();
				break;
			}
		case'7':
			{
				encdec dec;
				dec.decrypt();
				break;
				
			}
	}
    
  
}
