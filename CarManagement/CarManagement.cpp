#include <iostream>
#include <conio.h>
#include <Windows.h>

using namespace std;

class Car {
private:
	string _model;
	string _brand;
	string _color;
	int _year;
	int _price;
	int _rent;
	int _km;
	int _sellingPrice;
	void setSellingPrice() {
		_sellingPrice = _price * 0.2 + _price;
	}
	void setRent() {
		_rent = _price * 0.07;
	}
public:
	bool isCarRented;
	//Set
	void setModel(string model) {
		_model = model;
	}
	void setBrand(string brand) {
		_brand = brand;
	}
	void setColor(string color) {
		_color = color;
	}
	void setYear(int yr) {
		if (yr <= 2021 && yr >= 1920)
			_year = yr;
		else {
			_year = 2010;
			cout << "Error wrong year\n";
		}
	}

	void setPrice(int price) {
		if (price > 0)
			_price = price;
		else {
			_price = 2000;
			cout << "Error wrong price\n";
		}
	}
	void setKm(int km) {
		if (km >= 0)
			_km = km;
		else {
			_km = 0;
			cout << "Error wrong km\n";
		}
	}
	//Get
	string getModel() {
		return _model;
	}
	string getBrand() {
		return _brand;
	}
	string getColor() {
		return _color;
	}
	int getYear() {
		return _year;
	}
	int getRent() {
		return _rent;
	}
	int getPrice() {
		return _price;
	}
	int getKm() {
		return _km;
	}
	int getSellingPrice() {
		return _sellingPrice;
	}
	//Constructor
	Car() {
		_model = "unknown";
		_brand = "unknown";
		_color = "unknown";
		_year = 2010;
		_rent = 200;
		_price = 2000;
		_km = 0;
		setSellingPrice();
		setRent();
		isCarRented = false;
	}
	Car(const Car& car) {
		setBrand(car._brand);
		setModel(car._model);
		setColor(car._color);
		setYear(car._year);
		setPrice(car._price);
		setKm(car._km);
		setSellingPrice();
		setRent();
		isCarRented = car.isCarRented;
	}
	Car& operator=(const Car& car) {
		setBrand(car._brand);
		setModel(car._model);
		setColor(car._color);
		setYear(car._year);
		setPrice(car._price);
		setKm(car._km);
		setSellingPrice();
		setRent();
		isCarRented = car.isCarRented;
		return *this;
	}
};
class Employee {
private:
	string _name;
	string _lname;
	string _spec;
	int _salary;
	int _age;
	int _phnum;
public:
	//Set
	void setName(const string name) { _name = name; }
	void setlName(const string lname) { _lname = lname; }
	void setSpec(const string spec) { _spec = spec; }
	void setSalary(const int salary) {
		if (salary > 300) {
			_salary = salary;
		}
		else {
			cout << "\nmin salary 300";
			_salary = 300;
		}
	}
	void setAge(const int age) {
		if (age >= 18 && age < 65) { _age = age; }
		else {
			cout << "\nAge should be 18-64";
			_age = 18;
		}
	}
	void setPhnum(const int phnum) {
		if (phnum > 1000000 && phnum < 10000000) { _phnum = phnum; }
		else {
			cout << "\nWrong phone number";
			_phnum = 1234567;
		}
	}
	//Get
	string getName() { return _name; }
	string getlName() { return _lname; }
	string getSpec() { return _spec; }
	int getSalary() {
		return _salary;
	}
	int getAge() {
		return _age;
	}
	int getPhnum() {
		return _phnum;
	}
	//Constructor
	Employee() {
		_name = "unknown";
		_lname = "unknown";
		_spec = "unknown";
		_salary = 300;
		_age = 18;
		_phnum = 1234567;
	}
	Employee(const Employee& emp) {
		setAge(emp._age);
		setName(emp._name);
		setlName(emp._lname);
		setSpec(emp._spec);
		setSalary(emp._salary);
		setPhnum(emp._phnum);
	}
	Employee& operator=(const Employee& emp) {
		setAge(emp._age);
		setName(emp._name);
		setlName(emp._lname);
		setSpec(emp._spec);
		setSalary(emp._salary);
		setPhnum(emp._phnum);
		return *this;
	}
};
class Autosalon {
private:
	int cntCar;
	int cntEmp;
	Car* car = new Car[cntCar];
	Employee* emp = new Employee[cntEmp];
	//Budget
	int budget;
	int expense;
	int income;
	int profit;
	int ex;
	int pr;
	int week;
	int in;
public:
	//Car
	void addCar(Car& cr) {
		expense += cr.getPrice();
		cntCar++;
		Car* temp = new Car[cntCar];
		for (int i = 0; i < cntCar - 1; i++) { temp[i] = car[i]; }
		temp[cntCar - 1] = cr;
		delete[]car;
		car = temp;
		temp = nullptr;
	}
	void sellCar(int index) {
		income += car[index].getSellingPrice();
		cntCar--;
		Car* temp = new Car[cntCar];
		for (int i = 0; i < index; i++) { temp[i] = car[i]; }
		for (int i = index; i < cntCar; i++) { temp[i] = car[i + 1]; }
		delete[]car;
		car = temp;
		temp = nullptr;
	}
	void showCars() {
		system("cls");
		int i = 0;
		for (; i < cntCar; i++) {
			cout << i + 1 << "." << car[i].getBrand() << " " << car[i].getModel();
			if (car[i].isCarRented)cout << " Rented";
			cout << endl;
		}
		cout << i + 1 << ".Buy new car for salon\n"; i++;
		cout << i + 1 << ".Search\n"; i++;
		cout << i + 1 << ".Return\n";
	}
	void showCarsDetails(int index, int sh) {
		if (index > 0 && index <= cntCar) {
			index--;
			cout << "\nBrand: " << car[index].getBrand();
			cout << "\nModel: " << car[index].getModel();
			cout << "\nColor:	" << car[index].getColor();
			cout << "\nYear: " << car[index].getYear();
			cout << "\nKm: " << car[index].getKm() << " km";
			cout << "\nRent: " << car[index].getRent() << " $";
			cout << "\nPrice: " << car[index].getSellingPrice() << " $\n";
			if (!sh) {
				if (!car[index].isCarRented)
				{
					cout << "\n\n1.Sell" << "\n2.Rent" << "\n3.Return";
				}
				else cout << "\n1.Request car back\n2.Return";
			}
		}
		else cout << "Wrong index\n";
	}
	void requestCarBack(int index) { car[index].isCarRented = false; }
	void rentACar(int index) {
		car[index].isCarRented = true;
	}
	bool isRented(int index) { return car[index].isCarRented; }
	void searchCar(int index, int sch) {
		system("cls");
		bool found = false;
		switch (index)
		{
		case 4:
			for (int i = 0; i < cntCar; i++) {
				if (car[i].getYear() == sch) {
					showCarsDetails(i + 1, 1);
					found = true;
				}
			}
			break;
		case 5:
			for (int i = 0; i < cntCar; i++) {
				if (car[i].getPrice() >= sch - 1000 && car[i].getPrice() <= sch + 1000) {
					showCarsDetails(i + 1, 1);
					found = true;
				}
			}
			break;
		}
		if (!found) { cout << "\nNot found"; }
		cout << "\nPress any key to return..";
		_getch();
	}
	void searchCar(int index, string sch) {
		system("cls");
		bool found = false;
		switch (index)
		{
		case 1:
			for (int i = 0; i < cntCar; i++) {
				if (car[i].getBrand() == sch) {
					showCarsDetails(i + 1, 1);
					found = true;
				}
			}
			break;
		case 2:
			for (int i = 0; i < cntCar; i++) {
				if (car[i].getModel() == sch) {
					showCarsDetails(i + 1, 1);
					found = true;
				}
			}
			break;
		case 3:
			for (int i = 0; i < cntCar; i++) {
				if (car[i].getColor() == sch) {
					showCarsDetails(i + 1, 1);
					found = true;
				}
			}
			break;
		}
		if (!found) { cout << "\nNot found"; }
		cout << "\nPress any key to return..";
		_getch();
	}
	//Employee
	void addEmployee(Employee& em) {
		cntEmp++;
		Employee* temp = new Employee[cntEmp];
		for (int i = 0; i < cntEmp - 1; i++) { temp[i] = emp[i]; }
		temp[cntEmp - 1] = em;
		delete[] emp;
		emp = temp;
		temp = nullptr;
	}
	void fireEmployee(int index) {
		if (emp[index].getName() != "Murad" && emp[index].getlName() != "Seyidov") {
			cntEmp--;
			Employee* temp = new Employee[cntEmp];
			for (int i = 0; i < index; i++) { temp[i] = emp[i]; }
			for (int i = index; i < cntEmp; i++) { temp[i] = emp[i + 1]; }
			delete[]emp;
			emp = temp;
			temp = nullptr;
		}
		else { cout << "YOU CAN'T FIRE MURAD SEYIDOV!!!\n"; Sleep(1500); }
	}
	void showEmployees() {
		system("cls");
		int i = 0;
		for (; i < cntEmp; i++) {
			cout << i + 1 << "." << emp[i].getlName() << " " << emp[i].getName() << endl;
		}
		cout << i + 1 << ".Add new employee" << endl; i++;
		cout << i + 1 << ".Search" << endl; i++;
		cout << i + 1 << ".Return" << endl;
	}
	void showEmpDetails(int index, int sh) {
		system("cls");
		cout << "Name: " << emp[index].getName() << endl;
		cout << "Last Name: " << emp[index].getlName() << endl;
		cout << "Age: " << emp[index].getAge() << endl;
		cout << "Occupation: " << emp[index].getSpec() << endl;
		cout << "Phone Num: " << emp[index].getPhnum() << endl;
		cout << "Salary: " << emp[index].getSalary() << " $" << endl;
		if (!sh)
			cout << "1.Fire employee" << "\n2.Return";
	}
	void searchEmployee(int index, string sch) {
		system("cls");
		bool found = false;
		switch (index)
		{
		case 1:
			for (int i = 0; i < cntEmp; i++) {
				if (emp[i].getName() == sch) {
					showEmpDetails(i, 1);
					found = true;
				}
			}
			break;
		case 2:
			for (int i = 0; i < cntEmp; i++) {
				if (emp[i].getlName() == sch) {
					showEmpDetails(i, 1);
					found = true;
				}
			}
			break;
		}
		if (!found) { cout << "\nNot found"; }
		cout << "\nPress any key to return..";
		_getch();
	}
	//Autosalon
	int getnumOfCar() { return cntCar; }
	int getNumOfEmp() { return cntEmp; }
	void endWeek() {
		if (week == 4) {
			ex = 0;
			pr = 0;
			in = 0;
			week = 0;
		}
		week++;
		for (int i = 0; i < cntEmp; i++) { expense += emp[i].getSalary() / 4; }
		for (int i = 0; i < cntCar; i++) {
			if (car[i].isCarRented)
				income += car[i].getRent() / 4;
		}
		int temp = budget;
		budget = budget - expense + income;
		profit += budget - temp;
		ex += expense;
		in += income;
		pr += profit;
		expense = 0;
		income = 0;
		profit = 0;
	}
	void showBudget() {
		cout << "Week: " << week << endl;
		cout << "Budget: " << budget << endl;
		cout << "Expense: " << ex << endl;
		cout << "Income: " << in << endl;
		cout << "Profit: " << pr << endl;
		cout << "Press any key to return..\n";
		_getch();
	}
	Autosalon() {
		cntCar = 0;
		cntEmp = 0;
		budget = 500000;
		expense = 0;
		income = 0;
		profit = 0;
		ex = 0;
		pr = 0;
		in = 0;
		week = 0;
	}
};

