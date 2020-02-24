#include<iostream>
using namespace std;

class IQuackBehavior{
public:
	virtual void quack(){};
	IQuackBehavior(){};
	virtual ~IQuackBehavior(){}; //pure virtual;
};

class QuackBehavior1:public IQuackBehavior{
public:
	void quack(){
		cout << "biu~" << endl;
	}
	QuackBehavior1(){};
	virtual ~QuackBehavior1();

};
QuackBehavior1::~QuackBehavior1(){
	cout<<"test"<<endl;
}

class QuackBehavior2:public IQuackBehavior{
public:
	void quack(){
		cout << "GaGa~" << endl;
	}
	QuackBehavior2(){};
	virtual ~QuackBehavior2(){
		cout<<"test"<<endl;
	}
};

class IFlyBehavior{
public:
	virtual void fly(){};
	IFlyBehavior(){};
	virtual ~IFlyBehavior(){};
};

class FlyBehavior1:public IFlyBehavior{
public:
	void fly(){
		cout<<"flying...."<<endl;
	}
	FlyBehavior1(){};
	~FlyBehavior1(){};
};

class FlyBehavior2:public IFlyBehavior{
	public:
		void fly(){
			cout<<"cannot fly..T.T"<<endl;
		}
		FlyBehavior2(){};
		~FlyBehavior2(){};
};
/*
class IDisplayBehavior{
public:
	Duck d;
	virtual void display(){
		d.display();
		d.fly();
		d.quack();
	}
	virtual IDisplayBehavior();
	virtual ~IDisplayBehavior();
}
*/
class IDisplayBehavior{
	public:
		void print(){
			cout<<"---"<<endl;
		}
};
class Duck{
public:
	IFlyBehavior* fb;
	IQuackBehavior* qb;
	IDisplayBehavior* db;

	Duck(IFlyBehavior* fb, IQuackBehavior* qb, IDisplayBehavior* db){
		this->fb = fb;
		this->qb = qb;
		this->db = db;
	}
	void fly(){
		fb->fly();
	}
	void quack(){
		qb->quack();
	}
	void print(){
		db->print();
	}
	virtual void display(){
		cout<<"defualt display"<<endl;
	}
	void setFlyBehavior(IFlyBehavior* fb){
		this->fb = fb;
	}
	void setQuackBehavior(IQuackBehavior* qb){
		this->qb = qb;
	}

};

class MountainDuck:public Duck{
	public:
		MountainDuck(IFlyBehavior* fb, IQuackBehavior* qb, IDisplayBehavior* db):Duck(fb, qb, db){};
		void display(){
			cout<<"MontainDuck"<<endl;
		}

};

class RiverDuck:public Duck{
	public:
		RiverDuck(IFlyBehavior* fb, IQuackBehavior* qb, IDisplayBehavior* db):Duck(fb, qb, db){};
		void display(){
			cout<<"RiverDuck"<<endl;
		}
};

class CyberDuck:public Duck{
	public:
		CyberDuck(IFlyBehavior* fb, IQuackBehavior* qb, IDisplayBehavior* db):Duck(fb, qb, db){};
		void display(){
			cout<<"CyberDuck"<<endl;
		}
};


int main(){
	IQuackBehavior *biu = new QuackBehavior1();
	IQuackBehavior *gaga = new QuackBehavior2();

	IFlyBehavior *fly = new FlyBehavior1();
	IFlyBehavior *notFly = new FlyBehavior2();

	IDisplayBehavior *db = new IDisplayBehavior();
	
	Duck* d1 = new MountainDuck(fly, biu, db);
	d1->print();

}
