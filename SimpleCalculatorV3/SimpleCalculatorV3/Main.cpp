#include <iostream>//Includes the premade library iostream that allows the functions cout and cin to work in the program.
#include <string> //Includes the premade library string that allows objects to be represented as a sequences of characters.

using namespace std; //Tells the complier to check the std namespace when resolving identifiers (like cout and cin) so we dont have to put std:: infront of them.

int main() //Initiates the main function of our code and is the main body of the code.
{ 
	int iNums; //Creates a variable iNums as an integer only variable. This is used in our code in multiple areas to determine how many numbers the user want to process.
	float fTotal; //Creates a variable fTotal as a float variable. This is used in our code in multiple areas to keep a total of the users inputed values.
	float fNum1; //Creates a variable fNum1 as a float variable. This is used universally through the code and is the main variable that stores the users input.
	float fNum2; //Creates a variable fNum2 as a float variable. This is used in our code for the subtraction and division and acts as the second input from the user.
	int iChoice; //Creates a variable iChoice as an integer only variable. This is used in our code for the menu selecion and stores the users input.
	bool bContinue = true; //Creates a variable bContinue as a boolean variable and is set to true. This allows our while loop to work, repeating the program until exited by the user.
	char cUserContinue; //Creates a variable cUserContinue as a character sequence variable. This is used only when the user chooses to exit the program, and stores the input of the user.

	cout << "Welcome to this Simple Calculator." << endl << endl;
	cout << " _____________________ " << endl;
	cout << "|  _________________  |" << endl;
	cout << "| | JAI          0. | |" << endl;
	cout << "| |_________________| |" << endl;
	cout << "|  ___ ___ ___   ___  |" << endl;
	cout << "| | 7 | 8 | 9 | | + | |" << endl;
	cout << "| |___|___|___| |___| |" << endl;
	cout << "| | 4 | 5 | 6 | | - | |" << endl;
	cout << "| |___|___|___| |___| |" << endl;
	cout << "| | 1 | 2 | 3 | | x | |" << endl;
	cout << "| |___|___|___| |___| |" << endl;
	cout << "| | . | 0 | = | | / | |" << endl;
	cout << "| |___|___|___| |___| |" << endl;
	cout << "|_____________________|" << endl; //Welcome message as user opens the program.

	do //Do While loop loops the program until the test expression is reached. In this case, until the boolean value of bContinue is changed to false.
	{
		cout << endl << endl << "Please choose what you would like to do:" << endl;
		cout << "1 - Add multiple numbers." << endl;
		cout << "2 - Subtract one number by the other." << endl;
		cout << "3 - Multiply multiple numbers." << endl;
		cout << "4 - Divide a number by another." << endl;
		cout << "5 - Calculate the mean of mutiple numbers." << endl;
		cout << "6 - Exit the program." << endl;
		cout << "Choice: "; //In program menu to allow user to see what they can do with the program.
		cin >> iChoice; //Allows the user to input data and stores this as the variable iChoice.
		
		//This while loop is used after all user inputs (except for cUserContinue) to check if the user has inputed the correct data type to match the the type of variable.
		while (1) //While loop that runs infinately.
		{
			if (cin.fail()) //If statement asking if the input data from the user does not comply with the variable type.
			{
				cin.clear(); //Clears the error flag on cin so operations can continue as normal.
				cin.ignore(numeric_limits<streamsize>::max(),'\n'); //Discards the users input and skips to the next line.
				cout << "You have not entered a valid choice. Please choose again: "; //Prompts user to input a new integer value for iChoice.
				cin >> iChoice; //Allows the user to input data and stores this as the variable iChoice.
			}
			else //Happens when the if statement is not met.
				break; //Breaks from the if loop and continues the program.
		} 
		//While loop was reasearched due to a bug when inputting a letter, the program would not function anymore, hence using the website http://www.cplusplus.com/, I was able to build working code.


		switch (iChoice) //Due to having six different option, rather than using a lot of if statements, a switch statemnet would be easier and better to use.
		{
		case 1:
			fTotal = 0;
			cout << endl << endl << "You have chosen Option 1 - Add multiple numbers.";
			cout << endl << "Please type the number of numbers to want to add together: ";
			cin >> iNums;
			while (1)
			{
				if (cin.fail())
				{
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
					cout << "You have not entered a valid choice. Please choose again: ";
					cin >> iNums;
				}
				else
					break;
			}
			for (int i = 0; i < iNums; i++)
			{
				cout << "Enter a number: ";
				cin >> fNum1;
				while (1)
				{
					if (cin.fail())
					{
						cin.clear();
						cin.ignore(numeric_limits<streamsize>::max(), '\n');
						cout << "You have not entered a valid choice. Please choose again: ";
						cin >> fNum1;
					}
					else
						break;
				}
				fTotal = fTotal + fNum1;
			}
			cout << endl << "The total of all those numbers is: " << fTotal << endl;
			break;

		case 2:
			cout << endl << endl << "You have chosen Option 2 - Subtract one number by the other.";
			cout << endl  << "Please type a number: ";
			cin >> fNum1;
			while (1)
			{
				if (cin.fail())
				{
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
					cout << "You have not entered a valid choice. Please choose again: ";
					cin >> fNum1;
				}
				else
					break;
			}
			cout << "Please type a number: ";
			cin >> fNum2;
			while (1)
			{
				if (cin.fail())
				{
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
					cout << "You have not entered a valid choice. Please choose again: ";
					cin >> fNum2;
				}
				else
					break;
			}
			cout << endl << fNum1 << " - " << fNum2 << " = " << (fNum1 - fNum2) << endl;
			break;

		case 3:
			fTotal = 1;
			cout << endl << endl << "You have chosen Option 3 - Multiple multiple numbers.";
			cout << endl << "Please type the number of numbers to want to multiply together: ";
			cin >> iNums;
			while (1)
			{
				if (cin.fail())
				{
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
					cout << "You have not entered a valid choice. Please choose again: ";
					cin >> iNums;
				}
				else
					break;
			}
			for (int i = 0; i < iNums; i++)
			{
				cout << "Enter a number: ";
				cin >> fNum1;
				while (1)
				{
					if (cin.fail())
					{
						cin.clear();
						cin.ignore(numeric_limits<streamsize>::max(), '\n');
						cout << "You have not entered a valid choice. Please choose again: ";
						cin >> fNum1;
					}
					else
						break;
				}
				fTotal = fTotal * fNum1;
			}
			cout << endl << "The product of all those numbers is: " << fTotal << endl;
			break;

		case 4:
			cout << endl << endl << "You have choosen Option 4 - Divide a number by another.";
			cout << endl << "Please type a number: ";
			cin >> fNum1;
			while (1)
			{
				if (cin.fail())
				{
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
					cout << "You have not entered a valid choice. Please choose again: ";
					cin >> fNum1;
				}
				else
					break;
			}
			cout << "Please type a number: ";
			cin >> fNum2;
			while (1)
			{
				if (cin.fail())
				{
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
					cout << "You have not entered a valid choice. Please choose again: ";
					cin >> fNum2;
				}
				else 
					break;
			}
			while (fNum2 == 0)
			{
				cout << "You cannot divide by 0. Please type another number: ";
				cin >> fNum2;
				while (1)
				{
					if (cin.fail())
					{
						cin.clear();
						cin.ignore(numeric_limits<streamsize>::max(), '\n');
						cout << "You have not entered a valid choice. Please choose again: ";
						cin >> fNum2;
					}
					else 
						break;
				}
			}
			cout << endl << fNum1 << " / " << fNum2 << " = " << (fNum1 / fNum2) << endl;
			break;

		case 5:
			fTotal = 0;
			cout << endl << endl << "You have choosen Option 5 - Calculate the mean of multiple numbers.";
			cout << endl << "Please type the number of numbers you want to find the mean for: ";
			cin >> iNums;
			while (iNums == 0)
			{
				cout << "You cannot find the mean for zero numbers. Please type the number of numbers you want to find the mean for: ";
				cin >> iNums;
				while (1)
				{
					if (cin.fail())
					{
						cin.clear();
						cin.ignore(numeric_limits<streamsize>::max(), '\n');
						cout << "You have not entered a valid choice. Please choose again: ";
						cin >> iNums;
					}
					else
						break;
				}
			}
			while (1)
			{
				if (cin.fail())
				{
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
					cout << "You have not entered a valid choice. Please choose again: ";
					cin >> iNums;
				}
				else 
					break;
			}
			for (int i = 0; i < iNums; i++)
			{
				cout << "Enter a number: ";
				cin >> fNum1;
				while (1)
				{
					if (cin.fail())
					{
						cin.clear();
						cin.ignore(numeric_limits<streamsize>::max(), '\n');
						cout << "You have not entered a valid choice. Please choose again: ";
						cin >> fNum1;
					}
					else 
						break;
				}
				fTotal = fTotal + fNum1;
			}

			cout << endl << "The mean of all those numbers is: " << (fTotal / iNums) << endl;
			break;

		case 6:
			cout << endl << endl << "You have choosen Option 6 - Exit the program.";
			cout << endl << "Are you sure you want to exit? (y/n) ";
			cin >> cUserContinue;
			if (cUserContinue == 'y')
			{
				cout << endl << endl << "Goodbye!" << endl << endl;
				cout << " _____________________ " << endl;
				cout << "|  _________________  |" << endl;
				cout << "| | OFF          0. | |" << endl;
				cout << "| |_________________| |" << endl;
				cout << "|  ___ ___ ___   ___  |" << endl;
				cout << "| | 7 | 8 | 9 | | + | |" << endl;
				cout << "| |___|___|___| |___| |" << endl;
				cout << "| | 4 | 5 | 6 | | - | |" << endl;
				cout << "| |___|___|___| |___| |" << endl;
				cout << "| | 1 | 2 | 3 | | x | |" << endl;
				cout << "| |___|___|___| |___| |" << endl;
				cout << "| | . | 0 | = | | / | |" << endl;
				cout << "| |___|___|___| |___| |" << endl;
				cout << "|_____________________|" << endl << endl; //Exit message as user opens the program.
				bContinue = false;
			}
		default:
			break;
		}


	} while (bContinue != false);

	system("pause");

	return 0;
}