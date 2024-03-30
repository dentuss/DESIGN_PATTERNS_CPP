#include <iostream>

class Herbivor abstract {

protected:

	float weight;
	bool alive;

public:

	virtual void eat() abstract;
	virtual void sound() abstract;
	float getWeight() {

		return this->weight;
	}
};

class Carnivor abstract {

protected:

	float power;

public:

	virtual void eat(Herbivor* inputHerb) abstract;
};

class Bison : public Herbivor {

public:

	Bison(float inputWeight) {

		this->weight = inputWeight;
		this->alive = true;
	}

	void eat() override {

		std::cout << "Bison eats..." << std::endl;
		this->weight += 1.5;
	}
	void sound() override {

		std::cout << "Bison goes: 'Moo'" << std::endl;
	}
};

class Wolf : public Carnivor {

public:

	void eat(Herbivor* inputHerb) override {

		std::cout << "Wolf eats..." << std::endl;
		this->power += inputHerb->getWeight() / 3;
	}
};

class Continent abstract {

protected:

	Herbivor* herbivor;
	Carnivor* carnivor;

public:

	void getAnimals() {

		herbivor->eat();
		carnivor->eat(herbivor);
	}
};

class Europe : public Continent {


};