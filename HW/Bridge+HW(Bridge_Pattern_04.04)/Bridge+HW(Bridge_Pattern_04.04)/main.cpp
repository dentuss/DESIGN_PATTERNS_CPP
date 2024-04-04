#include <iostream>
#include <string>

class Print abstract {

public:

	virtual void print() const abstract;
};

class Device abstract : public Print {

protected:

	size_t volume;
	double price;
	std::string producer;
	std::string type;

public:

	Device();
};

class HDD : public Device {

public:

	HDD(size_t inpVol, double inpPrice, std::string inpProd, std::string inpType) {

		this->price = inpPrice;
		this->producer = inpProd;
		this->type = inpType;
		this->volume = inpVol;
	}

	void print() const {

		std::cout << "Device type: " << this->type << std::endl;
		std::cout << "Device volume: " << this->volume << std::endl;
		std::cout << "Device Producer: " << this->producer << std::endl;
		std::cout << "Device price: " << this->price << std::endl;
	}
};

class Abstact : public Print {

	Device* device;

public:

	Abstact() {

		device = nullptr;
	}

	void print() const {

		device->print();
	}

	void setDevice(Device* inpDev) {

		this->device = inpDev;
	}

	~Abstact() {

		delete device;
	}
};

int main(int argc, char* argv[]) {

	Abstact interface;

	Device* device = new HDD(100, 10.1, "Sony", "Hard Drive");
	interface.setDevice(device);

	interface.print();
	delete device;
}