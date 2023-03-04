#include <iostream>
#include <cstring>
class Car {
protected:
	int speed;
	char* name;
public:
	int gear;
	Car() {}
	Car(int speed, int gear, const char* name) // 생성자 오버로딩 - > 반환형이 아닌 파라메터에 따라 구분함
		: speed(speed), gear(gear) {// 초기화 리스트 사용 - > 생성 후 초기화 방식이 아니라 생성과 동시에 초기화를 함 - > 상수나 레퍼런스를 초기화 시킬 때 유용함.
		this->name = new char[strlen(name) + 1];
		strcpy(this->name, name);
	}
	void changeGear(int gear = 4) { // 디폴트 매개변수 4를 사용
		this->gear = gear;
	}
	void speedUp() {
		speed += 5;
	}
	void disPlay() {
		std::cout << name << " " << gear << " " << speed << std::endl;
	}
	void wherAmI() { std::cout << "객체 주소 : " << this; }
	~Car() { // 멤버 변수에 포인터 변수가 없을 경우 디폴트 생성자가 생성 되므로 생략 가능함!
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

Car& Car::operator=(const Car& rhs) { // 대입연산자 오버로딩
	if (this == &rhs)
		return *this;
	speed = rhs.speed;
	gear = rhs.gear;
	delete name;
	name = new char(strlen(rhs.name) + 1);
	strcpy(name, rhs.name);
	return *this;
}

bool Car::operator>(const Car& rhs) { // 비교 연산자 오버로딩
	if (speed > rhs.speed) return true;
	else 
		return false;
}