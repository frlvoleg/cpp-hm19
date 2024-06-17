//class Human {
//	char* name;
//	int age;
//
//public:
//
//	Human(const char* hName, int hAge) : name{ hName ? new char[strlen(hName) + 1] : nullptr }, age{ hAge } {
//		if (name) {
//			strcpy_s(name, strlen(hName) + 1, hName);
//		}
//	}
//
//	Human() : Human{ nullptr, 0 } {}
//
//
//
//	Human(const char* hName) : Human{ hName,0 } {}
//
//
//	Human(int hAge) : Human{ nullptr, hAge } {}
//
//
//	Human(const Human& hum) : name{ hum.name ? new char[strlen(hum.name) + 1] : nullptr }, age{ hum.age } {
//		if (name) {
//			strcpy_s(name, strlen(hum.name) + 1, hum.name);
//		}
//	}
//
//	Human& operator=(const Human& hum) {
//		if (this == &hum) {
//			return *this;
//		}
//		if (this->name != nullptr) {
//			delete[] name;
//		}
//		name = new char[strlen(hum.name) + 1];
//		age = hum.age;
//		strcpy_s(name, strlen(hum.name) + 1, hum.name);
//		return *this;
//	}
//
//	~Human() {
//		delete[] name;
//	}
//
//	const char* getName() const { return name; }
//	int getAge() const { return age; }
//
//	void setName(const char* hName) {
//		delete[] name;
//		name = hName ? new char[strlen(hName) + 1] : nullptr;
//		if (name) {
//			strcpy_s(name, strlen(hName) + 1, hName);
//		}
//	}
//	void setAge(int hAge) {
//		age = hAge;
//	}
//
//};
//
//class Flat {
//	Human* residents;
//	int size;
//	int floor;
//	int number;
//
//public:
//
//	Flat(const Human* fResidents, int fSize, int fFloor, int fNumber) : residents{ fSize ? new Human[fSize] : nullptr }, size{ fSize }, floor{ fFloor }, number{ fNumber } {
//		if (fResidents) {
//			for (int i = 0; i < fSize; i++) {
//				residents[i] = fResidents[i];
//			}
//		}
//	}
//
//	Flat() : Flat{ nullptr, 0, 0,0 } {}
//
//	Flat(const Human* fResidents, int fSize) : Flat{ fResidents, fSize, 0, 0 } {}
//
//	Flat(int fFloor, int fNumber) : Flat{ nullptr, 0, fFloor, fNumber } {}
//
//	//Flat(const Flat& flat) : residents{ flat.size ? new Human[flat.size] : nullptr }, size{ flat.size }, floor{ flat.floor }, number{ flat.number } {
//	//	if (residents) {
//	//		for (int i = 0; i < size; i++) {
//	//			residents[i] = flat.residents[i];
//	//		}
//	//	}
//	//}
//
//	Flat& operator=(const Flat& flat) {
//
//		if (this == &flat) {
//			return *this;
//		}
//
//		if (this->residents != nullptr) {
//			delete[]residents;
//		}
//		size = flat.size;
//		floor = flat.floor;
//		number = flat.number;
//		residents = new Human[flat.size];
//		for (int i = 0; i < flat.size; i++) {
//			residents[i] = flat.residents[i];
//		}
//		return *this;
//	}
//
//	~Flat() {
//		delete[] residents;
//	}
//
//	const Human* getResident(int index) const { return &residents[index]; }
//
//	int getSize() const { return size; }
//
//	int getFloor() const { return floor; }
//
//	int getNumber() const { return number; }
//
//	void setResident(int index, const Human& fResident) {
//		residents[index].setName(fResident.getName());
//		residents[index].setAge(fResident.getAge());
//	}
//
//	void setSize(int fSize) {
//		size = fSize;
//	}
//
//	void setFloor(int fFloor) {
//		floor = fFloor;
//	}
//
//	void setNumber(int fNumber) {
//		number = fNumber;
//	}
//
//};
//
//House::House() : apartments(nullptr), address(nullptr), floors(0), sizeAp(0) {}
//
//House::House(int hFlats) : House(nullptr, nullptr, hFlats, 0) {}
//
//House::House(const char* hAddress) : House{nullptr, hAddress ,0,0}{}
//
//House::House(const Flat* hFlats) : House{hFlats,nullptr,0, hFlats ? hFlats->getSize() : 0 }{}
//
//House::House(const Flat* hFlats, const char* hAddress, int hFloors, int hSize): sizeAp{ hFlats ? hFlats->getSize() : 0 }, apartments{ hFlats ? new Flat[hSize] : nullptr }, address{ hAddress ? new char[strlen(hAddress) + 1] : nullptr }, floors{ hFloors }{}
//
//
//
//House::~House()
//{
//	delete[]apartments;
//	delete[]address;
//}
//
//House::House(const House& home) : sizeAp{ home.sizeAp ? home.sizeAp : 0 }, apartments{ sizeAp ? new Flat[sizeAp] : nullptr }, address{ home.address ? new char[strlen(home.address) + 1] : nullptr }, floors{ home.floors } {
//	if (address) {
//		strcpy_s(address, strlen(home.address) + 1, home.address);
//	}
//}
//
//House& House::operator=(House home)
//{
//	if (this == &home) {
//		return *this;
//	}
//	if (this->apartments != nullptr) {
//		delete[]apartments;
//	}
//	delete[] address;
//	address = home.address ? new char[strlen(home.address) + 1] : nullptr;
//	if (address) {
//		strcpy_s(address, strlen(home.address) + 1, home.address);
//	}
//	floors = home.floors;
//	sizeAp = home.sizeAp;
//	apartments = new Flat[home.sizeAp];
//	for (int i = 0; i < home.sizeAp; i++) {
//		apartments[i] = home.apartments[i];
//	}
//	return *this;
//}
//
//const Flat* House::getFlat(int index) const
//{
//	return &apartments[index];
//}
//
//const char* House::getAddress() const
//{
//	return address;
//}
//
//int House::getFloors() const
//{
//	return floors;
//}
//
//int House::getSize() const
//{
//	return sizeAp;
//}
//
//void House::setFlat(int index, const Flat& hFlat)
//{
//	apartments[index].setFloor(hFlat.getFloor());
//	apartments[index].setNumber(hFlat.getNumber());
//	Human residentCopy = *hFlat.getResident(index);
//	apartments[index].setResident(index, residentCopy);
//	apartments[index].setSize(hFlat.getSize());
//}
//
//void House::setAddress(const char* hAddress)
//{
//	delete[] address;
//	address = hAddress ? new char[strlen(hAddress) + 1] : nullptr;
//	if (address) {
//		strcpy_s(address, strlen(hAddress) + 1, hAddress);
//	}
//}
//
//void House::setFloors(int hFloors)
//{
//	floors = hFloors;
//}
//
//void House::setSize(int hSize)
//{
//	sizeAp = hSize;
//}
//
//
