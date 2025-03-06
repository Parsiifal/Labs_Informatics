#include <iostream>
#include <string>
#include <iomanip>	// различные манипуляторы для потоков ввода/вывода;

using namespace std;

int check_inteSec(int min, string strngln)		
{	
	string x;
	cout << strngln << "\n";
	getline(cin, x);
	
	while (x.empty())
	{
		cout << "\nYou entered an empty string! Repeat the input!\n" << endl;;
		getline(cin, x);		
	}

	int i = 0;
	for (i = 0; i < x.length(); i++) // идем по символам и делаем проверку каждого
	{
		while (isalpha(x[i]) || (x[i] >= ' ' && x[i] <= '/' && x[i] != '-') || (x[i] >= ':' && x[i] <= '@') || (x[i] >= '[' && x[i] <= '`') || (x[i] >= '{' && x[i] <= '~') || (x[i] = '\t') || stoi(x) < min)
		{
			cout << "\n\nA letter, space, or special character is detected, or you have entered an invalid value! Repeat the input!\n" << endl;
			i = 0;
			getline(cin, x);
			
			while (x.empty())
			{
				cout << "\nYou entered an empty string! Repeat the input!\n" << endl;
				getline(cin, x);
				
			}

		}

	}
	
	int res = stoi(x);
	return res;

}


int main()
{
	char ans;
	cout << "\nTIME FORMATTER\n";
	do
	{
		
		int eSec = check_inteSec(0, "\nInput the number of seconds: \n");	// ввод кол-ва секунд с проверкой ввода;

		int sec0, sec, mins, hours;

		hours = eSec / 3600;			// математические расчеты;
		sec0 = eSec - 3600 * hours;
		mins = sec0 / 60;
		sec = sec0 - mins * 60;

		// вывод результата в формате чч:мм:сс с использованием setw(2) для задания ширины вывода знаков (2 знака) и setfill('0') для изменения символа заполнения на 0.

		cout << "\nThis equals: " << setw(2) << setfill('0') << hours << ":" << setw(2) << setfill('0') << mins << ":" << setw(2) << setfill('0') << sec;

		cout << "\n\nIf you want to repeat the execution of the program, press y! The program will end if you press any other symbol!\n"; 
		cin >> ans;
		cin.ignore(10000, '\n');

	} while (ans == 'y');

}