//DATA
void addData(Autosalon& salon) {
	int wrkNum = 4;
	Employee* emp = new Employee[wrkNum];
	emp[0].setName("Murad");
	emp[0].setlName("Seyidov");
	emp[0].setSalary(12000);
	emp[0].setSpec("CEO");
	emp[0].setPhnum(2700175);
	emp[0].setAge(20);
	//
	emp[1].setName("Thelma");
	emp[1].setlName("Evans");
	emp[1].setSalary(1237);
	emp[1].setSpec("Sales Manager");
	emp[1].setPhnum(8158704);
	emp[1].setAge(32);
	//
	emp[2].setName("Michael");
	emp[2].setlName("Christopher");
	emp[2].setSalary(895);
	emp[2].setSpec("HR Consultant");
	emp[2].setPhnum(4058060);
	emp[2].setAge(36);
	//
	emp[3].setName("Joseph");
	emp[3].setlName("Coleman");
	emp[3].setSalary(2313);
	emp[3].setSpec("Finance Manager");
	emp[3].setPhnum(9174582);
	emp[3].setAge(53);
	for (int i = 0; i < wrkNum; i++) { salon.addEmployee(emp[i]); }

	//
	int crnum = 5;
	Car* car = new Car[crnum];
	car[0].setBrand("STERLING TRUCK");
	car[0].setColor("Red");
	car[0].setModel("LT9522");
	car[0].setKm(449444);
	car[0].setPrice(69900);
	car[0].setYear(2001);
	//1
	car[1].setBrand("PONTIAC");
	car[1].setColor("Black");
	car[1].setModel("G5");
	car[1].setKm(309444);
	car[1].setPrice(15700);
	car[1].setYear(2007);
	//2
	car[2].setBrand("Honda");
	car[2].setColor("White");
	car[2].setModel("TRX500FE2");
	car[2].setKm(1274);
	car[2].setPrice(8300);
	car[2].setYear(2014);
	//3
	car[3].setBrand("Honda");
	car[3].setColor("Black");
	car[3].setModel("XR650Ra");
	car[3].setKm(39644);
	car[3].setPrice(3899);
	car[3].setYear(2005);
	//4
	car[4].setBrand("Cadillac");
	car[4].setColor("Silver");
	car[4].setModel("CATERA");
	car[4].setKm(76291);
	car[4].setPrice(4950);
	car[4].setYear(2001);
	for (int i = 0; i < crnum; i++) { salon.addCar(car[i]); }
}

