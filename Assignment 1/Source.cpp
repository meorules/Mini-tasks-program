// Programmer: Mazen Omar
// Time of Submission: 4:50 AM Sunday, 17th November 2019
#include <iostream>;
#include <time.h>;
#include <string>;
#include <ctime>;
#include <vector>;


using namespace std;
//method used to initiate the keep counting game
void keepCounting();
// the function designed to provide addition questions in the keep counting game
int addNum(int pAnswer,int nAnswer,int counter);
//the function designed to provide subtraction questions in the keep counting game
int subNum(int pAnswer,int nAnswer,int counter);
//the main method used to call on and convert 3 different base number systems being denary, binary and hexa and their conversion to each other
void numberConversion();
//the method used to convert denary to binary and print it in different methods
void denaryToBinary(int denary);
//the method used to convert denary to hexa and print it in various methods
void denaryToHexa(int denary);
//the UPC generator takes any number of up to 6 digits and adds the check 7th digit to it whether there are 5 0s in the number or not
void upcGen();
//this method is used to split digits given to the upc generator and checker into seperate integers which can be manipulated
void splitDigit(int fullNumber,int size,int digits[]);
// this function uses the calculations found within the specifications to find the check digit for any number of up to 6 digits
int checkDigit(int digits[]);
// this method uses methods and functions above to recalculate the check digit and compare it to the check digit provided
void upcCheck();
// this function is sent invalid inputs and allows the user to continuously provide inputs until it is valid and matches the maxiumum number of options provided
int validateInput(int check,int max);
// this method is used in many places to allow for the program to be quite at any moment
void quitApplication();



int main() {
	bool run = true;
	//continuously running the main menu until the user exits the program
	srand((int)time(NULL));
	while (run == true) {
		//printing the various options available for the user
		cout << "Main Menu: \n 1)Keep Counting Game \n 2)Number Conversion Tool \n 3)Universal Product Code (UPC) Calculator \n 4)Universal Product Code (UPC) Checker \n 5)Quit  \n Please enter option: \n";
		int input;
		cin >> input;
		if (input > 5 || input < 1 || cin.fail()) {
			//making sure the user cannot provide an invalid option
			input=validateInput(input,5);
		}
		switch (input) {
		case 1:
			// calling the first application and stating it's name
			cout << "Keep Counting Game: \n";
			keepCounting();
			run = true;
			break;
		case 2:
			//calling the second application
			cout << "Number Conversion Tool: \n";
			numberConversion();
			run = true;
			break;
		case 3:
			//calling the third application
			cout << "Universal Product Code Calculator";
			upcGen();
			run = true;
			break;
		case 4:
			cout << "Universal Product Code Checker";
			//using the previous main application to cross check the 7th digit. 
			upcCheck();
			run = true;
			break;
		case 5:
			//quiting the application or making sure the user does not exist accidentally
			cout << "Quitting Application: \n";
			quitApplication();
			break;
			}
	}
	return 0;
}
void upcGen() {
	//asking for a 6 digit number, but being able currently accept any number and filling any previous numbers with 0
	cout << "Please enter a 6 digit number in order to add the 7th digit and complete the Universal Product Code: \n Any number less than 6 digits long will assume 0s where there are no digits: \n";
	int preUPC;
	cin >> preUPC;;
	int digits[6];
	if (preUPC > 999999)  {
		//making sure a number larger than 6 digits long cannot be used for calculations
		cout << "Please enter a valid number which is 6 digits or shorter \n";
	} 
	else {
		//splitting the digits one by one in the method and passing it back so that can be changed using the index of each number to be able to edit it more easily
		splitDigit(preUPC, 6, digits);
		// sending the array to find the check digit and adding it to the original number
		int check = checkDigit(digits);
		int final = (preUPC * 10) + check;
		cout << "The UPC is now " << final << "\n";
	}
}
void upcCheck() {
	//asking for a 7 digit number or anything less which will consider the last digit the "7th" digit and anything before the first digit which is empty 0
	cout << "Please enter a 7 digit number in order to check if the 7th digit is valid and therefore if the UPC is valid:\n (Any number less than 7 digits long will assume 0s infront of the number you input)\n";
	int digitToValidate;
	cin >> digitToValidate;
	if (digitToValidate > 9999999) {
		cout << "Please enter a valid 7 digit number or shorter \n";
	}
	else {
		int digits[7];
		//splitting the number into a predefined array in order to save more memory and allow for easier access
		splitDigit(digitToValidate, 7, digits);
		//sending to recieve the check digit and validatng that it is equal to or not equal to the original check digit. 
		int check = checkDigit(digits);
		if (check == digits[6]) {
			cout << "The check digit is valid and thus the UPC is valid.";
		}
		else {
			//asking if the user wants to convert another or the same number into an official upc
			cout << "The check digit is not valid and thus the UPC is also not valid. \n Would you like to calculate a valid UPC for this number?";
			bool run;
			do {
				string choice;
				cin >> choice;
				if (choice == "yes" || choice == "Yes") {
					upcGen();
					run = true;
				}
				else if (choice == "no" || choice == "No") {
					main();
					run = true;
				}
				else {
					cout << "Please enter a valid response(yes/no): \n";
					run = false;
				}
			} while (run == false);
		}
	}

}
void splitDigit(int fullNumber,int size,int digits[]) {
	int digit;
	//splitting the digits by dividing it by decreasing powers of 10 and modding it to get the remainder which becomes the digit to be added into the array
	for (int x = 0; x < size; x++) {
		digit = fullNumber / (pow(10, ((size-1) - x)));
		digits[x] = digit % 10;
	}
}
int checkDigit(int digits[]) {
	//taking the array and preforming all the neccessary calculations on the number as stated in the specifications
	int check;
	int oddTotal=0;
	int evenTotal = 0;
	for (int a = 0; a < 6; a = a + 2) {
		//finding odd total by adding the odd numbers together
		oddTotal = digits[a] + oddTotal;
	}
	//finding even total by adding the even numbers together
	for (int a = 1; a < 6; a = a + 2) {
		evenTotal = digits[a] + evenTotal;
	}
	// calculating the result variable accordingly and using modulus to find the check digit is neccessary
	int result = (oddTotal * 3) + evenTotal;
	if (result % 10 == 0) {
		check = 0;
	}
	else {
		check = 10 - (result % 10);
	}
	return check;
}

