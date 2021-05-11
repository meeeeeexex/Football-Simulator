#pragma once
using namespace std;
class Player : public TeamMember {
public:
Player(Name new_name, int new_age, double new_height,
	int new_annual_salary, string new_position, int new_transfer_price) :
	TeamMember(new_name, new_age, new_height),
	annual_salary(new_annual_salary), position(new_position),
	transfer_price(new_transfer_price)//можно ли так делать при исключительных ситуациях
{
	//cout << name.nname;
	amount_of_goals = 0;
	bool f = false;
	for (auto i : positions)
	{
		if (new_position == i)
			f = true;
	}

	if (new_annual_salary < 0 || new_transfer_price < 0)
		throw logic_error("Failing in creating player . Salary and transfer price should be higher than 0");



	else if (!f)
	{
		throw logic_error("Failing in creating player . There is not such  position  in the world");
	}
}
Player(const Player& p) :TeamMember(p), annual_salary(p.annual_salary), position(p.position), transfer_price(p.transfer_price) {
	amount_of_goals = 0;
}

void GetInfo()override {
	cout <<"PLayer : "<< Player::GetName() << endl
		<<"With age  : "<< Player::GetAge() << endl <<
		"Height : "<<Player::GetHeigh() << endl << "With salary : "<<GetSalary()
		<< endl <<"Position : "<< GetPos()<<endl<<"Transfer price : "<<GetTransferPrice() << endl<<"Scored goals : "<<GetGoals()<<endl;
}


void SetAddedSalary() override {
	transfer_price += 10;
}


void SetGoals() override {
	++amount_of_goals;
	SetAddedSalary();
}


int GetGoals() const {
	return amount_of_goals;
}

bool isPlayer()const override {
	return true;

}
bool isManager() const override {
	return false;
}
bool isCoach()const override {
	return false;
}
int GetSalary() const override {
	return annual_salary;
}
string GetPos()const override {
	return position;
}
virtual void SetPos(string pos)  {
	position = pos;
}

int GetExperience()const override {
	return 0;
}

int GetTransferPrice()const override {
	return transfer_price;
}
private:
	int annual_salary;
	string position;
	int transfer_price;
	int amount_of_goals;
};
