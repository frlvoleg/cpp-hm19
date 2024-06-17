//#include "House.h"
//#include "Human.h"
//#include "Flat.h"
//#include<Windows.h>
//
//Human::Human() : Human ( nullptr, 0 ){}
//
//
//Human::Human(int hAge) : name(nullptr), age(hAge) {}
//
//Human::Human(const char* hName) : Human{ hName,0 } {}
//
//Human::Human(const char* hName, int hAge) : name{ hName ? new char[strlen(hName) + 1] : nullptr }, age{ hAge } {
//	if (name) {
//		strcpy_s(name, strlen(hName) + 1, hName);
//	}
//}
//
//Human::~Human()
//{
//	delete[] name;
//}
//
//Human::Human(const Human& hum) : name(nullptr), age(hum.age) {
//	if (hum.name) {
//		name = new char[strlen(hum.name) + 1];
//		strcpy_s(name, strlen(hum.name) + 1, hum.name);
//	}
//}
//
//Human& Human::operator=(const Human& hum) {
//	if (this != &hum) {
//		delete[] name;
//		name = nullptr;
//		age = hum.age;
//		if (hum.name) {
//			name = new char[strlen(hum.name) + 1];
//			strcpy_s(name, strlen(hum.name) + 1, hum.name);
//		}
//	}
//	return *this;
//}
//
//const char* Human::getName() const
//{
//	return name;
//}
//
//int Human::getAge() const
//{
//	return age;
//}
//
//void Human::setName(const char* hName)
//{
//	delete[] name;
//	name = hName ? new char[strlen(hName) + 1] : nullptr;
//	if (name) {
//		strcpy_s(name, strlen(hName) + 1, hName);
//	}
//}
//
//void Human::setAge(int hAge)
//{
//	age = hAge;
//}
