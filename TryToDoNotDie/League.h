#pragma once

class League {
public:
	void AddCharity(const int team , const int money) {
		cout <<endl<< league[team].GetNick() << " with current ballance " << league[team].GetBalance()<<endl;
		league[team].SetMoney(money);

		cout <<endl<< league[team].GetNick() << " with  ballance after charity " << league[team].GetBalance()<<endl;
	}
	bool CheckTheCapacity()const {//кол-во игроков в команде дл€ контрол€ обьемов составов
		for (int i = 0; i < league.size();++i) {
			if (league[i].PlayersinTheTeam() < 11)
			{
				
				return  false;
			}
			return true;
		}
	}
	void FireSomeone(int team_in_league ,int someone) {
		league[team_in_league].Fire(someone);
	}
	void AddtoTeam(int team_in_league, int someone ,  int from_team) {
		league[team_in_league].AddToTeam(league[from_team].FindPLayerByIdx(someone));
	}
	void Minus(int idx, int money) {
		league[idx].Minusmoney(money);
	}

	void Add(int idx, int money) {
		league[idx].SetMoney(money);
	}

	int CheckThePrice(int team , int player) {
		return league[team].GetPriceByName(league[team].GetName(player));
	}
	void NewTransfer(int from_team_input, int trans_input, int player_number) {

		int price = CheckThePrice(from_team_input, player_number + 2);
		SetNewTransfer(league[from_team_input].FindPLayerByIdx(player_number + 2), league[from_team_input].GetNick(), league[trans_input].GetNick());
		AddtoTeam(trans_input, player_number + 2, from_team_input);
		FireSomeone(from_team_input, player_number + 2);
		/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		Minus(trans_input, price);//пердавать стоимость и все будет швепс
		Add(from_team_input, price);
		cout << "\n “рансфер " << GetThePlayerNameByIdx(trans_input, league[trans_input].PlayersinTheTeam()+1)/*-1 дл€ тим мембера и +2 дл€ тигроков , так как тренера и манагеры*/ << 
			" в  " << league[trans_input].GetNick()<<" со стоимостью "<<price<< " успешно окончен \n";
	}

	
	void ResultOfLeague() {
		cout << "–езультаты чемпионата : \n";
		PrintTablelaLeague();
		cout << endl;
		vector<tuple<string, int, int>>medalists = GetTop3();
		
		cout << "\t\t„емпионат окончен \n\t „емпионом стал : " << get<0>(medalists[0]) <<
			" набрав " << get<1>(medalists[0]) << " очков , с разницей забитых и пропущенных м€чей : " << get<2>(medalists[0])<<endl<<endl;

		cout << "\t¬торое место зан€ла команда : " << get<0>(medalists[1]) <<
			" набрав " << get<1>(medalists[1]) << " очков , с разницей забитых и пропущенных м€чей : " << get<2>(medalists[1]) << endl << endl;
		cout << " \t“ретье место зан€ла команда : " << get<0>(medalists[2]) <<
			" набрав " << get<1>(medalists[2]) << " очков , с разницей забитых и пропущенных м€чей : " << get<2>(medalists[2]) << endl << endl;

		cout << "\tЋучшим бомбардиром стал - "; PrintScorer();
	}
	const int GetAmountOfTeamsInLeague()const {
		return league.size();
	}
	Name GetThePlayerNameByIdx(const int team_ind , const int player_ind) {
		return league[team_ind].GetName(player_ind);
	}
	void SetTEamToLeauge(const Team& team) {
		league.push_back(team);
	}
	void GetTeamsStaff(const int ind) {
		league[ind].CheckTheStaff();
	}
	void GetTeamsquad(const int ind)const {
		league[ind].PrintPlayersWithIdx();
		
	}
	void GetSquadWithPrice(const int ind)const{
		league[ind].PrintPlayersAndPriceWithIdx();
	}
	const int  GetAmountOfPlayersTeamssquad(const int ind) {
		return league[ind].PlayersinTheTeam();
	}
	void SortLeague() {
		sort(league.begin(), league.end());
	}
	

