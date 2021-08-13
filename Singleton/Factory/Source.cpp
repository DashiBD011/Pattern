#include<iostream>
#include<string>
#include<ctime>
#include<map>
using namespace std;

class Human
{
	unsigned int hp;
	unsigned int demage;
	unsigned int armor;
public:
	Human(unsigned int hp, unsigned int demage, unsigned int armor)
	{
		this->hp = hp;
		this->armor = armor;
		this->demage = demage;
	}
	virtual ~Human()
	{
		cout << "No human - No problem" << endl;
	}
	virtual void info()const
	{
		cout << "\n-----------------------------------\n";
		cout << typeid(*this).name() << endl;
		cout << "HP:\t" << hp << endl;
		cout << "Armor:\t" << armor << endl;
		cout << "damage:\t" << demage << endl;
	}
};

class Traveller :public Human
{
public:
	Traveller(unsigned int hp, unsigned int demage, unsigned int armor) :
		Human(hp, demage, armor) {}
	~Traveller() {}
};

class PoliceOfficer :public Human
{
	std::string weapon;
public:
	PoliceOfficer(unsigned int hp, unsigned int damage, unsigned int armor, const std::string& weapon) :Human(hp, damage, armor)
	{
		this->weapon = weapon;
	}
	~PoliceOfficer() {}
	void info()const
	{
		Human::info();
		cout << "Weapon:\t" << weapon << endl;
	}
};

class Bandit :public Human
{
	std::string weapon;
public:
	Bandit(unsigned int hp, unsigned int damage, unsigned int armor, const std::string& weapon = "") :Human(hp, damage, armor)
	{
		this->weapon = weapon;
	}
	~Bandit() {}
	void info()const
	{
		Human::info();
		cout << "Weapon:\t" << weapon << endl;
	}
};


class HumanFactory
{
public:

	enum HumanType
	{
		Traveller,
		PoliceOfficer,
		Bandit
	};

	static std::map<size_t, std::string> weapons;

	static Human* humanFactory(HumanType human_type)
	{
		switch (human_type)
		{
		case Traveller: return new class Traveller(100, rand() % 10 + 10, 0);
		case PoliceOfficer: return new class PoliceOfficer(100, rand() % 10 + 20, 100, "Beretta");
		case Bandit:
			return new class Bandit(rand() % 50 + 50, rand() % 10 + 30, rand() % 20 + 80, weapons[rand() % (weapons.size())]);
		}
	}

};

std::map<size_t, std::string> HumanFactory::weapons =
{
	std::pair<size_t,std::string>(0,"None"),
	std::pair<size_t, std::string>(1, "Knife"),
	std::pair<size_t, std::string>(2, "Beretta"),
	std::pair<size_t, std::string>(3, "SPAS-12"),
	std::pair<size_t, std::string>(4, "Ingram"),
	std::pair<size_t, std::string>(5, "M4A1")
};

//#define FACTORY_CHECK_1
#define FACTORY_CHECK_2

void main()
{
	setlocale(LC_ALL, "Russian");

	srand(time(NULL));

#ifdef FACTORY_CHECK_1
	Human* t = humanFactory(Traveller);
	t->info();

	Human* p = humanFactory(PoliceOfficer);
	p->info();

	Human* b = humanFactory(Bandit);
	b->info();

#endif // FACTORY_CHECK_1

#ifdef FACTORY_CHECK_2

	const int n = 10;
	Human* human[n]{};
	unsigned int traveller_count = 0;
	unsigned int police_count = 0;
	unsigned int bandit_count = 0;
	for (int i = 0; i < n; i++)
	{
		human[i] = HumanFactory::humanFactory(HumanFactory::HumanType(rand() % 3));
		human[i]->info();
		if (typeid(*human[i]) == typeid(class Traveller))traveller_count++;
		if (typeid(*human[i]) == typeid(class PoliceOfficer))police_count++;
		if (typeid(*human[i]) == typeid(class Bandit))bandit_count++;
	}
	cout << "Travellers: " << traveller_count << endl;
	cout << "PoliceOfficers: " << police_count << endl;
	cout << "Bandits: " << bandit_count << endl;
	for (int i = 0; i < n; i++)
	{
		delete human[i];
	}
#endif // FACTORY_CHECK_2



}