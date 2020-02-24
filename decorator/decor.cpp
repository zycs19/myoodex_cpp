#include <iostream>
#include <string>
using namespace std;
class Base{
	public:
	virtual void print(){
		cout<<"+1";
	} 
};

class Object: public Base {
	public:
		string desc;
		void print(){
			cout<<desc<<":";
		}
		Object(string s):desc(s){};

};

class Object2: public Base {
	public:
		string desc;
		void print(){
			cout<<desc<<":";
		}
		Object2(string s):desc(s){};

};
class Decor:public Base{
	public:
	Base* d;
	Decor(Base *d){
		this->d = d;
	}
	virtual void print(){
		d->print();
	}
};
class BaseAdd1: public Decor{
	public:

	virtual void print(){
		Decor::print();
		cout<<"+1";
	}
	BaseAdd1(Base *d):Decor(d){};
};

class BaseAdd2: public Decor{
	public:

	virtual void print(){
		Decor::print();
		cout<<"+2";
	}
	BaseAdd2(Base *d):Decor(d){};
};

int main(){
	Decor *newDecor = new BaseAdd1(new Object("test"));
	Decor *newDecor2 = new BaseAdd2(new BaseAdd1(new Object2("object2")));
	newDecor->print();
	newDecor2->print();
}
