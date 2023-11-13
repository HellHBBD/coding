#include <cmath>
#include <iostream>
using namespace std;

class Shape {
	public:
		virtual ~Shape(){};
		virtual double calculateArea() = 0;
		virtual double calculatePerimeter() = 0;
		virtual void displayInfo() = 0;
		virtual void set(double) = 0;
		virtual void set(double, double) = 0;
		void construct();
		void destruct();
		static int getShapeCount();

	private:
		static int shapeCount;
};

class TwoDimensionalShape: public Shape {
};

class ThreeDimensionalShape: public Shape {
};

class Rectangle: public TwoDimensionalShape {
	public:
		Rectangle();
		Rectangle(double, double);
		~Rectangle();
		double calculateArea() override;
		double calculatePerimeter() override;
		void displayInfo() override;
		void set(double) override;
		void set(double, double) override;

	private:
		double length, width;
};

class Circle: public TwoDimensionalShape {
	public:
		Circle();
		Circle(double);
		~Circle();
		double calculateArea() override;
		double calculatePerimeter() override;
		void displayInfo() override;
		void set(double) override;
		void set(double, double) override;

	private:
		double radius;
};

class Sphere: public ThreeDimensionalShape {
	public:
		Sphere();
		Sphere(double);
		~Sphere();
		double calculateArea() override;
		double calculatePerimeter() override;
		void displayInfo() override;
		void set(double) override;
		void set(double, double) override;

	private:
		double radius;
};

int main() {
	int size = 3;
	Shape *shape[size];
	shape[0] = new Rectangle(5, 3);
	shape[1] = new Circle(4);
	shape[2] = new Sphere(3);

	cout << "Enter the number of shape: " << size << endl;
	for (int i = 0; i < size; i++) {
		cout << endl;
		cout << "Shape " << i + 1 << ":" << endl;
		shape[i]->displayInfo();
		delete shape[i];
	}
	return 0;
}

void Shape::construct() {
	shapeCount++;
}

void Shape::destruct() {
	shapeCount--;
}

int Shape::getShapeCount() {
	return shapeCount;
}

int Shape::shapeCount = 0;

Rectangle::Rectangle() {
	set(0, 0);
	Shape::construct();
}

Rectangle::Rectangle(double length, double width) {
	set(length, width);
	Shape::construct();
}

Rectangle::~Rectangle() {
	Shape::destruct();
}

double Rectangle::calculateArea() {
	return length * width;
}

double Rectangle::calculatePerimeter() {
	return 2 * (length + width);
}

void Rectangle::displayInfo() {
	cout << "Rectangle Information:" << endl;
	cout << "Type: Rectangle" << endl;
	cout << "Length: " << length << " units" << endl;
	cout << "Width: " << width << " units" << endl;
	cout << "Area: " << calculateArea() << " square units" << endl;
	cout << "Perimeter: " << calculatePerimeter() << " units" << endl;
}

void Rectangle::set(double foo) {}

void Rectangle::set(double length, double width) {
	if (length >= 0)
		this->length = length;
	else
		this->length = 0;
	if (width >= 0)
		this->width = width;
	else
		this->width = 0;
}

Circle::Circle() {
	set(0, 0);
	Shape::construct();
}

Circle::Circle(double radius) {
	set(radius);
	Shape::construct();
}

Circle::~Circle() {
	Shape::destruct();
}

double Circle::calculateArea() {
	return M_PI * radius * radius;
}

double Circle::calculatePerimeter() {
	return 2 * M_PI * radius;
}

void Circle::displayInfo() {
	cout << "Circle Information:" << endl;
	cout << "Type: Circle" << endl;
	cout << "Radius: " << radius << " units" << endl;
	cout << "Area: " << calculateArea() << " square units" << endl;
	cout << "Perimeter: " << calculatePerimeter() << " units" << endl;
}

void Circle::set(double radius) {
	this->radius = radius;
}

void Circle::set(double foo1, double foo2) {}

Sphere::Sphere() {
	set(0);
	Shape::construct();
}

Sphere::Sphere(double radius) {
	set(radius);
	Shape::construct();
}

Sphere::~Sphere() {
	Shape::destruct();
}

double Sphere::calculateArea() {
	return M_PI * 4 / 3 * radius * radius * radius;
}

double Sphere::calculatePerimeter() {
	return 4 * M_PI * radius * radius;
}

void Sphere::displayInfo() {
	cout << "Sphere Information:" << endl;
	cout << "Type: Sphere" << endl;
	cout << "Radius: " << radius << " units" << endl;
	cout << "Volume: " << calculateArea() << " cubic units" << endl;
	cout << "Surface Area: " << calculatePerimeter() << " square units" << endl;
}

void Sphere::set(double radius) {
	this->radius = radius;
}

void Sphere::set(double foo1, double foo2) {}
