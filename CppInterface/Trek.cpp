#include "Trek.h"
#include <iostream>
#include<vector>
#include<string>
#include <fstream>

using namespace std;



//apears a catalog for the user
void firstscreen(){

	cout << "Prices Catalog" << endl << endl;
	cout << "Choose as many options as you want of the next list:" << endl << endl;
	cout << "Settler Carriages" << endl << endl;
	cout << "\t" << "Name" << "\t\t" << "Horses" << "\t" << "Settler" << "\t" << "Cost" << endl;
	cout << "1.- SettlerSmall" << "\t" << 1 << "\t" << 1 << "\t" << "$25" << endl;
	cout << "2.- SettlerMedium" << "\t" << 2 << "\t" << 2 << "\t" << "$40" << endl;
	cout << "3.- SettlerLarge" << "\t" << 4 << "\t" << 6 << "\t" << "$70" << endl << endl;

	cout << "Food Supply Carriages" << endl << endl;
	cout << "\t" << "Name" << "\t\t" << "Horses" << "\t" << "Water, potatoes and whisky" << "\t" << "Cost" << endl;
	cout << "4.- FoodSupply" << "\t\t" << 1 << "\t" << "included" << "\t\t\t" << "$50" << endl << endl;

	cout << "Shop Carriages" << endl << endl;
	cout << "\t" << "Name" << "\t\t" << "Horses" << "\t" << "Food Supply Carriages" << "\t" << "Cost" << endl;
	cout << "5.- ShopSmall" << "\t\t" << 1 << "\t" << 1 << "\t\t\t" << "$50" << endl;
	cout << "6.- ShopMedium" << "\t\t" << 1 << "\t" << 2 << "\t\t\t" << "$60" << endl;
	cout << "7.- ShopLarge" << "\t\t" << 1 << "\t" << 6 << "\t\t\t" << "$70" << endl << endl;

	cout << "Energy Source Carriage" << endl << endl;
	cout << "\t" << "Name" << "\t\t" << "Horses" << "\t" << "Carrots" << "\t" << "Cost" << endl;
	cout << "8.- EnergySource" << "\t" << 1 << "\t" << 500 << "\t" << "$35" << endl << endl;

	cout << "Hospital Carriage" << endl << endl;
	cout << "\t" << "Name" << "\t\t" << "Horses" << "\t" << "Operation table and two beds " << "\t" << "Cost" << endl;
	cout << "9.- Hospital" << "\t\t" << 1 << "\t" << "included" << "\t\t\t" << "$200" << endl << endl;

	cout << "Sheriff Carriages" << endl << endl;
	cout << "\t" << "Name" << "\t\t" << "Horses" << "\t" << "Settler protected" << "\t" << "Cost" << endl;
	cout << "10.- SheriffSmall" << "\t" << 1 << "\t" << 1 << "\t\t\t" << "$20" << endl;
	cout << "11.- SheriffMedium" << "\t" << 2 << "\t" << 4 << "\t\t\t" << "$30" << endl;
	cout << "12.- SheriffLarge" << "\t" << 4 << "\t" << 10 << "\t\t\t" << "$60" << endl << endl;

};//
//gets all the information from the trek
void testInterface(){

	Trek* trek = readTrek("4221198_trek.dat");
	//trek->userInterfaceCreateTrek();
	//	trek->readTrek("4221198_trek.dat");
	cout << "Information from Trek" << endl;
	cout << "Trek Name\t" << trek->getTrekName() << endl;
	cout << "Hospital\t" << trek->getHasMedic() << endl;
	cout << "Total energy\t" << trek->getEnergyConsumption() << endl;
	cout << "Total cost\t" << trek->getCost() << endl;
	cout << "Total Settlers\t" << trek->getSettlerCount() << endl;

	cout << "Information from Settlercarriage" << endl;
	vector<Carriage*> SettlerCarriageList = trek->getSettlerCarriageList();
	cout << "\tcarriage" << endl;

	for (unsigned int i = 0; i < SettlerCarriageList.size(); i++)
	{
		cout << i + 1 << "\t" << SettlerCarriageList[i]->getTypeName() << "\t" << endl;
		SettlerCarriage* settlercarriage = dynamic_cast<SettlerCarriage*>(SettlerCarriageList[i]);
		cout << "->SC():" << settlercarriage->getSettlerCount() << ";" << endl;		
		cout << "->I():" << settlercarriage->getIsInfected() << ";";
		settlercarriage->infect();		
		cout << "->D():" << settlercarriage->getIsDestroyed() << endl << endl;
		settlercarriage->destroy();
	}


	cout << "Information from Carriage" << endl;
	vector<Carriage*> CarriageList = trek->getCarriegeList();
	cout << "\tcarriage" << "\tenergy\t" << "cost\t\t" << endl;
	for (unsigned int i = 0; i < CarriageList.size(); i++)
	{
		cout << i + 1 << "\t" << CarriageList[i]->getTypeName() << "\t" << CarriageList[i]->getEnergyConsumption() << "\t" << CarriageList[i]->getCost() << endl << endl;
	}
	delete trek;
};
//write trek given by the user
void writeTrek(Trek* trek, string data){
	string a;
	int no[12] = { 0 };
	string carriage[12];
	carriage[0] = "SettlerSmall";
	carriage[1] = "SettlerMedium";
	carriage[2] = "SettlerLarge";
	carriage[3] = "FoodSupply";
	carriage[4] = "ShopSmall";
	carriage[5] = "ShopMedium";
	carriage[6] = "ShopLarge";
	carriage[7] = "EnergySource";
	carriage[8] = "Hospital";
	carriage[9] = "SheriffSmall";
	carriage[10] = "SheriffMedium";
	carriage[11] = "SheriffLarge";

	ofstream myfile(data);//open data
	if (myfile.is_open())//filter
	{
		int k = 0;
		vector<Carriage*> CarriageList = trek->getCarriegeList();
		for (unsigned int i = 0; i < CarriageList.size(); i++)
		{

			a = CarriageList[i]->getTypeName();
			for (unsigned int j = 0; j < 12; j++)
			{
				if (carriage[j] == a)
				{
					no[j] = no[j] + 1;
				}
			}
		}
		myfile << trek->getTrekName();
		myfile << endl;

		for (unsigned int k = 0; k < 12; k++)
		{
			if (no[k] != 0)
			{
				myfile << carriage[k] << "\t" << no[k] << endl;
			}
		}
		
	}
}
//read a file with a trek
Trek* readTrek(string data){
	Trek* trek = new Trek();//create a trek object
	vector <Carriage*> Clist;//vector for all the objects carriages
	vector <Carriage*> SClist;//vector for all the objects settler carriages
	Carriage *ptr;//pointer of carriage
	bool Hospital=false;//variable for hospital
	string TrekName;//variable for trek name
	ifstream infile(data);//take the data from a file
	string a;
	int b;
	getline(infile, TrekName);
	//Filter for the data carriage in the file
	while (infile >> a >> b)
	{
		if (a == "SettlerSmall")
		{
			ptr = new SettlerCarriageSmall;
			
			Clist.insert(Clist.end(), b, ptr);
			SClist.insert(SClist.end(), b, ptr);
		}

		else if (a == "SettlerMedium")
		{
			ptr = new SettlerCarriageMedium;
			Clist.insert(Clist.end(), b, ptr);
			SClist.insert(SClist.end(), b, ptr);
		}
		else if (a == "SettlerLarge")
		{
			ptr = new SettlerCarriageLarge;
			Clist.insert(Clist.end(), b, ptr);
			SClist.insert(SClist.end(), b, ptr);
		}
		else if (a == "FoodSupply")
		{
			ptr = new FoodSupplyCarriage;
			Clist.insert(Clist.end(), b, ptr);
		}
		else if (a == "ShopSmall")
		{
			ptr = new ShopCarriageSmall;
			Clist.insert(Clist.end(), b, ptr);
		}
		else if (a == "ShopMedium")
		{
			ptr = new ShopCarriageMedium;
			Clist.insert(Clist.end(), b, ptr);
		}
		else if (a == "ShopLarge")
		{
			ptr = new ShopCarriageLarge;
			Clist.insert(Clist.end(), b, ptr);
		}
		else if (a == "EnergySource")
		{
			ptr = new EnergySourceCarriage;
			Clist.insert(Clist.end(), b, ptr);
		}
		else if (a == "Hospital")
		{
			Hospital = true;
			ptr = new HospitalCarriage;
			Clist.insert(Clist.end(), b, ptr);
		}
		else if (a == "SheriffSmall")
		{
			ptr = new SheriffCarriageSmall;
			Clist.insert(Clist.end(), b, ptr);
		}
		else if (a == "SheriffMedium")
		{
			ptr = new SheriffCarriageMedium;
			Clist.insert(Clist.end(), b, ptr);
		}
		else if (a == "SheriffLarge")
		{
			ptr = new SheriffCarriageLarge;
			Clist.insert(Clist.end(), b, ptr);
		}
		else
		{
			cout << "Invalid data";
		}
	}
	//Initializing variables
	trek->SetCarriegeList(Clist);
	trek->SetSettlerCarriageList(SClist);
	trek->setHasMedic(Hospital);
	trek->SetTrekName(TrekName);

	return trek;
};
//create a trek from an interactive interface 
Trek* userInterfaceCreateTrek(){
		
	int option2;
	int numberof;//number of carriage chosen by the user
	Trek* trek = new Trek();//create an object Trek
	vector <Carriage*> Clist;//vector for all the objects carriages
	vector <Carriage*> SClist;//vector for all the objects settler carriages
	Carriage *ptr;//Pointer carriage
	bool Hospital = false;//variable for hospital
	string TrekName;//variable for trek name
	
	cout << "Write the name of your trek, please" << endl;
	cin >> TrekName;
	firstscreen();//appears the catalog to be seen by the user
		do{
			cout << "Please, choose any of the options above or 0 to finish" << endl;
			cin >> option2;
			switch (option2){
			case 0:
				option2 = 0;
				break;
			case 1:
				cout << "How many SettlerSmall?" << endl;
				cin >> numberof;
				ptr = new SettlerCarriageSmall;
				Clist.insert(Clist.end(), numberof, ptr);
				SClist.insert(SClist.end(), numberof, ptr);
				break;
			case 2:
				cout << "How many SettlerMedium?" << endl;
				cin >> numberof;
				ptr = new SettlerCarriageMedium;
				Clist.insert(Clist.end(), numberof, ptr);
				SClist.insert(SClist.end(), numberof, ptr);
				break;
			case 3:
				cout << "How many SettlerLarge?" << endl;
				cin >> numberof;
				ptr = new SettlerCarriageLarge;
				Clist.insert(Clist.end(), numberof, ptr);
				SClist.insert(SClist.end(), numberof, ptr);
				break;
			case 4:
				cout << "How many Food Supply Carriage?" << endl;
				cin >> numberof;
				ptr = new FoodSupplyCarriage;
				Clist.insert(Clist.end(), numberof, ptr);
				break;
			case 5:
				cout << "How many ShopSmall?" << endl;
				cin >> numberof;
				ptr = new ShopCarriageSmall;
				Clist.insert(Clist.end(), numberof, ptr);
				break;
			case 6:
				cout << "How many ShopMedium?" << endl;
				cin >> numberof;
				ptr = new ShopCarriageMedium;
				Clist.insert(Clist.end(), numberof, ptr);
				break;
			case 7:
				cout << "How many ShopLarge?" << endl;
				cin >> numberof;
				ptr = new ShopCarriageLarge;
				Clist.insert(Clist.end(), numberof, ptr);
				break;
			case 8:
				cout << "How many Energy Source Carriages?" << endl;
				cin >> numberof;
				ptr = new EnergySourceCarriage;
				Clist.insert(Clist.end(), numberof, ptr);
				break;
			case 9:
				cout << "How many Hospital Carriages?" << endl;
				cin >> numberof;
				Hospital = true;
				ptr = new HospitalCarriage;
				Clist.insert(Clist.end(), numberof, ptr);
				break;
			case 10:
				cout << "How many SheriffSmall?" << endl;
				cin >> numberof;
				ptr = new SheriffCarriageSmall;
				Clist.insert(Clist.end(), numberof, ptr);
				break;
			case 11:
				cout << "How many SheriffMedium?" << endl;
				cin >> numberof;
				ptr = new SheriffCarriageMedium;
				Clist.insert(Clist.end(), numberof, ptr);
				break;
			case 12:
				cout << "How many SheriffLarge?" << endl;
				cin >> numberof;
				ptr = new SheriffCarriageLarge;
				Clist.insert(Clist.end(), numberof, ptr);
				break;
			default:
				cout << "Invalid option" << endl;
			}
		} while (option2 != 0);
		//Initializing variables
		trek->SetCarriegeList(Clist);
		trek->SetSettlerCarriageList(SClist);
		trek->setHasMedic(Hospital);
		trek->SetTrekName(TrekName);

		return trek;
};
//tests the trek
void testTrekCreation(){
	Trek* trek = userInterfaceCreateTrek();
	writeTrek(trek,"test_trek.dat");
	delete trek;
}

