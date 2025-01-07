
/*
	[ 요구사항 ]

	1. 비행기 관리
	- 게임 내 비행기는 오직 하나만 존재한다.
	- 비행기의 초기 위치는 (0,0)

	2. 비행기 이동
	- 비행기는 move(int deltaX, int deltaY) 메서드를 통해 이동 하고, 위치를 업데이트 한다.
	- 현재 비행기 좌표를 확인할 수 있는 getPosition() 을 제공한다.
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
	Airplane(const Airplane&) = delete;				// 복사 생성자 제거
	Airplane& operator=(const Airplane&) = delete;	// 대입 연산자 제거

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
	// 생성자가 private 이기에 외부에서 생성자를 통해 객체 생성 불가능
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
