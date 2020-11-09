#include "Functions.h"

void Functions::moveFoundation(string columnIndex, card tableauArea[][7],
		card foundationHearts[], card foundationDiamonds[],
		card foundationClubs[], card foundationSpades[]) {
	Functions functions;

	int currentColumnIndex = std::stoi(columnIndex);
	int currentIndex = functions.findLastCard(currentColumnIndex, tableauArea);
	card currentcard = tableauArea[currentIndex][currentColumnIndex];
	tableauArea[currentIndex][currentColumnIndex].cardname = "0";
	if (currentcard.suitChar == 'H') {
		functions.addFoundation(foundationHearts, currentcard);
	} else if (currentcard.suitChar == 'D') {
		functions.addFoundation(foundationDiamonds, currentcard);
	} else if (currentcard.suitChar == 'C') {
		functions.addFoundation(foundationClubs, currentcard);
	} else if (currentcard.suitChar == 'S') {
		functions.addFoundation(foundationSpades, currentcard);
	}

}
int Functions::findLastCard(int columnIndex, card tableauArea[][7]) {
	int currentIndex;
	for (int i = 0; i < 19; i++) {
		if (tableauArea[i][columnIndex].cardname == "0") {
			if (i == 0) {
				currentIndex = -1;
				break;
			} else {
				currentIndex = (i - 1);
				break;
			}
		} else
			continue;
	}
	return currentIndex;
}
void Functions::openCardPile(string columnIndex, card tableauArea[][7]) {
	Functions functions;
	int currentColumnIndex = std::stoi(columnIndex);
	int currentIndex = functions.findLastCard(currentColumnIndex, tableauArea);
	tableauArea[currentIndex][currentColumnIndex].show = true;
}
void Functions::addFoundation(card array[], card currentCard) {
	if (currentCard.value == 1) {
		array[0] = currentCard;

	} else {
		int controlInt = (currentCard.value - 2);
		if (array[controlInt].cardname != "0") {
			array[controlInt + 1] = currentCard;
		} else
			cout << "Invaled Move" << endl;
	}
}
void Functions::moveAnotherPile(string currentPosition, string cardSize,
		string targetPosition, card tableauArea[][7]) {
	int currentPositionC = std::stoi(currentPosition);
	int cardSize1 = std::stoi(cardSize);
	int targetPositionC = std::stoi(targetPosition);

	Functions functions;

	int lastCardCurrentIndex = functions.findLastCard(currentPositionC,
			tableauArea);
	int firstCardCurrentIndex = lastCardCurrentIndex - cardSize1;
	int lastcardTargetIndex = functions.findLastCard(targetPositionC,
			tableauArea);
	card firstCardCurrent = tableauArea[firstCardCurrentIndex][currentPositionC];
	card destCard;
	if (lastcardTargetIndex == -1) {
		destCard.cardname = "-1";
	} else
		destCard = tableauArea[lastcardTargetIndex][targetPositionC];

	if (cardSize1 > lastCardCurrentIndex)
		cout << "Invalid Move";
	else {
		int firstcardInRow = lastCardCurrentIndex - cardSize1;
		int lastcardTargetIndex = functions.findLastCard(targetPositionC,
				tableauArea);
		card sendingCard = tableauArea[firstcardInRow][currentPositionC];
		if (destCard.cardname == "-1") {
			if (sendingCard.value == 13) {
				for (int tempV = 0; tempV < (cardSize1 + 1); tempV++) {
					card tempCard =
							tableauArea[firstcardInRow + tempV][currentPositionC];
					tableauArea[firstcardInRow + tempV][currentPositionC].cardname =
							"0";
					tableauArea[tempV][targetPositionC] = tempCard;
				}
			} else
				cout << "Invalid Move" << endl;
		} else {

			if ((sendingCard.value + 1) == destCard.value) {
				if (sendingCard.suitChar == 'H') {
					if (destCard.suitChar == 'S' || destCard.suitChar == 'C') {
						for (int tempV = 0; tempV < (cardSize1 + 1); tempV++) {
							card tempCard =
									tableauArea[firstcardInRow + tempV][currentPositionC];
							tableauArea[firstcardInRow + tempV][currentPositionC].cardname =
									"0";
							tableauArea[lastcardTargetIndex + tempV + 1][targetPositionC] =
									tempCard;
						}

					} else
						cout << "Invalid Moves";
				} else if (sendingCard.suitChar == 'D') {

					if (destCard.suitChar == 'S' || destCard.suitChar == 'C') {
						for (int tempV = 0; tempV < (cardSize1 + 1); tempV++) {
							card tempCard =
									tableauArea[firstcardInRow + tempV][currentPositionC];
							tableauArea[firstcardInRow + tempV][currentPositionC].cardname =
									"0";
							tableauArea[lastcardTargetIndex + tempV + 1][targetPositionC] =
									tempCard;
						}

					}

				} else if (sendingCard.suitChar == 'S') {
					if (destCard.suitChar == 'H' || destCard.suitChar == 'D') {
						for (int tempV = 0; tempV < (cardSize1 + 1); tempV++) {
							card tempCard =
									tableauArea[firstcardInRow + tempV][currentPositionC];
							tableauArea[firstcardInRow + tempV][currentPositionC].cardname =
									"0";
							tableauArea[lastcardTargetIndex + tempV + 1][targetPositionC] =
									tempCard;
						}

					} else
						cout << "Invalid Moves";

				} else if (sendingCard.suitChar == 'C') {
					if (destCard.suitChar == 'H' || destCard.suitChar == 'D') {
						for (int tempV = 0; tempV < (cardSize1 + 1); tempV++) {
							card tempCard =
									tableauArea[firstcardInRow + tempV][currentPositionC];
							tableauArea[firstcardInRow + tempV][currentPositionC].cardname =
									"0";
							tableauArea[lastcardTargetIndex + tempV + 1][targetPositionC] =
									tempCard;
						}

					} else
						cout << "Invalid Moves";
				}
			} else {
				cout << endl;
				cout << "Invalid Move!" << endl;
			}
		}

	}

}
void Functions::openFromStock(StockValues stockValuesList[]) {
	StockValues oneStock = stockValuesList[0];

	int tempStockValue;
	if (oneStock.currentStockIndex == ((oneStock.maxIndex) - 1)) {
		oneStock.currentStockIndex = -1;
		stockValuesList[0] = oneStock;

	} else {

		tempStockValue = oneStock.currentStockIndex;
		tempStockValue = tempStockValue + 1;
		oneStock.currentStockIndex = tempStockValue;
		stockValuesList[0] = oneStock;
	}

}
void Functions::moveWasteToPile(string targetColumn,
		StockValues stockValuesList[], card stockMatrix[][3], card stockArray[],
		card tableauArea[][7]) {
	Functions functions;
	int targetColumnP = std::stoi(targetColumn);
	int lastcardTargetIndex = functions.findLastCard(targetColumnP,
			tableauArea);
	card destCard;
	if (lastcardTargetIndex == -1) {
		destCard.cardname = "-1";
	} else {
		destCard = tableauArea[lastcardTargetIndex][targetColumnP];
	}

	string temp;
	int currentIndex = stockValuesList[0].currentStockIndex;

	if (stockMatrix[currentIndex][2].cardname == "null") {
		if (stockMatrix[currentIndex][1].cardname == "null") {
			if (stockMatrix[currentIndex][0].cardname == "null")
				cout << "\nInvalid move!" << endl;
			else {
				if (destCard.cardname == "-1") {
					if (stockMatrix[currentIndex][0].value == 13){
						tableauArea[0][targetColumnP] =stockMatrix[currentIndex][0];
						tableauArea[0][targetColumnP].show = true;
					}

					else
						cout << "Invalid Move!" << endl;
				} else {
					if (suitExpression(stockMatrix[currentIndex][0].suitChar,
							destCard.suitChar) == true) {
						stockMatrix[currentIndex][0].show = true;
						tableauArea[lastcardTargetIndex+1][targetColumnP] =
								stockMatrix[currentIndex][0];
					} else
						cout << "Invalid Move!" << endl;
				}


				temp = stockMatrix[currentIndex][0].cardname;
				stockMatrix[currentIndex][0].cardname = "null";
				deleteFromArray(stockArray, temp);
			}
		} else {
			if (destCard.cardname == "-1") {
				if (stockMatrix[currentIndex][1].value == 13){

					tableauArea[0][targetColumnP] =stockMatrix[currentIndex][1];
					tableauArea[0][targetColumnP].show = true;
				}


				else
					cout << "Invalid Move!" << endl;
			} else {
				if (suitExpression(stockMatrix[currentIndex][1].suitChar,
						destCard.suitChar) == true) {
					stockMatrix[currentIndex][1].show = true;
					tableauArea[lastcardTargetIndex+1][targetColumnP] =
							stockMatrix[currentIndex][1];
				} else
					cout << "Invalid Move!" << endl;
			}
			temp = stockMatrix[currentIndex][1].cardname;
			stockMatrix[currentIndex][1].cardname = "null";
			deleteFromArray(stockArray, temp);
		}

	} else {
		if (destCard.cardname == "-1") {
			if (stockMatrix[currentIndex][2].value == 13){
				tableauArea[0][targetColumnP] = stockMatrix[currentIndex][2];
				tableauArea[0][targetColumnP].show = true;

			}

			else
				cout << "Invalid Move!" << endl;
		} else {
			if (suitExpression(stockMatrix[currentIndex][2].suitChar,
					destCard.suitChar) == true) {
				stockMatrix[currentIndex][2].show = true;
				tableauArea[lastcardTargetIndex+1][targetColumnP] =
						stockMatrix[currentIndex][2];
			} else
				cout << "Invalid Move!" << endl;
		}

		temp = stockMatrix[currentIndex][2].cardname;
		stockMatrix[currentIndex][2].cardname = "null";
		deleteFromArray(stockArray, temp);
	}

}

void Functions::sortingStockArray(card stockArray[]) {
	cout << "hello world" << endl;
}
void Functions::deleteFromArray(card array[], string value) {
	int i;
	int k;
	for (k = 0; k < 24; k++) {
		if (array[k].cardname == value)
			break;
	}
	for (i = k; i < 23; i++)
		array[i] = array[i + 1];

	for (int in = 1; in < 24; in++)
		if (array[in].cardname == array[in - 1].cardname)
			array[in].cardname = "___";

}
bool Functions::suitExpression(char source, char dest) {
	if (source == 'H') {
		if (dest == 'C' || dest == 'S')
			return true;
		else
			return false;
	} else if (source == 'D') {
		if (dest == 'C' || dest == 'S')
			return true;
		else
			return false;
	} else if (source == 'C') {
		if (dest == 'H' || dest == 'D')
			return true;
		else
			return false;
	} else if (source == 'S') {
		if (dest == 'H' || dest == 'D')
			return true;
		else
			return false;
	}else
		return false;

}
