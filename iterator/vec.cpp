#include<iostream>
#include<vector>
#include<string>
#include<iterator>

using namespace std;

class Base{
	public:
	string Name;
	int Number;
	vector<int> vect{10,10,10}; //(10,10,10)
	Base(){
		Name = "default";
		Number = 0;
	}
	Base(string newName, int newNum):Name(newName), Number(newNum){};
	string Desc(){
		return (Name + " : " + to_string(Number)
				+ " vect[0] = " + to_string (vect[0]) ) ;
	}
	void print(){
		cout << Desc() <<endl;
	}
};

int main(){
	vector<int> vecInt;
	vecInt.push_back(1);
	vecInt.push_back(2);
	cout << "vecInt[0]: " << vecInt[0] << endl;
	cout << "vecInt[1]: " << vecInt[1] << endl;
	//the value of vecInt[i]
	//
	vector<Base> vecBase;

	Base newBaseObject1;
	cout << "newBaseObject1 = " << newBaseObject1.Desc() <<endl;
	Base *newBaseObject2 = new Base("new",6);
	cout << "newBaseObject2 = " << newBaseObject2->Desc()  <<endl;

	vecBase.push_back(newBaseObject1);
	vecBase.push_back(*newBaseObject2);
	for(int i=0; i<10; i++){
	vecBase.push_back( *( new Base("object"+to_string(i), i) ) );
	}

	//check if deep or shallow copy
	newBaseObject2->Name = "adapt";
	newBaseObject2->vect = {20,0,0};
	//vector push_back is a deep copy

	cout << "vecBase[0]" << vecBase[0].Desc() << endl;
	cout << "vecBase[1]" << vecBase[1].Desc() << endl;

	for (vector<Base>::iterator it = vecBase.begin(); 
			it < vecBase.end(); it ++){
		it->print();		
	}

}
