#include <iostream>
using namespace std;

//function prototypes
void lottonumbers(int[]);
void bonusnumbers(int[]);
void usernumbers(int[]);
int checkNums(int[], int[], int[]);


int main()
{

	srand((int)time(0)); //To make sure there are new lottonumbers every time program is run

	int lotto[7], bonus[3], num[7];
	int i, j, a;
	int temp;

	cout << "Today in lottery grand prize is 1 200 000!";

	//Showing lottonumbers

	cout << "\nLottery numbers are: ";

	lottonumbers(lotto);

	//Showing bonusnumbers
	cout << "\nBonus numbers are: ";

	bonusnumbers(bonus);


	//sorting lottery numbers
	for (i = 0; i < 7; i++)
	{
		for (a = i + 1; a < 7; a++)
		{
			if (lotto[i] > lotto[a])
			{
				temp = lotto[i];
				lotto[i] = lotto[a];
				lotto[a] = temp;
			}
		}
	}

	//printing sorted lottery numbers
	cout << "\nLottery numbers from smallest to largest: " << endl;
	for (i = 0; i < 7; i++)
		cout << lotto[i] << " ";

	//sorting bonus numbers
	for (j = 0; j < 3; j++)
	{
		for (a = j + 1; a < 3; a++)
		{
			if (bonus[j] > bonus[a])
			{
				temp = bonus[j];
				bonus[j] = bonus[a];
				bonus[a] = temp;
			}
		}
	}
	//printing sorted bonus numbers
	cout << "\nBonus numbers from smallest to largest: " << endl;
	for (j = 0; j < 3; j++)
		cout << bonus[j] << " ";

	//Getting numbers from the user

	usernumbers(num);

	//Checking correct numbers

	checkNums(lotto, num, bonus);

	return 0;
}

//Getting lottery numbers
void lottonumbers(int lotto[]) {
	for (int i = 0; i < 7; i++)
	{
		int r;
		bool found = true;
		while (found) {
			found = false;
			r = rand() % 39 + 1; // Rand for lottery numbers
			for (int j = 0; j < i; j++)
			{
				if (r == lotto[j])
				{
					found = true;
					break;
				}
			}
		}
		cout << " " << r << " ";
		lotto[i] = r;
	}


}

//Getting bonus numbers
void bonusnumbers(int bonus[]) {
	for (int j = 0; j < 3; j++)
	{
		int e;
		bool found = true;
		while (found) {
			found = false;
			e = rand() % 39 + 1;
			for (int i = 0; i < j; i++)
			{
				if (e == bonus[i]) {
					found = true;
					break;
				}
			}
		}
		cout << " " << e << " ";
		bonus[j] = e;
	}
}

//Getting user numbers
void usernumbers(int num[])
{
	int check;
	int sum = 0;

start: cout << "\nDo you want to check your numbers? Press 1 for yes or 2 for no: ";
	cin >> check;
	// Making sure that wrong inputs don't crash the program
	while (cin.fail()) {
		cout << "Please enter 1 for yes or 2 for no: ";
		cin.clear();
		cin.ignore(256, '\n');
		cin >> check;

	}
	if (check != 1 && check != 2)
		goto start;

	if (check == 2)
		cout << "Have a nice day!\n";

	else
		cout << "Input your numbers :\n";

	for (int u = 0; u < 7; u++) { // For- loop to get 7 numbers from the user
		int lottery_number;

		cin >> lottery_number;
		// Making sure that wrong inputs don't crash the program
		while (cin.fail()) {
			cout << "Please enter a proper number ";
			cin.clear();
			cin.ignore(256, '\n');
			cin >> lottery_number;
		}

		num[u] = lottery_number;

	}
}

//checking users numbers
int checkNums(int lotto[], int num[], int bonus[])
{
	int nums = 0;
	int bonusnums = 0;

	//checking how many lotto numbers were correct
	for (int i = 0; i < 7; i++)
		for (int j = 0; j < 7; j++)
			if (lotto[i] == num[j])
				nums++;

	// Checking how many bonus numbers were correct
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 7; j++)
			if (bonus[i] == num[j])
				bonusnums++;


// Telling user how many numbers were correct
	cout << "You had " << nums << " correct lotto numbers and " << bonusnums << " correct bonus numbers" << endl;
	
	// Telling user how much they won
	if (nums == 7)
		cout << "You won the jackpot! Congratulations!";

	if (nums == 6)
		cout << "You won 2 275, 89 euros!";

	if (nums == 5)
		cout << "You won 55,90 euros!";

	if (nums == 4)
		cout << "You won 10 euros!";

	if ((nums == 6) && (bonusnums >= 1))
		cout << "You won 162 589,73 euros!";

	if ((nums == 3) && (bonusnums >= 1))
		cout << "You won 5 euros!";

	if ((nums <= 3))
		cout << "You didn't win. Better luck next time!";

	return bonusnums;
}