//Carriage methods
Carriage::Carriage(){};
Carriage::~Carriage(){};
int Carriage::getCost()const{ return cost; };//Gets the cost of every carriage
string Carriage::getTypeName()const{ return typeName; };//Gets the name of every carriage
int Carriage::getEnergyConsumption()const{ return energy; };//Gets the energy of every carriage
int Carriage::HorsesCount()const{ return horses; };//Gets the amount of horses of every carriage
int Carriage::getSettlerCount()const{ return settlers; };//Gets the amount of settlers of every carriage

//Trek methods
Trek::Trek(){};
Trek::~Trek(){};
int Trek::getEnergyConsumption()const {

	int TotalEnergy = NULL;

	for (unsigned int i = 0; i < Clist.size(); i++)
	{
		TotalEnergy = TotalEnergy+Clist[i]->getEnergyConsumption();
	}
	return TotalEnergy;
};
//counts settlers
int Trek::getSettlerCount()const{ 
	
		int TotalSettlers = NULL;

	for (unsigned int i = 0; i < SClist.size(); i++)
	{
		TotalSettlers = TotalSettlers + SClist[i]->getSettlerCount();
	}
	return TotalSettlers;
	
 };
//calculate trek cost
int Trek::getCost() const{ 
	
	int TotalCost = NULL;

	for (unsigned int i = 0; i < Clist.size(); i++)
	{
		TotalCost = TotalCost + Clist[i]->getCost();
	}
	return TotalCost;
	
};
//gets medic
bool Trek::getHasMedic() const{ 	
	return Hospital;
};
//sets medic
void Trek::setHasMedic(bool newMedic){ Hospital = newMedic; };
//gets trek name
string Trek::getTrekName() const{ 
		return TrekName;
};
//sets trek name
void Trek::SetTrekName(string newTrekName){ TrekName = newTrekName; };
//get Settler Carriage List
vector<Carriage*> Trek::getSettlerCarriageList() const{ return SClist; };
//get Carriege List
vector<Carriage*> Trek::getCarriegeList() const{ return Clist; };
//Set Settler Carriage List
void Trek::SetSettlerCarriageList(vector<Carriage*> NewSClist){ SClist = NewSClist; };//set vector for settler carriages
//Set Carriege List
void Trek::SetCarriegeList(vector<Carriage*> NewClist){ Clist = NewClist; };//set vector for carriages

