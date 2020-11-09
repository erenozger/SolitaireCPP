#include "CommandRead.h"
#include <stdio.h>
#include <string.h>
#include <sstream>

using namespace std;

void CommandRead::calculateWholeCommand(string commandLine,card tableauArea[][7], card stockMatrix[][3],
		card stockArray[], card foundationHearts[], card foundationDiamonds[],
		card foundationClubs[], card foundationSpades[],StockValues stockValuesList[]) {
	Functions functions;
	string commandArray[5];
	cout<<endl;
	cout << commandLine << endl;


	wholeCommand = commandLine;
	{
		int i = 0;
		stringstream ssin(wholeCommand);
		while (ssin.good() && i < 5) {
			ssin >> commandArray[i];
			i++;
		}
	}
	mainCommand = commandArray[0];
	secondCommand = commandArray[1];
	thirdCommand = commandArray[2];
	fourthCommand = commandArray[3];
	fifthCommand = commandArray[4];

	if(mainCommand == "move"){
		if(secondCommand == "to"){
			if(fourthCommand=="pile")
				functions.moveFoundation(fifthCommand,tableauArea,foundationHearts,foundationDiamonds,foundationClubs,foundationSpades);
			else if(fourthCommand=="waste"){
				cout<<endl;
				cout<<"allah allah"<<endl;
			}


		}else if(secondCommand == "pile"){
			functions.moveAnotherPile(thirdCommand,fourthCommand,fifthCommand,tableauArea);
		}else if(secondCommand == "waste"){
			functions.moveWasteToPile(thirdCommand,stockValuesList,stockMatrix,stockArray,tableauArea);
		}
	}else if(mainCommand == "open"){
		if(secondCommand == "from"){
			functions.openFromStock(stockValuesList);

		}else{
			functions.openCardPile(secondCommand, tableauArea);
		}

	}
	else
		cout<<"another command"<<endl;

	cout << endl;
	cout<<"****************************************"<<endl;
}
