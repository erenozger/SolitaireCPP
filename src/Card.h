#ifndef CARD_H_
#define CARD_H_
#include <iostream>
using namespace std;
class card {
public:
	string cardname;
	char suitChar;
	int value;
	bool show;
};

class StockValues{
public:
	int currentStockIndex;
	int maxIndex;
};


#endif /* CARD_H_ */
