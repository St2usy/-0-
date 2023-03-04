#include <iostream>
#include <cstring>
class Car {
protected:
	int speed;
	char* name;
public:
	int gear;
	Car() {}
	Car(int speed, int gear, const char* name) // ������ �����ε� - > ��ȯ���� �ƴ� �Ķ���Ϳ� ���� ������
		: speed(speed), gear(gear) {// �ʱ�ȭ ����Ʈ ��� - > ���� �� �ʱ�ȭ ����� �ƴ϶� ������ ���ÿ� �ʱ�ȭ�� �� - > ����� ���۷����� �ʱ�ȭ ��ų �� ������.
		this->name = new char[strlen(name) + 1];
		strcpy(this->name, name);
	}
	void changeGear(int gear = 4) { // ����Ʈ �Ű����� 4�� ���
		this->gear = gear;
	}
	void speedUp() {
		speed += 5;
	}
	void disPlay() {
		std::cout << name << " " << gear << " " << speed << std::endl;
	}
	void wherAmI() { std::cout << "��ü �ּ� : " << this; }
	~Car() { // ��� ������ ������ ������ ���� ��� ����Ʈ �����ڰ� ���� �ǹǷ� ���� ������!
		if (name != NULL)
			delete[] name;
	} 
	bool operator>(const Car& rhs);
};

class SportsCar : public Car
{
public:
	bool bTurbo;
	void setTurbo(bool bTurbo) { this->bTurbo = bTurbo; }
	void speedUp() {
		if (bTurbo) speed += 20;
		else Car::speedUp();
	}
};

Car& Car::operator=(const Car& rhs) { // ���Կ����� �����ε�
	if (this == &rhs)
		return *this;
	speed = rhs.speed;
	gear = rhs.gear;
	delete name;
	name = new char(strlen(rhs.name) + 1);
	strcpy(name, rhs.name);
	return *this;
}

bool Car::operator>(const Car& rhs) { // �� ������ �����ε�
	if (speed > rhs.speed) return true;
	else 
		return false;
}