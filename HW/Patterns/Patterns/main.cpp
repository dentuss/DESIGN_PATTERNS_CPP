#include "framework.h"

struct RGB
{
	unsigned short rgb[3];
};

class Figure abstract {

protected:

	int grid[4][4];
	RGB rgbValue;

public:

	Figure() {

		for (int i = 0; i < 4; i++) {

			for (int j = 0; j < 4; j++) {

				this->grid[i][j] = 0;
			}
		}

		for (int i = 0; i < 3; i++) {

			this->rgbValue.rgb[i] = 0;
		}
	}
};

class FigureL : public Figure {

public:

	FigureL() {

		for (int i = 0; i < 3; i++) {

			this->grid[i][0] = 1;
		}
		for (int j = 0; j < 3; j++) {

			this->grid[3][j] = 1;
		}
		for (int i = 0; i < 3; i++) {

			this->rgbValue.rgb[i] = 50 * i;
		}

		for (int i = 0; i < 4; i++) {


			for (int j = 0; j < 4; j++) {

				if (this->grid[i][j] == 1) {

					std::cout << grid[i][j] << " ";
				}
			}

			std::cout << std::endl;
		}

		std::cout << "RGB value: ";
		for (int i = 0; i < 3; i++) {

			std::cout << this->rgbValue.rgb[i] << ", ";
		}
		std::cout << std::endl;
	}
};

class Developer abstract {

public:

	virtual Figure* create() = 0;
};

class DevFigureL : public Developer {

public:

	Figure* create() override {

		return new FigureL;
	}
};

Figure* returnFPtr(Developer* ptrDev) {

	return ptrDev->create();
}

int main(int argc, char* argv[]) {

	Developer* ptrDev = new DevFigureL();
	Figure* ptrFigure = returnFPtr(ptrDev);
	delete ptrDev;
	delete ptrFigure;
}