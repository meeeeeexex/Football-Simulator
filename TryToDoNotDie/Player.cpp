/*#include"Player.h"

using namespace std;
Player::Player(Name new_name, int new_age, double new_height,
	int new_annual_salary, std::string new_position, int new_transfer_price) :
			TeamMember(new_name, new_age, new_height),
			annual_salary(new_annual_salary), position(new_position), 
			transfer_price(new_transfer_price)//можно ли так делать при исключительных ситуациях
{
	amount_of_goals = 0;
	bool f = false;
	for (auto i : positions)
	{
		if (new_position == i)
			f = true;
	}

	if (new_annual_salary < 0 || new_transfer_price < 0)
		throw logic_error("Failing in creating player . Salary and transfer price should be higher than 0");

	else if (new_annual_salary < 0 || new_position.size() < 0 || new_transfer_price < 0
		|| new_height < 0 || new_age < 0 ||
		(new_name.FathersName.size() <= 0 || new_name.nname.size() <= 0 ||
			new_name.SurName.size() <= 0))
		throw out_of_range("Should be more than 0");

	else if (!f)
	{
		throw logic_error("Failing in creating player . There is not such  position  in the world");
	}
}
	void Player::SetAddedSalary() override {
		transfer_price += 10;
	}
	void Player::SetGoals() override {
		++amount_of_goals;
	}
	int Player::GetGoals() const {
		return amount_of_goals;
	}
	bool Player::isPlayer()const override {
		return true;

	}

	bool Player::isManager() const override {
		return false;
	}

	bool Player::isCoach()const override {
		return false;
	}

	int Player::GetSalary() const override {
		return annual_salary;
	}
	string Player::GetPos()const {
		return position;
	}

	int Player::GetExperience()const override {
		return 0;
	}

	int GetTransferPrice()const override {
		return transfer_price;
	}

*/