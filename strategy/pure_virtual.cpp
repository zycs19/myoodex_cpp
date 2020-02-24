#include "iostream"

class base{
	public:
	virtual ~base() = 0;
};

class derived{
	public:
	~derived(){};
};

int main(){
	derived b;
}
