
/*
	[ �䱸���� ]

	1. �⺻ ����
	- ������ �⺻ ���̽��� �ݵ�� �ʿ� �մϴ�.
	- �⺻ ���ڿ��� �̸��� ������ ���ǵǾ� �ֽ��ϴ�.

	2. ���� �߰�
	- ���ڿ� ����(ġ��, ���۷δ�, �ø���)�� �������� �߰��� �� �ֽ��ϴ�.
	- ������ �̸��� �߰� ����� �����ϴ�.

	3. ���� ���� ����
	- ���� ������ �̸�(�⺻ ���� + �߰��� ���ε�)�� ������ ���� �մϴ�.
*/

#include <iostream>
#include <string>

// �߻� ������Ʈ : Pizza
// �߻� Ŭ����
class Pizza
{
public:
	virtual std::string getName() const = 0;	// ������ �̸� ��ȯ
	virtual double getPrice() const = 0;		// ������ ���� ��ȯ
	virtual ~Pizza() = default;					// �Ҹ���
};

// ��ü ������Ʈ : BasicPizza
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

// �߻� ���ڷ����� : PizzaDecorator
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

// ��ü ���ڷ����� : Cheese, Pepperoni, Olive

// ġ�� ����
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

// ���䷯�� ����
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

// �ø��� ����
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
	// �⺻ ���� �ֹ�
	Pizza* pizza = new BasicPizza();
	std::cout << "order : " << pizza->getName() << std::endl;
	std::cout << "price : " << pizza->getPrice() << std::endl;

	std::cout << "\n\n";

	// ġ�� ���� �߰�
	std::cout << "add Chesse Topping" << std::endl;
	pizza = new CheeseDecorator(pizza);
	std::cout << "order : " << pizza->getName() << std::endl;
	std::cout << "price : " << pizza->getPrice() << std::endl;

	std::cout << "\n\n";

	// ����δ� ���� �߰�
	std::cout << "add Pepperoni Topping" << std::endl;
	pizza = new PepperoniDecorator(pizza);
	std::cout << "order : " << pizza->getName() << std::endl;
	std::cout << "price : " << pizza->getPrice() << std::endl;

	std::cout << "\n\n";

	// �ø��� ���� �߰�
	std::cout << "add Olive Topping" << std::endl;
	pizza = new OliveDecorator(pizza);
	std::cout << "order : " << pizza->getName() << std::endl;
	std::cout << "price : " << pizza->getPrice() << std::endl;

	return 0;
}