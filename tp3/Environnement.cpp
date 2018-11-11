#include "Environnement.h"

Environnement::Environnement() {
	level = 3;
	forest = new vector<>();
	agentPosition.x = 0;
	agentPosition.y = 0;
	generateForest();
}

void Environnement::updateForestLevel() {
	level++;
	forest.clear();
	generateForest();
};

void Environnement::generateForest() {
	for (int i; i<level; i++) {
		vector<Cell>* line = new vector<Cell>;
		for (int j; j < level; j++) {
			Cell* cell = new Cell(Vide)
			line->push_back(cell);
		}
		forest.push_back(*ligne);
	}
	

}