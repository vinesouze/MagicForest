#include "Environnement.h"

int RandomNumber(int level) {
	int size = level*level;
	int random = 0;
	srand(time(NULL));
	do {
		random = rand() % size;
	} while (random==0);
	return random;
};

void Environnement::addState(int i, int j, int level, State state) {
	State vide = Vide;

	// première ligne
	if (i==0) {
		if (forest[i][j-1].getState() == vide) {
			forest[i][j-1].setState(state);
		}
		if (forest[i+1][j].getState() == vide) {
			forest[i+1][j].setState(state);
		}
		if (j!=level-1) {
			if (forest[i][j+1].getState() == vide) {
				forest[i][j+1].setState(state);
			}
		}
		return;
	}
	// dernière ligne
	if (i==level-1) {
		if (forest[i-1][j].getState() == vide) {
			forest[i-1][j].setState(state);
		}
		if (j!=level-1) {
			if (forest[i][j+1].getState() == vide) {
				forest[i][j+1].setState(state);
			}
		}
		if (j!=0) {
			if (forest[i][j-1].getState() == vide) {
				forest[i][j-1].setState(state);
			}
		}
		return;
	}

	// ligne du milieu
	if (j==0) {
		if (forest[i-1][j].getState() == vide) {
			forest[i-1][j].setState(state);
		}
		if (forest[i][j+1].getState() == vide) {
			forest[i][j+1].setState(state);
		}
		if (forest[i+1][j].getState() == vide) {
			forest[i+1][j].setState(state);
		}
		return;
	}

	if (j==level-1) {
		if (forest[i-1][j].getState() == vide) {
			forest[i-1][j].setState(state);
		}
		if (forest[i][j-1].getState() == vide) {
			forest[i][j-1].setState(state);
		}
		if (forest[i+1][j].getState() == vide) {
			forest[i+1][j].setState(state);
		}
		return;
	}

	if (forest[i-1][j].getState() == vide) {
		forest[i-1][j].setState(state);
	}
	if (forest[i][j-1].getState() == vide) {
		forest[i][j-1].setState(state);
	}
	if (forest[i+1][j].getState() == vide) {
		forest[i+1][j].setState(state);
	}
	if (forest[i+1][j+1].getState() == vide) {
		forest[i+1][j+1].setState(state);
	}
	return;
};

Environnement::Environnement() {
	level = 3;
	//vector<vector<Cell> >* forest = new vector<vector<Cell> >;
	agentPosition.x = 0;
	agentPosition.y = 0;
	cout << "creation d'une foret" << endl;
	this->generateForest();
};

void Environnement::updateForestLevel() {
	level++;
	forest.clear();
	generateForest();
};

Cell& Environnement::getCell(int i, int j) {
    return forest[i][j];
}

void Environnement::generateForest() {
	// ------ initialise la foret
	for (int i = 0; i<level; i++) {
		vector<Cell>* line = new vector<Cell>;
		for (int j = 0; j < level; j++) {
			Cell* cell = new Cell();
			cell->setState(State::Vide);
			cell->setInconnu(true);
			line->push_back(*cell);
		}
		forest.push_back(*line);
	}

	// ------ Position aléatoire du portail
	int random = RandomNumber(level);
	int i = random / level;
	int j = random % level;
	cout << "i est : " << i << " et j est : " << j << endl;
	getCell(i,j).setState(State::Portail);

	// ---- Position aléatoire des monstres et crevasses
	int nbMonster = level-2;
	int nbHole = level / 2;
	cout << "nb de hole " << nbHole << endl;
    cout << "nb de monster " << nbHole << endl;

	int countMonster = 0;
	int countHole = 0;
	State vide = Vide;
	State monstre = Monster;
	State crevasse = Hole;
	State vent = Vent;
	State crotte = Crotte;

	while ((countMonster != nbMonster) || (countHole != nbHole)) {
		do {
			random = RandomNumber(level);
		} while (forest[random / level][random % level].getState() != vide);
		if (countMonster < nbMonster) {
			forest[random / level][random % level].setState(Monster);
			countMonster++;
		}
		else {
			forest[random / level][random % level].setState(Hole);
			countHole++;
		}
	}

	// ---- Position des vents et crottes
	for (int i = 0; i < level; i++) {
		for (int j = 0; j < level; j++) {
			if (forest[i][j].getState() == monstre) {
				this->addState(i,j,level,crotte);
			}
			else if (forest[i][j].getState() == crevasse) {
				this->addState(i,j,level,vent);
			}
		}
	}
}

void Environnement::Display() {
	State state;
	for (int i = 0; i < level; i++) {
		for (int j = 0; j < level; j++) {
			state = forest[i][j].getState();
			switch(state) {
				case Vent:
					cout << "V ";
					break;
				case Crotte:
					cout << "C ";
					break;
				case Monster:
					cout << "M ";
					break;
				case Hole:
					cout << "T ";
					break;
				case Portail:
					cout << "P ";
					break;
				default:
					cout << "  ";
			}
		}
		cout << endl;
	}
}