	void PrintTablelaLeague() {
			vector<tuple<int, string,int,int,int,int>>vvv;//поинты, название , кол-во побед , поражений , ничьих , забитых и пропущеных голов
			for (auto i : league) {
				vvv.push_back(make_tuple(i.GetPoints(), i.GetNick(),i.GetWin(),i.GetLose(),i.GetDraw(),i.GetGoalDifference()));
			}
			sort(vvv.begin(), vvv.end(), MyFuncforTuple);
			
			string s = "Team name";
			int ms = 50 - s.size();
			cout << s << setw(ms) << "Points  W   L   D   Goal\n";
			for (auto i : vvv) {
				int sze = 30 - get<1>(i).size();
				cout << get<1>(i) << setfill('-') << setw(sze) << get<0>(i) << " | " <<
					get<2>(i);	(get<2>(i) > 9) ? cout << "| " : cout/*победы*/ << " | "; cout << get<3>(i); 

				(get<3>(i) > 9) ? cout << "| " : cout/*поражени€*/ << " | ";
				cout<< get<4>(i)
					<</*ничьи*/ " | ";
				if (get<5>(i) >= 0)
					cout << " ";
				cout<< get<5>(i)/*баланс*/ << endl;
			}
		
		}

	void SetLose(int idx) {
		
	}
	void SetWin(int idx) {
		league[idx].SetPoints_Win();
		
	}
	void SetDraw(int idx) {
		league[idx].SetPoints_Draw();
	}
	
	void PrintALlTheTeams()const {
		int counter = 0;
		for (auto i : league) {
			cout<<counter<< "  "  << i.GetNick() << endl;
			++counter;
		}
	}


	//поробовать реализовать таблицу как решение судоку через первичное рандомное генерирование матчей
	void PrintTopScorers() {
		cout << endl << "Top scorers : \n";
		vector<pair<int, string>>vv;
		for (auto i : top_scorer) {
			vv.push_back(make_pair(i.second, i.first.SurName));
		}
		sort(vv.begin(), vv.end(), MyFunc);
		
		for (auto i : vv) {
			cout << i.second << "- " << i.first << endl;
		}
		
		
	}
	void PrintScorer() {
		vector<pair<Name, int>>vv;
		for (auto i : top_scorer) {
			vv.push_back(make_pair(i.first, i.second));
		}
		sort(vv.begin(), vv.end(), MyFuncSco);

		for (auto i : vv) {
			cout << i.first << " забив " << i.second<<" голов \n";
			break;
		}
		}
	
	void CheckTheTeamBalance(int idx)const {
		cout<<league[idx].GetNick()<< " после "<<league[idx].GetPassedMatch()<<" сыгранных матчей  имеет на счету : "<< league[idx].GetBalance()<<endl;
	 }
	void CheckTheBalWithoutOtherInfo(int idx)const {
		cout <<endl<< league[idx].GetNick() <<" имеет на счету : " << league[idx].GetBalance() << endl;
	}
	string GetTeamNickByIdx(const int idx)const {
		return league[idx].GetNick();
	}
	const void PrintTourByIdx(int idx) const{

		cout << "________________________________________________\n";
		CreateFuncFromidx(idx);
		for (auto i : tour_safe[idx]) {
			cout << league[i.first].GetNick() << " vs " << league[i.second].GetNick() << endl;
		}

		cout << "________________________________________________\n";
	}
	void PrintAllthetours()const {
		for(int i = 0; i < tour_safe.size(); i++) {
			PrintTourByIdx(i);
		}
	}
	void ChangeBallance(int idx, int price) {
		league[idx].SetMoney(price);
	}

