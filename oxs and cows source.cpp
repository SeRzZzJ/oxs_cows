
// CPP.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "../../std_lib_facilities.h"

int main()
{
	srand(static_cast<unsigned int>(time(0)));
	vector<int> user_num(4);
	vector<int> my_num(4);
	bool menu = 1;
	bool game = 1;
	cout << "Welcome in the game Oxs and Cows " << endl;

	while (menu) {
		bool repeat_my_num = 0;
		game = 1;
		for (int i = 0; i < my_num.size(); i++) {
			my_num[i] = 0 + rand() % 9;
		}
		for (int i = 0; i < user_num.size(); i++) {
			for (int j = i + 1; j < user_num.size(); j++) {
				if (my_num[i] == my_num[j]) {
					repeat_my_num = 1;
					break;
				}
			}
		}
		if (repeat_my_num == 1) {
			continue;
		}
		//cout << my_num[0] << ", ";
		//cout << my_num[1] << ", ";
		//cout << my_num[2] << ", ";
		//cout << my_num[3] << ", ";
		while (game) {
			int num;
			int ox = 0;
			int cow = 0;
			bool repeat_user_num = 0;
			cout << "Enter the numbers: ";
			cin >> num;
			user_num[0] = (num % 10000) / 1000;
			user_num[1] = (num % 1000) / 100;
			user_num[2] = (num % 100) / 10;
			user_num[3] = num % 10;
			for (int i = 0; i < user_num.size(); i++) {
				for (int j = i + 1; j < user_num.size(); j++) {
					if (user_num[i] == user_num[j]) {
						cout << "Enter please another the number!" << endl;
						repeat_user_num = 1;
						break;
					}
				}
			}

			if (repeat_user_num == 1) {
				continue;
			}

			for (int i = 0; i <= my_num.size() - 1; i++) {
				if (user_num[i] == my_num[i]) ox++;
			}
			for (int i = 0; i < my_num.size(); i++) {
				for (int j = 0; j < my_num.size(); j++) {
					if (user_num[i] == my_num[j]) cow++;
					//cout << "user_num = " << user_num[i] << "	";
					//cout << "my_num = " << my_num[j] << endl;
				}
			}
			//cout << "Cows = " << cow - ox << " " << "Oxs = " << ox << endl;
			cout << "Oxs = " << ox << " " << "Cows = " << cow - ox << endl;
			if (ox == 4) {
				cout << "Excellent! You win!!!" << endl;
				cout << "Will you play yet? (1 or 0): ";
				cin >> menu;
				if (menu == 1) {
					game = 0;
					//my_num.clear();
					
				}
				else {
					cout << "Good luck! Goodbye!";
					menu = 0;
					game = 0;
				}
			}
		}
	}
	return 0;
}

