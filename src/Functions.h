#ifndef FUNCTIONS_H_
#define FUNCTIONS_H_
#include <iostream>
#include "Card.h"



using namespace std;
class Functions{

public:
	void moveFoundation(string columnIndex,card tableauArea[][7],card foundationHearts[],
			card foundationDiamonds[], card foundationClubs[],
			card foundationSpades[]);
	int findLastCard(int columnIndex,card tableauArea[][7]);
	void openCardPile(string columnIndex,card tableauArea[][7]);
	void addFoundation(card[],card);
	void moveAnotherPile(string currentPosition,string cardSize,string targetPosition,card tableauArea[][7]);
};


#endif /* MOVE_H_ */
