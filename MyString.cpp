#include "MyString.h"

MyString::MyString()
{
	pr_CharArray = nullptr;
	pr_Array_Length = 0;
}


MyString::MyString(int Length, char* copy_Array)
{
	pr_Array_Length = Length;

	pr_CharArray = new char[Length + 1];
	for (int i = 0; copy_Array[i] != '\0'; i++)
	{
		pr_CharArray[i] = copy_Array[i];
	}
	copy_Array[Length] = '\0';
}



MyString::MyString(char* copy_Array)
{
	for (int i = 0; copy_Array[i] != '\0'; i++)
	{
		pr_Array_Length++;
	}

	pr_CharArray = new char[pr_Array_Length + 1];

	for (int i = 0; copy_Array[i] != '\0'; i++)
	{
		pr_CharArray[i] = copy_Array[i];
	}

	pr_CharArray[pr_Array_Length] = '\0';
}

//copy constructor
MyString::MyString(MyString& copy_obj)
{
	pr_Array_Length = copy_obj.pr_Array_Length;
	pr_CharArray = new char[pr_Array_Length + 1];

	for (int i = 0; i < pr_Array_Length; i++)
	{
		pr_CharArray[i] = copy_obj.pr_CharArray[i];
	}

	pr_CharArray[pr_Array_Length]='\0';
}


//istream operator
void operator>>(istream& in , MyString& obj_in)
{
	obj_in.pr_Array_Length = 0;

	char* ptr_Array = new char[100];
	//in.ignore();
	in.getline(ptr_Array, 100);

	for (int i = 0; ptr_Array[i] != '\0'; i++)
	{
		obj_in.pr_Array_Length++;
	}

	if (obj_in.pr_CharArray != nullptr)
	{
		delete[] obj_in.pr_CharArray;
	}

	obj_in.pr_CharArray = new char[obj_in.pr_Array_Length + 1];

	for (int i = 0; ptr_Array[i] != '\0'; i++)
	{
		obj_in.pr_CharArray[i] = ptr_Array[i];
	}

	obj_in.pr_CharArray[obj_in.pr_Array_Length] = '\0';

	delete[]ptr_Array;
	ptr_Array = nullptr;
}


//ostream operator
void operator<<(ostream& out , MyString& obj_in)
{
	out << obj_in.pr_CharArray;
}




char& MyString::operator[](int const index)
{
	return pr_CharArray[index];
}

MyString& MyString::operator=(const MyString& obj_in)
{
	pr_Array_Length = obj_in.pr_Array_Length;

	if (pr_CharArray == nullptr)
	{
		pr_CharArray = new char[pr_Array_Length + 1];
	}
	else
	{
		delete[]pr_CharArray;
		pr_CharArray = new char[pr_Array_Length + 1];
	}

	for (int i = 0; i < pr_Array_Length; i++)
	{
		pr_CharArray[i] = obj_in.pr_CharArray[i];
	}

	pr_CharArray[pr_Array_Length] = '\0';

	return *this;
}

MyString MyString::operator+(const MyString& obj_in)
{
	MyString obj_return;
	int counter = 0;
	int size = 0;


	size = pr_Array_Length + obj_in.pr_Array_Length + 1;
	obj_return.pr_CharArray = new char[size];

	obj_return.pr_Array_Length = pr_Array_Length + obj_in.pr_Array_Length;

	
	for (int i = 0; pr_CharArray[i] != '\0'; i++)
	{
		obj_return.pr_CharArray[counter] = pr_CharArray[i];
		counter++;
	}

	

	for (int i = 0; obj_in.pr_CharArray[i]!='\0' ; i++)
	{
		obj_return.pr_CharArray[counter] = obj_in.pr_CharArray[i];
		counter++;
	}

	obj_return.pr_CharArray[obj_return.pr_Array_Length] = '\0';

	return obj_return;
}

