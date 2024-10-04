#include <iostream>
#include <cmath>
#include <Windows.h>

using namespace std;

int main()
{
	double z;
	int a = 1, R1,R2,R3;
	while (a != 0)
	{
		try
		{
			cout << "Enter R1: ";
			cin >> R1;
			cout << "Enter R2: ";
			cin >> R2;
			cout << "Enter R3: ";
			cin >> R3;
			if ((R1 | R2 | R3) == 0)
			{
				throw std::logic_error("Divide-by-zero error.\n");
			}
			if ((R1 | R2 | R3) == 9999)
			{
				throw std::runtime_error("Some error.\n");
				break;
			}
			if ((R1 | R2 | R3) == 7777)
			{
				terminate();
			}
			z = cos(R1) / atan(R2 / R1) + R3;
			cout << "Answer: " << z << "\n0 - close program; 1 - continue.\nChoose: ";
			cin >> a;
		}
		catch (int)
		{
			cout << "Divisible 7777 cannot be entered.\n";
		}
		catch (std::logic_error e)
		{
			cout << "A logical error has occurred.\n";
		}
	}
	return 0;
}