int main() {
	int num = 0;
	Autosalon salon;
	addData(salon);
	while (true) {
		system("cls");
		if (num == 0) {
			cout << "1.Cars\n" << "2.Employees\n" << "3.Budget\n" << "4.End Week\n" << "ENTER: ";
			cin >> num;
		}
		system("cls");
		if (num == 1) {//Cars
			salon.showCars();
			cout << "ENTER: ";
			cin >> num;
			if (num <= salon.getnumOfCar()) {//Car"s details
				system("cls");
				salon.showCarsDetails(num, 0);
				int index = num - 1;
				cout << "\nENTER: ";
				cin >> num;
				system("cls");
				if (salon.isRented(index)) {//Rented
					if (num == 1) {//Request car back
						salon.requestCarBack(index);
					}
					else if (num == 2) { num = 1; }//Return
				}
				else {//Not Rented
					if (num == 1) {//Sell
						salon.sellCar(index);
					}
					else if (num == 2) {//Rent
						salon.rentACar(index);
						num = 1;
					}
					else if (num == 3) { num = 1; } //Return
				}
			}
			else if (num == salon.getnumOfCar() + 1) {//Buy Car for salon
				system("cls");
				Car car;
				int tmInt;
				string tmString;
				cout << "Brand: ";
				cin >> tmString; car.setBrand(tmString);
				cout << "\nModel: ";
				cin >> tmString; car.setModel(tmString);
				cout << "\nColor:	";
				cin >> tmString; car.setColor(tmString);
				while (true) {
					cout << "\nYear: ";
					cin >> tmInt;
					if (tmInt >= 1920 && tmInt <= 2021)
						break;
					cout << "\nWrong";
				}
				car.setYear(tmInt);
				while (true) {
					cout << "\nKm: ";
					cin >> tmInt;
					if (tmInt >= 0)
						break;
					cout << "\nWrong";
				}
				car.setKm(tmInt);
				while (true) {
					cout << "\nPrice: ";
					cin >> tmInt;
					if (tmInt > 0)
						break;
					cout << "\nWrong";
				}
				car.setPrice(tmInt);
				salon.addCar(car);
				num = 1;
			}
			else if (num == salon.getnumOfCar() + 2) {//Search
				system("cls");
				cout << "Search car for:\n";
				cout << "1.Brand\n2.Model\n3.Color\n4.Year\n5.Price\n6.Return";
				cout << "\nENTER: ";
				cin >> num;
				if (num > 0 && num < 4) {//String Search
					system("cls");
					string sch;
					cout << "Search: ";
					cin >> sch;
					salon.searchCar(num, sch);
					num = 1;
				}
				else if (num > 3 && num < 6) {//Int Search
					system("cls");
					int sch;
					cout << "Search: ";
					cin >> sch;
					salon.searchCar(num, sch);
					num = 1;
				}
				else if (num == 6) { num = 1; }//Return
			}
			else if (num == salon.getnumOfCar() + 3) { salon.endWeek(); num = 0; } //Return
		}
		else if (num == 2) {//Employees
			salon.showEmployees();
			cout << "\nENTER: ";
			cin >> num;
			if (num <= salon.getNumOfEmp()) {//Show Employee
				system("cls");
				salon.showEmpDetails(num - 1, 0);
				int index = num - 1;
				cout << "\nENTER: ";
				cin >> num;
				system("cls");
				if (num == 1) {//Fire Employee
					salon.fireEmployee(index);
					num = 2;
				}
			}
			else if (num <= salon.getNumOfEmp() + 1) {//Add new employee
				system("cls");
				int intg;
				string str;
				Employee emp;
				cout << "Name: ";
				cin >> str;
				emp.setName(str);
				cout << "Last Name: ";
				cin >> str;
				emp.setlName(str);
				while (true) {
					cout << "Age: ";
					cin >> intg;
					if (intg >= 18 && intg < 65)
						break;
					cout << "\nWrong\n";
				}
				emp.setAge(intg);
				cout << "Occupation: ";
				cin >> str;
				emp.setSpec(str);
				while (true) {
					cout << "Phone Num: ";
					cin >> intg;
					if (intg > 1000000 && intg < 10000000)
						break;
					cout << "\nWrong\n";
				}
				emp.setPhnum(intg);
				while (true) {
					cout << "Salary: ";
					cin >> intg;
					if (intg > 300)
						break;
					cout << "\nWrong\n";
				}
				emp.setSalary(intg);
				salon.addEmployee(emp);
				num = 2;
			}
			else if (num <= salon.getNumOfEmp() + 2) {//Search
				system("cls");
				cout << "Search employee for:\n";
				cout << "1.Name\n2.Last Name\n3.Return";
				cout << "\nENTER: ";
				cin >> num;
				if (num > 0 && num < 3) {//String Search
					system("cls");
					string sch;
					cout << "Search: ";
					cin >> sch;
					salon.searchEmployee(num, sch);
					num = 2;
				}
				else if (num == 3) { num = 2; }//Return
			}
			else if (num <= salon.getNumOfEmp() + 3) { num = 0; }//Return
		}
		else if (num == 3) { salon.showBudget(); num = 0; } //Budget
		else if (num == 4) { salon.endWeek(); num = 0; }//End Week
	}
}