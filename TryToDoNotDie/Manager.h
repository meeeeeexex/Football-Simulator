#pragma once
#include"TeamMember.h"
class Manager : public TeamMember {
public:
	Manager(Name new_name, int new_age, double new_height,
		int new_annual_salary) :
		TeamMember(new_name, new_age, new_height),
		annual_salary(new_annual_salary) {
		if (new_annual_salary < 0 || new_height < 0
			|| new_age < 0 || (new_name.FathersName.size() < 0 ||
				new_name.nname.size() < 0 || new_name.SurName.size() < 0))
			throw out_of_range("Manager test failed  :  Should be more than 0");
	}

	Manager(const Manager& m) : TeamMember(m), annual_salary(m.annual_salary) {}

	int GetExperience()const override {
		return 0;
	}
	void SetAddedSalary() override {

	}
	string GetPos()const override
	{
		return "";
	}
	 void GetInfo() override {
		cout<<"Manager : "<< Manager::GetName() << endl<<"Age : " << Manager::GetAge() << endl<<"Height : " << Manager::GetHeigh() << endl<<"Salary : " << GetSalary()<<endl<<endl;
	}

	 int GetSalary() const override {
		return annual_salary;
	}

	 int GetTransferPrice()const override {
		return 0;
	}

	 bool isManager() const override {
		return true;
	}
	 bool isCoach()const override {
		return false;
	}

	 bool isPlayer()const override {
		return false;
	}

	 void SetGoals() override {
		
	}

private:
	int annual_salary;
};
