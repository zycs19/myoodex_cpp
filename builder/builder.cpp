#include<iostream>
#include<string>

using namespace std;

class RobotPlan{
	public:
		virtual void setRobotHead(string head){};
		virtual void setRobotTorso(string torso){};
		virtual void setRobotArms(string arms){};
		virtual void setRobotLegs(string legs){};
		virtual void print(){};
		//virtual RobotPlan(){};
};

class Robot: public RobotPlan{
	private:
		string robotHead;
		string robotTorso;
		string robotArms;
		string robotLegs;

	public:
		void setRobotHead(string head){
			robotHead = head;
		}
		void setRobotTorso(string torso){
			robotTorso = torso;
		}
		void setRobotArms(string arms){
			robotArms = arms;
		}
		void setRobotLegs(string legs){
			robotLegs = legs;
		}
		
		string getRobotHead(){
			return robotHead;
		}
		string getRobotTorso(){
			return robotTorso;
		}
		string getRobotArms(){
			return robotArms;
		}
		string getRobotLegs(){
			return robotLegs;
		}
		void print(){
			cout<<"$Robot Head:"<<getRobotHead()
				<<"Torso:"<<getRobotTorso()
				<<"Arms:"<<getRobotArms()
				<<"Legs:"<<getRobotLegs()
				<<endl;
		}
		//Robot(){};
};

class RobotBuilder{
	public:
		virtual void buildRobotHead(){};
		virtual void buildRobotTorso(){};
		virtual void buildRobotArms(){};
		virtual void buildRobotLegs(){};
		virtual Robot* getRobot(){
			return NULL;
		};
};

class OldRobotBuilder : public RobotBuilder{
	private:
		Robot *robot;
	public:
		OldRobotBuilder(){
			this->robot = new Robot();
		}
		void buildRobotHead(){
			robot->setRobotHead("Head1");
		}
		void buildRobotTorso(){
			robot->setRobotTorso("Torse1");
		}
		void buildRobotArms(){
			robot->setRobotArms("Arms1");
		}
		void buildRobotLegs(){
			robot->setRobotLegs("Legs1");
		}
		Robot* getRobot(){
			return this->robot;
		}
};

class RobotEngineer{
	private:
		RobotBuilder* robotBuilder;
	public:
		RobotEngineer(RobotBuilder* robotBuilder){
			this->robotBuilder = robotBuilder;
		}
		Robot* getRobot(){
			return this->robotBuilder->getRobot();
		}
		void makeRobot(){
			this->robotBuilder->buildRobotHead();
			this->robotBuilder->buildRobotTorso();
			this->robotBuilder->buildRobotArms();
			this->robotBuilder->buildRobotLegs();
		}
};
int main(){
	RobotBuilder* oldStyleRobot = new OldRobotBuilder();
	RobotEngineer* robotEngineer = new RobotEngineer(oldStyleRobot);
	robotEngineer->makeRobot();

	Robot* robot = robotEngineer->getRobot();
	robot->print();


}
