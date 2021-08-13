#pragma once
#include<iostream>
using namespace std;

class Tank
{
protected:
	unsigned int volume;
public:
	Tank(unsigned int volume) :volume(volume) {}
	virtual ~Tank() {}
	virtual unsigned int getVolume()const = 0;
	void info()const
	{
		cout << typeid(*this).name() << ", volume: " << volume << " liters\n";
	}
};

class SportTank :public Tank
{
public:
	SportTank() :Tank(80) {}
	~SportTank() {}
	unsigned int getVolume()const
	{
		return this->volume;
	}
};

class TruckTank :public Tank
{
public:
	TruckTank() :Tank(2000) {}
	~TruckTank() {}
	unsigned int getVolume()const
	{
		return this->volume;
	}
};