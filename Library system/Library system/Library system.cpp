#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
//-----------------------------------------------------------------
struct Book
{
	int id;
	string name;
	int Max_quantity;
	int cur_quantity;
	Book(int id, string name, int Max_quantity)
	{
		this->id = id;
		this->name = name;
		this->Max_quantity = Max_quantity;
		cur_quantity = Max_quantity;
	}
};
struct User
{
	int id;
	string name;
	int N_borrowed_books;
	const int Max_borrowed = 5;
	User(int id, string name)
	{
		this->id = id;
		this->name = name;
		N_borrowed_books = 0;
	}
};
//-----------------------------------------------------------------
vector<Book> Books;
vector<User> Users;
vector<vector<int>> Borrowing_Books;
//-----------------------------------------------------------------
bool sort_book_names(Book& b1, Book& b2)
{
	return b1.name < b2.name;
}
bool sort_book_ids(Book& b1, Book& b2)
{
	return b1.id < b2.id;
}
bool sort_user_names(User& u1, User& u2)
{
	return u1.name < u2.name;
}
bool sort_user_ids(User& u1, User& u2)
{
	return u1.id < u2.id;
}
void Remove_element(vector<vector<int>>& v, int index)
{
	int n = v.size();
	for (int i = index; i < n - 1; i++)
	{
		v[i] = v[i + 1];
	}
	v.pop_back();
}
int  abs(int num)
{
	if (num < 0)
		num *= -1;
	return num;
}
bool is_prefix(string s, string pre)
{
	int n = s.length();
	int m = pre.length();

	if (n < m)
		return false;
	for (int i = 0; i < m; i++)
	{
		if (!(s[i] == pre[i] || abs(s[i] - pre[i]) == 32))
			return false;
	}
	return true;
}
int Get_id_of_user(string name)
{
	int n = Users.size();
	for (int i = 0; i < n; i++)
	{
		if (Users[i].name == name)
			return Users[i].id;
	}
	return -1;
}
int Get_id_of_book(string name)
{
	int n = Books.size();
	for (int i = 0; i < n; i++)
	{
		if (Books[i].name == name)
			return Books[i].id;
	}
	return -1;
}
Book* Get_book(int id)
{
	int n = Books.size();
	for (int i = 0; i < n; i++)
	{
		if (Books[i].id == id)
			return &Books[i];
	}

	Book b(15, "xdgfchvjbk", 12);
	return &b;
}
User* Get_user(int id)
{
	int n = Users.size();
	for (int i = 0; i < n; i++)
	{
		if (Users[i].id == id)
			return &Users[i];
	}

	User u(15, "xdgfchvjbk");
	return &u;
}
void Print_id_and_name_of_user(int id)
{
	int n = Users.size();
	for (int i = 0; i < n; i++)
	{
		if (Users[i].id == id)
		{
			cout << "ID is " << Users[i].id << "  ";
			cout << "Name is " << Users[i].name << "\n";
			break;
		}
	}
}
void Print_id_and_name_of_book(int id)
{
	int n = Books.size();
	for (int i = 0; i < n; i++)
	{
		if (Books[i].id == id)
		{
			cout << "ID is " << Books[i].id << "  ";
			cout << "Name is " << Books[i].name << "\n";
			break;
		}
	}
}
void print_book(Book& book)
{
	cout << "ID : " << book.id << "\n";
	cout << "Name : " << book.name << "\n";
	cout << "Quantity : " << book.cur_quantity << "\n";
	cout << "This book is borrowed by " << book.Max_quantity - book.cur_quantity << " People which are : \n";

	if (book.cur_quantity != book.Max_quantity)
	{
		int n = Borrowing_Books.size();
		for (int i = 0; i < n; i++)
		{
			if (Borrowing_Books[i][1] == book.id)
			{
				Print_id_and_name_of_user(Borrowing_Books[i][0]);
			}
		}
	}

}
void print_user(User& user)
{
	cout << "ID : " << user.id << "\n";
	cout << "Name : " << user.name << "\n";
	cout << "Number of borrowed books  =  " << user.N_borrowed_books << " which are " << "\n";

	if (user.N_borrowed_books)
	{
		int n = Borrowing_Books.size();
		for (int i = 0; i < n; i++)
		{
			if (Borrowing_Books[i][0] == user.id)
			{
				Print_id_and_name_of_book(Borrowing_Books[i][1]);
			}
		}
	}

}
void Add_a_book()
{
	cout << "Please ; Enter the id, Name , Qyantity of the book\n";
	int id;
	string name;
	int Quantity;

	cin >> id >> name >> Quantity;

	Books.push_back({ id , name , Quantity });

}
void Search_book_by_prefix()
{
	cout << "Please ; Enter the prefix of the book\n";
	string pre;
	cin >> pre;

	int n = Books.size();

	for (int i = 0; i < n; i++)
	{
		if (is_prefix(Books[i].name, pre))
		{
			print_book(Books[i]);
			return;
		}
	}
	cout << "Not found\n";
}
void Print_who_borrowed_book_by_name()
{
	cout << "Please ; Enter the name of the book: ";
	string Name;
	cin >> Name;

	int id = Get_id_of_book(Name);
	if (id == -1)
	{
		cout << Name << " is not found\n";
		return;
	}
	int n = Borrowing_Books.size();
	cout << "This book is borrowed by : \n";
	for (int i = 0; i < n; i++)
	{
		if (Borrowing_Books[i][1] == id)
		{
			Print_id_and_name_of_user(Borrowing_Books[i][0]);
		}
	}
}
void print_library()
{
	cout << "These are Books ids , Names , Quantities in libaray : \n";

	int n = Books.size();
	for (int i = 0; i < n; i++)
	{
		cout << Books[i].id << "   " << Books[i].name << "   " << Books[i].cur_quantity;
	}
}
void print_library_by_id()
{
	sort(Books.begin(), Books.end(), sort_book_ids);
	print_library();
}
void print_library_by_name()
{
	sort(Books.begin(), Books.end(), sort_book_names);
	print_library();
}
void Add_user()
{
	cout << "Please ; Enter the id, Name User\n";
	int id;
	string name;


	cin >> id >> name;

	Users.push_back({ id , name });

}
void User_borrow_book()
{
	cout << "Please ; Enter the name of the user : ";
	string User_name;
	cin >> User_name;

	cout << "Please ; Enter the name of the book : ";
	string Book_name;
	cin >> Book_name;

	int id_user = Get_id_of_user(User_name);
	int id_book = Get_id_of_book(Book_name);

	if (id_user == -1 || id_book == -1)
	{
		cout << "Please ; Enter valid data\n";
		return;
	}
	Book* B = Get_book(id_book);
	if (B->cur_quantity == 0)
	{
		cout << "There is no copies from this book in the library\n";
		return;
	}
	B->cur_quantity--;
	User* U = Get_user(id_user);
	if (U->N_borrowed_books >= U->Max_borrowed)
	{
		cout << "Sorry this user can not borrow another book\n";
		return;
	}
	U->N_borrowed_books++;
	Borrowing_Books.push_back({ id_user ,id_book });
}
void User_return_book()
{
	cout << "Please ; Enter the name of the user : ";
	string User_name;
	cin >> User_name;

	cout << "Please ; Enter the name of the book : ";
	string Book_name;
	cin >> Book_name;

	int id_user = Get_id_of_user(User_name);
	int id_book = Get_id_of_book(Book_name);

	if (id_user == -1 || id_book == -1)
	{
		cout << "Please ; Enter valid data\n";
		return;
	}

	int n = Borrowing_Books.size();
	for (int i = 0; i < n; i++)
	{
		if (Borrowing_Books[i][0] == id_user && Borrowing_Books[i][1] == id_book)
		{
			Remove_element(Borrowing_Books, i);
			Book* B = Get_book(id_book);
			User* U = Get_user(id_user);
			B->cur_quantity++;
			U->N_borrowed_books--;

			cout << User_name << "  ; thank you for your hounsty\n";
			cout << User_name << "  ; now you can borrow up to " << U->Max_borrowed - U->N_borrowed_books << " books\n";

			return;
		}
	}
	cout << User_name << " did not borrow " << Book_name << " book\n";
}
void Print_users()
{
	int n = Users.size();

	for (int i = 0; i < n; i++)
	{
		print_user(Users[i]);
	}
}
//-----------------------------------------------------------------
void Menu()
{
	cout << "Please ; Enter a choice from 1 to 9: \n";
	cout << "1 ) Add a book\n";
	cout << "2 ) Search book by prefix\n";
	cout << "3 ) Print who borrowed book by name\n";
	cout << "4 ) print library by id\n";
	cout << "5 ) print library by name\n";
	cout << "6 ) Add a user\n";
	cout << "7 ) User borrow book\n";
	cout << "8 ) User return book\n";
	cout << "9 ) Print users\n";
	int choice;
	cin >> choice;

	switch (choice)
	{
	case 1:
		Add_a_book();
		break;
	case 2:
		Search_book_by_prefix();
		break;
	case 3:
		Print_who_borrowed_book_by_name();
		break;
	case 4:
		print_library_by_id();
		break;
	case 5:
		print_library_by_name();
		break;
	case 6:
		Add_user();
		break;
	case 7:
		User_borrow_book();
		break;
	case 8:
		User_return_book();
		break;
	case 9:
		Print_users();
		break;

	}

	cout << "*********************\n";

}
int main()
{
	while (true)
	{
		Menu();
		//cout << "*********************\n";
	}
	return 0;
}