// Data structures
// Using STL containers, algorithms and iterators
// to handle a database of library books
// Add, Search, Display, Update and get highest versions' books



#include <iostream>
#include <map>
#include <iterator>
#include <string>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

map<string, string> book_map;
map<string, string>::iterator itr;


void addBook();							//add book to the library
void searchBookByName(string name);		//Getting the name from the user to print the book if found
void searchBookByAuthor(string author); //Getting the author name from the user to print the book if found
void listBooksAsc();					//Display all books in ascending order
void updateVersions(string name);		//Update existing book versions
void findHighestVersions();				//Find highest version book
void printAllBooks();					//used to test the program behaviour
string toLower(string str);				//used to lowercase the characters of 
int getVersion(string value);			//returns the highest version of the given value of a book
//int maximum(int, int);

int main()
{

	char choice = ' ';
	string name = "", author = "";

	while (true)
	{
		cout << "\n-----------------------------------------------------\n";
		cout << "Please choose the operation you want: \n";
		cout << "1.Add book\n2.Search book by name.\n3.Search book by author.\n4.List books in alphabetical order(Ascending).\n";
		cout << "5.Update available number of versions of a book.\n6.Find the books which have the highest number of versions and print books information.\n7.Exit program.\n>>";
		cin >> choice;
		switch (choice)
		{
		case '1':
			addBook();
			break;

		case '2':
			cout << "Please enter the name of the book: ";
			getline(cin >> std::ws, name);

			name = toLower(name);
			searchBookByName(name);
			break;

		case '3':
			cout << "Please enter the author of the book: ";
			getline(cin >> std::ws, author);

			author = toLower(author);
			searchBookByAuthor(author);
			break;

		case '4':
			listBooksAsc();
			break;

		case '5':
			cout << "Please enter the name of the book: ";
			getline(cin >> std::ws, name);

			name = toLower(name);
			updateVersions(name);
			break;

		case '6':
			findHighestVersions();
			break;

		case '7':
			cout << "Thank you for using this program.\n";
			return 0;

		default:
			cout << "\nInvalid Input.\n";
		}

	}

    return 0;
}

void addBook()
{
	string key = "", value = "";
	string name = "", author = "", year = "", version = "";
	//cin.ignore();
	cout << "\nPlease enter the book name: ";
	getline(cin >> std::ws, name);

	for (int i = 0; i < name.length(); i++)
	{
		if ((name[i] < 65 && name[i] > 122 && name[i] != 32))
		{
			cout << "Invalid input.\n";
			getline(cin >> std::ws, name);
			i++;
		}
	}


	cout << "\nPlease enter the book author: ";
	//cin.ignore();
	getline(cin >> std::ws, author);

	bool check = true;
	while (check)   //to check that the year is a number
	{
		cout << "\nPlease enter the book year published: ";
		cin >> year;
		cout << endl;
		for (int i = 0; i < year.length(); i++)
		{
			if (year[i] < char(0 + 48) || year[i] > char(9 + 48))
			{
				check = true;
				cout << "\nInvalid input.\n";

				break;
			}
			else
			{
				check = false;
			}
		}
	}
	check = true;
	while (check)   //to check that the year is a number
	{
		cout << "\nPlease enter the book number of version: ";
		cin >> version;
		cout << endl;
		for (int i = 0; i < version.length(); i++)
		{
			if (version[i] < char(0 + 48) || version[i] > char(9 + 48))
			{
				check = true;
				cout << "\nInvalid input.\n";

				break;
			}
			else
			{
				check = false;
			}
		}
	}
	check = true;

	key += name;

	value += author;
	value += '|';
	value += year;
	value += '|';
	value += version;
	value += '|';

	key = toLower(key);
	value = toLower(value);

	if (book_map.count(key) > 0)
	{
		std::cout << "\nThis book already exist.\n" << endl;
	}
	else
	{
		book_map.insert(pair<string, string>(key, value));
		cout << "\nBook added successfuly.\n";
	}

	//printAllBooks();

}

void searchBookByName(string name)
{
	bool found = false;
	for (itr = book_map.begin(); itr != book_map.end(); ++itr)
	{
		if (itr->first == name)
		{
			found = true;
			cout << "\nName: " << itr->first;
			
			int i = 0;
			cout << "\nAuthor: ";
			while (itr->second[i] != '|')
			{
				cout << itr->second[i];
				i++;
			}
			i++;
		
			cout << "\nYear Published: ";
			while (itr->second[i] != '|')
			{
				cout << itr->second[i];
				i++;
			}
			i++;

			cout << "\nAvaliable versions: ";
			while (itr->second[i] != '|')
			{
				cout << itr->second[i];
				i++;
			}
			
		}
	}
	if (found == false)
		cout << "\nBook not found.\n";
}

void searchBookByAuthor(string author)
{
	bool found = false;
	string author_temp = "";
	int i = 0;
	for (itr = book_map.begin(); itr != book_map.end(); ++itr)
	{
		i = 0; author_temp = "";
		while (itr->second[i] != '|')
		{
			author_temp += itr->second[i];
			i++;
		}
		
		if (author_temp == author)
		{
			found = true;
			cout << "\nName: " << itr->first;

			i = 0;
			cout << "\nAuthor: ";
			while (itr->second[i] != '|')
			{
				cout << itr->second[i];
				i++;
			}
			i++;

			cout << "\nYear Published: ";
			while (itr->second[i] != '|')
			{
				cout << itr->second[i];
				i++;
			}
			i++;

			cout << "\nAvaliable versions: ";
			while (itr->second[i] != '|')
			{
				cout << itr->second[i];
				i++;
			}

		}
	}
	if (found == false)
		cout << "\nBook not found.\n";
}

