// || nums[x] == 'X' || nums[x] == 'C' || nums[x] == 'M'

//	Symbol       Value		Index
//	I             1			0
//	V             5			1
//	X             10		2
//	L             50		3
//	C             100		4
//	D             500		5
//	M             1000		6

#include <iostream>
#include <string>

const char* checkNumbers = "IVXLCDM";
const int checkSize = 6;

int start() {
	int answer = 0;
	while (true) {		
		std::cout << "�������� ��������\n";
		std::cout << "������� -> �������� (1)\t�������� -> ������� (2)\t����� (3)\n";
		std::cin >> answer;
		system("cls");
		if (std::cin.fail()) {
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<int>::max(), '\n');
		}
		if (answer >= 1 && answer <= 3) {
			return answer;
			break;
		}
	}
}

int countToArabic(char symbol, char nextSymbol, int size, int el) {
	int x = 0;

	if (el != size) {
		if (symbol == 'I' && nextSymbol != symbol) {
			x -= 1;
			return x;
		}
		if (symbol == 'X' && nextSymbol != symbol && nextSymbol != 'I' && nextSymbol != 'V') {
			x -= 10;
			return x;
		}
		if (symbol == 'C' && nextSymbol != symbol && nextSymbol != 'I' && nextSymbol != 'V' && nextSymbol != 'X' && nextSymbol != 'L') {
			x -= 100;
			return x;
		}
	}

	if (symbol == 'I') {
		x += 1;
		return x;
	}
	if (symbol == 'V') {
		x += 5;
		return x;
	}
	if (symbol == 'X') {
		x += 10;
		return x;
	}
	if (symbol == 'L') {
		x += 50;
		return x;
	}
	if (symbol == 'C') {
		x += 100;
		return x;
	}
	if (symbol == 'D') {
		x += 500;
		return x;
	}
	if (symbol == 'M') {
		x += 1000;
		return x;
	}

}
void countToRoman(const char* nums, int res) {
	int units = res % 10;
	int dozens = res / 10 % 10;
	int hundreds = res / 100 % 10;
	int thousands = res / 1000;
	if (res > 999) {
		for (int x = 0; x < thousands; x++) {
			std::cout << nums[6];
		}
	}

	if (res > 99) {
		if (hundreds != 0) {
			if (hundreds == 9) {
				std::cout << nums[4] << nums[6];
			}
			if (hundreds >= 5 && hundreds < 9) {
				std::cout << nums[5];
				for (int x = 0; x < hundreds % 5; x++) {
					std::cout << nums[4];
				}
			}
			if (hundreds == 4) {
				std::cout << nums[4] << nums[5];
			}
			else if (hundreds < 4) {
				for (int x = 0; x < hundreds; x++) {
					std::cout << nums[4];
				}
			}
		}
	}

	if (res > 9) {
		if (dozens != 0) {
			if (dozens == 9) {
				std::cout << nums[2] << nums[4];
			}
			if (dozens >= 5 && dozens < 9) {
				std::cout << nums[3];
				for (int x = 0; x < dozens % 5; x++) {
					std::cout << nums[2];
				}
			}
			if (dozens == 4) {
				std::cout << nums[2] << nums[3];
			}
			else if (dozens < 4) {
				for (int x = 0; x < dozens; x++) {
					std::cout << nums[2];
				}
			}
		}
	}

	if (res > 0) {
		if (units != 0) {
			if (units == 9) {
				std::cout << nums[0] << nums[2];
			}
			if (units >= 5 && units < 9) {
				std::cout << nums[1];
				for (int x = 0; x < units % 5; x++) {
					std::cout << nums[0];
				}
			}
			if (units == 4) {
				std::cout << nums[0] << nums[1];
			}
			else if (units < 4) {
				for (int x = 0; x < units; x++) {
					std::cout << nums[0];
				}
			}
		}
	}
}

