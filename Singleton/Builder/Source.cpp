#include<iostream>
#include<string>
using namespace std;

class Computer
{
	std::string type;
	std::string cpu;
	std::string ram;
	std::string disk;
	std::string gpu;
public:
	void setType(const std::string& type)
	{
		this->type = type;
	}
	void setCPU(const std::string& cpu)
	{
		this->cpu = cpu;
	}
	void setRAM(std::string ram)
	{
		this->ram = ram;
	}
	void setDisk(const std::string& disk)
	{
		this->disk = disk;
	}
	void setGPU(const std::string& gpu)
	{
		this->gpu = gpu;
	}

	void info()const
	{
		cout << type << endl;
		cout << cpu << endl;
		cout << ram << endl;
		cout << disk << endl;
		cout << gpu << endl;
	}
};

class ComputerBuilder	//Abstract builder
{
protected:
	Computer* computer;
public:
	ComputerBuilder()
	{
		this->computer = new Computer;
	}
	virtual ~ComputerBuilder()
	{
		delete this->computer;
	}
	Computer* getComputer()
	{
		return computer;
	}
	void createNewComputer()
	{
		computer = new Computer;
	}
	virtual void setType() = 0;
	virtual void setCPU() = 0;
	virtual void setRAM() = 0;
	virtual void setDisk() = 0;
	virtual void setGPU() = 0;
};
class GameComputerBuilder :public ComputerBuilder
{
public:
	~GameComputerBuilder()
	{

	}
	void setType()
	{
		computer->setType("GameComputer");
	}
	void setCPU()
	{
		computer->setCPU("Core i9-9900k");
	}
	void setGPU()
	{
		computer->setGPU("GeForce 3090 Ti");
	}
	void setRAM()
	{
		computer->setRAM("64GB");
	}
	void setDisk()
	{
		computer->setDisk("Samsung 980-Pro");
	}
};
class ServerBuilder :public ComputerBuilder
{
public:
	void setType()
	{
		computer->setType("Server");

	}
	void setCPU()
	{
		computer->setCPU("Intel Xeon E3");
	}
	void setGPU()
	{
		computer->setGPU("Maxtor");
	}
	void setRAM()
	{
		computer->setRAM("128 GB ECC");
	}
	void setDisk()
	{
		computer->setDisk("Samsung 980-Evo 2TB");
	}
};
class Sysadmin
{
	ComputerBuilder* comp_builder;
public:
	void assemblyComputer(ComputerBuilder* comp_builder)
	{
		this->comp_builder = comp_builder;
		comp_builder->setType();
		comp_builder->setCPU();
		comp_builder->setGPU();
		comp_builder->setRAM();
		comp_builder->setDisk();
	}
	void turnOnTheComputer()
	{
		//comp_builder->getComputer()->power_button();
		comp_builder->getComputer()->info();
	}
};
void main()
{
	setlocale(LC_ALL, "Russian");
	
	
}