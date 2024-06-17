////#include "House.h"
////#include "Human.h"
////#include "Flat.h"
////#include<Windows.h>
////
////Flat::Flat() : residents(nullptr), size(0), floor(0), number(0) {}
////
////Flat::Flat(const Human* fResidents, int fSize) : Flat(fResidents, fSize, 0, 0) {}
////
////Flat::Flat(int fFloor, int fNumber) : Flat(nullptr, 0, fFloor, fNumber) {}
////
////Flat::Flat(const Human* fResidents, int fSize, int fFloor, int fNumber) : residents{ fSize ? new Human[fSize] : nullptr }, size{ fSize }, floor{ fFloor }, number{ fNumber } {
////	if (fResidents) {
////		for (int i = 0; i < fSize; i++) {
////			residents[i] = fResidents[i];
////		}
////	}
////}
////
////Flat::Flat(const Flat& flat) : residents{ flat.size ? new Human[flat.size] : nullptr }, size{ flat.size }, floor{ flat.floor }, number{ flat.number } {
////	if (residents) {
////		for (int i = 0; i < size; i++) {
////			residents[i] = flat.residents[i];
////		}
////	}
////}
////
////Flat& Flat::operator=(Flat flat) {
////
////	if (this == &flat) {
////		return *this;
////	}
////
////	if (this->residents != nullptr) {
////		delete[]residents;
////	}
////	size = flat.size;
////	floor = flat.floor;
////	number = flat.number;
////	residents = new Human[flat.size];
////	for (int i = 0; i < flat.size; i++) {
////		residents[i] = flat.residents[i];
////	}
////	return *this;
////}
////
////Flat::~Flat()
////{
////	delete[] residents;
////}
////
////const Human* Flat::getResident(int index) const
////{
////	return &residents[index];
////}
////
////int Flat::getSize() const
////{
////	return size;
////}
////
////int Flat::getFloor() const
////{
////	return floor;
////}
////
////int Flat::getNumber() const
////{
////	return number;
////}
////
////void Flat::setResident(int index, const Human& fResident) {
////	residents[index].setName(fResident.getName());
////	residents[index].setAge(fResident.getAge());
////}
////
////void Flat::setSize(int fSize)
////{
////	size = fSize;
////}
////
////void Flat::setFloor(int fFloor)
////{
////	floor = fFloor;
////}
////
////void Flat::setNumber(int fNumber)
////{
////	number = fNumber;
////}
//
//#include "House.h"
//#include "Human.h"
//#include "Flat.h"
//#include <Windows.h>
//
//Flat::Flat() : residents(nullptr), size(0), floor(0), number(0) {}
//
//Flat::Flat(const Human* fResidents, int fSize) : residents(fSize ? new Human[fSize] : nullptr), size(fSize), floor(0), number(0) {
//    if (fResidents) {
//        for (int i = 0; i < fSize; i++) {
//            residents[i] = fResidents[i];
//        }
//    }
//}
//
//Flat::Flat(int fFloor, int fNumber) : residents(nullptr), size(0), floor(fFloor), number(fNumber) {}
//
//Flat::Flat(const Human* fResidents, int fSize, int fFloor, int fNumber) : residents(fSize ? new Human[fSize] : nullptr), size(fSize), floor(fFloor), number(fNumber) {
//    if (fResidents) {
//        for (int i = 0; i < fSize; i++) {
//            residents[i] = fResidents[i];
//        }
//    }
//}
//
//Flat::Flat(const Flat& flat) : residents(flat.size ? new Human[flat.size] : nullptr), size(flat.size), floor(flat.floor), number(flat.number) {
//    if (residents) {
//        for (int i = 0; i < size; i++) {
//            residents[i] = flat.residents[i];
//        }
//    }
//}
//
//Flat& Flat::operator=(Flat flat) {
//    if (this == &flat) {
//        return *this;
//    }
//
//    delete[] residents;
//
//    size = flat.size;
//    floor = flat.floor;
//    number = flat.number;
//    residents = new Human[flat.size];
//    for (int i = 0; i < flat.size; i++) {
//        residents[i] = flat.residents[i];
//    }
//    return *this;
//}
//
//Flat::~Flat() {
//    delete[] residents;
//}
//
//const Human* Flat::getResident(int index) const {
//    return &residents[index];
//}
//
//int Flat::getSize() const {
//    return size;
//}
//
//int Flat::getFloor() const {
//    return floor;
//}
//
//int Flat::getNumber() const {
//    return number;
//}
//
//void Flat::setResident(int index, const Human& fResident) {
//    residents[index].setName(fResident.getName());
//    residents[index].setAge(fResident.getAge());
//}
//
//void Flat::setSize(int fSize) {
//    size = fSize;
//}
//
//void Flat::setFloor(int fFloor) {
//    floor = fFloor;
//}
//
//void Flat::setNumber(int fNumber) {
//    number = fNumber;
//}