	void ToursRealising(int idx)  {
		vector < pair<pair<string, string>, pair<int, int>>> teams_and_their_score;
		vector<pair<string, string>>scorers;
		CreateFuncFromidx(idx);
	
		for (auto i : tour_safe[idx]) {
			
			pair<vector<int>, vector< int>>v11;
			int res1 = rand() % 5, res2 = rand() % 5;
			if (league[i.first].TeamsOverallPrice() > league[i.first].TeamsOverallPrice())
				res1++;
			else if (league[i.first].TeamsOverallPrice() < league[i.second].TeamsOverallPrice())
				res2++;
			league[i.first].SetNewMatch();
			league[i.second].SetNewMatch();
			
			teams_and_their_score.push_back(make_pair(make_pair(league[i.first].GetNick(), league[i.second].GetNick()), make_pair(res1, res2)));
		
			vector<int> tmp1, tmp2;
			for (int item = 0; item < res1; item++) {
				int scorere = /*int (amount of staff)*/2 + rand() % (league[i.first].AmountOfMembers()-2);
				league[i.first].SetGoalByIdx(scorere);
				tmp1.push_back(scorere);
				top_scorer[league[i.first].GetName(scorere)]++;
			}
			for (int item = 0; item < res2; item++) {
				int scorere = 2 + rand() % (league[i.second].AmountOfMembers()-2);
				league[i.second].SetGoalByIdx(scorere);
				tmp2.push_back(scorere);
				top_scorer[league[i.second].GetName(scorere)]++;
			}
			
			if (res1 > res2) {
				
				league[i.first].SetPoints_Win(); 
				league[i.first].SetWin();
				league[i.second].SetLose();
				
			}
			else if (res1 < res2) {
				league[i.second].SetPoints_Win();
				league[i.first].SetLose();
				league[i.second].SetWin();
			}
			else if (res1 == res2) {
				league[i.first].SetPoints_Draw();
				league[i.second].SetPoints_Draw();
				league[i.first].SetDraw();
				league[i.second].SetDraw();
			}
			league[i.first].TeamScoredGoals(res1);
			league[i.first].TeamMissedGoals(res2);
			league[i.second].TeamScoredGoals(res2);
			league[i.second].TeamMissedGoals(res1);
			cout << "Match " << league[i.first].GetNick() << " vs " << league[i.second].GetNick() << " ended with result : " << res1 << " : " << res2 << endl;


			if (!res1)
				cout << "Nobody scored goal for " << league[i.first].GetNick() << endl;
			else if (res1 == 1)
			{
				cout << "For " << league[i.first].GetNick() << " scored a goal "; league[i.first].PrintName(tmp1[0]); cout << endl;
			}
			else {
				cout << " For " << league[i.first].GetNick() << " goals scored : \n";
				for (auto it : tmp1) {
					league[i.first].PrintName(it); cout << endl;
				}
			}
			if (!res2)
				cout << "Nobody scored goal for " << league[i.second].GetNick() << endl;
			else if (res2 == 1)
			{
				cout << "For " << league[i.second].GetNick() << " scored a goal "; league[i.second].PrintName(tmp2[0]); cout << endl;
			}
			else {
				cout << "For " << league[i.second].GetNick() << " goals scored  : \n ";
				for (auto it : tmp2) {
					league[i.second].PrintName(it); cout << endl;
				}
			}
			cout << endl;

		}
		cout << endl << endl << endl;
		cout << "Short result of "; CreateFuncFromidx(idx);
		for (auto i : teams_and_their_score) {
			cout << i.first.first << "  vs " << i.first.second << setw(40 - (i.first.second.size() + i.first.first.size())) << "  (" << i.second.first << " : " 
				 << i.second.second << " )" << endl;
		}
		cout << endl;
	}
	
	void CreateLeague() {
		Create();
	}
	void PrintInfoAboutTeam(int idx)
	{
		league[idx].PrintPlayersWithIdx();
	}
private:
	vector<Team> league;
	vector<vector<pair<int, int>>>tour_safe;

	map<Name, int>top_scorer;



