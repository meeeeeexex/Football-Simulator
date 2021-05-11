#pragma once
#include<tuple>
#include"TeamMember.h"
//должен быть глобальным
class TransferList {
public:



	void SetNewTransfer(TeamMember* tm, const string& from_team, const string& new_team) {
		//	transfers.push_back(tm);
		vector<string>res;
		res.push_back(from_team); res.push_back(new_team);
		pair<Name, vector<string>>rr = make_pair(tm->GetName(), res);
		r.push_back(rr);
		//just_try[tm->GetName()] = res;vector
		//just_try[tm->GetName()] = make_pair(from_team, new_team);pair
		cout << " Transfer succeed " << endl;
	}
	void GetAllTransferList() {
		for (int i = 0; i < r.size(); i++) {
			cout << r[i].first << " -  " << r[i].second << endl;
		}
	}
private:

	vector<TeamMember*>transfers;
	vector < pair<Name, vector<string>>> r;//потому что вектор легче перегрузить на вывод строк , чем пару

};