//settler carriage methods
SettlerCarriage::SettlerCarriage(){};
SettlerCarriage::~SettlerCarriage(){};
//infects  carriages if it is called
void SettlerCarriage::infect()
{
	if (infected==false)
	{
		infected = true;
	}
	
};
//gets the state of the carriage, false if it is not infected, true if it is infected
bool SettlerCarriage::getIsInfected() const{ return infected; };
//destroy carriages if it is called
void SettlerCarriage::destroy()
{ 
	if (destroyed == false)
	{
		destroyed = true;
	}

};
//gets the state of the carriage, false if it is not destroyed, true if it is destroyed
bool SettlerCarriage::getIsDestroyed() const{ return destroyed; };

//Settler Carriage Small methods
//Settler Carriage constructor
SettlerCarriageSmall::SettlerCarriageSmall()
{
	cost = 25;
	typeName = "SettlerSmall";
	horses = 1;
	energy = horses * 20;
	settlers = 1;
};
//Settler Carriage destructor
SettlerCarriageSmall::~SettlerCarriageSmall(){};


//Settler Carriage medium methods
//Settler CarriageMedium constructor
SettlerCarriageMedium::SettlerCarriageMedium()
{
	cost = 40;
	typeName = "SettlerMedium";
	horses = 2;
	energy = horses * 20;
	settlers = 2;
};
//Settler CarriageMedium destructor
SettlerCarriageMedium::~SettlerCarriageMedium(){};


