#include <iostream>
using namespace std;

class Human{
	char* name;
	int age;

public:

	Human(const char* hName, int hAge) : name{ hName ? new char[strlen(hName) + 1] : nullptr }, age{ hAge } {
		if (name) {
			strcpy_s(name, strlen(hName) + 1, hName);
		}
	}

	Human() : Human{nullptr, 0} {}

	

	Human(const char* hName) : Human{hName,0 } {}


	Human(int hAge) : Human {nullptr, hAge }{}


	Human(const Human& hum) : name{ hum.name ? new char[strlen(hum.name) + 1] : nullptr }, age{hum.age}{
		if (name && hum.name) {
			strcpy_s(name, strlen(hum.name) + 1, hum.name);
		}
	}


	Human& operator=(const Human& hum) {
		if (this == &hum) {
			return *this;
		}
		if (this->name != nullptr) {
			delete[] name;
		}
		name = hum.name ? new char[strlen(hum.name) + 1] : nullptr;
		age = hum.age;
		if (name && hum.name) {
			strcpy_s(name, strlen(hum.name) + 1, hum.name);
		}
		return *this;
	}

	~Human() {
		delete[] name;
	}

	const char* getName() const { return name; }
	int getAge() const { return age; }

	void setName(const char* hName) {
			delete[] name;
			name = hName ? new char[strlen(hName) + 1] : nullptr;
			if (name) {
			strcpy_s(name, strlen(hName) + 1, hName);
		}
	}
	void setAge(int hAge) {
		age = hAge;
	}

};

class Flat{
	Human* residents;
	int size;
	int floor;
	int number;

public:

	Flat(const Human* fResidents, int fSize, int fFloor, int fNumber) : residents{ fSize ? new Human[fSize] : nullptr }, size{ fSize }, floor{ fFloor }, number{ fNumber } {
		if (fResidents) {
			for (int i = 0; i < fSize; i++) {
				residents[i] = fResidents[i];
			}
		}
	}

	Flat() : Flat{ nullptr, 0, 0,0 }{}

	Flat(const Human* fResidents, int fSize) : Flat{ fResidents, fSize, 0, 0 } {}

	Flat(int fFloor, int fNumber) : Flat{ nullptr, 0, fFloor, fNumber } {}

	Flat(const Flat& flat) : residents{ flat.size ? new Human[flat.size] : nullptr }, size{ flat.size }, floor{ flat.floor }, number{ flat.number } {
		if (residents) {
			for (int i = 0; i < size; i++) {
				residents[i] = flat.residents[i];
			}
		}
	}

	Flat& operator=(const Flat& flat) {

		if (this == &flat) {
			return *this;
		}

		if (this->residents != nullptr) {
			delete[]residents;
		}
		size = flat.size;
		floor = flat.floor;
		number = flat.number;
		residents = new Human[flat.size];
		for (int i = 0; i < flat.size; i++) {
			residents[i] = flat.residents[i];
		}
		return *this;
	}

	~Flat() {
			delete[] residents;
	}

	const Human* getResident(int index) const { return &residents[index]; }

	int getSize() const { return size; }

	int getFloor() const { return floor; }

	int getNumber() const { return number; }

	void setResident(int index, const Human& fResident) {
		residents[index].setName(fResident.getName());
		residents[index].setAge(fResident.getAge());
	}

	void setSize(int fSize) {
		size = fSize;
	}

	void setFloor(int fFloor) {
		floor = fFloor;
	}

	void setNumber(int fNumber) {
		number = fNumber;
	}

};

class House {
	Flat* apartments;
	char* address;
	int floors;
	int sizeAp;

public:
	House() : House{ nullptr, nullptr, 0,0 } {}

	House(int hFlats) : House{ nullptr, nullptr, hFlats, 0 } {}

	House(const char* hAddress) : House{ nullptr, hAddress ,0,0 } {}

