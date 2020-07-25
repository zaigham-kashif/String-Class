#include<iostream>
#include<fstream>
#include"MyString.h"

using namespace std;

int main()
{
	int option_1, option_2;

	ofstream fout;
	ifstream fin;
	MyString str1,str2,str3;

	cout << "	Enter string 1 : ";
	cin >> str1;
	cout << endl;
	
	cout << "	Enter string 2 : ";
	cin >> str2;
	cout << "	" << str2;
	cout << endl;

	do
	{
		system("CLS");
		cout << "	-------------------------------------" << endl;
		cout << "	Select an option from the menu below " << endl;
		cout << "	-------------------" << endl;
		cout << "	1->Add Strings" << endl;
		cout << "	-------------------" << endl;
		cout << "	2->Subtract strings" << endl;
		cout << "	-------------------" << endl;
		cout << "	3->Compare Strings" << endl;
		cout << "	-------------------" << endl;
		cout << "	4->Print String 1" << endl;
		cout << "	-------------------" << endl;
		cout << "	5->Print String 2" << endl;
		cout << "	-------------------" << endl;
		cout << "	6->Edit  String 1" << endl;
		cout << "	-------------------" << endl;
		cout << "	7->Edit  String 2" << endl;
		cout << "	-------------------" << endl;
		cout << "	8->Write to file" << endl;
		cout << "	-------------------" << endl;
		cout << "	9->Read From File" << endl;
		cout << "	-------------------" << endl;
		cout << "	0->Exit" << endl;
		cout << "	-------------------" << endl;
		cout << "	";
		cin >> option_1;
		cin.ignore();

		if (option_1 == 1)
		{
			str3 = str1 + str2;
			cout << "	" << str3;
			cout << endl;
			system("pause");
		}
		else if (option_1 == 2)
		{
			str3.Clear();
			str3 = str1 - str2;
			cout << "	" << str3;
			cout << endl;
			system("pause");
		}
		else if (option_1 == 3)
		{
			do
			{
				system("CLS");
				cout << "	--------------------------------" << endl;
				cout << "	Select an option from menu below" << endl;
				cout << "	--------------------------------" << endl;
				cout << "	1->Equal To Comparison" << endl;
				cout << "	--------------------------------" << endl;
				cout << "	2->Not Equal To Comparison" << endl;
				cout << "	--------------------------------" << endl;
				cout << "	3->Greater then comparison" << endl;
				cout << "	--------------------------------" << endl;
				cout << "	4->Less then comparison" << endl;
				cout << "	--------------------------------" << endl;
				cout << "	0->Exit to main menu" << endl;
				cout << "	--------------------------------" << endl;
				cout << "	";
				cin >> option_2;
				cin.ignore();
				if (option_2 == 1)
				{
					if (str1 == str2)
					{
						cout << "	Yes,Strings are equal" << endl;
					}
					else
					{
						cout << "	Strings are not equal" << endl;
					}
					system("pause");
				}
				else if (option_2 == 2)
				{
					if (str1 != str2)
					{
						cout << "	Yes,Strings are not equal" << endl;
					}
					else
					{
						cout << "	Strings are equal" << endl;
					}
					system("pause");
				}
				else if (option_2 == 3)
				{
					if (str1 > str2)
					{
						cout << "	string 1 is greater then string 2" << endl;
					}
					else
					{
						cout << "	string 2 is greater then string 1" << endl;
					}
					system("pause");
				}
				else if (option_2 == 4)
				{
					if (str1 < str2)
					{
						cout << "	string 1 is smaller then string 2" << endl;
					}
					else
					{
						cout << "	string 2 is smaller then string 1" << endl;
					}
					system("pause");
				}
				else if(option_2 != 0)
				{
					cout << "	Invalid Option Selected" << endl;
					system("pause");
				}
			} while (option_2 < 0 || option_2>0);
		}
		else if (option_1 == 4)
		{
			cout << "	" << str1;
			cout << endl;
			system("pause");
		}
		else if (option_1 == 5)
		{
			cout << "	" << str2;
			cout << endl;
			system("pause");
		}
		else if (option_1 == 6)
		{
			str1.Clear();
			cout << "	Enter string 1 : ";
			cin >> str1;
			cout << endl;
		}
		else if (option_1 == 7)
		{
			str2.Clear();
			cout << "	Enter string 2 : ";
			cin >> str2;
			cout << endl;
		}
		else if (option_1 == 8)
		{
			fout.open("MyString.txt");
			fout << str1;
			fout << str2;
			fout.close();
		}
		else if (option_1 == 9)
		{
			fin.open("MyString.txt");
			fin >> str1;
			fin >> str2;
			fin.close();
		}
		else if(option_1!=0)
		{
			cout << "	Invalid Option Selected" << endl;
			system("pause");
		}

	} while (option_1 > 0 || option_1 < 0);

	

}