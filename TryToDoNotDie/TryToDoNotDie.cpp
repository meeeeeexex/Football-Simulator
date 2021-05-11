
#include <iostream>
#include <map>
#include <sstream>
#include <set>
#include <iomanip>
#include<vector>
#include<tuple>
#include<memory>
#include<unordered_map>
#include<fstream>
#include<ctime>
#include<algorithm>
using namespace std;
struct Name {
	string SurName;
	string  nname;
	string FathersName;
};
struct Goals {
	int scored_goals;
	int missed_goals;
};
bool MyFunc(pair<int, string> a, pair<int, string>  b) {
	return (a.first > b.first);
}
bool MyFuncSco(pair<Name, int> a, pair<Name, int>  b) {
	return (a.second > b.second);
}

bool MyFuncforTuple(tuple<int, string, int, int,int, int > a, tuple<int, string, int, int, int, int> b ) {
	if(get<0>(a) != get<0>(b))
	return (get<0>(a) > get<0>(b));
	else {
		return( get<5>(a) > get<5>(b));
	}
}
void CreateFuncFromidx(int idx) {
	switch (idx) {
	case 0:
		cout << "First tour  : \n";
		break;
	case 1:
		cout << "Second tour  : \n";
		break;
	case 2:
		cout << "Third tour  : \n";
		break;
	case 3:
		cout << "Fourth tour  : \n";
		break;
	case 4:
		cout << "Fifth tour  : \n";
		break;
	case 5:
		cout << "Sixth tour  : \n";
		break;
	case 6:
		cout << "Seventh tour  : \n";
		break;
	case 7:
		cout << "Eighth tour  : \n";
		break;
	case 8:
		cout << "Nineth tour  : \n";
		break;
	case 9:
		cout << " Tenth tour : \n";
		break;
	case 10:
		cout << "Eleventh tour  : \n";
		break;
	case 11:
		cout << " Twelfth tour  : \n";
		break;
	case 12:
		cout << " Thirteenth tour  : \n";
		break;
	case 13:
		cout << " Fourteenth tour  : \n";
		break;
	case 14:
		cout << " Fifteenth tour  : \n";
		break;
	case 15:
		cout << "Sixteenth tour  : \n";
		break;
	case 16:
		cout << "Seventeenth tour  : \n";
		break;
	case 17:
		cout << "Eighteenth tour  : \n";
		break;
	case 18:
		cout << "Nineteenth tour  : \n";
		break;
	}
}
vector<string> positions = { "GK" , "CB", "LB", "RB" , "LWB" , "RWB" ,"CDM" , "CM", "CAM", "CF","LM" ,"LW","RM","RW","ST" };
#include"Operator.h"
#include"TeamMember.h"

//#include"Player.h"
#include"Header.h"

#include"Coach.h"
#include"Manager.h"
#include"GLTransfer.h"
#include"TTeam.h"
#include"League.h"
#include"Standing.h"



bool operator >(const Team& lhs, const Team& rhs) {
	return lhs.GetPoints() > rhs.GetPoints();
}
bool operator <(const Team& lhs, const Team& rhs) {
	return lhs.GetPoints() < rhs.GetPoints();
}
bool operator ==(const Team& lhs, const Team& rhs) {
	return lhs.GetPoints() == rhs.GetPoints();
}

