#include <bits/stdc++.h>
#include <fstream>
using namespace std;
int main()
{
  ofstream outFile;
  outFile.open("Contacts.txt", ios::app);
  string quit = "y";
  string name;
  string number;
  string email;
  string address;
  while (quit != "n") 
  {
    cout << "Full Name : ";
    getline(cin, name);
    
    cout << "Mobile Number : ";
    getline(cin, number);
    
    cout << "E-mail : ";
    getline(cin, email);
    
    cout << "Address : ";
    getline(cin, address);
    
	outFile << name <<" -> "<<number<<" -> "<<email<<" -> "<<address<<endl;
    cout << "Add New Contact (y/n)? ";
    getline(cin, quit);
  }
  outFile.close();
  return 0;
}
