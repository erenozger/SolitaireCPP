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
	cout << commandLine << endl;
	cout<<endl;
	cout<<"****************************************"<<endl;
	cout<<endl;
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

		}else if(secondCommand == "waste"){

		}
	}else if(mainCommand == "open"){


	}
	else
		cout<<"another command"<<endl;

}
