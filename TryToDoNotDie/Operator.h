#pragma once

ostream& operator << (ostream& out, Name T)
{
	out << T.SurName << " " << T.nname << " " << T.FathersName;
	return out;
}

bool operator == (const Name& lhs, const Name& rhs) {
	return ((lhs.FathersName == rhs.FathersName) && (lhs.nname == rhs.nname) && (lhs.SurName == rhs.SurName));
}
template<typename T>
ostream& operator << (ostream& out, set<T> s)//для использования этого нужно перегрузить каждый класс Мэмбера
{
	for (auto i : s) {
		cout << i << " ";
	}
	return out;
}
bool operator >(const Name & lhs, const Name & rhs) {
	return lhs.SurName > rhs.SurName;
}
bool operator >(const pair<int, Name>& lhs, const pair<int, Name>& rhs) {
	return lhs.first > rhs.first;
}

bool operator <(const pair<int, Name>& lhs, const pair<int, Name>& rhs) {
	return lhs.first < rhs.first;
}

bool operator <(const Name& lhs, const Name& rhs) {
	return lhs.SurName < rhs.SurName;
}
template<typename T>
ostream& operator <<(ostream& out, const pair<T, T>& pp) {

	return out << pp.first << " vs " << pp.second << endl;
}
template<typename T>
ostream& operator <<(ostream& out, const vector<T>& v) {

	for (auto i : v) {
		out << i << " ";
	}
	return out;
}

ostream& operator <<(ostream& out, vector<string> v) {

	return out << "From : " << v[0] << "  To : " << v[1];
}/*
ostream& operator << (ostream& out, pair)
{
	for (auto i : s) {
		cout << i << " ";
	}
	return out;
}*/
/*
ostream& operator << (ostream& out, Player T) {
	out << "That's player " << T.GetName() << endl;
	out << "His salary is " << T.GetPlayerSalary() << endl;
	out << "His position is " << T.GetPos() << endl;
	out << "His transer price is " << T.GetTransferPrice() << endl;
	return out;
}

ostream& operator << (ostream& out, Coach T) {
	out << "That's coach " << T.GetName() << endl;
	out << "His salary is " << T.GetSal() << endl;
	out << "His experience is " << T.GetExperience() << endl;
	return out;
}

ostream& operator << (ostream& out, Manager T) {
	out << "That's manager " << T.GetName() << endl;
	out << "His salary is " << T.GetSal() << endl;
	return out;
}
/*
ostream& operator << (ostream& out, TeamMember& T) {///////////////////как выводить мэнэджеров и все прчее , если они часть тим мемберства
	out << "That's " << T.GetName() << endl;
	out << "His age is " << T.GetAge() << endl;
	out << "His height is " << T.GetHeigh() << endl;
	return out;
}*/
