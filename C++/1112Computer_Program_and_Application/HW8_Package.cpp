#include <iostream>
#include <iomanip>
using namespace std;

class Package{
	public:
		Package(string[],string[],double = 0,double = 0);
		Package &setSender(string[]);
		Package &setRecipient(string[]);

		Package &setSenderName(string);
		Package &setSenderAddress(string);
		Package &setSenderCity(string);
		Package &setSenderState(string);
		Package &setSenderZIP(string);

		string getSenderName() const;
		string getSenderAddress() const;
		string getSenderCity() const;
		string getSenderState() const;
		string getSenderZIP() const;

		Package &setRecipientName(string);
		Package &setRecipientAddress(string);
		Package &setRecipientCity(string);
		Package &setRecipientState(string);
		Package &setRecipientZIP(string);

		string getRecipientName() const;
		string getRecipientAddress() const;
		string getRecipientCity() const;
		string getRecipientState() const;
		string getRecipientZIP() const;

		Package &setWeight(double);
		Package &setCostPerOunce(double);
		double getWeight() const;
		double getCostPerOunce() const;
		double calculateCost();
		void info();
	private:
		string sender[5],recipient[5];
		double weight,costPerOunce;
};

class TwoDayPackage: public Package{
	public:
		TwoDayPackage(string[],string[],double,double,double);
		void setFlatFee(double);
		double getFlatFee() const;
		double calculateCost();
		void info();
	private:
		double flatFee;
};

class OvernightPackage: public Package{
	public:
		OvernightPackage(string[],string[],double,double,double);
		void setAdditionalFee(double);
		double getAdditionalFee() const;
		double calculateCost();
		void info();
	private:
		double additionalFee;
};

int main(){
	string Paul[5] = {"Paul","1st Street","Taichung","Taiwan","402"},John[5] = {"John","4th Street","Tainan","Taiwan","23"};
	TwoDayPackage apple(Paul,John,18,1.05,8);
	apple.info();
	OvernightPackage banana(John,Paul,12,1.5,1.1);
	banana.info();
	return 0;
}

Package::Package(string sender[],string recipient[],double weight,double costPerOunce){
	setSender(sender).setRecipient(recipient).setWeight(weight).setCostPerOunce(costPerOunce);
}

Package &Package::setSender(string sender[]){
	setSenderName(sender[0]).setSenderAddress(sender[1]).setSenderCity(sender[2]).setSenderState(sender[3]).setSenderZIP(sender[4]);
	return *this;
}

Package &Package::setRecipient(string recipient[]){
	setRecipientName(recipient[0]).setRecipientAddress(recipient[1]).setRecipientCity(recipient[2]).setRecipientState(recipient[3]).setRecipientZIP(recipient[4]);
	return *this;
}

Package &Package::setSenderName(string name){
	sender[0] = name;
	return *this;
}

Package &Package::setSenderAddress(string adress){
	sender[1] = adress;
	return *this;
}

Package &Package::setSenderCity(string city){
	sender[2] = city;
	return *this;
}

Package &Package::setSenderState(string state){
	sender[3] = state;
	return *this;
}

Package &Package::setSenderZIP(string ZIP){
	sender[4] = ZIP;
	return *this;
}

string Package::getSenderName() const{
	return sender[0];
}

string Package::getSenderAddress() const{
	return sender[1];
}

string Package::getSenderCity() const{
	return sender[2];
}

string Package::getSenderState() const{
	return sender[3];
}

string Package::getSenderZIP() const{
	return sender[4];
}

Package &Package::setRecipientName(string name){
	recipient[0] = name;
	return *this;
}

Package &Package::setRecipientAddress(string adress){
	recipient[1] = adress;
	return *this;
}

Package &Package::setRecipientCity(string city){
	recipient[2] = city;
	return *this;
}

Package &Package::setRecipientState(string state){
	recipient[3] = state;
	return *this;
}

Package &Package::setRecipientZIP(string ZIP){
	recipient[4] = ZIP;
	return *this;
}

