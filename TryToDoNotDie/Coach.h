#pragma once
#include"TeamMember.h"

class Coach : public TeamMember {
public:
	Coach(Name new_name, int new_age, double new_height,
		int new_annual_salary, int experieneinyears) :
		TeamMember(new_name, new_age, new_height),
		annual_salary(new_annual_salary), experience(experieneinyears) {
		if (new_annual_salary < 0 || experieneinyears < 0
			|| new_height < 0 || new_age < 0 ||
			(new_name.FathersName.size() < 0 || new_name.nname.size() < 0 ||
				new_name.SurName.size() < 0))
			throw out_of_range("Failing coach test : Should be more than 0");

	}
	Coach(const Coach& c) :TeamMember(c) , annual_salary(c.annual_salary) , experience(c.experience) {
		//cout << "///////////////////////////////////";
	}
	void SetAddedSalary() override {
		
	}
	string GetPos()const override {
		return "";
	}

	 void GetInfo()override {
		cout<<"Coach : " << Coach::GetName() << endl
			<< "Age : "<< Coach::GetAge() << endl <<
			"Height : " <<Coach::GetHeigh() << endl <<"Salary : "<< GetSalary()
			<< endl <<"With experinece in "<< GetExperience()<<" years " << endl<<endl;
	}

	 bool isPlayer()const override {
		return false;
	}

	 bool isManager() const override {
		return false;
	}
	 bool isCoach()const override {
		return true;
	}

	 void SetGoals() override {
		
	}

	 int GetSalary()const override
	{
		return annual_salary;
	}

	/*int GetExperience()const  {
		return experience;
	}*/

	 int GetTransferPrice()const override{
		return 0;
	}
     int GetExperience()const override{
		 return experience;
	 }
private:
	int annual_salary;
	int experience;
	
};