int isWrong(char* nums, int size) {
	int check = 0;
	for (int x = 0; x < size; x++) {
		if (nums[x] == 'I' || nums[x] == 'V' || nums[x] == 'X' || nums[x] == 'L' || nums[x] == 'C' || nums[x] == 'D' || nums[x] == 'M') {
			check++;
		}
	}
	if (check == size) {
		return 0;
	}
	else if (check == 0) {
		return 1;
	}
}
int isNotValid(char* nums, int size) {
	for (int x = 0; x < size; x++) {
		if (nums[x - 1] == 'V' && nums[x] == 'I' && nums[x + 1] == 'V') {
			std::cout << "����� 5 \"V\" 1 \"I\" 5 \"V\" ������ �������� ������������ ���������, ���������� ��������� 1 \"I\" 10 \"X\"";
			return 1;
		}
		if (nums[x - 1] == 'V' && nums[x] == 'I' && nums[x + 1] == 'X') {
			std::cout << "����� 5 \"V\" 1 \"I\" 10 \"X\" ������ �������� ������������ ���������, ���������� ��������� 10 \"X\" 1 \"I\" 5 \"V\"";
			return 1;
		}
		if (nums[x - 1] == 'I' && nums[x] == 'I' && (nums[x + 1] == 'V' || nums[x + 1] == 'X')) {
			std::cout << "����� 1 \"I\" ���������� ������� ����� ����� ����. ";
			if (nums[x + 1] == 'V') {
				std::cout << "���������� ��������� 1 \"I\" 1 \"I\" 1 \"I\"";
			}
			if (nums[x + 1] == 'X') {
				std::cout << "���������� ��������� 5 \"V\" 1 \"I\" 1 \"I\" 1 \"I\"";
			}
			return 1;
		}
		if (nums[x] == 'I' && (nums[x + 1] == 'L' || nums[x + 1] == 'C' || nums[x + 1] == 'D' || nums[x + 1] == 'M')) {
			std::cout << "����� 1 \"I\" ���������� ������� �������� �� ����� ";
			if (nums[x + 1] == 'L') {
				std::cout << "50 \"L\". ���������� ��������� 10 \"X\" 50 \"L\" 1 \"I\"";
			}
			if (nums[x + 1] == 'C') {
				std::cout << "100 \"C\". ���������� ��������� 10 \"X\" 100 \"C\" 1 \"I\"";
			}
			if (nums[x + 1] == 'D') {
				std::cout << "500 \"D\". ���������� ��������� 100 \"C\" 500 \"D\" 10 \"X\" 100 \"C\" 1 \"I\"";
			}
			if (nums[x + 1] == 'M') {
				std::cout << "1000 \"M\". ���������� ��������� 100 \"C\" 1000 \"M\" 10 \"X\" 100 \"C\" 1 \"I\"";
			}
			return 1;
		}
		if (nums[x] == 'V' && (nums[x + 1] == 'X' || nums[x + 1] == 'L' || nums[x + 1] == 'C' || nums[x + 1] == 'D' || nums[x + 1] == 'M')) {
			std::cout << "����� 5 \"V\" ���������� ������� �� ����� ";
			if (nums[x + 1] == 'X') {
				std::cout << "10 \"X\". ��� ��� ��������� ����� ����� 5 \"V\".";
			}
			if (nums[x + 1] == 'L') {
				std::cout << "50 \"L\". ���������� ��������� 10 \"X\" 50 \"L\" 5 \"V\".";
			}
			if (nums[x + 1] == 'C') {
				std::cout << "100 \"C\". ���������� ��������� 10 \"X\" 100 \"C\" 5 \"V\".";
			}
			if (nums[x + 1] == 'D') {
				std::cout << "500 \"D\". ���������� ��������� 100 \"C\" 500 \"D\" 10 \"X\" 100 \"C\" 5 \"V\".";
			}
			if (nums[x + 1] == 'M') {
				std::cout << "1000 \"M\". ���������� ��������� 100 \"C\" 1000 \"M\" 10 \"X\" 100 \"C\" 5 \"V\".";
			}
			return 1;
		}
		if (nums[x] == 'X' && (nums[x + 1] == 'D' || nums[x + 1] == 'M')) {
			std::cout << "����� 10 \"X\" ���������� ������� �� ����� ";
			if (nums[x + 1] == 'D') {
				std::cout << "500 \"D\". ���������� ��������� 100 \"C\" 500 \"D\" 10 \"X\" 100 \"C\".";
			}
			if (nums[x + 1] == 'M') {
				std::cout << "1000 \"M\". ���������� ��������� 100 \"C\" 1000 \"M\" 10 \"X\" 100 \"C\".";
			}
			return 1;
		}
		if (nums[x] == 'L' && (nums[x + 1] == 'C' || nums[x + 1] == 'D' || nums[x + 1] == 'M')) {
			std::cout << "����� 50 \"L\" ���������� ������� �� ����� ";
			if (nums[x + 1] == 'C') {
				std::cout << "100 \"C\". ��� ��� ��������� ����� ����� 50 \"L\".";
			}
			if (nums[x + 1] == 'D') {
				std::cout << " 500 \"D\". ���������� ��������� 100 \"C\", 500 \"D\", 50 \"L\".";
			}
			if (nums[x + 1] == 'M') {
				std::cout << "500 \"M\". ���������� ��������� 100 \"C\", 1000 \"M\", 50 \"L\".";
			}
			return 1;
		}
		if (nums[x] == 'D' && nums[x + 1] == 'M') {
			std::cout << "����� 500 \"D\" �� 1000 \"M\" ������� ����������, ����� 500 \"D\" ���� ���� �� ����.";
			return 1;
		}
		if (nums[x] == 'V' && nums[x + 1] == 'V') {
			std::cout << "����� 5 \"V\" � 5 \"V\" ���������� �������, ����� 10 \"X\" ���� ���� �� ����.";
			return 1;
		}
		if (nums[x] == 'L' && nums[x + 1] == 'L') {
			std::cout << "����� 50 \"L\" � 50 \"L\" ���������� �������, ����� 100 \"C\" ��� ���� �� ����.";
			return 1;
		}
		if (nums[x] == 'D' && nums[x + 1] == 'D') {
			std::cout << "����� 500 \"D\" � 500 \"D\" ���������� �������, ����� 1000 \"M\" ���� ���� �� ����.";
			return 1;
		}
		if ((nums[x] == 'I' || nums[x] == 'X' || nums[x] == 'C' || nums[x] == 'M') && (nums[x] == nums[x + 1] && nums[x + 1] == nums[x + 2] && nums[x + 2] == nums[x + 3])) {
			std::cout << "����� 1 \"I\", 10 \"X\", 100 \"C\" ���������� ������� ����� 3�� ���. ���������� ��������� 4 \"IV\", 40 \"XL\", 400 \"CD\".";
			return 1;
		}
	}
	return 0;
}

