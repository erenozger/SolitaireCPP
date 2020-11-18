#ifndef FUNCTIONS_H_
#define FUNCTIONS_H_
#include <iostream>
#include "Card.h"



using namespace std;
class Functions{

public:
	void moveFoundation(string columnIndex,card tableauArea[][7],card foundationHearts[],
			card foundationDiamonds[], card foundationClubs[],
			card foundationSpades[],card[],std::ostream& output);
	int findLastCard(int columnIndex,card tableauArea[][7]);
	void openCardPile(string columnIndex,card tableauArea[][7],std::ostream& output);
	void addFoundation(card[],card,card [],string,card [][7],int , int ,std::ostream& output);
	void addFoundation2(card[],card,card [],string,card [][3],int,int,std::ostream& output,StockValues stockValuesList[]);
	void moveAnotherPile(string currentPosition,string cardSize,string targetPosition,card tableauArea[][7],std::ostream& output);
	void openFromStock(StockValues[],card[],card [][3],std::ostream& output );
	void sortingStockArray(card []);
	void moveWasteToPile(string,StockValues[],card stockMatrix[][3],card stockArray[],card tableauArea[][7],std::ostream& output);
	void deleteFromArray(card array[], string);
	bool suitExpression(char,char);
	void moveWasteToFoundation(StockValues [], card [][3], card [],card [], card [],
			card [], card [],std::ostream& output);
	void setNewMaxValue(card [][3],StockValues []);
	void calculateStockMatrix(card stockArray[],card stockMatrix[][3]);
	void createWasteWhenEmpty(StockValues stockvalues[],card stockMatrix[][3],std::ostream &output);
};


#endif /* MOVE_H_ */
