#include <iostream>

class Strategy
{
public:
	virtual ~Strategy() {}
	virtual void Method() = 0;
};

class StrategyA : public Strategy
{
public:
	void Method() override
	{
		std::cout << "StrategyA::Method()" << std::endl;
	}
};

class StrategyB : public Strategy
{
public:
	void Method() override
	{
		std::cout << "StrategyB::Method()" << std::endl;
	}
};

class Context
{
public:
	Context(Strategy* strategy)
		:strategy_(strategy) {}
	void execute()
	{
		strategy_->Method();
	}
private:
	Strategy* strategy_;
};

int main(int argc, char* argv[])
{
	Strategy* strategy = new StrategyA();
	Context ctx(strategy);
	ctx.execute();
	ctx = new StrategyB();
	ctx.execute();
	return 0;
}