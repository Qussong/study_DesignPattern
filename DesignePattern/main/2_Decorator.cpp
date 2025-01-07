
/*
	[ 요구사항 ]

	1. 기본 피자
	- 피자의 기본 베이스가 반드시 필요 합니다.
	- 기본 피자에는 이름과 가격이 정의되어 있습니다.

	2. 토핑 추가
	- 피자에 토핑(치즈, 페퍼로니, 올리브)를 동적으로 추가할 수 있습니다.
	- 토핑은 이름과 추가 비용을 가집니다.

	3. 피자 정보 제공
	- 최종 피자의 이름(기본 피자 + 추가된 토핑들)과 가격을 제공 합니다.
*/

#include <iostream>
#include <string>

// 추상 컴포넌트 : Pizza
// 추상 클래스
class Pizza
{
public:
	virtual std::string getName() const = 0;	// 피자의 이름 반환
	virtual double getPrice() const = 0;		// 피자의 가격 반환
	virtual ~Pizza() = default;					// 소멸자
};

// 구체 컴포넌트 : BasicPizza
class BasicPizza : public Pizza
{
public:
	virtual std::string getName() const override
	{
		return "Basic Pizza";
	}

	virtual double getPrice() const override
	{
		return 5.0;
	}

	virtual ~BasicPizza() override = default;
};

// 추상 데코레이터 : PizzaDecorator
class PizzaDecorator : public Pizza
{
protected:
	Pizza* pizza;
public:
	PizzaDecorator(Pizza* p) : pizza(p) {}

	virtual ~PizzaDecorator() 
	{
		delete pizza;
	}
};

// 구체 데코레이터 : Cheese, Pepperoni, Olive

// 치즈 토핑
class CheeseDecorator : public PizzaDecorator
{
public:
	CheeseDecorator(Pizza* p) : PizzaDecorator(p) {}
	virtual std::string getName() const override
	{
		return pizza->getName() + " + Chesse";
	}
	virtual double getPrice() const override
	{
		return pizza->getPrice() + 2.0;
	}
};

// 페페러니 토핑
class PepperoniDecorator : public PizzaDecorator
{
public:
	PepperoniDecorator(Pizza* p) : PizzaDecorator(p) {}
	virtual std::string getName() const override
	{
		return pizza->getName() + " + Pepperoni";
	}
	virtual double getPrice() const override
	{
		return pizza->getPrice() + 3.0;
	}
};

// 올리브 토핑
class OliveDecorator : public PizzaDecorator
{
public:
	OliveDecorator(Pizza* p) : PizzaDecorator(p) {}
	virtual std::string getName() const override
	{
		return pizza->getName() + " + Olive";
	}
	virtual double getPrice() const override
	{
		return pizza->getPrice() + 1.5;
	}
};

int main()
{
	// 기본 피자 주문
	Pizza* pizza = new BasicPizza();
	std::cout << "order : " << pizza->getName() << std::endl;
	std::cout << "price : " << pizza->getPrice() << std::endl;

	std::cout << "\n\n";

	// 치즈 토핑 추가
	std::cout << "add Chesse Topping" << std::endl;
	pizza = new CheeseDecorator(pizza);
	std::cout << "order : " << pizza->getName() << std::endl;
	std::cout << "price : " << pizza->getPrice() << std::endl;

	std::cout << "\n\n";

	// 페페로니 토핑 추가
	std::cout << "add Pepperoni Topping" << std::endl;
	pizza = new PepperoniDecorator(pizza);
	std::cout << "order : " << pizza->getName() << std::endl;
	std::cout << "price : " << pizza->getPrice() << std::endl;

	std::cout << "\n\n";

	// 올리브 토핑 추가
	std::cout << "add Olive Topping" << std::endl;
	pizza = new OliveDecorator(pizza);
	std::cout << "order : " << pizza->getName() << std::endl;
	std::cout << "price : " << pizza->getPrice() << std::endl;

	return 0;
}