MyString MyString::operator-(const MyString& obj_in)
{
	int flag = 0;


	if (obj_in.pr_Array_Length < pr_Array_Length)
	{
		MyString obj_return;
		for (int i = 0; i < pr_Array_Length; i++)
		{
			if (pr_CharArray[i] == obj_in.pr_CharArray[0])
			{
				int b = 0;
				for (int j = i; j < pr_Array_Length && j < obj_in.pr_Array_Length + i; j++)
				{
					if (pr_CharArray[j] == obj_in.pr_CharArray[b])
					{
						flag = 1;
						b++;
					}
					else
					{
						flag = 0;
						break;
					}
				}

				if (flag == 1)
				{
					int a = 0;
					obj_return.pr_Array_Length = pr_Array_Length - obj_in.pr_Array_Length;
					obj_return.pr_CharArray = new char[obj_return.pr_Array_Length + 1];
					for (int x = 0; x < i; x++)
					{
						obj_return[x] = pr_CharArray[x];
						a = x;
					}

					a++;

					for (int x = i + obj_in.pr_Array_Length; x < pr_Array_Length; x++)
					{
						obj_return[a] = pr_CharArray[x];
						a++;
					}
					obj_return.pr_CharArray[obj_return.pr_Array_Length] = '\0';
					return obj_return;
				}
			}
		}

		return *this;
	}
	else
	{
		return *this;
	}
}

bool MyString::operator==(const MyString& obj_in)
{
	if (pr_Array_Length == obj_in.pr_Array_Length)
	{
		for (int i = 0; i < pr_Array_Length; i++)
		{
			if (pr_CharArray[i] != obj_in.pr_CharArray[i])
			{
				return false;
			}

		}
		return true;
	}
	else
	{
		return false;
	}
}

bool MyString::operator>(const MyString& obj_in)
{
	if (pr_Array_Length == obj_in.pr_Array_Length)
	{
		for (int i = 0; i < pr_Array_Length; i++)
		{
			if (pr_CharArray[i] > obj_in.pr_CharArray[i])
			{
				return true;
			}

			if (pr_CharArray[i] != obj_in.pr_CharArray[i])
			{
				break;
			}
		}

		return false;

	}
	else if (pr_Array_Length > obj_in.pr_Array_Length)
	{
		return true;
	}
	else if (pr_Array_Length < obj_in.pr_Array_Length)
	{
		return false;
	}
}

bool MyString::operator<(const MyString& obj_in)
{
	if (pr_Array_Length == obj_in.pr_Array_Length)
	{
		for (int i = 0; i < pr_Array_Length; i++)
		{
			if (pr_CharArray[i] < obj_in.pr_CharArray[i])
			{
				return true;
			}

			if (pr_CharArray[i] != obj_in.pr_CharArray[i])
			{
				break;
			}
		
		}

		return false;
	}
	else if (pr_Array_Length < obj_in.pr_Array_Length)
	{
		return true;
	}
	else if(pr_Array_Length > obj_in.pr_Array_Length)
	{
		return false;
	}
}

bool MyString::operator!=(const MyString& obj_in)
{
	if (*this == obj_in)
	{
		return false;
	}
	else
	{
		return true;
	}
}

void operator>>(ifstream& in, MyString& obj_in)
{
	if (obj_in.pr_CharArray != nullptr)
	{
		delete[]obj_in.pr_CharArray;
	}
	
	in >> obj_in.pr_Array_Length;
	obj_in.pr_CharArray = new char[obj_in.pr_Array_Length + 1];

	for (int i = 0; i < obj_in.pr_Array_Length; i++)
	{
		in >> obj_in.pr_CharArray[i];
	}
	
	obj_in.pr_CharArray[obj_in.pr_Array_Length] = '\0';

}

void operator<<(ofstream& out, MyString& obj_in)
{
	
	out << obj_in.pr_Array_Length;
	out << " ";
	for (int i = 0; i < obj_in.pr_Array_Length; i++)
	{
		out << obj_in.pr_CharArray[i];
	}
	out << " ";
	
}

void MyString::Clear()
{
	pr_Array_Length = 0;
	if (pr_CharArray != nullptr)
	{
		delete[]pr_CharArray;
		pr_CharArray = nullptr;
	}

}

MyString::~MyString()
{
	if (pr_CharArray != nullptr)
	{
		delete[]pr_CharArray;
	}
}

