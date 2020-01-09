#include <iostream>
#include <windows.h>
#include <cstdlib>
#include <ctime>
#include <string>

using namespace std;

//int rand_0toN1(int F);

int main()
{
	bool gameloop = true;

	int Food_level = 10, Water_level = 10;
	int Beg_skill, People_choices;
	double Thieve_chances, Thieve_item;
	int Days_survived = 0;
	int Money_checker = 0;
	int Money_amount = 0;
	string c, sc, thieve; //C = Choice -- SC = Seacond Choice -- thieves = thievery strings

	srand(time(NULL)); //set seed for random numberss
	Beg_skill = (rand() % 20) + 1;
	Thieve_chances = (rand() % 20) + 1;
	Thieve_item = (rand() % 4) + 1;
	People_choices = (rand() % 2) + 1;

	cout << "Hello There, Lets get straight to the point. You are homeless in the streets of New York\n";
	cout << "Yeah it sucks I know\n";
	cout << "You will have to survive the streets\n";
	cout << "If you ever need help with the commands please type help\n";
	cout << "\n";
	cin >> c;

	while (gameloop) {
		//-------------Help Menu----------------
		if (c == "help") {
			cout << "\n";
			cout << "Here are the basic commands of the Game\n";
			Sleep(50);
			cout << "beg--To Beg what did you expect\n";
			Sleep(50);
			cout << "levels--To Check your hunger and water levels (if any of your levels reaches 0 you DIE!!!)\n";
			Sleep(50);
			cout << "steal--To Steal (will open a window for more commands)\n";
			Sleep(50);
			cout << "die--this command will kill your character \n";
			cout << "\n";
			cin >> c;
		}
		
		if (c == "die") {
			Food_level = 0;
		}
		//-------------Levels Checker----------------
		if (c == "levels" && Money_checker == 1) {
			cout << "\n";
			cout << "Your Water level is " << Water_level << endl;
			Sleep(50);
			cout << "Your Hunger level is " << Food_level << endl;
			Sleep(50);
			cout << "You Have currently survived for " << Days_survived << " days\n";
			Sleep(50);
			cout << "Your money totals up to " << Money_amount << endl;
			Sleep(50);
			cout << "\n";
			cin >> c;
		}
		if (c == "levels") {
			cout << "\n";
			cout << "Your Water level is " << Water_level << endl;
			Sleep(50);
			cout << "Your Hunger level is " << Food_level << endl;
			Sleep(50);
			cout << "You Have currently survived for " << Days_survived << " days\n";
			Sleep(50);
			cout << "\n";
			cin >> c;
		}
		//-------------Begging----------------
		if (c == "beg" && Beg_skill >= 18) {  //10% chance
			cout << "Your Beggging Payed of and A Kind Person Gave You Water and Food\n";
			cout << "\n";
			Beg_skill = (rand() % 10) + 1;
			Days_survived++;
			cin >> c;
		}
		if (c == "beg" && Beg_skill >= 13 && Beg_skill <= 17 && People_choices == 1) {  // 20% chance
			cout << "Your Beggging Payed of and A Kind Person Gave You Food\n";
			cout << "\n";
			Beg_skill = (rand() % 20) + 1;
			People_choices = (rand() % 3) + 1;
			Days_survived++;
			Water_level--;
			cin >> c;
		}
		if (c == "beg" && Beg_skill >= 13 && Beg_skill <= 17 && People_choices == 2) {  // 20% chance
			cout << "Your Beggging Payed of and A Kind Person Gave You Water\n";
			cout << "\n";
			Beg_skill = (rand() % 20) + 1;
			People_choices = (rand() % 3) + 1;
			Days_survived++;
			Food_level--;
			cin >> c;
		}
		if (c == "beg" && Beg_skill >= 3 && Beg_skill <= 13) {  // 50% chance
			cout << "Sadly your begging did not get you anything\n";
			cout << "\n";
			Beg_skill = (rand() % 20) + 1;
			People_choices = (rand() % 3) + 1;
			Days_survived++;
			Food_level--;
			Water_level--;
			cin >> c;
		}

		//-------------Specialty Items in begging----------------
		if (c == "beg" && Beg_skill >= 13 && Beg_skill <= 17 && People_choices == 3) {  // 20% chance
			cout << "A Kind Person came by you and game you some money\n";
			cout << "(you can use money to buy either food or water by using the \"buy water/food\" command\n";
			cout << "\n";
			Beg_skill = (rand() % 20) + 1;
			People_choices = (rand() % 3) + 1;
			Days_survived++;
			Food_level--;
			Water_level--;
			Money_checker++;   //if this value is 1 then it should open new options in the levels menu
			Money_amount++;
			cin >> c;
		}
		if (c == "beg" && Beg_skill == 2) {  // 5% chance
			cout << "You get noticed by some person who gives you a soda\n";
			cout << "(Items like Soda gives you +2 Water)\n";
			cout << "\n";
			Beg_skill = (rand() % 20) + 1;
			People_choices = (rand() % 3) + 1;
			Days_survived++;
			Food_level--;
			Water_level += 2;
			cin >> c;
		}
		if (c == "beg" && Beg_skill == 1) {  // 5% chance
			cout << "You get noticed by some person who gives you a Pizza\n";
			cout << "(Items like Pizza gives you +2 Food)\n";
			cout << "\n";
			Beg_skill = (rand() % 20) + 1;
			People_choices = (rand() % 3) + 1;
			Days_survived++;
			Food_level += 2;
			Water_level--;
			cin >> c;
		}
		//-----------------Thievery--------------------
		if (c == "steal") {
			cout << "What would you like to steal from? (gas station-1)\n";
			cin >> thieve;
			if (thieve == "1" && Thieve_chances >= 8 && Thieve_chances <= 14) { // 30% chance
				cout << "\n";
				cout << "You have chosen the gas station\n";
				cout << "You manage to sneak a few waterbottle into your pocket\n";
				Water_level += 3;
				Thieve_chances = (rand() % 20) + 1;
				cout << "\n";
				cin >> c;
			}
			if (thieve == "1" && Thieve_chances >= 14 && Thieve_chances <= 20) {   // 30% chance
				cout << "\n";
				cout << "You have chosen the gas station\n";
				cout << "You manage to sneak a few sandwich into your pocket\n";
				Food_level += 3;
				Thieve_chances = (rand() % 20) + 1;
				cout << "\n";
				cin >> c;
			}
			if (thieve == "1" && Thieve_chances >= 1 && Thieve_chances <= 8) {   // 40% chance
				cout << "You get noticed trying to sneak food into your pocket and get arrested\n";
				Thieve_chances = (rand() % 20) + 1;
				cout << "\n";
				cout << "GAME OVER\n";
				cout << "You Survived " << Days_survived << " Days\n";
				Sleep(1200);
				cout << "Would you like to start over? (yes/ no)\n";
				cin >> sc;
				if (sc == "no" || sc == "n") {
					cout << "Thankyou For Playing Hobo Life\n";
					gameloop = false;
					break;
				}
				if (sc == "yes" || sc == "y") {
					gameloop = true;
					Food_level = 10;
					Water_level = 10;
					Days_survived = 0;
					Money_checker = 0;
					Money_amount = 0;
					cout << "\n";
					cout << "You wake up on a park bench in the early hours of New York\n";
					cout << "Better start begging";
					cout << "\n";
					cin >> c;
				}
				else {
					cout << "Invalid Input\n";
					cout << "\n";
					cin >> sc;
				}
			}
		}
		//-------------Invalid Input-------------------
		if (c != "beg" && c != "levels" && c != "steal" && thieve != "1" && c != "die" && c != "help") {
			cout << "Invalid Input\n";
			cout << "\n";
			cin >> c;
		}

		//-------------------Death---------------------
		if (Food_level == 0 || Water_level == 0) {
			cout << "\n";
			cout << "\n";
			cout << "You died\n";
			cout << "You Survived " << Days_survived << " Days\n";
			Sleep(1200);
			cout << "Would you like to start over? (yes/ no)\n";
			cin >> sc;
			if (sc == "no" || sc == "n") {
				cout << "Thankyou For Playing Hobo Life\n";
				gameloop = false;
				break;
			}
			else if (sc == "yes" || sc == "y"){
				gameloop = true;
				Food_level = 10;
				Water_level = 10;
				Days_survived = 0;
				Money_checker = 0;
				Money_amount = 0;
				cout << "\n";
				cout << "You wake up on a park bench in the early hours of New York\n";
				cout << "Better start begging";
				cout << "\n";
				cin >> c;
			}
			else {
				cout << "Invalid Input\n";
				cout << "\n";
				cin >> sc;
			}
		}
	}
	return 0;
}