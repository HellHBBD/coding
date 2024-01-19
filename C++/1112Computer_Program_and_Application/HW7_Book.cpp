#include <iostream>
using namespace std;

class Book
{
		public:
		void print();
		Book &update(char, string);
		Book &update(char, float);
		Book &update(char, int);
		string getTitle();
		string getAuthor();
		float getPrice();
		int getStock();

		private:
		string title, author;
		float price;
		int stock;
};

class Bookstore
{
		public:
		Bookstore(int = 0);
		~Bookstore();
		bool addBook(Book);
		void print();
		bool update(string);

		private:
		Book *shelf;
		int capacity, maxCapacity;
};

int main()
{
		Book Cplusplus, Calculus, Economics;
		Cplusplus.update('T', "C++ How to Program").update('A', "Paul Deitel").update('P', 157.97f).update('S', 1456);
		Calculus.update('T', "Essential Calculus").update('A', "James Stewart").update('P', 165).update('S', 498);
		Economics.update('T', "Principle of Economics").update('A', "Frank").update('P', 210).update('S', 943);
		Bookstore Tainan, NCKU(2), IIM(4);
		cout << Tainan.addBook(Cplusplus) << Tainan.addBook(Calculus) << Tainan.addBook(Economics) << endl;
		cout << NCKU.addBook(Cplusplus) << NCKU.addBook(Calculus) << NCKU.addBook(Economics) << endl;
		IIM.addBook(Calculus);
		IIM.addBook(Cplusplus);
		IIM.addBook(Economics);
		cout << endl;
		NCKU.print();
		cout << endl;
		IIM.print();
		cout << endl;
		cout << NCKU.update("Essential Calculus") << NCKU.update("Principle of Economics") << endl;
		return 0;
}

void Book::print()
{
		cout << "title:" << getTitle() << endl;
		cout << "author:" << getAuthor() << endl;
		cout << "price:" << getPrice() << endl;
		cout << "stock:" << getStock() << endl;
}

Book &Book::update(char member, string content)
{
		if (member == 'T')
				this->title = content;
		if (member == 'A')
				this->author = content;
		return *this;
}

Book &Book::update(char member, float content)
{
		if (member == 'P')
				this->price = content;
		if (member == 'S')
				this->stock = content;
		return *this;
}

Book &Book::update(char member, int content)
{
		if (member == 'P')
				this->price = content;
		if (member == 'S')
				this->stock = content;
		return *this;
}

string Book::getTitle()
{
		return title;
}

string Book::getAuthor()
{
		return author;
}

float Book::getPrice()
{
		return price;
}

int Book::getStock()
{
		return stock;
}

Bookstore::Bookstore(int capacity)
{
		this->capacity = 0;
		maxCapacity = capacity;
		shelf = new Book[capacity];
}

Bookstore::~Bookstore()
{
		delete[] shelf;
}

bool Bookstore::addBook(Book book)
{
		if (capacity == maxCapacity)
				return false;
		shelf[capacity] = book;
		capacity++;
		return true;
}

void Bookstore::print()
{
		for (int i = 0; i < capacity; i++) {
				cout << i + 1 << "." << endl;
				shelf[i].print();
		}
}

bool Bookstore::update(string title)
{
		for (int i = 0; i < capacity; i++)
				if (title == shelf[i].getTitle())
						return true;
		return false;
}
