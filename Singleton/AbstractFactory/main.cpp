#include<iostream>
#include"Factory.h"
using namespace std;

class SportCar
{
	Engine* engine;
	Tank* tank;
public:
	SportCar(SportCarFactory* Factory)
	{
		this->engine = Factory->createEngine();
		this->tank = Factory->createTank();
	}
	~SportCar() {}
	void info()const
	{
		engine->info();
		tank->info();
	}
};

class SUV
{	
	Engine* engine;
	Tank* tank;
	Wheel* wheel;
public:
	SUV(SUVFactory* Factory)
	{
		this->engine = Factory->createEngine();
		this->tank = Factory->createTank();
		this->wheel = Factory->createWheel();
	}
	~SUV() {}
	void info()const
	{
		engine->info();
		tank->info();
		wheel->info();
	}
};

void main()
{
	setlocale(LC_ALL,"Russian");
	SportCar lambarghini(new SportCarFactory);
	lambarghini.info();

	cout << endl;
	
	SUV cruiser(new SUVFactory);
	cruiser.info();
}
