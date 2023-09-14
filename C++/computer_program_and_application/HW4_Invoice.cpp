#include <iostream>
using namespace std;

class Invoice{
	public:
		Invoice();
		void setNumber(string);
		void setDescription(string);
		void setQuantity(int);
		void setPrice(int);
		string getNumber();
		string getDescription();
		int getQuantity();
		int getPrice();
		int getInvoiceAmount();
	private:
		string number,description;
		int quantity,price;
};

int main(){
	Invoice apple;
	apple.setNumber("0147");
	apple.setDescription("An apple a day keeps the doctor away!");
	apple.setQuantity(145);
	apple.setPrice(35);

	cout << endl;

	cout << "number: " << apple.getNumber() << endl;
	cout << "description: " << apple.getDescription() << endl;
	cout << "quantity: " << apple.getQuantity() << endl;
	cout << "price: " << apple.getPrice() << endl;
	int totalPrice = apple.getInvoiceAmount();
	cout << "total price is " << totalPrice << endl;;
	return 0;
}

Invoice::Invoice(){
	number = description = "";
	quantity = price = 0;
}

void Invoice::setNumber(string inputNumber){
	number = inputNumber;
}

void Invoice::setDescription(string inputDescription){
	description = inputDescription;
}

void Invoice::setQuantity(int inputQuantity){
	if (inputQuantity < 0)
		inputQuantity = 0;
	quantity = inputQuantity;
}

void Invoice::setPrice(int inputPrice){
	if (inputPrice < 0)
		inputPrice = 0;
	price = inputPrice;
}

string Invoice::getNumber(){
	return number;
}

string Invoice::getDescription(){
	return description;
}

int Invoice::getQuantity(){
	return quantity;
}

int Invoice::getPrice(){
	return price;
}

int Invoice::getInvoiceAmount(){
	return quantity * price;
}