void result(const char* nums, int res) {
	int units = res % 10;
	int dozens = res / 10 % 10;
	int hundreds = res / 100 % 10;
	int thousands = res / 1000;
	if (res > 999) {
		for (int x = 0; x < thousands; x++) {
			std::cout << nums[6];
		}
		std::cout << " = " << thousands * 1000 << " ";
	}

	if (res > 99) {
		if (hundreds != 0) {
			if (hundreds == 9) {
				std::cout << nums[4] << nums[6];
				std::cout << " = " << hundreds * 100 << " ";
			}
			if (hundreds >= 5 && hundreds < 9) {
				std::cout << nums[5];
				for (int x = 0; x < hundreds % 5; x++) {
					std::cout << nums[4];
				}
				std::cout << " = " << hundreds * 100 << " ";
			}
			if (hundreds == 4) {
				std::cout << nums[4] << nums[5];
				std::cout << " = " << hundreds * 100 << " ";
			}
			else if (hundreds < 4) {
				for (int x = 0; x < hundreds; x++) {
					std::cout << nums[4];
				}
				std::cout << " = " << hundreds * 100 << " ";
			}
		}
	}

	if (res > 9) {
		if (dozens != 0) {
			if (dozens == 9) {
				std::cout << nums[2] << nums[4];
				std::cout << " = " << dozens * 10 << " ";
			}
			if (dozens >= 5 && dozens < 9) {
				std::cout << nums[3];
				for (int x = 0; x < dozens % 5; x++) {
					std::cout << nums[2];
				}
				std::cout << " = " << dozens * 10 << " ";
			}
			if (dozens == 4) {
				std::cout << nums[2] << nums[3];
				std::cout << " = " << dozens * 10 << " ";
			}
			else if (dozens < 4) {
				for (int x = 0; x < dozens; x++) {
					std::cout << nums[2];
				}
				std::cout << " = " << dozens * 10 << " ";
			}
		}
	}

	if (res > 0) {
		if (units != 0) {
			if (units == 9) {
				std::cout << nums[0] << nums[2];
				std::cout << " = " << units << " ";
			}
			if (units >= 5 && units < 9) {
				std::cout << nums[1];
				for (int x = 0; x < units % 5; x++) {
					std::cout << nums[0];
				}
				std::cout << " = " << units << " ";
			}
			if (units == 4) {
				std::cout << nums[0] << nums[1];
				std::cout << " = " << units << " ";
			}
			else if (units < 4) {
				for (int x = 0; x < units; x++) {
					std::cout << nums[0];
				}
				std::cout << " = " << units;
			}
		}
	}
}