//Settler Carriage large methods
//Settler CarriageMedium constructor
SettlerCarriageLarge::SettlerCarriageLarge()
{ 	
	cost = 25;
	typeName = "SettlerLarge";
	horses = 4;
	energy = horses * 20;
	settlers = 6;
};
//Settler CarriageMedium constructor
SettlerCarriageLarge::~SettlerCarriageLarge(){};


//Food Supply methods
//Food Supply constructor
FoodSupplyCarriage::FoodSupplyCarriage()
{
	cost = 50; 
	typeName = "FoodSupply";
	horses = 1;
	energy = horses * 20;
	settlers = 0;
};
//Food Supply desstructor
FoodSupplyCarriage::~FoodSupplyCarriage(){};
//infects  carriages if it is called
void FoodSupplyCarriage::infect(){};
//adds potatoes to FoodSupplyCarriage
void FoodSupplyCarriage::addPotatoes(Potatoes* NewKilo){ Kilo=NewKilo;};
//removes potatoes from FoodSupplyCarriage
void FoodSupplyCarriage::removePotatoes(){ Kilo = NULL; };
//adds water to FoodSupplyCarriage
void FoodSupplyCarriage::addWater(Water* NewLitre){ Litre = NewLitre; };
//removes water from FoodSupplyCarriage
void FoodSupplyCarriage::removeWater(){ Litre = NULL; };
//adds whisky to FoodSupplyCarriage
void FoodSupplyCarriage::addWhisky(Whisky*  NewPint){ Pint = NewPint; };
//removes whisky from FoodSupplyCarriage
void FoodSupplyCarriage::removeWhisky(){ Pint = NULL; };

