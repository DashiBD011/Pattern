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
	~SportCar()
	{

	}
	void info()const
	{
		engine->info();
		tank->info();
	}
};

void main()
{
	setlocale(LC_ALL,"Russian");
	SportCar lambarghini(new SportCarFactory);
	lambarghini.info();
}