void numberConversion() {
	cout << "Please enter the option for what conversion you would like to make: \n 1)Denary to Binary & Hexa \n 2)Binary to Denary & Hexa \n 3)Hexa to Denary & Binary \n 4)Quit Applicaiton \n";
	int option;
	cin >> option;
	//making sure no invalid options are selected from above
	option = validateInput(option, 4);
	// a switch to decide what conversion the user wants to preform
	switch (option) {
	case 1: {
		cout << "Please enter the number you would like to convert into binary and hexadecimal: \n";
		int number;
		cin >> number;
		//preforming the methods stated below in order to convert the denary number into both binary and hexadecimal versions
		denaryToBinary(number);
		denaryToHexa(number);
		break;
	}
	case 2: {
		//accepting the binary number as a string input
		cout << "Please enter the binary number you would like to convert into denary and hexadecimal: \n";
		string binary;
		cin >> binary;
		//	A more advanced way to do it, but you said it was cheating , int denary = stoi(binary, 0, 2);
		int denary = 0;
		for (int x = 0; x < binary.size(); x++) {
			int parsing;
			//parsing the binary digits into ints without any outside functions
			if (binary.at(x) == '0') {
				parsing = 0;
			}
			else {
				parsing = 1;
			}
			//using the formula to turn binary digits into denary digits
			denary = ((pow(2, binary.size() - x - 1) * (parsing)) + denary);
		}
		cout << "Denary Version: \n" << denary << "\n";
		// using the denary digits found to find the hexadecimal version of the number
		denaryToHexa(denary);
		break;
	}
	case 3: {
		cout << "Please enter the hexadecimal number which you would like to convert into denary and binary: \n";
		string hexa;
		cin >> hexa;
		// also a more efficient method,but also too easy and using an outside function int denary2 = stoi(hexa, 0, 16);
		//converting all the hexa digits into denary numbers including the letters which makes their manipulation and display into binary and denary much simpler
		int denary2 = 0;
		int parsing = 0;
		for (int x = 0; x < hexa.size(); x++) {
			/* to turn the hexa characters into integers which can be manipulated. Unfortunateley, doing this with a for loop was initially a good idea, however,
			due to having to search through both the ASCII and actual number loops at the same time, the number of iterations was a lot more than doing 9 possible checks
			hence why the switch statement was used instead, and also the stoi statement was not. */
			switch (hexa.at(x)) {
			case '1':
				parsing = 1;
				break;
			case '2':
				parsing = 2;
				break;
			case '3':
				parsing = 3;
				break;
			case '4':
				parsing = 4;
				break;
			case '5':
				parsing = 5;
				break;
			case '6':
				parsing = 6;
				break;
			case '7':
				parsing = 7;
				break;
			case '8':
				parsing = 8;
				break;
			case '9':
				parsing = 9;
				break;
			case 'A':
				parsing = 10;
				break;
			case 'B':
				parsing = 11;
				break;
			case 'C':
				parsing = 12;
				break;
			case 'D':
				parsing = 13;
				break;
			case 'E':
				parsing = 14;
				break;
			case 'F':
				parsing = 15;
				break;
			}
			//calculating the amount of 16^x where x is the digit index +1 from the right 
			denary2 = ((pow(16, hexa.size() - x - 1) * (parsing)) + denary2);
		}
		cout << "Denary Version: \n" << denary2 << "\n";
		// using the method created to turn the denary value into a binary value
		denaryToBinary(denary2);
		break;
	}
	case 4: {
		quitApplication();
	}
	}
}
void denaryToHexa(int denary) {
	//spliting the denary number into a vector and storing it as characters
	vector<string> hexa;
	int remainder, quotient;
	do {
		//continuously dividing the number by 16 to find the remainder which would be the hexadecimal digit
		quotient = denary / 16;
		remainder = denary % 16;
		if (remainder > 9) {
			//converting any number above 9 into the following letters which are part of the hexadecimal code
			switch (remainder) {
			case 10:
				hexa.push_back("A");
				break;
			case 11:
				hexa.push_back("B");
				break;
			case 12:
				hexa.push_back("C");
				break;
			case 13:
				hexa.push_back("D");
				break;
			case 14:
				hexa.push_back("E");
				break;
			case 15:
				hexa.push_back("F");
				break;
			}
		}
		else {
			hexa.push_back(to_string(remainder));
		}
		denary = quotient;
	} while (quotient != 0);
	cout << "Hexadecimal Version: \n";
	//reversing the vector so that it is printed in the right order
	reverse(hexa.begin(), hexa.end());
	for (int x = 0; x < hexa.size(); x++) {
		//printing the hexadecimal number digit by digit
		cout << hexa.at(x);
	}
	cout << "\n";
}
void denaryToBinary(int denary) {
	//splitting the denary digit into a vector
	vector<int> binary;
	int remainder, quotient;
	do {
		//continuously dividing the numbers by 2 to find the remainders and set them as the seperate digits
		quotient = denary / 2;
		remainder = denary % 2;
		binary.push_back(remainder);
		denary = quotient;
	} while (quotient != 0);
	cout << "Binary Version: \n";
	//reversing the binary vector to make it print correctly
	reverse(binary.begin(), binary.end());
	for (int x = 0; x < binary.size(); x++) {
		//printing the binary number digit by digit
		cout << binary.at(x);
	}
	cout << "\n";
}

