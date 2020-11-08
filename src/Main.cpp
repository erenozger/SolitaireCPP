//============================================================================
// Name        : Assignment1.cpp
// Author      : Eren Özger
// Version     : 14
// Student ID  : 21427215
// Description : Solitaire Cpp
//============================================================================

#include <iostream>
#include <fstream>
#include <string>
#include "CommandRead.h"
#include "Card.h"

#define STOCKSIZE 24
#define PILESIZE 7
#define ONESUITSIZE 13
using namespace std;

/*class card {
 public:
 string cardname;
 char suitChar;
 int value;
 bool show;
 };*/
void reverseDeck(card deck[], int begin, int end) {
	if (end != 51) {
		cout << "Invaled deck size!" << endl;
		exit(0);
	} else {
		while (begin < end) {
			card temp = deck[begin];
			deck[begin] = deck[end];
			deck[end] = temp;
			begin++;
			end--;
		}
	}

}

void printDeck(card deck[], int size) {
	for (int i = 0; i < size; i++)
		cout << deck[i].cardname << " ";
	cout << endl;
}
void createUpperTriangularBoard(card deckArray[], card tableauArea[19][7],
		card stockArray[]) {
	int i, j, k, l;
	int size = 7;
	int count;
	for (i = 0; i < 7; i++)
		for (j = 0; j < 7; j++)
			if (i < j)
				tableauArea[i][j] = deckArray[(size * (size - 1) / 2)
						- ((size - i) * (size - i - 1) / 2) + j];
			else if (i == j) {
				tableauArea[i][j] = deckArray[(size * (size - 1) / 2)
						- ((size - i) * (size - i - 1) / 2) + j];
				tableauArea[i][j].show = true;
			}

			else
				tableauArea[i][j].cardname = "0";

	for (k = 7; k < 19; k++)
		for (l = 0; l < 7; l++)
			tableauArea[k][l].cardname = "0";

	int temp1 = 0;
	for (count = 28; count < 52; count++) {
		stockArray[temp1] = deckArray[count];
		temp1++;
	}

}
void printMatrix(card matrix[][7], int row, int column) {

	int i, j;
	int printRow;
	int rowCount = 0;

	for (int first = 0; first < row; first++) {
		if (rowCount == 7) {
			printRow = first;
			break;
		} else
			rowCount = 0;

		for (int second = 0; second < column; second++) {
			if (matrix[first][second].cardname == "0")
				rowCount++;
		}
	}

	for (i = 0; i < printRow - 1; i++) {
		for (j = 0; j < column; j++) {
			if (matrix[i][j].cardname != "0") {
				if (matrix[i][j].show == false)
					cout << "@@@" << "   ";
				else
					cout << matrix[i][j].cardname << "   ";

			} else
				cout << "   " << "   ";

		}
		printf("\n");
	}

}
void createStock(card stockArray[24], card stockMatrix[8][3]) {
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 3; j++) {
			stockMatrix[i][j] = stockArray[(3 * i) + j];
		}
	}

}
void printStockMatrix(card array[][3]) {
	int i, j;
	for (i = 0; i < 8; i++) {
		for (j = 0; j < 3; j++) {
			if (array[i][j].cardname == "null")
				cout << "___" << "\t";
			else
				cout << array[i][j].cardname << "\t";

		}
		cout << endl;
	}
}
void printStocksInGame(card stockMatrix[][3], int index, int maxindex) {
	if (index == -1) {
		cout << "@@@" << " " << "___" << " " << "___" << " " << "___" << " ";

	} else if (index == (maxindex - 1)) {
		cout << "___" << " ";
		for (int i = 0; i < 3; i++) {
			cout << stockMatrix[index][i].cardname << " ";

		}

	} else {
		cout << "@@@" << " ";
		for (int i = 0; i < 3; i++) {
			cout << stockMatrix[index][i].cardname << " ";

		}

	}
	cout << "        ";

}
void printFoundations(card foundationHearts[], card foundationDiamonds[],
		card foundationClubs[], card foundationSpades[]) {
	if (foundationHearts[0].cardname == "0")
		cout << "___" << " ";
	else

		for (int temp = 1; temp < 13; temp++) {
			if (temp == 12) {
				if (foundationHearts[temp].cardname == "0")
					cout << foundationHearts[temp - 1].cardname << " ";
				else
					cout << foundationHearts[temp].cardname << " ";
			} else if (foundationHearts[temp].cardname == "0") {
				cout << foundationHearts[temp - 1].cardname << " ";
				break;
			}
		}
	if (foundationDiamonds[0].cardname == "0")
		cout << "___" << " ";
	else {
		for (int temp1 = 1; temp1 < 13; temp1++) {
			if (temp1 == 12) {
				if (foundationDiamonds[temp1].cardname == "0")
					cout << foundationDiamonds[temp1 - 1].cardname << " ";
				else
					cout << foundationDiamonds[temp1].cardname << " ";
			} else if (foundationDiamonds[temp1].cardname == "0") {
				cout << foundationDiamonds[temp1 - 1].cardname << " ";
				break;
			}
		}
	}
	if (foundationSpades[0].cardname == "0")
		cout << "___" << " ";
	else {
		for (int temp3 = 1; temp3 < 13; temp3++) {
			if (temp3 == 12) {
				if (foundationSpades[temp3].cardname == "0")
					cout << foundationSpades[temp3 - 1].cardname << " ";
				else
					cout << foundationSpades[temp3].cardname << " ";
			} else if (foundationSpades[temp3].cardname == "0") {
				cout << foundationSpades[temp3 - 1].cardname << " ";
				break;
			}
		}
	}
	if (foundationClubs[0].cardname == "0")
		cout << "___" << " ";
	else {
		for (int temp2 = 1; temp2 < 13; temp2++) {
			if (temp2 == 12) {
				if (foundationClubs[temp2].cardname == "0")
					cout << foundationClubs[temp2 - 1].cardname << " ";
				else
					cout << foundationClubs[temp2].cardname << " ";
			} else if (foundationClubs[temp2].cardname == "0") {
				cout << foundationClubs[temp2 - 1].cardname << " ";
				break;
			}
		}
	}
	cout << endl << endl;
}
void playSolitaire(card tableauArea[][7], card stockMatrix[][3],
		card stockArray[], card foundationHearts[], card foundationDiamonds[],
		card foundationClubs[], card foundationSpades[]) {
	int currentStockIndex = -1;
	int maxIndex = 8;
	printStocksInGame(stockMatrix, currentStockIndex, maxIndex);
	printFoundations(foundationHearts, foundationDiamonds, foundationClubs,
			foundationSpades);
	printMatrix(tableauArea, 19, 7);

	string command;
	ifstream commandFile("commands.txt");
	while (std::getline(commandFile, command)) {
		CommandRead commandread;
		commandread.calculateWholeCommand(command, tableauArea, stockMatrix,
				stockArray, foundationHearts, foundationDiamonds,
				foundationClubs, foundationSpades);
		printStocksInGame(stockMatrix, currentStockIndex, maxIndex);
		printFoundations(foundationHearts, foundationDiamonds, foundationClubs,
				foundationSpades);
		printMatrix(tableauArea, 19, 7);
		cout << endl;
	}


}
int main() {

	ifstream file("deck.txt");
	int deckSizeCount = 0;
	string line;
	while (getline(file, line)) {
		deckSizeCount++;
	}

	struct card deckArray[deckSizeCount];
	string str;
	int arrayTemp = 0;
	file.clear();
	file.seekg(0, ios::beg);
	while (std::getline(file, str)) {
		deckArray[arrayTemp].cardname = str;
		deckArray[arrayTemp].show = false;
		deckArray[arrayTemp].suitChar = str.at(0);
		string subString = str.substr(1, 2);
		int valueTemp = std::stoi(subString);
		deckArray[arrayTemp].value = valueTemp;
		arrayTemp++;

	}
	reverseDeck(deckArray, 0, deckSizeCount - 1);
	card tableauArea[PILESIZE + (ONESUITSIZE - 1)][PILESIZE];
	card stockArray[STOCKSIZE];
	card stockMatrix[8][3];
	card emptyCard;
	emptyCard.cardname = "0";

	card foundationClubs[13] = { emptyCard, emptyCard, emptyCard, emptyCard,
			emptyCard, emptyCard, emptyCard, emptyCard, emptyCard, emptyCard,
			emptyCard, emptyCard, emptyCard };
	card foundationSpades[13] = { emptyCard, emptyCard, emptyCard, emptyCard,
			emptyCard, emptyCard, emptyCard, emptyCard, emptyCard, emptyCard,
			emptyCard, emptyCard, emptyCard };
	card foundationHearts[13] = { emptyCard, emptyCard, emptyCard, emptyCard,
			emptyCard, emptyCard, emptyCard, emptyCard, emptyCard, emptyCard,
			emptyCard, emptyCard, emptyCard };
	card foundationDiamonds[13] = { emptyCard, emptyCard, emptyCard, emptyCard,
			emptyCard, emptyCard, emptyCard, emptyCard, emptyCard, emptyCard,
			emptyCard, emptyCard, emptyCard };

	createUpperTriangularBoard(deckArray, tableauArea, stockArray);
	createStock(stockArray, stockMatrix);
	playSolitaire(tableauArea, stockMatrix, stockArray, foundationHearts,
			foundationDiamonds, foundationClubs, foundationSpades);

	return 0;
}

