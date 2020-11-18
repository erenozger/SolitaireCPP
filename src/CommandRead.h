#ifndef COMMANDREAD_H_
#define COMMANDREAD_H_
#include <iostream>
#include "Card.h"
#include "Functions.h"

using namespace std;
class CommandRead {
public:
	string wholeCommand;
	string mainCommand;
	string secondCommand;
	string thirdCommand;
	string fourthCommand;
	string fifthCommand;

	void calculateWholeCommand(string, card tableauArea[][7],
			card stockMatrix[][3], card stockArray[], card foundationHearts[],
			card foundationDiamonds[], card foundationClubs[],
			card foundationSpades[],StockValues stockValuesList[] ,std::ostream& output);

};

#endif /* COMMANDREAD_H_ */
