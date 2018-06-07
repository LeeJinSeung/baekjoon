	#include <iostream>
	#include <cmath>
	using namespace std;
	int main()
	{
		int arr[5];
		for (int i = 0; i < 5; ++i)
		{
			cin >> arr[i];
		}

		for (int i = 0; i < 4; ++i)
		{
			for (int j = 0; j<4 - i; ++j)
				if (arr[j] > arr[j + 1])
				{
					int swap;
					swap = arr[j];
					arr[j] = arr[j + 1];
					arr[j + 1] = swap;
					for (int k = 0; k < 5; ++k)
					{
						cout << arr[k] << " ";
					}
					cout << endl;
				}
		}

		system("pause >> null");
		return 0;
	};