	House(const Flat* hFlats, int hSize) : House{ hFlats,nullptr,0, hSize } {}

	House(const Flat* hFlats, const char* hAddress, int hFloors, int hSize) : apartments{ hFlats ? new Flat[hSize] : nullptr }, address{ hAddress ? new char[strlen(hAddress) + 1] : nullptr }, floors{ hFloors }, sizeAp{hSize} {
		if (hFlats) {
			for (int i = 0; i < hSize; i++) {
				apartments[i] = hFlats[i];
			}
		}
		if (address) {
			strcpy_s(address, strlen(hAddress) + 1, hAddress);
		}
	}



	House(const House& home) : address{ home.address ? new char[strlen(home.address) + 1] : nullptr }, floors{ home.floors }, sizeAp{ home.sizeAp }, apartments{ home.sizeAp ? new Flat[home.sizeAp] : nullptr } {
		if (address) {
			strcpy_s(address, strlen(home.address) + 1, home.address);
		}
		if (apartments) {
			for (int i = 0; i < sizeAp; ++i) {
				apartments[i] = home.apartments[i];
			}
		}
	}



	House& operator=(const House& home) {
		if (this == &home) {
			return *this;
		}
		if (this->apartments != nullptr) {
			delete[]apartments;
		}

		if (this->address != nullptr) {
			delete[]address;
		}
		floors = home.floors;
		sizeAp = home.sizeAp;

		address = new char[strlen(home.address) + 1];
		strcpy_s(address, strlen(home.address) + 1, home.address);

		apartments = new Flat[home.sizeAp];
		for (int i = 0; i < home.sizeAp; i++) {
			apartments[i] = home.apartments[i];
		}
		return *this;

	}


	~House() {
		delete[] apartments;
		delete[] address;
	}


	const Flat* getFlat(int index) const { return &apartments[index]; }
	const char* getAddress() const { return address; }
	int getFloors() const { return floors; }
	int getSize() const { return sizeAp; }
	void setFlat(int index, const Flat& hFlat)
		{
			apartments[index].setFloor(hFlat.getFloor());
			apartments[index].setNumber(hFlat.getNumber());
			Human residentCopy = *hFlat.getResident(index);
			apartments[index].setResident(index, residentCopy);
			apartments[index].setSize(hFlat.getSize());
		}
	
	void setAddress(const char* hAddress){
		delete[] address;
		address = hAddress ? new char[strlen(hAddress) + 1] : nullptr;
		if (address) {
			strcpy_s(address, strlen(hAddress) + 1, hAddress);
		}
	}
	void setFloors(int hFloors){ floors = hFloors; }
	void setSize(int hSize){ sizeAp = hSize; }
};


int main() {
	

	Human person1("Alice", 30);
	cout << "Name: " << person1.getName() << ", Age: " << person1.getAge() << endl;

	Human person2("Bob");
	cout << "Name: " << person2.getName() << ", Age: " << person2.getAge() << endl;

	Human person3("Andrew", 25);
	cout << "Name: " << person3.getName() << ", Age: " << person3.getAge() << endl;


	Human residents[] = { person1, person2, person3 };
	Flat flat(residents, 3, 1, 101);
	cout << "Flat size: " << flat.getSize() << ", Floor: " << flat.getFloor() << ", Number: " << flat.getNumber() << endl;


	Human newResident("Charlie", 40);
	flat.setResident(1, newResident);
	cout << "Modified resident: " << flat.getResident(1)->getName() << ", Age: " << flat.getResident(1)->getAge() << endl;


	Flat flats[] = { flat };
	House house(flats, "123 Main St", 5, 1);
	cout << "House address: " << house.getAddress() << ", Floors: " << house.getFloors() << ", Number of flats: " << house.getSize() << endl;


	House newHouse;
	newHouse = house;
	newHouse.setAddress("456 Elm St");
	cout << "Modified house address: " << newHouse.getAddress() << endl;

	cout << "Success" << endl;

	return 0;
}