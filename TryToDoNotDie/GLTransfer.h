#pragma once
#include<tuple>
//��������� ��������� ��� ������ �������
//vector<TeamMember*>transfers;
vector < pair<Name, pair<string,string>>> r;//������ ��� ������ ����� ����������� �� ����� ����� , ��� ����

void SetNewTransfer(TeamMember* tm, const string& from_team, const string& new_team) {
	//	transfers.push_back(tm);
	vector<string>res;
	res.push_back(from_team); res.push_back(new_team);
	pair<Name, pair<string,string>>rr = make_pair(tm->GetName(), make_pair(from_team,new_team));
	r.push_back(rr);

}

void GetAllTransferList() {
	if (r.empty()) {
		cout << "��� �� ��� ����������� �� ���� �������� \n";
	}
	else {
		for (int i = 0; i < r.size(); i++) {
			cout << r[i].first << "- " << " �� " << r[i].second.first << " � " << r[i].second.second << endl;
		}
	}
}