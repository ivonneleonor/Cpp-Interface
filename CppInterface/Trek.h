#include <iostream>
#include<vector>
#include<string>
#include <fstream>
using namespace std;

#ifndef TREK_H
#define TREK_H

class furniture{
public:
	furniture();
	~furniture();
};
class Potatoes{
	Potatoes();
	~Potatoes();
};
class Water{
	Water();
	~Water();
};
class Whisky{
	Whisky();
	~Whisky();
};

//abstract class carriage
class Carriage{

public:
	int cost = NULL;
	int energy = NULL;
	int horses = NULL;
	string typeName;
	int settlers=NULL;

	Carriage();
	virtual ~Carriage();

	virtual int HorsesCount()const;//Returns horses count 
	virtual int getEnergyConsumption()const;//Returns energy consumption regarding the number of horses
	virtual int getCost()const;//Returns the cost of the trek
	virtual string getTypeName()const;//Returns the name of the carriage
	virtual int getSettlerCount()const;//Returns the settler count
	virtual void infect() = 0;//It allows the user to infect the carriage
	
};
//class SettlerCarriage, inherits from Carriage
class SettlerCarriage :public Carriage{
private:
	bool infected = false;
	bool destroyed = false;

public:
	SettlerCarriage();
	~SettlerCarriage();

	
	void infect();//Changes variable infected
	bool getIsInfected() const;
	void destroy();//Changes variable destroyed
	bool getIsDestroyed()const;

};
//class SettlerCarriageSmall, inherits from SettlerCarriage
class SettlerCarriageSmall :public SettlerCarriage{
public:
	SettlerCarriageSmall();
	~SettlerCarriageSmall();

	

};
//class SettlerCarriageMedium, inherits from SettlerCarriage
class SettlerCarriageMedium :public SettlerCarriage{
public:
	SettlerCarriageMedium();
	~SettlerCarriageMedium();

	

};
//class SettlerCarriageLarge, inherits from SettlerCarriage
class SettlerCarriageLarge :public SettlerCarriage{
public:
	SettlerCarriageLarge();
	~SettlerCarriageLarge();

	

};
//class FoodSupplyCarriage, inherits from Carriage
class FoodSupplyCarriage :public Carriage{
private:
	//aggregation with class resources
	Water* Litre;
	Potatoes* Kilo;
	Whisky* Pint;
public:
	FoodSupplyCarriage();
	~FoodSupplyCarriage();

	void infect();
	
	//These functions Manage resources for FoodSupplyCarriage 
	void addPotatoes(Potatoes* NewKilo);
	void removePotatoes();
	void addWater(Water* NewWater);
	void removeWater();
	void addWhisky(Whisky*  NewPint);
	void removeWhisky();
};
//class ShopCarriage, inherits from Carriage
class ShopCarriage :public Carriage{

public:
	FoodSupplyCarriage FSC;

	ShopCarriage();
	~ShopCarriage();
	void infect();
	
};

//class ShopCarriageSmall, inherits from ShopCarriage
class ShopCarriageSmall :public ShopCarriage{
public:
	ShopCarriageSmall();
	~ShopCarriageSmall();

};
//class ShopCarriageSmall, inherits from ShopCarriage
class ShopCarriageMedium :public ShopCarriage{
public:
	ShopCarriageMedium();
	~ShopCarriageMedium();

};
//class ShopCarriageSmall, inherits from ShopCarriage
class ShopCarriageLarge :public ShopCarriage{
public:
	ShopCarriageLarge();
	~ShopCarriageLarge();

};
//class EnergySourceCarriage, inherits from Carriage
class EnergySourceCarriage :public Carriage{

public:
	EnergySourceCarriage();
	~EnergySourceCarriage();

	void infect();
	
};
//class HospitalCarriage, inherits from Carriage
class HospitalCarriage :public Carriage{

private:
	//Composition with class furniture
	furniture table, bed1, bed2;

public:
	HospitalCarriage();
	~HospitalCarriage();

	void infect();
	
};
//class SheriffCarriage, inherits from Carriage
class SheriffCarriage :public Carriage{

public:

	SheriffCarriage();
	~SheriffCarriage();

	void infect();


};
//class SheriffCarriageSmall, inherits from SheriffCarriage
class SheriffCarriageSmall :public SheriffCarriage{
public:
	SheriffCarriageSmall();
	~SheriffCarriageSmall();

};
//class SheriffCarriageMedium, inherits from SheriffCarriage
class SheriffCarriageMedium :public SheriffCarriage{
public:
	SheriffCarriageMedium();
	~SheriffCarriageMedium();

};
//class SheriffCarriageLarge, inherits from SheriffCarriage
class SheriffCarriageLarge :public SheriffCarriage{
public:
	SheriffCarriageLarge();
	~SheriffCarriageLarge();

};

//Main class trek
class Trek{
private:

	bool Hospital = false;//Variable for Hospital
	string TrekName;//Name of the Trek
	Carriage *ptr;//Pointer for objects of carrige type
	vector <Carriage*> Clist;//vector for all the objects carriages
	vector <Carriage*> SClist;//vector for objects settler carriages
	
public:
	Trek();
	~Trek();

	int getEnergyConsumption()const;//Returns the enegy consumption for a food carriage
	int getSettlerCount() const;//Return the number of settlers for a food supply carriage
	int getCost() const;//Return the cost for a food supply carriage
	bool getHasMedic() const;//Returns true if the trek has hospital carriage and false otherwise
	void setHasMedic(bool newMedic);//Set Medic
	string getTrekName() const;//Returns the name of carriage for a ShopCarriageSmall carriage
	void SetTrekName(string newTrekName);//Set Trek name
	vector<Carriage*> getSettlerCarriageList() const;//vector for settler carriages
	vector<Carriage*> getCarriegeList() const;//vector for carriages
	void SetSettlerCarriageList(vector<Carriage*> NewSClist);//set vector for settler carriages
	void SetCarriegeList(vector<Carriage*> NewClist);//set vector for carriages

};

//methods for testing the interface
void testInterface();
Trek* readTrek(string data);
void firstscreen();
void writeTrek(Trek* trek, string data);
void testTrekCreation();







#endif