	vector<tuple<string, int, int>> GetTop3() {
		vector<tuple<string, int, int>> res;
		vector<tuple<int, string, int, int, int, int>>vvv;//поинты, название , кол-во побед , поражений , ничьих , забитых и пропущеных голов
		for (auto i : league) {
			vvv.push_back(make_tuple(i.GetPoints(), i.GetNick(), i.GetWin(), i.GetLose(), i.GetDraw(), i.GetGoalDifference()));
		}
		sort(vvv.begin(), vvv.end(), MyFuncforTuple);//переделать май функ
		for (auto i = 0; i < 3; i++) {
			res.push_back(make_tuple(get<1>(vvv[i]), get<0>(vvv[i]), get<5>(vvv[i])));

		}
		return res;

	}
	void CreateReverse() {
		vector<vector<pair<int, int>>> rev_safe;
		for (auto i : tour_safe) {
			vector<pair<int, int>>v;
			for (auto j : i) {
				v.push_back(make_pair(j.second, j.first));
			}
			rev_safe.push_back(v);
		}
		for (auto i : rev_safe) {
			tour_safe.push_back(i);
		}
	}
	void Create() {
			vector<pair<int, int>> v;
			for (int i = 0, j = 0; i < 5, j < 10; i++, j++) {
				int first = j;
				++j; int second = j;
				v.push_back(make_pair(first, second));
			}
		
			tour_safe.push_back(v);

			vector<pair<int, int>>v1;
				for (int i = 0; i < 10; i++) {
					if (i == 0 || i == 1 || i == 4) {
						v1.push_back(make_pair(i, i + 2));
					}
					else if (i == 7)
						v1.push_back(make_pair(i, i + 1));
					else if (i == 5)
						v1.push_back(make_pair(i, i + 4));
					else
					{
						continue;
					}
				}
				
				tour_safe.push_back(v1);
			
 
		vector<pair<int, int>>v2;

		for (int i = 0; i < 10; i++) {
			if (i == 0 || i == 5 || i == 6 || i == 4)
				v2.push_back(make_pair(i, i + 3));
			else if (i == 1)
				v2.push_back(make_pair(i, i + 1));
		}

		tour_safe.push_back(v2);
		
			vector<pair<int, int>>v4;

			for (int i = 0; i < 10; i++) {
				if (i == 0 || i == 2 || i == 1) {
					v4.push_back(make_pair(i, i + 4));
				}
				else if (i == 7) {
					v4.push_back(make_pair(i, i + 2));
				}
				else if (i == 3) {
					v4.push_back(make_pair(i, i + 5));
				}
			}
			tour_safe.push_back(v4);

				vector<pair<int, int>>v5;

				for (int i = 0; i < 10; i++) {
					if (i == 0)
					{
						v5.push_back(make_pair(i, i + 5));
					}
					else if (i == 1) {
						v5.push_back(make_pair(i, i + 3));
					}
					else if (i == 2) {
						v5.push_back(make_pair(i, i + 7));
					}
					else if (i == 3) {
						v5.push_back(make_pair(i, i + 4));
					}
					else if (i == 6) {
						v5.push_back(make_pair(i, i + 2));
					}

				}

				tour_safe.push_back(v5);

				vector<pair<int, int>>v6;

				for (int i = 0; i < 10; i++) {
					if (i == 5 || i == 2) {
						v6.push_back(make_pair(i, i + 2));
					}
					else if (i == 0 || i == 3) {
						v6.push_back(make_pair(i, i + 6));
					}
					else if (i == 1) {
						v6.push_back(make_pair(i, i + 7));
					}

				}

				tour_safe.push_back(v6);

				vector<pair<int, int>>v7;

				for (int i = 0; i < 10; i++) {
					if (i == 5 || i == 3) {
						v7.push_back(make_pair(i, i + 1));
					}
					else if (i == 0)
					{
						v7.push_back(make_pair(i, i + 7));
					}
					else if (i == 1)
					{
						v7.push_back(make_pair(i, i + 8));
					}
					else if (i == 1)
					{
						v7.push_back(make_pair(i, i + 6));
					}
				}

				tour_safe.push_back(v7);

				vector<pair<int, int>>v8;

				for (int i = 0; i < 10; i++) {
					if (i == 4 || i == 2 || i == 1)
						v8.push_back(make_pair(i, i + 5));
					else if (i == 3)
						v8.push_back(make_pair(i, i + 2));
					else if (i == 0)
						v8.push_back(make_pair(i, i + 8));
				}

				tour_safe.push_back(v8);

				vector<pair<int, int>>v9;

				for (int i = 0; i < 10; i++) {
					if (i == 3 || i == 2)
						v9.push_back(make_pair(i, i + 2));
					else if (i == 0)
						v9.push_back(make_pair(i, i + 9));
					else if (i == 1)
						v9.push_back(make_pair(i, i + 6));
					else if (i == 4)
						v9.push_back(make_pair(i, i + 4));
				}

				tour_safe.push_back(v9);
				CreateReverse();
		
	}

	vector<pair<int, int>> CreateScheduleForTour() {

		vector<pair<int, int>> v; set <int> safe; vector<int> v1, res;
		for (int i = 0; i <= 9; ++i) {
			v1.push_back(i);
		}
		for (int i = 0; i < 5; i++) {
			


			int  ik;
			int  is;
			bool ff = false;
			ik = rand() % 9;
			is = rand() % 9;

			//cout << "A" << ik;
			if (i == 0) {
				while (is == ik)
					ik = rand() % 9;
			}
			else
			{
				if (safe.count(ik)) {
					if (safe.count(is)) {
						while ((safe.count(is)))
						{
							is = rand() % 9;
							ff = true;

							//cout << is;
						}
					}
					safe.insert(is);
					while ((safe.count(ik)))
					{
						ik = rand() % 9;
						//	cout <<" "<< ik<<endl;
						if (is == ik) {
							int our = ik;
							for (auto iks : v1) {
								bool f = false;
								if (!safe.count(iks))

									if (!f)
									{
										ik = iks; //cout << "A" << ik;

								}
								}
						}

					}

				}
			}

			res.push_back(is);
			res.push_back(ik);
			v.push_back(make_pair(ik, is));

			safe.insert(ik); if (!ff) safe.insert(is);
		}
		return v;
	}

	vector<pair<int, int>> Tours() {
		vector<pair<int, int>> v;
		for (int i = 0, j = 0 ; i < 5 , j <10; i++ , j++) {
			int first = j;
			++j;int second = j;
			v.push_back(make_pair(first, second));
		}
		for (auto i : v) {
			cout << i.first << " vs " << i.second << endl;
		}
		return v;
	}


	 

	
};