#include <iostream>
#include <string>
#include <vector>

using namespace std;
class Fish {
public:
	string type;
	int size;
	int stepsToDie;
	int stepsToReproduce;

	Fish(string type,int size,int stepsToDie,int stepsToReproduce){}

	void eatAlgae() {
		cout << type << "Рыбка ест водоросли" << endl;
	}
	
	void reproduce() {
		cout << type << "Рыбка размножается" << endl;
	}

	void die() {
		cout << type << "Рыбка умерла" << endl;
	}

};

class Algae {
public:
	int quality;
	Algae(int quality){}
	void grow() {
		cout << "Водоросли растут" << endl;
	}
	void decrease() {
		cout << "Водоросли уменьшаются" << endl;
	}
};
class Aquarium {
public:
    vector<Fish> fishes;
    Algae algae;

    Aquarium(int algaeQuantity) : algae(algaeQuantity) {}

    void addFish(Fish fish) {
        fishes.push_back(fish);
    }

    void simulate(int steps) {
        for (int i = 0; i < steps; i++) {
            for (Fish& fish : fishes) {
                if (fish.stepsToDie == 0) {
                    fish.die();
                }
                else {
                    fish.stepsToDie--;
                }

                if (fish.stepsToReproduce == 0) {
                    fish.reproduce();
                    fish.stepsToReproduce = fish.size;
                }
                else {
                    fish.stepsToReproduce--;
                }

                if (fish.type == "Predator") {
                    for (Fish& otherFish : fishes) {
                        if (otherFish.type == "Prey") {
                            fish.eatAlgae();
                        }
                    }
                }
                else if (fish.type == "Prey") {
                    algae.decrease();
                }
            }

            algae.grow();
        }
    }

    void displayState() {
        cout << "Текущее состояние аквариума:" << endl;
        cout << "Количество рыбок: " << fishes.size() << endl;
        for (Fish& fish : fishes) {
            cout << "Тип рыбки: " << fish.type << ", Размер: " << fish.size << endl;
        }

    }
};

int main() {
    Fish predator("Хищник", 3, 2, 4);
    Fish prey("Добыча", 2, 3, 5);
    Algae algae(10);

    Aquarium aquarium(10);
    aquarium.addFish(predator);
    aquarium.addFish(prey);

    aquarium.displayState();
    aquarium.simulate(5);
    aquarium.displayState();

    return 0;
}