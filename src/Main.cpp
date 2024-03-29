//============================================================================
// Name        : Assignment1.cpp
// Author      : Eren �zger
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

void reverseDeck(card deck[], int begin, int end,std::ostream& output) {
	if (end != 51) {
		output << "Invalid deck size!" << endl;
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

void printDeck(card deck[], int size,std::ostream& output) {
	for (int i = 0; i < size; i++)
		output << deck[i].cardname << " ";
	output << endl;
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
void printMatrix(card matrix[][7], int row, int column,std::ostream& output) {

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
					output << "@@@" << "   ";
				else
					output << matrix[i][j].cardname << "   ";

			} else
				output << "   " << "   ";

		}
		output<<endl;
	}

}
void createStock(card stockArray[24], card stockMatrix[8][3]) {
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 3; j++) {
			stockMatrix[i][j] = stockArray[(3 * i) + j];
		}
	}

}
void printStockMatrix(card array[][3],std::ostream& output) {
	int i, j;
	for (i = 0; i < 8; i++) {
		for (j = 0; j < 3; j++) {
			if (array[i][j].cardname == "null")
				output << "___" << "\t";
			else
				output << array[i][j].cardname << "\t";

		}
		output << endl;
	}
}
void printStocksInGame(card stockMatrix[][3], StockValues stockValuesList[],std::ostream& output) {
	StockValues oneStock = stockValuesList[0];
	if (oneStock.currentStockIndex == -1) {
		output << "@@@" << " " << "___" << " " << "___" << " " << "___" << " ";

	} else if (oneStock.currentStockIndex == (oneStock.maxIndex - 1)) {
		output << "___" << " ";
		for (int i = 0; i < 3; i++) {
			if (stockMatrix[oneStock.currentStockIndex][i].cardname == "null")
				output << "___" << " ";
			else
				output << stockMatrix[oneStock.currentStockIndex][i].cardname
						<< " ";

		}

	} else {
		output << "@@@" << " ";
		for (int i = 0; i < 3; i++) {
			if (stockMatrix[oneStock.currentStockIndex][i].cardname == "null")
				output << "___" << " ";
			else
				output << stockMatrix[oneStock.currentStockIndex][i].cardname
						<< " ";

		}

	}
	output << "        ";

}
void printFoundations(card foundationHearts[], card foundationDiamonds[],
		card foundationClubs[], card foundationSpades[],std::ostream& output) {
	if (foundationHearts[0].cardname == "0")
		output << "___" << " ";
	else

		for (int temp = 1; temp < 13; temp++) {
			if (temp == 12) {
				if (foundationHearts[temp].cardname == "0")
					output << foundationHearts[temp - 1].cardname << " ";
				else
					output << foundationHearts[temp].cardname << " ";
			} else if (foundationHearts[temp].cardname == "0") {
				output << foundationHearts[temp - 1].cardname << " ";
				break;
			}
		}
	if (foundationDiamonds[0].cardname == "0")
		output << "___" << " ";
	else {
		for (int temp1 = 1; temp1 < 13; temp1++) {
			if (temp1 == 12) {
				if (foundationDiamonds[temp1].cardname == "0")
					output << foundationDiamonds[temp1 - 1].cardname << " ";
				else
					output << foundationDiamonds[temp1].cardname << " ";
			} else if (foundationDiamonds[temp1].cardname == "0") {
				output << foundationDiamonds[temp1 - 1].cardname << " ";
				break;
			}
		}
	}
	if (foundationSpades[0].cardname == "0")
		output << "___" << " ";
	else {
		for (int temp3 = 1; temp3 < 13; temp3++) {
			if (temp3 == 12) {
				if (foundationSpades[temp3].cardname == "0")
					output << foundationSpades[temp3 - 1].cardname << " ";
				else
					output << foundationSpades[temp3].cardname << " ";
			} else if (foundationSpades[temp3].cardname == "0") {
				output << foundationSpades[temp3 - 1].cardname << " ";
				break;
			}
		}
	}
	if (foundationClubs[0].cardname == "0")
		output << "___" << " ";
	else {
		for (int temp2 = 1; temp2 < 13; temp2++) {
			if (temp2 == 12) {
				if (foundationClubs[temp2].cardname == "0")
					output << foundationClubs[temp2 - 1].cardname << " ";
				else
					output << foundationClubs[temp2].cardname << " ";
			} else if (foundationClubs[temp2].cardname == "0") {
				output << foundationClubs[temp2 - 1].cardname << " ";
				break;
			}
		}
	}
	output << endl << endl;
}
void playSolitaire(card tableauArea[][7], card stockMatrix[][3],
		card stockArray[], card foundationHearts[], card foundationDiamonds[],
		card foundationClubs[], card foundationSpades[],
		StockValues stockValuesList[],std::ostream& output) {
	output<<endl;
	printStocksInGame(stockMatrix, stockValuesList,output);
	printFoundations(foundationHearts, foundationDiamonds, foundationClubs,
			foundationSpades,output);
	printMatrix(tableauArea, 19, 7,output);

	string command;
	ifstream commandFile("commands4.txt");
	while (std::getline(commandFile, command)) {
		CommandRead commandread;
		commandread.calculateWholeCommand(command, tableauArea, stockMatrix,
				stockArray, foundationHearts, foundationDiamonds,
				foundationClubs, foundationSpades, stockValuesList,output);
		output<<endl;
		printStocksInGame(stockMatrix, stockValuesList,output);
		printFoundations(foundationHearts, foundationDiamonds, foundationClubs,
				foundationSpades,output);
		printMatrix(tableauArea, 19, 7,output);


	}

}
int main() {
	ofstream output;
	output.open("output.txt");
	ifstream file("deck4.txt");
	int deckSizeCount = 0;
	string line;
	while (getline(file, line)) {
		deckSizeCount++;
	}
	StockValues stockValues;
	stockValues.currentStockIndex = -1;
	stockValues.maxIndex = 8;
	StockValues stockValuesList[1] = { stockValues };

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
		int valueTemp = stoi(subString);
		deckArray[arrayTemp].value = valueTemp;
		arrayTemp++;

	}
	reverseDeck(deckArray, 0, deckSizeCount - 1,output);
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
			foundationDiamonds, foundationClubs, foundationSpades,
			stockValuesList,output);

	output<<endl;
	output<<endl;
	output<<"****************************************"<<endl;
	output<<endl;
	output<<"You Win!"<<endl;
	output<<endl;
	output<<"Game Over!"<<endl;
	output<<endl;
	return 0;
}

