#pragma once
#include<iostream>
using namespace std;

class Engine
{
protected:
	unsigned int power;
public:
	Engine(unsigned int power) :power(power) {}
	virtual ~Engine() {}
	virtual unsigned int getPower()const = 0;
	void info()const
	{
		cout << typeid(*this).name();
		cout << " engine power:\t" << power << endl;
	}
};

class SportEngine :public Engine
{
public:
	SportEngine() :Engine(500) {}
	~SportEngine() {}
	unsigned int getPower()const
	{
		return this->power;
	}
};

class TruckEngine :public Engine
{
public:
	TruckEngine() :Engine(1000) {}
	~TruckEngine() {}
	unsigned int getPower()const
	{
		return this->power;
	}
};

class SUVEngine :public Engine
{
public:
	SUVEngine() :Engine(250) {}
	~SUVEngine() {}
	unsigned int getPower()const
	{
		return this->power;
	}
};