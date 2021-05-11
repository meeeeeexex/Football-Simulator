#pragma once


class TeamMember {
public:
	TeamMember(const Name new_name, int new_age, const double new_height) :
		name(new_name), age(new_age), height(new_height)
	{
		if (new_age <= 0 || new_height < 50)
			throw logic_error("Failing in creating Team member . Age and height should be more than 0");
	}
	TeamMember(const TeamMember& sth_new) : name(sth_new.name) ,age(sth_new.age) , height(sth_new.height)
	{
	}
	virtual void GetInfo()  {
		cout << GetName() << endl << GetAge() << endl << GetHeigh();
	}
	const Name & GetName() const {
		return name;
	}
	const int GetAge() const {
		return age;
	}
	double GetHeigh() const {
		return height;
	}
	virtual void SetAddedSalary()  {
		
	}
	void SetName(const Name nan) {
		name = nan;
	 }
	virtual string GetPos()const = 0;
	virtual int GetExperience()const = 0;
	virtual void SetGoals() {};
	virtual bool isPlayer()const = 0;
	virtual bool isManager()const = 0; 
	virtual bool isCoach()const = 0;
	virtual int GetTransferPrice()const = 0;
	virtual int GetSalary() const = 0;

	virtual void SetPos(const string c)  {
		
	}
protected:
	 Name name;
	 int age;
	 double height;

}; 