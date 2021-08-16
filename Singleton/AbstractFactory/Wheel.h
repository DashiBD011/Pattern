#pragma once
#include<iostream>
using namespace std;

class Wheel
{
protected:
	double width;
	double profile_height;
	double diameter;
public:
	Wheel(double width, double profile_height, double diameter)
		:width(width), profile_height(profile_height), diameter(diameter)
	{}
	virtual~Wheel() {}
	virtual double get_width()const = 0;
	virtual double get_profile_height()const = 0;
	virtual double get_diameter()const = 0;
	void info()const
	{
		cout << typeid(*this).name();
		cout <<", параметры:\t"<< width << "/" << profile_height << "R" << diameter << endl;
	}
};

class SportWheel :public Wheel
{
public:
	SportWheel() :Wheel(275, 40, 18) {}
	~SportWheel() {}

	double get_width()const
	{
		return this->width;
	}
	double get_profile_height()const
	{
		return this->profile_height;
	}
	double get_diameter()const
	{
		return this->diameter;
	}
};

class TruckWheel :public Wheel
{
public:
	TruckWheel() :Wheel(385, 65, 22.5) {}
	~TruckWheel() {}

	double get_width()const
	{
		return this->width;
	}
	double get_profile_height()const
	{
		return this->profile_height;
	}
	double get_diameter()const
	{
		return this->diameter;
	}
};

class SUVWheel :public Wheel
{
public:
	SUVWheel() :Wheel(275, 70, 16) {}
	~SUVWheel() {}

	double get_width()const
	{
		return this->width;
	}
	double get_profile_height()const
	{
		return this->profile_height;
	}
	double get_diameter()const
	{
		return this->diameter;
	}
};