void keepCounting() {
	cout << "You will be shown a series of questions, these will include having either addition, subtraction or a mix of both question types.\n Each correct answer will be a part of the next question asked: \n Please pick an option from below: \n 1)Addition \n 2)Subtraction \n 3)Addition & Subtraction \n";
	int choice;
	cin >> choice;
label1:
	if (choice == 1 || choice == 2 || choice == 3 || choice == 4) {
		int answer;
		int pAnswer = 0;
		int nAnswer = 0;
		int counter = 1;
		int range = 9;
		time_t startTime;
		pAnswer = (rand() % 9) + 1;
		bool correct = true;
		while (correct == true && counter < 9) {
			correct = false;
			switch (choice) {
			case 1:
				startTime = time(0);
				nAnswer = addNum(pAnswer, nAnswer, counter);
				break;
			case 2:
				startTime = time(0);
				nAnswer = subNum(pAnswer, nAnswer, counter);
				break;
      case 3: {
        startTime = time(0);
        int randomise = rand() % 2;
        if (randomise == 1) {
          nAnswer = addNum(pAnswer, nAnswer, counter);
        }
        else {
          nAnswer = subNum(pAnswer, nAnswer, counter);
        }
      }
				break;
			case 4:
				quitApplication();
				break;
			}
			cin >> answer;
			if (answer == nAnswer) {
				correct = true;
				pAnswer = nAnswer;
				counter++;
			}
			else {
				correct = false;
				counter--;
			}
			
		}
		int finishTime = time(0) - startTime;
		if (counter == 0) {
			cout << "You answered 0/8  questions correctly in " << finishTime << " seconds. \n";

		}
		else {
			float timePerQuestion = finishTime / counter;
			cout << "You answered " << counter-1 << "/8 questions correctly in " << finishTime << " seconds which is an average of " << timePerQuestion << " seconds per question. \n";
		}
	}
	else {
		choice=validateInput(choice, 3);
		goto label1;
	}
}

int addNum(int pAnswer, int nAnswer,int counter) {
	int currentNumber = (rand() % 9) + 1;
	cout << "Question " << counter << ": " << pAnswer << " + " << currentNumber << " = ";
	nAnswer = pAnswer + currentNumber;
	return nAnswer;
}

int subNum(int pAnswer, int nAnswer,int counter) {
	int currentNumber = (rand() % 9) + 1;
	cout << "Question " << counter << ": " << pAnswer << " - " << currentNumber << " = ";
	nAnswer = pAnswer - currentNumber;
	return nAnswer;
}

int validateInput(int check,int max) {
	while (check > max || check < 1 || cin.fail()) {
		cin.clear();
		cin.ignore(INT_MAX , '\n');
		cout << "Please enter a valid option from above: \n";
		cin >> check;
	}
	return check;
}

void quitApplication() {
	bool run;
	cout << "Are you sure you want to quit?(yes/no)";
	do {
		string choice;
		cin >> choice;
		if (choice == "yes" || choice == "Yes") {
			exit(0);
			run = true;
		}
		else if (choice == "no" || choice == "No") {
			main();
			run = true;
		}
		else {
			cout << "Please enter a valid response(yes/no): \n";
			run = false;
		}
	} while (run == false);
	
}