void listBooksAsc()
{
	int i = 0;
	for (itr = book_map.begin(); itr != book_map.end(); ++itr)
	{
		cout << "\nName: " << itr->first;
		i = 0;
		cout << "\nAuthor: ";
		while (itr->second[i] != '|')
		{
			cout << itr->second[i];
			i++;
		}
		i++;

		cout << "\nYear Published: ";
		while (itr->second[i] != '|')
		{
			cout << itr->second[i];
			i++;
		}
		i++;

		cout << "\nAvaliable versions: ";
		while (itr->second[i] != '|')
		{
			cout << itr->second[i];
			i++;
		}
		cout << "\n";
	}
}

void updateVersions(string name)
{
	bool found = false;
	int i = 0;
	for (itr = book_map.begin(); itr != book_map.end(); ++itr)
	{
		if (itr->first == name)
		{
			found = true;
			i = 0;
			string new_version = "", temp = "";
			
			
			cout << "Please enter the new version: ";
			cin >> temp;

			new_version += itr->second;
			new_version[new_version.length() - 1] = ',';
			new_version += temp;
			new_version += '|';

			itr->second = new_version;
			
		}
	}
	if (found == false)
	{
		cout << "\nBook not found.\n";
	}
	printAllBooks();
}

/*void findHighestVersions()
{
	int i = 0;
	int max = 0;
	vector<string> vec_names;
	vector<int> vec_num = { 0 };
	string curr_version = "";
	for (itr = book_map.begin(); itr != book_map.end(); ++itr)
	{
		i = 0;
		while (itr->second[i] != '|')
		{
			//skip the author
			i++;
		}
		i++;
		while (itr->second[i] != '|')
		{
			//skip the year
			i++;
		}
		i++;
		curr_version = "";
		while (itr->second[i] != '|')
		{
			curr_version += itr->second[i];
			i++;
		}
		cout << "current version: " << curr_version << endl;
		
		
		for (int j = 0, i=0  ; j < curr_version.length() ; j++)
		{
				if (curr_version[j] != ',' && curr_version[j] - 48 >= max)
				{
					max = (curr_version[j] - 48);
					vec_num.push_back(max);
					vec_names.push_back(itr->first);				
					cout << "ITR First: " << itr->first << endl;

				}
				j++;
		
		}
	}
	
	for (int k = 0; k < vec_names.size(); k++)	cout << vec_names[k] << " ";
	max = *max_element(vec_num.begin(), vec_num.end());
	//vec_names.push_back();
	cout << "Max = " << max << endl;
	cout << "i : " << i << endl;
	for (int j = 0; j < vec_names.size(); j++)
	{
		
		cout << "\nname: " << vec_names[j] << endl;
		searchBookByName(vec_names[j]);
	}
}

*/

void findHighestVersions()
{
	map<string, int> map_new;
	vector<int> vec_num; string name = "";
	int k = 0; int max = 0;
	vector<int>::iterator vec_itr;
	string str_versions = "";
	for (itr = book_map.begin(); itr != book_map.end(); ++itr)
	{
		int version = getVersion(itr->second);
		if (max < version)
		{
			max = version;
			name = itr->first;
		}

	}
		searchBookByName(name);

}

///helps
void printAllBooks()
{
	for (itr = book_map.begin(); itr != book_map.end(); ++itr)
	{
		cout << "Key: " << itr->first << ", ";
		cout << "Value: " << itr->second << endl;
	}
}

string toLower(string str)
{
	for (int i = 0; i < str.length(); i++)
	{
		str[i] = tolower(str[i]);
	}
	return str;
}
/*
int getVersion(string s)
{
	int temp_int = 0, counter = 0, j = 0;
	string temp_str = "";

	for (int i = 0; i < s.length(); i++)
	{
		if (s[i] == '|') counter++;
		if (counter == 2)
		{
			temp_str += s[i];
		}
	}
	temp_str.erase(0, 1);
	for (int i = 0; i < temp_str.length(); i++)
	{
		if (temp_str[i] != ',') temp_int++;
	}
	cout << "versions : " << temp_int;
	return temp_int;
}*/

int getVersion(string value)
{
	int temp_int = 0, counter = 0, j=0;
	string temp_str="";


	for (int i = 0; i < value.length(); i++)
	{
		if (value[i] == '|') 
		{
			i++;	counter++;
		}
		if (counter == 2)
		{
			temp_str += value[i];
		}
	}
	for (int i = 0; i < temp_str.length(); i++)
	{
		if (temp_str[i] == ',') i++;
		else
		{
			if (temp_int < (temp_str[i] - '0')) temp_int = (temp_str[i] - '0');

		}
	}
	
	return temp_int;
}
/*
int maximum(int x, int y)
{
	if (x > y)
	{
		return x;
	}
	else
	{
		return y;
	}
}*/