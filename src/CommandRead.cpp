#include "CommandRead.h"
#include <stdio.h>
#include <string.h>
#include <sstream>

using namespace std;

void CommandRead::calculateWholeCommand(string commandLine,card tableauArea[][7], card stockMatrix[][3],
		card stockArray[], card foundationHearts[], card foundationDiamonds[],
		card foundationClubs[], card foundationSpades[]) {
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
			functions.moveFoundation(fifthCommand,tableauArea,foundationHearts,foundationDiamonds,foundationClubs,foundationSpades);
		}else if(secondCommand == "pile"){
			functions.moveAnotherPile(thirdCommand,fourthCommand,fifthCommand,tableauArea);
		}else if(secondCommand == "waste"){

		}
	}else if(mainCommand == "open"){
		if(secondCommand == "from"){

		}else{
			functions.openCardPile(secondCommand, tableauArea);
		}

	}
	else
		cout<<"another command"<<endl;

	cout << endl;
	cout<<"****************************************"<<endl;
}
