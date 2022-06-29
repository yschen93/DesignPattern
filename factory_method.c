#include <iostream>

class Iproduct
{
public:
	virtual ~Iproduct() = default;
	Iproduct() = default;
	virtual void SomeOperation() const = 0;
};

class Ifactory
{
public:
	virtual ~Ifactory() = default;
	Ifactory() = default;
	virtual Iproduct* CreateProduct() = 0;
	void Operation()
	{
		Iproduct* product_ = this->CreateProduct();
		product_->SomeOperation();
	}
};

class ConcreteProductA : public Iproduct
{
public:
	virtual void SomeOperation() const override
	{
		std::cout << "ConcreteProductA::SomeOperation()" << "\n";
	}
};

class ConcreteProductB : public Iproduct
{
public:
	virtual void SomeOperation() const override
	{
		std::cout << "ConcreteProductB::SomeOperation()" << "\n";
	}
};

class ConcreteFactoryA : public Ifactory
{
public:
	virtual Iproduct* CreateProduct() override
	{
		return new ConcreteProductA();
	}
};

class ConcreteFactoryB : public Ifactory
{
public:
	virtual Iproduct* CreateProduct() override
	{
		return new ConcreteProductB();
	}
};

void ClientOperation(Ifactory* factory)
{
	Iproduct* product;
	factory->Operation();
}

int main(int argc, char* argv[])
{
	ClientOperation(new ConcreteFactoryA());
	ClientOperation(new ConcreteFactoryB());

}
