#pragma once
#include"TeamMember.h"
class Team {
public:
	Team(const string& nickname, string coy, int cur_bal/*,vector<Player>pl_v  */, vector<TeamMember*> v /*, Coach coach, Manager manager*/)
		:Nick(nickname), country(coy), current_balance(cur_bal)/*,squad(pl_v)*/, staff(v), points(0) {
		match_tracking = 0; Wins = 0; Loses = 0; Draws=0;
		goals_statistic.missed_goals = 0;
		goals_statistic.scored_goals = 0;
	}
	void PrintPlayersWithIdx()const {
		int i = 0, j =0 ;
		for (i; i < staff.size(); i++) {
			if (staff[i]->isPlayer()) {
				cout << j << ". " << staff[i]->GetName() << endl << endl;
				++j;
			}
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

	TeamMember* FindPLayerByIdx(const int idx) {
		return staff[idx];
	}

	void PrintPlayersAndPriceWithIdx()const {
		int i = 0, j = 0;
		cout << "Name"<<setw(41)<<"|  Price \n\n";
		
		for (i; i < staff.size(); i++) {
			if (staff[i]->isPlayer()) {
				if(j<10)
				cout << j << ". " << staff[i]->GetName()<<setw(36 - size_ofName(staff[i]->GetName()))<<" |  "<<staff[i]->GetTransferPrice() << endl << endl;
				else
					cout << j << ". " << staff[i]->GetName() << setw(35 - size_ofName(staff[i]->GetName())) << " |  " << staff[i]->GetTransferPrice() << endl << endl;
				++j;
			}
		}
	}
	
	int GetPriceByName(const Name name) {
		for (auto i : staff) {
			if (i->GetName() == name) {
			

				return i->GetTransferPrice();
				
				
			}
		}
	}

int GetTransferPrice(TeamMember* p) const {
		return p->GetTransferPrice();
	}
void Minusmoney(int money) {
		current_balance -= money;
	}
	void SetNewTransfer(string first_team , string current_team , Name name) {
		int price;
		for (auto i : staff) {
			if (i->GetName() == name) {
				price = i->GetTransferPrice();
				cout << price;
			}
		}
	}
	void SetMoney(const int money) {
		current_balance += money;
	}
	
	void GetInfoAboutTeam() {
		cout << "Team  : " << GetNick() << "  from " << GetCountry() << " with balance : " << GetBalance() << " and staff  : \n"; CheckTheStaff();
	}
	void SetWin() {
		++Wins;
	}
	void SetLose() {
		++Loses;
	}
	void SetDraw() {
		++Draws;
	}
	const int GetWin()const {
		return Wins;
	}
	const int GetLose()const {
		return Loses;
	}
	const int GetDraw()const {
		return Draws;
	}
	const int GetScoredGoals()const {
		return goals_statistic.scored_goals;
	}
	const int GetMissedGoals()const {
		return goals_statistic.missed_goals;
	}
	void TeamScoredGoals(int  amount) {
		goals_statistic.scored_goals += amount;
	//	cout << endl << Nick << " scored " << goals_statistic.scored_goals << endl;
	}
	void TeamMissedGoals(int  amount) {
		goals_statistic.missed_goals += amount;

	}
	
	const int GetGoalDifference()const {
		return (goals_statistic.scored_goals - goals_statistic.missed_goals);
	}

	void PrintInfoAboutPlayer(int idx) {
		if(staff[idx]->isPlayer())
		staff[idx]->GetInfo();
		
	}

	void FireSomeone(const Name& name) {
		for (int i = 0; i < staff.size(); i++) {

			if ((staff[i]->GetName()) == name)

				staff.erase(staff.begin() + i);//если не получиться приисвоить всем параметрам ""
			else throw logic_error("There is no one with this name");
		}
	}
	void Fire(const int indx) {
		staff.erase(staff.begin() + indx)
			;
		
	}
	void AddToTeam( TeamMember* pl) {
		staff.push_back(pl);
	}


	void SellPLayer(const Name& name) {//для осуществления покупки нужно только удалить игрока из команды и зачислить его цену в бюджет
		for (int i = 0; i < staff.size(); i++) {
			if ((staff[i]->GetName()) == name)
			{
				current_balance += staff[i]->GetTransferPrice();
				staff.erase(staff.begin() + i);
				cout << "Current balance of  " << GetNick() << " after selling " << name << " : " << current_balance<<endl;
				

			}
		}
	}


	int TeamsOverallPrice() const {
		int res = 0;
		for (auto i : staff) {
			res += i->GetTransferPrice();
		}
		return res;
	}


	bool IsAnyoneINTheTeam()  const {
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

	


	


	void GetPlayersList() const {
		vector<Player>v;
		for (int i = 0; i < staff.size(); i++) {
			if (staff[i]->isPlayer())
			{
				cout << staff[i]->GetName() << endl;
			}
		}
	}


	Name GetName(int idx)
	{		
		return (staff[idx]->GetName());
	}

	void SetGoalByIdx(int idx) {
		if (staff[idx]->isPlayer())
			staff[idx]->SetGoals();//доделать добавление зарплаты за каждый гол
			//p->SetAddedSalary();
	}

	void SetGoal(TeamMember* p) {
		if (p->isPlayer())
			p->SetGoals();
	}
	//dynamic cast
	pair<TeamMember*,bool> ReturnPlayerFromTeanForTransfer( const Name& tmp_p) {
		for (auto i : staff) {
			if (i->GetName() == tmp_p) {
				return make_pair(i, true);
			}
	}
		return make_pair(staff[0], false);
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


	const string GetNick()const {
		return Nick;
	}


	const string GetCountry()const {
		return country;
	}


	//реализовать функции SetBalance () - какие-то фонды , при условии того , что это любимая команда юзера , можно добаить 1000000000000
	const int GetBalance()const {
		return current_balance;
	}


	const void PrintName(int idx) const {
		
		cout<< staff[idx]->GetName();
		
	}

	const void PrintAllInfoAboutTeam() const {
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
		if (staff.empty() )
			cout << "There is no one yet in the club";

		else
		{
			for (auto i : staff) {


				i->GetInfo();
				cout << endl;
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
		points += 0;
	}
	void SetPoints_Draw() {
		points++;
	}
	const int PlayersinTheTeam() const{
		int cnt = 0;
		for (auto i : staff) {
			if (i->isPlayer())
				cnt++;
		}
		return cnt;
	}

private:
	string Nick;
	string country;
	int current_balance;
	vector<TeamMember*> staff;
	int points;
	int match_tracking;
	int Wins;
	int Loses;
	int Draws;
	Goals goals_statistic;


	int size_ofName(Name name) const {
		string res;
		res = name.SurName + name.nname + name.FathersName;
		res += "   ";
		return res.size();
	}
};
