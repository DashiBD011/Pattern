#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
#include<ctime>
using namespace std;

class Singleton
{
	static Singleton* instance;
	string last_name;
	string first_name;
	tm birth_date;
	Singleton()
	{
		cout << "Constructor:\t" << this << endl;
	}
public:
	void set_last_name(const string& last_name)
	{
		this->last_name = last_name;
	}
	void set_first_name(const string& first_name)
	{
		this->first_name = first_name;
	}
	void set_birth_date(size_t year, size_t month, size_t day)
	{
		this->birth_date.tm_year = year-1900;
		this->birth_date.tm_mon = month-1;
		this->birth_date.tm_mday = day;
	}

	~Singleton()
	{
		cout << "Destructor:\t" << this << endl;
	}
	static Singleton* getInstance()
	{
		if (instance == nullptr) instance = new Singleton;    // Lazy initialisation- объект НЕ создается до тех пор пока он не понадобится
		return instance;
	}
	void pritn()const 
	{
		time_t timer;
		time(&timer);
		tm* current_time = localtime(&timer);
		size_t age = current_time->tm_year - birth_date.tm_year;
		if (current_time->tm_mon < birth_date.tm_mon)age--;
		if (current_time->tm_mon == birth_date.tm_mon &&
			current_time->tm_mday < birth_date.tm_mday)age--;
		//cout << last_name << " " << first_name << " " << age << " лет\n";
		printf("%s %s %u", last_name.c_str(), first_name.c_str(), age);
	}
};

Singleton* Singleton::instance = nullptr;

//#define SINGLETON_1	
#define SINGLETON_2	

void main()
{
	setlocale(LC_ALL, "Russian");

#ifdef SINGLETON_1
	//Singleton obj;
	Singleton::getInstance();  // метод getInstance является статическим и может быть вызван только для класса, а не для объекта
	Singleton::getInstance()->set_last_name("Tupenko");
	Singleton::getInstance()->set_first_name("Vasiliy");
	Singleton::getInstance()->set_birth_date(2001, 7, 23);
	Singleton::getInstance()->pritn();
#endif // SINGLETON_1

#ifdef SINGLETON_2

	Singleton* director = Singleton::getInstance();
	director->set_last_name("Tupenko");
	director->set_first_name("Vasiliy");
	director->set_birth_date(1991,5,15);
	director->pritn();
	cout << endl;

	Singleton* director1 = Singleton::getInstance();
	director1->set_last_name("Tupeko");
	director1->set_first_name("Vailiy");
	director1->set_birth_date(1999, 5, 3);
	director1->pritn();
	cout << endl;
	director->pritn();
#endif // SINGLETON_2

}