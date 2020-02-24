#include <iostream>
#include <memory>

class Vehicle
{
public:
    virtual void useVehicle() = 0;
};

class FordFigo : public Vehicle
{
public:
    void useVehicle()
    {
        std::cout << "Driving a Ford Figo." << std::endl;
    }
};

class TataNano : public Vehicle
{
public:
    void useVehicle()
    {
        std::cout << "Driving a Tata Nano." << std::endl;
    }
};

class BlackPulsar : public Vehicle
{
public:
    void useVehicle()
    {
        std::cout << "Riding a Black Pulsar." << std::endl;
    }
};

class HondaActiva : public Vehicle
{
public:
    void useVehicle()
    {
        std::cout << "Riding a Honda Activa." << std::endl;
    }
};


class TransportMode
{
   public:
      virtual void use() = 0;
};

class VehicularTransportMode : public TransportMode
{
   public:
      VehicularTransportMode(Vehicle* v) : vehicle(v) {}
      virtual void use()
      {
         vehicle->useVehicle();
      }
      std::unique_ptr<Vehicle> vehicle;
};

class TrainTransportMode : public TransportMode
{
   virtual void use()
   {
      // Do the needful to use the train.
      std::cout << "Riding a train." << std::endl;
   }
};

class PedestrianTransportMode : public TransportMode
{
   virtual void use()
   {
      // Do the needful to use the feet :)
        std::cout << "Walking by foot." << std::endl;
   }
};

class FamilyMember
{
private:
    std::unique_ptr<TransportMode> myTransportMode;
public:
    virtual void display() = 0;
    void setTransportMode(TransportMode *mode)
    {
        myTransportMode.reset(mode);
    }
    void transport()
    {
        myTransportMode->use();
    }
};

class Father : public FamilyMember
{
public:
    virtual void display()
    {
        std::cout << "I am Father" << std::endl;
    }
};

class Mother : public FamilyMember
{
public:
    virtual void display()
    {
        std::cout << "I am Mother" << std::endl;
    }
};


class Son : public FamilyMember
{
public:
    virtual void display()
    {
        std::cout << "I am Son" << std::endl;
    }
};


class Daughter : public FamilyMember
{
public:
    virtual void display()
    {
        std::cout << "I am Daughter" << std::endl;
    }
};

int main()
{
    FamilyMember *fam = new Father();
    fam->display();
    fam->setTransportMode(new VehicularTransportMode(new FordFigo()));
    fam->transport();

    fam = new Daughter();
    fam->display();
    fam->setTransportMode(new VehicularTransportMode(new HondaActiva()));
    fam->transport();

    fam->setTransportMode(new TrainTransportMode());
    fam->transport();

    fam->setTransportMode(new PedestrianTransportMode());
    fam->transport();
    return 0;
}
