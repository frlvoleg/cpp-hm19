#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;

class reservoir
{
	char* type;
	char* name;
	double width;
	double length;
	double depth;

public:

	reservoir() : type(nullptr), name(nullptr), width(0), length(0), depth(0) {}

	reservoir(const char* r_type, double r_width = 0, double r_length=0, double r_depth=0) : type(nullptr), name(nullptr), width(r_width), length(r_length), depth(r_depth)
	{
		set_type(r_type);
	}

	reservoir(const char* r_name) : type(nullptr), name(nullptr), width(0), length(0), depth(0)
	{
		set_name(r_name);
	}

	reservoir(double r_width, double r_length, double r_depth) : type(nullptr), name(nullptr), width(r_width), length(r_length), depth(r_depth) {}


	reservoir(const char* r_type, const char* r_name, double r_width, double r_length, double r_depth) : type{ nullptr }, name { nullptr }, width{ r_width }, length{ r_length }, depth(r_depth)
	{
		const char* valid_types[] = { "sea","river", "lake", "pool", nullptr };
		bool valid = false;

		for(int i=0; valid_types[i] != nullptr;i++)
		{
			if(_stricmp(r_type, valid_types[i]) == 0)
			{
				valid = true;
				type = new char[strlen(r_type) + 1];
				strcpy_s(type, strlen(r_type) + 1, r_type);
				break;

			}
		}
		if (!valid) {
			cout << "Invalid type of reservoir" << endl;
			type = nullptr;
		}
		if(r_name)
		{
			name = new char[strlen(r_name) + 1];
			strcpy_s(name, strlen(r_name) + 1, r_name);
		}
	}

	reservoir(const reservoir& object):type{ object.type ? new char[strlen(object.type)+1]:nullptr}, name{object.name ? new char[strlen(object.name)+1]:nullptr},width{object.width},length{object.length}, depth{object.depth}
	{
		if(type)
		{
			strcpy_s(type, strlen(object.type) + 1, object.type);
		}
		if(name)
		{
			strcpy_s(name, strlen(object.name) + 1, object.name);
		}
	}

	reservoir& operator=(const reservoir& obj)
	{
		if (this==&obj)
		{
			return *this;
		}
		if(this->type !=nullptr)
		{
			delete[]type;
		}
		if (this->name != nullptr)
		{
			delete[]name;
		}
		width = obj.width;
		length = obj.length;
		depth = obj.depth;

		type = new char[strlen(obj.type) + 1];
		name = new char[strlen(obj.name) + 1];
		strcpy_s(type, strlen(obj.type) + 1, obj.type);
		strcpy_s(name, strlen(obj.name) + 1, obj.name);

		return *this;
	}

	~reservoir()
	{
		delete[] type;
		delete[] name;
	}

	double volume() const
	{
		double vol = this->depth * this->length * this->width;
		return vol;
	}

	double square() const
	{
		double sqr = this->length * this->width;
		return sqr;
	}

	void same_type(const reservoir& obj) 
	{
		if (_stricmp(this->type, obj.type) == 0) {
			cout << "The same type\n";
		}
		else
		{
			cout << "Different types\n";

		}
		
	}



	const char* get_type() const
	{
		const char* valid_types[] = { "sea", "river", "lake", "pool", nullptr };

		while (true)
		{
			if (type == nullptr) {
				cout << "Type is not set. Please enter a valid type: ";
				char buff[100];
				gets_s(buff);
				const_cast<reservoir*>(this)->set_type(buff);
				continue;
			}

			for (int i = 0; valid_types[i] != nullptr; i++)
			{
				if (_stricmp(type, valid_types[i]) == 0)
				{
					return type;
				}
			}

			cout << "Invalid type. Please enter a valid type: ";
			char buff[100];
			gets_s(buff);
			const_cast<reservoir*>(this)->set_type(buff);
		}
	}
	const char* get_name() const { return name; }
	double get_width() const { return width; };
	double get_length() const { return length; };
	double get_depth() const { return depth; };

