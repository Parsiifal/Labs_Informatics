#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

int check_input(string msg)
{
	int res;
	string inp;
	bool state = true;
	cout << msg;

	while (state)
	{
		getline(cin, inp);
		try
		{
			res = stoi(inp);
			if (inp.size() == to_string(res).size() && res < 10000000 && res > -10000000)
			{
				state = false;
				return res;
			}
			else
				cout << "\nError! Repeat the input!\n";

		}
		catch (invalid_argument)
		{
			cout << "\nError! Repeat the input!!!\n";
		}

	}

}

char check_Y_N(string str) // Y и N
{
	cout << str;
	string inp;
	bool state = true;

	while (state)
	{
		getline(cin, inp);
	
		if (inp.size() == 1 && (inp[0] == 'Y' || inp[0] == 'N'))
		{
			state = false;
			return inp[0];
		}
		else
			cout << "\nError! Repeat the input!\n";	
	}

}

void input_values(int& a, int& b, int& c, int& d, int& e, int& f)
{
	a = check_input("\nInput a(1, 1): ");
	b = check_input("Input a(1, 2): ");
	c = check_input("Input a(2, 1): ");
	d = check_input("Input a(2, 2): ");
	e = check_input("Input b(1): ");
	f = check_input("Input b(2): ");
}

void calculations(int a, int b, int c, int d, int b1, int b2)
{
	double x, y;
	double determinant = a * d - b * c;
	double det1 = b1 * d - b * b2;
	double det2 = a * b2 - b1 * c;

	if (determinant == 0 && (det1 !=0 || det2 != 0)) // нет решений
		cout << "\nNo solution!\n";
	else if (determinant == 0 && (det1 == 0 && det2 == 0)) // беск много решений
		cout << "\nInfinite solutions!\n";
	else
	{
		x = det1 / determinant;
		y = det2 / determinant;		
		cout << fixed << setprecision(1) << "\n(" << x << ", " << y << ")" << endl;
	}

}

int main()
{
	char ans;
	cout << "\nSystem of linear equations solver\n";

	do
	{
		int a11, a12, a21, a22, b1, b2;

		input_values(a11, a12, a21, a22, b1, b2);
		calculations(a11, a12, a21, a22, b1, b2);

		ans = check_Y_N("\nContinue? (Y/N): ");

	} while (ans == 'Y');

}