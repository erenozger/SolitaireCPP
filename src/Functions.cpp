#include "Functions.h"

void Functions::moveFoundation(string columnIndex, card tableauArea[][7],
		card foundationHearts[], card foundationDiamonds[],
		card foundationClubs[], card foundationSpades[]) {
	Functions functions;

	int currentColumnIndex = std::stoi(columnIndex);
	int currentIndex = functions.findLastCard(currentColumnIndex, tableauArea);

	tableauArea[currentIndex][currentColumnIndex].cardname ="0";



}
int Functions::findLastCard(int columnIndex, card tableauArea[][7]) {
	int currentIndex;
	for (int i = 0; i < 19; i++) {
		if (tableauArea[i][columnIndex].cardname == "0") {
			if (i == 0) {
				cout << "Invaled Move" << endl;
				break;
			} else {
				currentIndex = (i - 1);
				break;
			}
		}
		else
			continue;
	}
	return currentIndex;
}