string Package::getRecipientName() const{
	return recipient[0];
}

string Package::getRecipientAddress() const{
	return recipient[1];
}

string Package::getRecipientCity() const{
	return recipient[2];
}

string Package::getRecipientState() const{
	return recipient[3];
}

string Package::getRecipientZIP() const{
	return recipient[4];
}

Package &Package::setWeight(double weight){
	this->weight = (weight >= 0) ? weight : 0;
	return *this;
}

Package &Package::setCostPerOunce(double cost){
	this->costPerOunce = (cost >= 0) ? cost : 0;
	return *this;
}

double Package::getWeight() const{
	return weight;
}

double Package::getCostPerOunce() const{
	return costPerOunce;
}

double Package::calculateCost(){
	return getWeight() * getCostPerOunce();
}

void Package::info(){
	cout << "#######################################" << endl;
	cout << "Package" << endl;
	cout << "Sender       " << getSenderName() << endl;
	cout << "             " << getSenderAddress() << endl;
	cout << "             " << getSenderCity() << " " << getSenderState() << " " << getSenderZIP() << endl;
	cout << endl;
	cout << "Recipient    " << getRecipientName() << endl;
	cout << "             " << getRecipientAddress() << endl;
	cout << "             " << getRecipientCity() << " " << getRecipientState() << " " << getRecipientZIP() << endl;
	cout << "Cost         $ " << setprecision(5) << calculateCost() << endl;
	cout << "#######################################" << endl;
}

TwoDayPackage::TwoDayPackage(string sender[],string recipient[],double weight,double cost,double flatFee)
	:Package::Package(sender,recipient,weight,cost)
{
	setFlatFee(flatFee);
}

void TwoDayPackage::setFlatFee(double flatFee){
	this->flatFee = flatFee;
}

double TwoDayPackage::getFlatFee() const{
	return flatFee;
}

double TwoDayPackage::calculateCost(){
	return Package::calculateCost() + getFlatFee();
}

void TwoDayPackage::info(){
	cout << "#######################################" << endl;
	cout << "2 Day Delivery" << endl;
	cout << "Sender       " << getSenderName() << endl;
	cout << "             " << getSenderAddress() << endl;
	cout << "             " << getSenderCity() << " " << getSenderState() << " " << getSenderZIP() << endl;
	cout << endl;
	cout << "Recipient    " << getRecipientName() << endl;
	cout << "             " << getRecipientAddress() << endl;
	cout << "             " << getRecipientCity() << " " << getRecipientState() << " " << getRecipientZIP() << endl;
	cout << "Cost         $ " << fixed << setprecision(2) << calculateCost() << endl;
	cout << "#######################################" << endl;
}

OvernightPackage::OvernightPackage(string sender[],string recipient[],double weight,double cost,double additionalFee)
	:Package::Package(sender,recipient,weight,cost)
{
	setAdditionalFee(additionalFee);
}

void OvernightPackage::setAdditionalFee(double additionalFee){
	this->additionalFee = additionalFee;
}

double OvernightPackage::getAdditionalFee() const{
	return additionalFee;
}

double OvernightPackage::calculateCost(){
	return Package::calculateCost() + getAdditionalFee() * getWeight();
}

void OvernightPackage::info(){
	cout << "#######################################" << endl;
	cout << "Overnight Delivery" << endl;
	cout << "Sender       " << getSenderName() << endl;
	cout << "             " << getSenderAddress() << endl;
	cout << "             " << getSenderCity() << " " << getSenderState() << " " << getSenderZIP() << endl;
	cout << endl;
	cout << "Recipient    " << getRecipientName() << endl;
	cout << "             " << getRecipientAddress() << endl;
	cout << "             " << getRecipientCity() << " " << getRecipientState() << " " << getRecipientZIP() << endl;
	cout << "Cost         $ " << fixed << setprecision(2) << calculateCost() << endl;
	cout << "#######################################" << endl;
}
