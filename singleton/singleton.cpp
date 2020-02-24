#include <iostream>

using namespace std;

class singleton{
	static singleton* instance;
private:
	singleton(){
		i=0;
		i++;
		n++;
		
	};
public:
	static int n;
	int i;

	static singleton* getInstance(){
		if(instance==NULL){
			instance = new singleton();
		}
		return instance;
	}
	void print(){
		i++;
		cout<<"This is the No."<<i<<" time access the singleton" <<endl;
		cout<<"There is "<<n<<" singleton in total."<<endl;
	}
};

//initialization all static members 
int singleton::n=0;
singleton* singleton::instance=NULL;

int main(){
	//static member functions can be access without an object.
	singleton* s2 = singleton::getInstance();
	s2->print();
}


