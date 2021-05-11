#pragma once
#include"TeamMember.h"
class Team {
public:
	Team(const string& nickname, string coy, int cur_bal/*,vector<Player>pl_v  */  ,vector<TeamMember*> v /*, Coach coach, Manager manager*/)
		:Nick(nickname), country(coy), current_balance(cur_bal)/*,squad(pl_v)*/, staff(v) , points(0){
		
	}

	void GetInfoAboutTeam() {
		cout << "Team  : " << GetNick() << "  from " << GetCountry() << " with balance : " << GetBalance() << " and staff  : \n"; CheckTheStaff();
	}


	void SetNewPosition(Player& p) {
		Amount_of_players_on_position[p.GetPos()]++;
	}


	void FireSomeone(const Name& name) {
		for (int i = 0; i < staff.size(); i++) {

			if ((staff[i]->GetName()) == name)

				staff.erase(staff.begin() + i);//если не получиться приисвоить всем параметрам ""
			else throw logic_error("There is no one with this name");
		}
	}


	void SellPLayer(const Name& name) {//для осуществления покупки нужно только удалить игрока из команды и зачислить его цену в бюджет
		for (int i = 0; i < staff.size(); i++) {
			if ((staff[i]->GetName()) == name)
			{
				current_balance += staff[i]->GetTransferPrice();

				cout << "Current balance of  " << GetNick() << " after selling " << name << " : " << current_balance;
				staff.erase(staff.begin() + i);

			}
		}
	}


	int TeamsOverallPrice() const{
		int res = 0;
		for (auto i : staff) {
			res += i->GetTransferPrice();
		}
		return res;
	}


	bool IsAnyoneINTheTeam()  const{
		return staff.size();
	}
	string GetPlayersPosition(const TeamMember* p)const {
		return p->GetPos();//динамик каст // передавать через имя , а потом искать в стаффе

	}
	void GetP()const {
		for (auto i : staff) {
			if (i->isPlayer())
				cout << i->GetPos();
		}
	}

	int GetTransferPrice(TeamMember* p) const {
		return p->GetTransferPrice();
	}


	void BuyPLayer(Player& p) {//для первичного собирания команды
		TeamMember* new_player = &p;
		staff.push_back(new_player);
		SetNewPosition(p);
		//необходимо сразу заполнять мапу позиций
		Amount_of_players_on_position[p.GetPos()]++;
	}


	void GetPlayersList() const{
		vector<Player>v;
		for (int i = 0; i < staff.size(); i++) {
			if (staff[i]->isPlayer())
			{
				cout << staff[i]->GetName() << endl;
			}
		}
	}


	vector<Name> GetReturnedPlayerList()//{
	{
		vector<Name> v;
		for (int i = 0; i < staff.size(); i++) {
			if (staff[i]->isPlayer())
			{
				v.push_back(staff[i]->GetName());
			}
		}
		return v;
	}


	void SetGoal(TeamMember* p) {
		if(p->isPlayer())
		p->SetGoals();//доделать добавление зарплаты за каждый гол
		//p->SetAddedSalary();
	}
	//dynamic cast

	void BuyPLayerFromTeam(Player& p, Team& tt) {
		int player_price = p.GetTransferPrice();
		for (int i = 0; i < tt.staff.size(); i++) {
			if (tt.staff[i]->GetName() == p.GetName())
			{
				if (player_price <= current_balance) {
					TeamMember* player = &p;
					cout << "Do you really want to buy: (if yes - print yes - if no - print no)" << endl;
					player->GetInfo();
					cout << endl;
					string answer; cin >> answer; if (answer == "yes")
					{
						current_balance -= player->GetTransferPrice();
						cout << "Current balance of  " << GetNick() << " : " << current_balance << endl;
						staff.push_back(player);

						//необходимо сразу заполнять мапу позиций
						Amount_of_players_on_position[p.GetPos()]++;

					    SetNewTransfer(player, tt.GetNick(), GetNick());
						// transfer_list.GetAllTransferList();
						tt.SellPLayer(player->GetName());
					}
				}
				


			}
		}
	}
	
	int GetCoachExperience() {
		for (auto i : staff) {
			if (i->isManager())
				return i->GetExperience();
		}
	}


	void SeeAllTransfers() {
	 GetAllTransferList();//глобальный метод трансферов
	}


	void SalaryAdding() {//при каком условии начислять заработаную плату
		for (int i = 0; i < staff.size(); i++) {
			current_balance -= staff[i]->GetSalary();
		}
	}


	string GetNick()const {
		return Nick;
	}


	string GetCountry()const {
		return country;
	}


	//реализовать функции SetBalance () - какие-то фонды , при условии того , что это любимая команда юзера , можно добаить 1000000000000
	int GetBalance()const {
		return current_balance;
	}


	void PrintAllInfoAboutTeam() const {
		cout << "That's team : " << GetNick() << " from " << GetCountry()
			<< "\n With balance in : " << GetBalance() << endl <<
			"With " << AmountOfMembers();
		if (AmountOfMembers() != 1)
			cout << " members" << endl;
		else {
			cout << " member" << endl;
		}
	}


	int AmountOfMembers() const {
		return staff.size();
	}


	void CheckTheStaff()const {
		if (staff.empty()&&squad.empty())
			cout << "There is no one yet in the club";
		
		else
		{
			for (auto i : staff) {
				
				
				 i->GetInfo();
				cout << endl;
			}
		
		}
	}


	int GetAmountOfPlayersOnPosition(const string& position) {
		bool f = false;
		for (auto i : positions) {
			if (i == position)
				f = true;
		}
		if (f) {
			return Amount_of_players_on_position[position];
		}
		else {
			throw logic_error("There are not this position");
		}
	}

	TeamMember* FindPlayerByName(const Name& name) {
		for (auto i : staff) {
			if (i->GetName() == name)
			{
				if (i->isPlayer())
					return i;
			}
		}
	}

	void SetNewMatch() { // после каждого матча выплачивается зарплата
		match_tracking++;
		SalaryAdding();
	}

	int GetPoints() const {
		return points;
	}

	int GetPassedMatch() const {
		return match_tracking;
	}

	void SetPoints_Win() {
		points += 3;
	}
	void SetPoints_Lose() {
		points +=0
	}
	void SetPoints_Draw() {
		points++;
	}


private:
	string Nick;
	string country;
	int current_balance;
	vector<Player> squad;
	vector<TeamMember*> staff;//работает//должно быть скорее множество
	//Manager managers;
	//Coach coaches;
	map<string, int>Amount_of_players_on_position;
	int points;
	int match_tracking;
};
