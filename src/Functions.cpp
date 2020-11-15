#include "Functions.h"

void Functions::moveFoundation(string columnIndex, card tableauArea[][7],
		card foundationHearts[], card foundationDiamonds[],
		card foundationClubs[], card foundationSpades[], card stockArray[]) {
	Functions functions;
	string temp = "none";
	int currentColumnIndex = std::stoi(columnIndex);
	int currentIndex = functions.findLastCard(currentColumnIndex, tableauArea);
	card currentcard;
	if (currentIndex == -1) {
		cout << endl;
		cout << "Invalid Move!" << endl;
	} else
		currentcard = tableauArea[currentIndex][currentColumnIndex];

	//tableauArea[currentIndex][currentColumnIndex].cardname = "0";
	if (currentcard.suitChar == 'H') {
		functions.addFoundation(foundationHearts, currentcard, stockArray, temp,
				tableauArea, currentIndex, currentColumnIndex);
	} else if (currentcard.suitChar == 'D') {

		functions.addFoundation(foundationDiamonds, currentcard, stockArray,
				temp, tableauArea, currentIndex, currentColumnIndex);
	} else if (currentcard.suitChar == 'C') {

		functions.addFoundation(foundationClubs, currentcard, stockArray, temp,
				tableauArea, currentIndex, currentColumnIndex);

	} else if (currentcard.suitChar == 'S') {
		functions.addFoundation(foundationSpades, currentcard, stockArray, temp,
				tableauArea, currentIndex, currentColumnIndex);
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
void Functions::addFoundation(card array[], card currentCard, card stockArray[],
		string temp, card tableauArea[][7], int currentIndex,
		int currentColumnIndex) {
	if (currentCard.value == 1) {
		array[0] = currentCard;
		deleteFromArray(stockArray, temp);
		tableauArea[currentIndex][currentColumnIndex].cardname = "0";

	} else {
		int controlInt = (currentCard.value - 2);
		if (array[controlInt].cardname != "0") {
			array[controlInt + 1] = currentCard;
			deleteFromArray(stockArray, temp);
			tableauArea[currentIndex][currentColumnIndex].cardname = "0";
		} else {
			cout << endl;
			cout << "Invalid Move!" << endl;
		}

	}
}
void Functions::addFoundation2(card array[], card currentCard,
		card stockArray[], string temp, card stockMatrix[][3], int currentIndex,
		int position) {
	if (currentCard.value == 1) {
		array[0] = currentCard;
		deleteFromArray(stockArray, temp);
		stockMatrix[currentIndex][position].cardname = "null";
	} else {
		int controlInt = (currentCard.value - 2);
		if (array[controlInt].cardname != "0") {
			array[controlInt + 1] = currentCard;
			deleteFromArray(stockArray, temp);
			stockMatrix[currentIndex][position].cardname = "null";

		} else {
			cout << endl;
			cout << "Invalid Move!" << endl;
		}

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

	if (cardSize1 > lastCardCurrentIndex) {
		cout << endl;
		cout << "Invalid Move";
	}

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
			} else {
				cout << endl;
				cout << "Invalid Move" << endl;
			}

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
void Functions::openFromStock(StockValues stockValuesList[], card stockArray[],
		card stockMatrix[][3]) {
	StockValues oneStock = stockValuesList[0];

	int tempStockValue;
	if (oneStock.currentStockIndex == ((oneStock.maxIndex) - 1)) {
		oneStock.currentStockIndex = -1;
		stockValuesList[0] = oneStock;
		calculateStockMatrix(stockArray, stockMatrix);
		setNewMaxValue(stockMatrix, stockValuesList);

	} else {

		tempStockValue = oneStock.currentStockIndex;
		int maxSize = oneStock.maxIndex;
		int countZero = 0;
		for (int i = (tempStockValue + 1); i < maxSize; i++) {
			if (stockMatrix[i][0].cardname == "null")
				countZero++;

			else
				break;
		}
		cout << endl;

		tempStockValue = tempStockValue + 1 + countZero;
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

	if (stockMatrix[currentIndex][2].cardname == "null"
			|| stockMatrix[currentIndex][2].cardname == "___") {
		if (stockMatrix[currentIndex][1].cardname == "null"
				|| stockMatrix[currentIndex][1].cardname == "___") {
			if (stockMatrix[currentIndex][0].cardname == "null")
				cout << "\nInvalid move!" << endl;
			else {
				if (destCard.cardname == "-1") {
					if (stockMatrix[currentIndex][0].value == 13) {
						tableauArea[0][targetColumnP] =
								stockMatrix[currentIndex][0];
						tableauArea[0][targetColumnP].show = true;
						temp = stockMatrix[currentIndex][0].cardname;
						stockMatrix[currentIndex][0].cardname = "null";
						deleteFromArray(stockArray, temp);
					}

					else
						cout << "Invalid Move!" << endl;
				} else {

					if (stockMatrix[currentIndex][0].value
							== (destCard.value - 1)) {
						if (suitExpression(
								stockMatrix[currentIndex][0].suitChar,
								destCard.suitChar) == true) {
							stockMatrix[currentIndex][0].show = true;
							tableauArea[lastcardTargetIndex + 1][targetColumnP] =
									stockMatrix[currentIndex][0];
							temp = stockMatrix[currentIndex][0].cardname;
							stockMatrix[currentIndex][0].cardname = "null";
							deleteFromArray(stockArray, temp);

						} else
							cout << "Invalid Move!" << endl;
					} else
						cout << "Invalid Move!" << endl;

				}
				int tempMax = stockValuesList[0].maxIndex;

				if (currentIndex != 0 && currentIndex != (tempMax - 1))
					stockValuesList[0].currentStockIndex = currentIndex - 1;
				else if (currentIndex == (tempMax - 1)) {
					if (stockMatrix[currentIndex - 1][2].cardname == "null") {
						if (stockMatrix[currentIndex - 1][1].cardname
								== "null") {
							if (stockMatrix[currentIndex - 1][0].cardname
									== "null")
								cout << "Invalid Move!" << endl;
							else {
								card tempPre = stockMatrix[currentIndex - 1][0];
								stockMatrix[currentIndex - 1][0].cardname =
										"null";
								stockMatrix[currentIndex][0] = tempPre;
							}
						} else {
							card tempPre = stockMatrix[currentIndex - 1][1];
							stockMatrix[currentIndex - 1][1].cardname = "null";
							stockMatrix[currentIndex][0] = tempPre;
						}
					} else {
						card tempPre = stockMatrix[currentIndex - 1][2];
						stockMatrix[currentIndex - 1][2].cardname = "null";
						stockMatrix[currentIndex][0] = tempPre;
					}

				}

			}
		} else {
			if (destCard.cardname == "-1") {
				if (stockMatrix[currentIndex][1].value == 13) {

					tableauArea[0][targetColumnP] =
							stockMatrix[currentIndex][1];
					tableauArea[0][targetColumnP].show = true;
					temp = stockMatrix[currentIndex][1].cardname;
					stockMatrix[currentIndex][1].cardname = "null";
					deleteFromArray(stockArray, temp);
				}

				else
					cout << "Invalid Move!" << endl;
			} else {

				if (stockMatrix[currentIndex][1].value
						== (destCard.value - 1)) {
					if (suitExpression(stockMatrix[currentIndex][1].suitChar,
							destCard.suitChar) == true) {
						stockMatrix[currentIndex][1].show = true;
						tableauArea[lastcardTargetIndex + 1][targetColumnP] =
								stockMatrix[currentIndex][1];
						temp = stockMatrix[currentIndex][1].cardname;
						stockMatrix[currentIndex][1].cardname = "null";
						deleteFromArray(stockArray, temp);
					} else
						cout << "Invalid Move!" << endl;

				} else
					cout << "Invalid Move!" << endl;

			}

		}

	} else {
		if (destCard.cardname == "-1") {
			if (stockMatrix[currentIndex][2].value == 13) {
				tableauArea[0][targetColumnP] = stockMatrix[currentIndex][2];
				tableauArea[0][targetColumnP].show = true;
				temp = stockMatrix[currentIndex][2].cardname;
				stockMatrix[currentIndex][2].cardname = "null";
				deleteFromArray(stockArray, temp);

			}

			else
				cout << "Invalid Move!" << endl;
		} else {
			if (stockMatrix[currentIndex][2].value == (destCard.value - 1)) {
				if (suitExpression(stockMatrix[currentIndex][2].suitChar,
						destCard.suitChar) == true) {
					stockMatrix[currentIndex][2].show = true;
					tableauArea[lastcardTargetIndex + 1][targetColumnP] =
							stockMatrix[currentIndex][2];
					temp = stockMatrix[currentIndex][2].cardname;
					stockMatrix[currentIndex][2].cardname = "null";
					deleteFromArray(stockArray, temp);
				} else
					cout << "Invalid Move!" << endl;

			} else
				cout << "Invalid Move!" << endl;

		}

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
	} else
		return false;

}
void Functions::moveWasteToFoundation(StockValues stockValuesList[],
		card stockMatrix[][3], card stockArray[], card foundationHearts[],
		card foundationDiamonds[], card foundationClubs[],
		card foundationSpades[]) {
	string temp;
	Functions functions;
	int currentIndex = stockValuesList[0].currentStockIndex;
	card tempCard;
	if (stockMatrix[currentIndex][2].cardname == "null"
			|| stockMatrix[currentIndex][2].cardname == "___") {
		if (stockMatrix[currentIndex][1].cardname == "null"
				|| stockMatrix[currentIndex][1].cardname == "___") {
			if (stockMatrix[currentIndex][0].cardname == "null") {
				cout << "Invalid Move!" << endl;
			} else {
				tempCard = stockMatrix[currentIndex][0];
				temp = tempCard.cardname;
				//stockMatrix[currentIndex][0].cardname = "null";
				if (tempCard.suitChar == 'H') {
					functions.addFoundation2(foundationHearts, tempCard,
							stockArray, temp, stockMatrix, currentIndex, 0);
				} else if (tempCard.suitChar == 'D') {
					functions.addFoundation2(foundationDiamonds, tempCard,
							stockArray, temp, stockMatrix, currentIndex, 0);
				} else if (tempCard.suitChar == 'C') {
					functions.addFoundation2(foundationClubs, tempCard,
							stockArray, temp, stockMatrix, currentIndex, 0);
				} else if (tempCard.suitChar == 'S') {
					functions.addFoundation2(foundationSpades, tempCard,
							stockArray, temp, stockMatrix, currentIndex, 0);
				}
				if (currentIndex > 0)
					stockValuesList[0].currentStockIndex = currentIndex - 1;

			}
		} else {
			tempCard = stockMatrix[currentIndex][1];
			temp = tempCard.cardname;
			//stockMatrix[currentIndex][1].cardname = "null";
			if (tempCard.suitChar == 'H') {
				functions.addFoundation2(foundationHearts, tempCard, stockArray,
						temp, stockMatrix, currentIndex, 1);
			} else if (tempCard.suitChar == 'D') {
				functions.addFoundation2(foundationDiamonds, tempCard,
						stockArray, temp, stockMatrix, currentIndex, 1);
			} else if (tempCard.suitChar == 'C') {
				functions.addFoundation2(foundationClubs, tempCard, stockArray,
						temp, stockMatrix, currentIndex, 1);
			} else if (tempCard.suitChar == 'S') {
				functions.addFoundation2(foundationSpades, tempCard, stockArray,
						temp, stockMatrix, currentIndex, 1);
			}

		}
	} else {
		tempCard = stockMatrix[currentIndex][2];
		temp = tempCard.cardname;
		//stockMatrix[currentIndex][2].cardname = "null";
		if (tempCard.suitChar == 'H') {
			functions.addFoundation2(foundationHearts, tempCard, stockArray,
					temp, stockMatrix, currentIndex, 2);
		} else if (tempCard.suitChar == 'D') {
			functions.addFoundation2(foundationDiamonds, tempCard, stockArray,
					temp, stockMatrix, currentIndex, 2);
		} else if (tempCard.suitChar == 'C') {
			functions.addFoundation2(foundationClubs, tempCard, stockArray,
					temp, stockMatrix, currentIndex, 2);
		} else if (tempCard.suitChar == 'S') {
			functions.addFoundation2(foundationSpades, tempCard, stockArray,
					temp, stockMatrix, currentIndex, 2);
		}
	}

}
void Functions::setNewMaxValue(card stockMatrix[][3],
		StockValues stockValuesList[]) {
	int nullCount = 0;
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 3; j++) {
			if (stockMatrix[i][j].cardname == "___")
				nullCount++;
		}
	}

	int newSize;
	int notNullCount = (24 - nullCount);

	if (notNullCount <= 3) {
		newSize = 1;
	} else if (notNullCount > 3) {
		if (notNullCount % 3 == 0)
			newSize = notNullCount / 3;
		else
			newSize = notNullCount / 3 + 1;
	}
	stockValuesList[0].maxIndex = newSize;

}
void Functions::calculateStockMatrix(card stockArray[], card stockMatrix[][3]) {
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 3; j++) {
			stockMatrix[i][j] = stockArray[(3 * i) + j];
		}
	}
}
