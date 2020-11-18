#include "CommandRead.h"
#include <stdio.h>
#include <string.h>
#include <sstream>
#include <iostream>

using namespace std;

void CommandRead::calculateWholeCommand(string commandLine,card tableauArea[][7], card stockMatrix[][3],
		card stockArray[], card foundationHearts[], card foundationDiamonds[],
		card foundationClubs[], card foundationSpades[],StockValues stockValuesList[],std::ostream& output) {
	Functions functions;
	string commandArray[5];
	output<<endl;
	output << commandLine << endl;


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
				functions.moveFoundation(fifthCommand,tableauArea,foundationHearts,foundationDiamonds,foundationClubs,foundationSpades,stockArray,output);
			else if(fourthCommand=="waste"){
				functions.moveWasteToFoundation(stockValuesList, stockMatrix, stockArray,foundationHearts,foundationDiamonds,foundationClubs,foundationSpades,output);
			}


		}else if(secondCommand == "pile"){
			functions.moveAnotherPile(thirdCommand,fourthCommand,fifthCommand,tableauArea,output);
		}else if(secondCommand == "waste"){
			functions.moveWasteToPile(thirdCommand,stockValuesList,stockMatrix,stockArray,tableauArea,output);
		}
	}else if(mainCommand == "open"){
		if(secondCommand == "from"){
			functions.openFromStock(stockValuesList,stockArray,stockMatrix,output);

		}else{
			functions.openCardPile(secondCommand, tableauArea,output);
		}

	}else if(mainCommand == "exit"){
		output<<endl;
		output<<"****************************************"<<endl<<endl;
		output<<"Game Over!"<<endl;
		exit(0);
	}
	else
		output<<"another command"<<endl;

	output << endl;
	output<<"****************************************"<<endl;
}
