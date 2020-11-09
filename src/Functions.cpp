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

