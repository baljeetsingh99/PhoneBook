#include <bits/stdc++.h>
#include <fstream>

using namespace std;

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
    
	    File << name <<" -> "<<number<<" -> "<<email<<" -> "<<address<<endl;
        cout << "Add New Contact (y/n)? ";
        
		getline(cin, quit);
    }
    File.close();
}

int main()
{
    char c;
  	cout << "**** PHONEBOOK ******" << endl;
  	cout<<endl;
    cout<<"1. Add contact: "<<endl;
    cout<<"2. Delete contact: "<<endl;
    cout<<"3. View all contacts: "<<endl;
    cout<<"4. Search for contact: "<<endl;
    cout<<"5. Modify contact: "<<endl;
    cout<<"6. Encrypt contacts file"<<endl;
    cout<<"7. Decrypt contacts file"<<endl;
    cin>>c;
    cin.ignore();
	switch(c)
    {
    	case '1':
    		{
    			addcont();
				break;
            }
       /* case '2':
        	{
        		delcont();
        		break;
			}
		case '3':
			{
				viewcont();
				break;
			}
		case'4':
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
