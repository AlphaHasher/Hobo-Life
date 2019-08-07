#include <iostream>
#include <windows.h>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <conio.h>
#include <string>

using namespace std;

//int rand_0toN1(int F);

int main()
{
	bool gameloop = true;

	int F = 10, W = 10; //F = Food Level -- W = Water Level
	int BegS, PG; //BegS = Begging Skills -- PG = People Giving choices
	double thieveN, thieveI; //Thieve = Thievery -- thieveI = items you steal
	int D = 0;
	string c, sc, thieve; //C = Choice -- SC = Seacond Choice -- thieves = thievery strings

	srand(time(NULL)); //set seed for random numberss
	BegS = (rand() % 20) + 1;
	thieveN = (rand() % 20) + 1;
	thieveI = (rand() % 4) + 1;
	PG = (rand() % 2) + 1;

	cout << "Hello There, Lets get straight to the point. You are homeless in the streets of New York\n";
	cout << "Yeah it sucks I know\n";
	cout << "You will have to survive the streets\n";
	cout << "If you ever need help with the commands of this game please type !help\n";
	cout << "\n";
	cin >> c;

	while (gameloop) {
		if (c == "!help") {
			cout << "\n";
			cout << "Here are the basic commands of the Game\n";
			Sleep(50);
			cout << "beg--To Beg what did you expect\n";
			Sleep(50);
			cout << "levels--To Check your hunger and water levels (if any of your levels reaches 0 you DIE!!!)\n";
			Sleep(50);
			cout << "steal--To Steal (will open a window for more commands)\n";
			Sleep(50);
			cout << "gas station (low)--the risk is low but riases the more you steal\n";
			cout << "\n";
			cin >> c;
		}
		if (c == "levels") {
			cout << "Your Water level is " << W << endl;
			cout << "Your Hunger level is " << F << endl;
			cout << "You Have currenl survived for " << D << " days\n";
			cout << "\n";
			D++;
			cin >> c;
		}
		if (c == "beg" && BegS >= 18) {  //10% chance
			cout << "Your Beggging Payed of and A Kind Person Gave You Water and Food\n";
			cout << "\n";
			BegS = (rand() % 10) + 1;
			D++;
			cin >> c;
		}
		if (c == "beg" && BegS >= 13 && BegS <= 17 && PG == 1) {  // 20% chance
			cout << "Your Beggging Payed of and A Kind Person Gave You Food\n";
			cout << "\n";
			BegS = (rand() % 20) + 1;
			PG = (rand() % 2) + 1;
			D++;
			W--;
			cin >> c;
		}
		if (c == "beg" && BegS >= 13 && BegS <= 17 && PG == 2) {  // 20% chance
			cout << "Your Beggging Payed of and A Kind Person Gave You Water\n";
			BegS = (rand() % 20) + 1;
			PG = (rand() % 2) + 1;
			D++;
			F--;
			cin >> c;
		}
		if (c == "beg" && BegS >= 14 && BegS <= 17) {  // 15% chance
			cout << "A Kind Person came by you and game you some money\n";
			cout << "(you can use money to buy either food or water by using the \"buy water/food\" command\n";
			cout << "\n";
			BegS = (rand() % 20) + 1;
			PG = (rand() % 2) + 1;
			D++;
			F--;
			W--;
			cin >> c;
		}
		if (c == "beg" && BegS >= 3 && BegS <= 13) {  // 50% chance
			cout << "Sadly your begging did not get you anything\n";
			cout << "\n";
			BegS = (rand() % 20) + 1;
			PG = (rand() % 2) + 1;
			D++;
			F--;
			W--;
			cin >> c;
		}

		//-------------Specialty Items----------------
		if (c == "beg" && BegS == 2) {  // 5% chance
			cout << "You get noticed by some person who gives you a soda\n";
			cout << "(Items like Soda gives you +2 Water)\n";
			cout << "\n";
			BegS = (rand() % 20) + 1;
			PG = (rand() % 2) + 1;
			D++;
			F--;
			W += 2;
			cin >> c;
		}
		if (c == "beg" && BegS == 1) {  // 5% chance
			cout << "You get noticed by some person who gives you a Pizza\n";
			cout << "(Items like Pizza gives you +2 Food)\n";
			cout << "\n";
			BegS = (rand() % 20) + 1;
			PG = (rand() % 2) + 1;
			D++;
			F += 2;
			W--;
			cin >> c;
		}
		//-----------------Thievery--------------------

		if (c == "steal") {
			cout << "What would you like to steal from? (gas station-1)\n";
			cin >> thieve;
			if (thieve == "1" && thieveN >= 12 && thieveN <= 16) { // 30% chance
				cout << "You have chosen the gas station\n";
				cout << "\n";
				cout << "You manage to sneak a waterbottle into your pocket\n";
				thieveN = (rand() % 20) + 1;
				cout << "\n";
				cout << "Would you Like to test your chances and steal something else?\n";
				cin >> thieve;
			}
			if (thieve == "1" && thieveN >= 17 && thieveN <= 20) {   // 30% chance
				cout << "You manage to sneak a sandwich into your pocket\n";
				thieveN = (rand() % 20) + 1;
				cout << "\n";
				cout << "Would you Like to test your chances and steal something else?\n";
				cin >> thieve;
			}
			if (thieve == "1" && thieveN >= 1 && thieveN <= 11) {   // 40% chance
				cout << "You get noticed trying to sneak food into your pocket and get arrested\n";
				cout << "\n";
				cout << "GAME OVER\n";
				cout << "You Survived " << D << " Days\n";
				Sleep(1250);
				cout << "Would you like to start over? (yes/ no)\n";
				cin >> sc;
				if (sc == "no" || "n") {
					cout << "Thankyou For Playing Hobo Life\n";
					gameloop = false;
					break;
				}
				if (sc == "yes" || "n") {
					cout << "You find yourself on a park bench, its early morning. Better start begging\n";
					cin >> c;
				}
				else {
					cout << "Invalid Input\n";
					cin >> sc;
				}
			}
		}
		//-------------Invalid Input-------------------
		if (c != "beg" && c != "levels" && c != "steal" && thieve != "1") {
			cout << "Invalid Input\n";
			cin >> c;
		}

		//-------------------Death---------------------
		if (F == 1 || W == 1) {
			cout << "You died\n";
			cout << "You Survived " << D << " Days\n";
			Sleep(1250);
			cout << "Would you like to start over? (yes/ no)\n";
			cin >> sc;
			if (sc == "no" || "n") {
				cout << "Thankyou For Playing Hobo Life\n";
				gameloop = false;
				break;
			}
			if (sc == "yes" || "n"){
				cout << "You find yourself on a park bench, its early morning. Better start begging\n";
				cin >> c;
			}
			else {
				cout << "Invalid Input\n";
				cin >> sc;
			}
		}
	}
	return 0;
}