ifstream input("Teams.txt");
int main()
{
	srand(time(0));
	setlocale(LC_ALL, "Russian");
	try {

		League league;
		vector<Team>EPL;
		vector<string> teams_nicks, countries;
		vector<int>balances;
		vector<vector<Player>>players_overall;//каждая ячейка - отдельная команда 
		vector<Coach>coaches_overall;
		vector<Manager>managersoverall;
		while (!input.eof()) {

			bool f = true;
			for (int i = 0; i < 10; i++)
			{
				string nick, country;
				cout << nick;
				int balance;
				input >> nick >> country >> balance;
				bool f = true;
				vector<Player>ttmp;
				teams_nicks.push_back(nick);
				countries.push_back(country);
				balances.push_back(balance);


				for (int i = 0; i < 12; i++) {

					Name player_tmp;
					input >> player_tmp.SurName >> player_tmp.nname >> player_tmp.FathersName;
					if (player_tmp.FathersName == "A")
						player_tmp.FathersName = " ";
					int age, height, salary;
					input >> age >> height >> salary;
					string pos; input >> pos;
					int transfer_price;
					input >> transfer_price;

					Player p(player_tmp, age, height, salary, pos, transfer_price);
					ttmp.push_back(p);

				}
				players_overall.push_back(ttmp);
				Name coach_tmp;
				input >> coach_tmp.SurName >> coach_tmp.nname >> coach_tmp.FathersName;

				int y, h;
				input >> y >> h;
				int sall, exp_y;
				input >> sall >> exp_y;


				Coach coAch(coach_tmp, y, h, sall, exp_y);
				Manager manager(coach_tmp, y, h, sall);

				coaches_overall.push_back(coAch);
				managersoverall.push_back(manager);


			}


		}


		vector<vector<TeamMember*>>team_members;
		vector<TeamMember*> t;
		TeamMember* co = NULL;
		TeamMember* ma = NULL;
		TeamMember* pl = NULL;
		TeamMember* s = NULL;
		int amount_of_teams = managersoverall.size();
		for (int i = 0; i < amount_of_teams; i++) {
			co = &coaches_overall[i];
			t.push_back(co);
			ma = &managersoverall[i];
			t.push_back(ma);
			for (auto it = 0; it < 12; it++) {
				pl = &players_overall[i][it];
				t.push_back(pl);
			}
			team_members.push_back(t);
			t.clear();
		}

		for (int i = 0; i < team_members.size(); i++) {
			Team a(teams_nicks[i], countries[i], balances[i], team_members[i]);
			EPL.push_back(a);
			league.SetTEamToLeauge(a);
		}


		league.CreateLeague();

		enum Commands
		{
			CheckTeams,
			CheckTable,
			WatchNextTour,
			SimNextTour,
			CheckTopScorers,
			Transfers,
			AddMoneyToTeam,
			CheckTheB,
			CheckTheS,
			SimToTheEnd,
			CheckToTheEnd,
		};

		bool whatever = true;
		int tour_counter = 0;
		while (whatever)
		{
			
			cout << "Привет дорогой пользователь ,выбери что ты хочешь увидеть и введи соответсвующий номер , ";
			cout << " который находится напротив твоего желания\n0 - Посмотреть команды , какие учавствуют в турнире\n1 - Посмотреть турнирную таблицу\n"
				<< "2 - Посмотреть распиcание следующего тура\n3 - Посмотреть результаты текущего тура\n4 - Посмотреть список бомбардиров\n5 - Перейти в раздел трансферов\n" <<
				"6 - Добавить денег в бюджет любой команде\n7 - Помотреть баланс клуба\n8 - Посмотреть состав интересующей команды \n9 - Если просимулировать весь сезон , вплоть до его завершения\n"<<
				"10- Посмотреть расписание всех туров\n";
			int in_int;
			cin >> in_int;
			Commands in = static_cast<Commands>(in_int);
			if (in == CheckTeams)
			{
				league.PrintALlTheTeams();

			}
			else if (in == CheckTable)
			{
				if (!tour_counter)
					cout << "Турнирная таблица на старте чемпионата \n";
				else
					cout << "Турнирная таблица после " << tour_counter << " тура\n";
				league.PrintTablelaLeague();
			}
			else if (in == WatchNextTour)
				league.PrintTourByIdx(tour_counter);
			else if (in == SimNextTour)
			{
				league.ToursRealising(tour_counter);
				++tour_counter;
				if (tour_counter ==( league.GetAmountOfTeamsInLeague() - 1)*2) {
					league.ResultOfLeague();
					break;
				}
			}
			else if (in == CheckTopScorers) {
				league.PrintTopScorers();
			}
			else if (in == Transfers) {
				cout << "Нажмите 0 - Если Вы хотите посмотреть список уже осуществленных трансеров \nНажмите 1 - Если хотите осуществить любой трансфер\n";
				int inpit;
				cin >> inpit;
				switch (inpit)
				{
				case 0 : 
					GetAllTransferList();
					break;
				case 1 :
					league.PrintALlTheTeams();
					cout << endl << "Введите номер команды в которую  , вы хотели бы купить игрока\n";
					int trans_input;
					cin >> trans_input;
					cout << "\n Введите номер команды из которой хотите приобрести игрока \n";
					int from_team_input;
					cin >> from_team_input;
					if (from_team_input >= league.GetAmountOfTeamsInLeague() || trans_input >= league.GetAmountOfTeamsInLeague())
						cout << "Введите номер из перечиленных выше\n ";
					else {
						if (from_team_input == trans_input)
						{
							cout << "\nНельзя покупать и продавать футболистов из одной и той же команды\n";

						}
						else {
							league.CheckTheBalWithoutOtherInfo(trans_input);
							cout << "Выберите номер игрока , которого хотите приобрести\n\n";
							league.GetSquadWithPrice(from_team_input);
							int player_number;
							cin >> player_number;
							league.NewTransfer(from_team_input, trans_input, player_number);
						}

						if (league.GetAmountOfPlayersTeamssquad(from_team_input) < 11)
						{

							cout << "\n В команде "; cout << league.GetTeamNickByIdx(from_team_input) << " недостаточно игроков для продолжения участия в турнире"
								<< "\n Введите номер команды из которой хотите приобрести игрока для этой команды\n" << endl;
							league.PrintALlTheTeams();
							int capacity_input;
							cin >> capacity_input;
							if (from_team_input == capacity_input)
							{
								cout << "\nНельзя покупать и продавать футболистов из одной и той же команды поэтому мы выбрали команду за тебя\n";
								if (capacity_input)
									capacity_input = 0;
								else
									capacity_input = 1;
								
							}

							cout << "\n Выберите номер игрока , которого хотите приобрести\n";
							league.GetSquadWithPrice(capacity_input);
							int playe_input;
							cin >> playe_input;
							league.NewTransfer(capacity_input, from_team_input, playe_input);
						}
					}
					break;
				}
			}
			else if (in == AddMoneyToTeam) {
				league.PrintALlTheTeams();
				cout << endl << "Введите номер команды которой хотели бы начислить дополнительные финансы\n";
				int trans_input;
				cin >> trans_input;
				cout << endl << "Введите сумму , которую хотели бы начислить , она должна быть не больше чем 2 000 000 \n";
				int charity;
				cin >> charity;
				league.AddCharity(trans_input, charity);
			}
			else if (in == CheckTheB) {
				league.PrintALlTheTeams();
				int input_balance;
				cin >> input_balance;
				league.CheckTheTeamBalance(input_balance);
			}
			else if (in == CheckTheS) {
				league.PrintALlTheTeams();
				int input_team;
				cin >> input_team;
				league.GetTeamsquad(input_team);
			}
			else if (in == SimToTheEnd) {
			for (int i = tour_counter; i < (league.GetAmountOfTeamsInLeague() -1)*2; i++)
				{
				league.ToursRealising(i);
				}
			league.ResultOfLeague();
			break;
			}
			else if (in == CheckToTheEnd) {
			league.PrintAllthetours();
			}
			cout << "Если хотите продолжить введите любой символ, а если хотите закончить введите -  exit\n";
			string s_inp;
			cin >> s_inp;
			if (s_inp == "exit") {
				whatever = false;
				break;
			}
			}

			return 0;
		}

	




	catch (exception & e) {
		cout << e.what();
	}
} 