int romanToArabic() {
	std::string inNum = "";
	int outNum = 0;	

	std::cout << "������� ������� ����� / h - ������� / 0 - ���������: ";
	std::cin >> inNum;

	if (inNum == "h") {
		system("cls");		
		std::cout << "Symbol\tValue\nI\t1\nV\t5\nX\t10\nL\t50\nC\t100\nD\t500\nM\t1000" << std::endl << std::endl;
		std::cout << "������� ������� ����� / 0 - ���������: ";
		std::cin >> inNum;
	}

	if (inNum == "0") {
		system("cls");
		return 0;
	}

	system("cls");

	int size = inNum.length();

	for (int x = 0; x < size; x++) {
		inNum[x] = static_cast<char>(toupper(inNum[x]));
	}

	char* checkArray = new char[size];
	for (int x = 0; x < size; x++) {
		checkArray[x] = static_cast<char>(inNum[x]);
	}
	if (isWrong(checkArray, size)) {
		std::cout << "��� ����� ������� �����, ���:";
		for (int x = 0; x < size; x++) {
			int check = 0;
			for (int y = 0; y < checkSize; y++) {
				if (checkArray[x] == checkNumbers[y]) {
					check++;
					break;
				}
			}
			if (check == 0) {
				std::cout << ' ' << checkArray[x];
			}
		}
		std::cout << std::endl << std::endl;
		delete[] checkArray;
		return 0;
	}


	std::cout << "���� �����: ";
	for (int x = 0; x < size; x++) {
		std::cout << inNum[x];
	}
	std::cout << std::endl;

	if (isNotValid(checkArray, size)) {
		std::cout << std::endl << std::endl;
		delete[] checkArray;
		return 0;
	}


	delete[] checkArray;
	size--;
	for (int x = 0; x <= size; x++) {
		outNum += countToArabic(inNum[x], inNum[x + 1], size, x);
	}

	std::cout << "�������� �����: " << outNum << std::endl;

	std::cout << "������� ����� ������� ��: ";
	result(checkNumbers, outNum);

	std::cout << std::endl << std::endl;
}
int arabicToRoman() {
	int inNum = 0;
	std::string outNum = "";

	while (true) {
		std::cout << "������� �������� ����� (�� 1 �� 3999) / 0 - ���������: ";
		std::cin >> inNum;
		system("cls");		
		if (std::cin.fail()) {
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<int>::max(), '\n');
			std::cout << "���������� ������ �����!\n";
		}
		else if (!(inNum >= 0 && inNum < 4000)) {
			std::cout << "����� �� � ���������!\n";
		}
		else break;
	}
	
	if (inNum == 0) {
		return 0;
	}

	std::cout << "���� �������� �����: " << inNum << std::endl;

	
	std::cout << "������� �����: ";
	countToRoman(checkNumbers, inNum);
	std::cout << std::endl;

	std::cout << "������� ����� ������� ��: ";
	result(checkNumbers, inNum);

	std::cout << std::endl << std::endl;
}

int main() {

	setlocale(LC_ALL, "Russian");
	
	while (true) {	
		int act = start();
		if (act == 1) {
			romanToArabic();
		}
		else if (act == 2) {
			arabicToRoman();
		}
		else if (act == 3) {
			break;
		}

	}

}