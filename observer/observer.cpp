#include <iostream>
#include <vector>

using namespace std;

class Observer{
	public:
		void update(double ibmPrice,double aaplPrice, double googPrice);
};

class Subject{
	public:
		virtual void registerObserver(Observer o)=0;
		virtual void unregisterObserver(Observer o)=0;
		virtual void notifyObserver()=0;
};

class StockGrabber :public Subject{
	private:
		vector<Observer> observers;
		double ibmPrice;
		double aaplPrice;
		double googPrice;
	public:
		StockGrabber(){
			observers = new vector<Observer>();
		}
		void registerObserver(Observer newObserver){
			observers.push_back(newObserver);
		}
		void unregisterObserver(Observer deleteObserver){
			int observerIndex = observers.indexOf(deleteObserver);
		}
		void notifyObserver(){}
}

int main(){
}
