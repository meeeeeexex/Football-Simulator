/*#pragma once

class Player : public TeamMember {
public:
	Player(Name new_name, int new_age, double new_height,
		int new_annual_salary, std::string new_position, int new_transfer_price);

	 void GetInfo ()override {
		 std::cout << Player::GetName() << std::endl << "Age : "
			 << Player::GetAge() << std:: endl << "Height : " <<
			 Player::GetHeigh() << std::endl << "Salary : " << GetSalary() << std::endl << 
			 "Transfer price : " << GetTransferPrice() << std::endl << "Position : " << GetPos() << 
			std::endl << "Goals scored : " << GetGoals() <<std::endl;
	}
	
	 void SetAddedSalary() override;

	 void SetGoals() override;
	


	 int GetGoals() const;
	 int GetTransferPrice()const override;

	 bool isPlayer()const override;
	 bool isManager() const override;
	 bool isCoach()const override;

	 std::string GetPos()const;

	 int GetSalary() const override;

	 int GetExperience()const override;

private:
	int annual_salary;
	std::string position;
	int transfer_price;
	int amount_of_goals;
};
*/