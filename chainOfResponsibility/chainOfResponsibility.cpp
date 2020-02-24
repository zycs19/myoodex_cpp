#include<iostream>
#include<string>
#include<cstring>

using namespace std;


class Numbers{
	public:
		int n1;
		int n2;
		int result;
		string calculationWanted;
	public:
		Numbers(int n1, int n2, string calculationWanted){
			this->n1 = n1;
			this->n2 = n2;
			this->calculationWanted = calculationWanted;
		}

		int getN1()
			{return n1;}
		int getN2()
			{return n2;}
		int getResult(){
			return result;
		}
		void putResult(int result){
			this->result = result;
		}
		string getCalcWanted(){return calculationWanted;}
};

class Chain{
//	public:
//		Chain* nextInChain;
	public:
		virtual void setNextChain(Chain* nextInChain)=0;
		virtual void calculate(Numbers* request)=0;
};

class Add:public Chain{
//	public:
		Chain* nextInChain;
	public:
		void setNextChain(Chain* nextInChain){
			this->nextInChain = nextInChain;
			//cout<<"Within Add:Chain setNextChain:"<<nextInChain<<endl;
		}
		void calculate(Numbers* request){
			 //cout<<"-9-"<<endl;
			if( !request->getCalcWanted().compare("add")){
				request->putResult( request->getN1()+request->getN2() );
			}
			else{
				//cout<<"-5-"<<nextInChain<<endl;
				nextInChain->calculate(request);
			}
		}
};
class Sub:public Chain{
//	public:
		Chain* nextInChain;
	public:
		void setNextChain(Chain* nextInChain){
			this->nextInChain = nextInChain;
		}
		void calculate(Numbers* request){
			//cout<<"-7-"<<endl;
			if( !request->getCalcWanted().compare("sub")){
				request->putResult( request->getN1()-request->getN2() );
			}
			else{//cout<<"-6-"<<endl; 
				nextInChain->calculate(request);
			}
		}
};

class Mult:public Chain{
//	public:
		Chain* nextInChain;
	public:
		void setNextChain(Chain* nextInChain){
			this->nextInChain = nextInChain;
		}
		void calculate(Numbers* request){
			if( !request->getCalcWanted().compare("mult")){
				 //cout<<"-7-"<<endl;
				request->putResult( (request->getN1()) * (request->getN2()) );
				//cout<< request->getN1() <<endl;
				//cout<< request->getN2() <<endl;
			}
			else{ 
				nextInChain->calculate(request);
			}
		}
};

class Devide:public Chain{
//	public:
		Chain* nextInChain;
	public:
		void setNextChain(Chain* nextInChain){
			this->nextInChain = nextInChain;
		}
		void calculate(Numbers* request){
			if( !request->getCalcWanted().compare("/")){
				request->putResult( (request->getN1()) / (request->getN2()) );
			}
			else{
				//nextInChain->calculated(request);
				cout<<"only works for add, sub, mult and devide" <<endl;
			}
		}
};

int main(){
	
	Chain* c1 = new Add();
	//cout<<"-1-"<<endl;
	Chain* c2 = new Sub();
	Chain* c3 = new Mult();
	Chain* c4 = new Devide();

	c1->setNextChain(c2);
	//cout<<c1<<endl;
	//cout<<"*"<<c2<<endl;
	//cout<<c1->nextInChain<<endl;
	c2->setNextChain(c3);
	//cout<<c2<<endl;
	//cout<<c2->nextInChain<<endl;
	c3->setNextChain(c4);
	//cout<<c3<<endl;
 //cout<<"-2-"<<endl;

	Numbers* request = new Numbers(4,2,"mult");
//	 cout<<"-3-"<<endl;
	c1->calculate(request);
//	 cout<<"-4-"<<endl;
	cout<< request->getResult() <<endl;
}
