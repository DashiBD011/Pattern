#include<iostream>
#include"Factory.h"
using namespace std;

class SportCar
{
	Engine* engine;
	Tank* tank;
	Wheel* wheel;
public:
	SportCar(SportCarFactory* Factory)
	{
		this->engine = Factory->createEngine();
		this->tank = Factory->createTank();
		this->wheel = Factory->createWheel();
	}
	~SportCar() {}
	void info()const
	{
		engine->info();
		tank->info();
		wheel->info();
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
		for (int i = 0; i < 4; i++)
		{
			this->wheel = Factory->createWheel();
		}
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
	
	SUV LandCruiser(new SUVFactory);
	LandCruiser.info();
}
