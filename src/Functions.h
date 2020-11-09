#ifndef FUNCTIONS_H_
#define FUNCTIONS_H_
#include <iostream>
#include "Card.h"



using namespace std;
class Functions{

public:
	void moveFoundation(string columnIndex,card tableauArea[][7],card foundationHearts[],
			card foundationDiamonds[], card foundationClubs[],
			card foundationSpades[],card[]);
	int findLastCard(int columnIndex,card tableauArea[][7]);
	void openCardPile(string columnIndex,card tableauArea[][7]);
	void addFoundation(card[],card,card [],string,card [][7],int , int );
	void addFoundation2(card[],card,card [],string);
	void moveAnotherPile(string currentPosition,string cardSize,string targetPosition,card tableauArea[][7]);
	void openFromStock(StockValues[],card[],card [][3] );
	void sortingStockArray(card []);
	void moveWasteToPile(string,StockValues[],card stockMatrix[][3],card stockArray[],card tableauArea[][7]);
	void deleteFromArray(card array[], string);
	bool suitExpression(char,char);
	void moveWasteToFoundation(StockValues [], card [][3], card [],card [], card [],
			card [], card []);
	void setNewMaxValue(card [][3],StockValues []);
	void calculateStockMatrix(card stockArray[],card stockMatrix[][3]);
};


#endif /* MOVE_H_ */
