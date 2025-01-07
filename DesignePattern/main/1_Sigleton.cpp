
/*
	[ �䱸���� ]

	1. ����� ����
	- ���� �� ������ ���� �ϳ��� �����Ѵ�.
	- ������� �ʱ� ��ġ�� (0,0)

	2. ����� �̵�
	- ������ move(int deltaX, int deltaY) �޼��带 ���� �̵� �ϰ�, ��ġ�� ������Ʈ �Ѵ�.
	- ���� ����� ��ǥ�� Ȯ���� �� �ִ� getPosition() �� �����Ѵ�.
*/

#include <iostream>

class Airplane
{
private:
	static Airplane* instance;
	int posX;
	int posY;

	Airplane()
		: posX(0)
		, posY(0)
	{
		std::cout << "Airplane Created at (" << posX << ", " << posY << ")" << std::endl;
	}
public:
	Airplane(const Airplane&) = delete;				// ���� ������ ����
	Airplane& operator=(const Airplane&) = delete;	// ���� ������ ����

public:
	static Airplane* getInstance() {
		if (instance == nullptr)
		{
			instance = new Airplane;
		}
		return instance;
	}

	void move(int deltaX, int deltaY)
	{
		posX += deltaX;
		posY += deltaY;
		std::cout << "Airplane moved to (" << posX << ", " << posY << ")" << std::endl;
	}

	void getPosition() const
	{
		std::cout << "Airplane Position : (" << posX << ", " << posY << ")" << std::endl;
	}
};

Airplane* Airplane::instance = nullptr;

int main()
{
	// �����ڰ� private �̱⿡ �ܺο��� �����ڸ� ���� ��ü ���� �Ұ���
	//Airplane* air = new Airplane();

	std::cout << "Create Air1\n";
	Airplane* air1 = Airplane::getInstance();
	std::cout << "Air1 pos : ";
	air1->getPosition();
	std::cout << "Air1 move : ";
	air1->move(10, 10);

	std::cout << "\n\n";

	std::cout << "Create Air2\n";
	Airplane* air2 = Airplane::getInstance();
	std::cout << "Air2 pos : ";
	air2->getPosition();

	return 0;
}