//Shop Carriage methods
ShopCarriage::ShopCarriage(){};
//ShopCarriage constructor
ShopCarriage::~ShopCarriage(){};
//ShopCarriage destructor
void ShopCarriage::infect(){};

//Shop Carriage Small methods
//ShopCarriage Small constructor
ShopCarriageSmall::ShopCarriageSmall()
{
	cost = 50;
	typeName = "ShopSmall";
	horses = FSC.HorsesCount() * 1 + 1;
	energy = horses * 20;
	settlers = 0;
};
//ShopCarriage Small denstructor
ShopCarriageSmall::~ShopCarriageSmall(){};


//Shop Carriage Medium methods
// ShopCarriage Medium constructor
ShopCarriageMedium::ShopCarriageMedium()
{
	cost =60 ; 
	typeName = "ShopMedium";
	horses = FSC.HorsesCount() * 2 + 1;
	energy = horses * 20;
	settlers = 0;
};
// ShopCarriage Medium destructor
ShopCarriageMedium::~ShopCarriageMedium(){};


//Shop Carriage Large methods
// ShopCarriage Large constructor
ShopCarriageLarge::ShopCarriageLarge()
{
	cost = 70;
	typeName = "ShopLarge";
	horses = FSC.HorsesCount() * 4 + 1;
	energy = horses * 20;
	settlers = 0;
};
// ShopCarriage Large constructor
ShopCarriageLarge::~ShopCarriageLarge(){};


//Energy Source Carriage methods
//Energy Source Carriage constructor
EnergySourceCarriage::EnergySourceCarriage()
{
	cost = 35;
	typeName = "EnergySource";
	horses = 1;
	energy = horses * 20;
	settlers = 0;
};
//Energy Source Carriage constructor
EnergySourceCarriage::~EnergySourceCarriage(){};
//infects  carriages if it is called
void EnergySourceCarriage::infect(){};
//int EnergySourceCarriage::getSettlerCount(){ int a = NULL; return a; }

// Hospital Carriage methods
// Hospital Carriage constructor
HospitalCarriage::HospitalCarriage()
{
	cost = 200;
	typeName = "Hospital";
	horses = 1;
	energy = horses * 20;
	settlers = 0;
};
// Hospital Carriage destructor
HospitalCarriage::~HospitalCarriage(){};
//infects  carriages if it is called
void HospitalCarriage::infect(){};

// SheriffCarriage methods
// SheriffCarriage constructor
SheriffCarriage::SheriffCarriage(){};
// SheriffCarriage destructor
SheriffCarriage::~SheriffCarriage(){};
//infects  carriages if it is called
void SheriffCarriage::infect(){};

//Sheriff Carriage Small methods
//Sheriff Carriage Small constructor
SheriffCarriageSmall::SheriffCarriageSmall()
{
	cost = 20;
	typeName = "SheriffSmall";
	horses = 1;
	energy = horses * 20;
	settlers = 0;
};
//Sheriff Carriage Small destructor
SheriffCarriageSmall::~SheriffCarriageSmall(){};


//Sheriff Carriage Medium methods
//Sheriff Carriage Medium constructor
SheriffCarriageMedium::SheriffCarriageMedium()
{
	cost = 30;
	typeName = "SheriffMedium";
	horses = 2;
	energy = horses * 20;
	settlers = 0;
};
//Sheriff Carriage Medium destructor
SheriffCarriageMedium::~SheriffCarriageMedium(){};


//Sheriff Carriage Large methods
//Sheriff Carriage Large constructor
SheriffCarriageLarge::SheriffCarriageLarge()
{
	cost = 60;
	typeName = "SheriffLarge";
	horses = 4;
	energy = horses * 20;
	settlers = 0;
};
//Sheriff Carriage Large  destructor
SheriffCarriageLarge::~SheriffCarriageLarge(){};

//Resources for Hospital
furniture::furniture(){};
furniture::~furniture(){};
//Resources for FoodSupplyCarriage
Water::Water(){};
Water::~Water(){};
Potatoes::Potatoes(){};
Potatoes::~Potatoes(){};
Whisky::Whisky(){};
Whisky::~Whisky(){};