	void set_type(const char* s_type)
	{
		delete[] type;
		type = nullptr;

		while (true)
		{
			if (s_type)
			{
				const char* valid_types[] = { "sea", "river", "lake", "pool", nullptr };

				for (int i = 0; valid_types[i] != nullptr; i++)
				{
					if (_stricmp(s_type, valid_types[i]) == 0)
					{
						type = new char[strlen(s_type) + 1];
						strcpy_s(type, strlen(s_type) + 1, s_type);
						return;
					}
				}
			}
			cout << "Invalid type of reservoir. Please enter a valid type: ";
			char buff[100];
			gets_s(buff);
			s_type = buff;
		}
	}

	void set_name(const char* s_name)
	{
		delete[] name;
		name = s_name ? new char[strlen(s_name) + 1] : nullptr;
		if(name)
		{
			strcpy_s(name, strlen(s_name) + 1, s_name);
		}
	}

	void set_width(const double s_width)
	{
		width = s_width;
	}

	void set_length(const double s_length)
	{
		length = s_length;
	}

	void set_depth(const double s_depth)
	{
		depth = s_depth;
	}

};

reservoir* memory(int size)
{
	return new reservoir[size];
}

void init(reservoir* array, int size)
{
	char buff[100];

	for(int i=0; i<size;i++)
	{
		cout << "Enter reservoir #" << (i + 1) << " details:\n";

		cout << "Type: ";
		gets_s(buff);
		array[i].set_type(buff);

		cout << "Name: ";
		gets_s(buff);
		array[i].set_name(buff);

		double s_width, s_length, s_depth;

		cout << "Width: ";
		cin >> s_width;
		array[i].set_width(s_width);
		cin.ignore();

		cout << "Length: ";
		cin >> s_length;
		array[i].set_length(s_length);
		cin.ignore();

		cout << "Depth: ";
		cin >> s_depth;
		array[i].set_depth(s_depth);
		cin.ignore();

		cout << endl;
	}
}

void del(reservoir* array){
	delete[]array;
}

void check_type(reservoir* array, int size)
{

	char buff1[100];
	char buff2[100];
	int index_first = -1;
	int index_second = -1;

	while (true) {
		cout << "Enter the name of the first reservoir to compare type: ";
		gets_s(buff1);

		cout << "Enter the name of the second reservoir to compare type: ";
		gets_s(buff2);

		for (int i = 0; i < size; i++)
		{
			if (array[i].get_name() && _stricmp(array[i].get_name(), buff1) == 0)
			{
				index_first = i;
			}

			if (array[i].get_name() && _stricmp(array[i].get_name(), buff2) == 0)
			{
				index_second = i;
			}
		}

		if (index_first == -1)
		{
			cout << "Invalid first reservoir name entered. Please enter a valid name." << endl;
		}

		if (index_second == -1)
		{
			cout << "Invalid second reservoir name entered. Please enter a valid name." << endl;
		}

		if (index_first != -1 && index_second != -1)
		{
			array[index_first].same_type(array[index_second]);
			break;
		}


		index_first = -1;
		index_second = -1;
	}

}

int main()
{
	
	int size;
	cout << "How many reservoirs would you like to do?\n";
	cin >> size;
	cin.ignore();
	reservoir* reservoirs = memory(size);

	init(reservoirs, size);

	cout << "Reservoirs:\n";
	for (int i = 0; i < size; i++)
	{
		cout << "Reservoir #" << (i + 1) << ":\n";
		cout << "Type: " << reservoirs[i].get_type() << "\n";
		cout << "Name: " << reservoirs[i].get_name() << "\n";
		cout << "Width: " << reservoirs[i].get_width() << "\n";
		cout << "Length: " << reservoirs[i].get_length() << "\n";
		cout << "Depth: " << reservoirs[i].get_depth() << "\n";
		cout << endl;
	}
	if (size > 1) {
		check_type(reservoirs, size);
	}
	
	

	del(reservoirs);

	return 0;
}