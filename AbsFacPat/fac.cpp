#include<iostream>
#include<string>
using namespace std;

class Enemyship{
	private:
		string shipName;
		int amtDamage;
	public:
		string getName(){
			return shipName;
		}
		void setName(string newName){
			shipName = newName;
		}
		int getDamage(){
			return amtDamage;
		}
		void setDamage(int Damage){
			amtDamage = Damage;
		}
		virtual void energyShipShoots(){
			cout<<"shoot"<<endl;
		}
		virtual void print(){
			cout<<"Ship name:"<<shipName<<"amtDamage"<<amtDamage<<endl;
		}
		Enemyship(){};
};

class UFOShip:public Enemyship{
	public:
		UFOShip(){
			setName("U");
			setDamage(20);
		}
};

class RocketShip:public Enemyship{
	public:
		RocketShip(){
			setName("R");
			setDamage(40);
		}
};

class EnemyShipFactory{
	public:
		Enemyship* makeShip(string shipName){
			if (shipName == "U")
				return new UFOShip;
			else if (shipName == "R")
				return new RocketShip;
			else
				return NULL;

		}
};
int main(){
	Enemyship* enemyship;
	EnemyShipFactory shipFactory;
	
	string shipName;

	while(cin>>shipName){
		enemyship =  shipFactory.makeShip(shipName);
		delete enemyship;
		if(enemyship != NULL)
			enemyship->print();
		else 
			cout<<"invalide enemy ship name. "<<endl;
	}
}
