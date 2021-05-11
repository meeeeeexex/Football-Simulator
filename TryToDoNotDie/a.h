/*#pragma once
/*
void CreateMatch(vector<Team>league)
{
	

	srand(time(0)); // автоматическая рандомизация
	//int it = rand() % 8;
	//int ik = rand() % 8;

	int it = 2, ik = league.size() - 1;//передаелать на рандомные когда разберусь как заполнять поля для игроков
	while (it == ik) {
		it = rand() % 8;
	}
	cout << league[it].GetNick() << " vs " << league[ik].GetNick() << endl;
	cout << league[it].AmountOfMembers() << "  vs  " << league[ik].AmountOfMembers();

	int res1 = rand() % 5;
	//повысить шанс , при определенных условиях , придумать каких
	int res2 = rand() % 5;

	league[it].SetNewMatch();
	league[ik].SetNewMatch();//добавляем матчи в статус команды



	///условия при которых у команды больше шансов на победу - 1)если стоимость ее игрроков выше стоимости игроков соперника 2-) опыт тренера дает + 1 гол
	//сделать или одного тренера на команду , или искать их среднее значение
	//что делают манагеры кроме трат на зарплату
	if (league[it] > league[ik])//перегрузили оператор сравнения по общей цене
	{
		res1++;
	}
	else if (league[ik] > league[it]) {//перегрузили оператор сравнения по общей цене
		res2++;
	}

	if (league[it].GetCoachExperience() > league[ik].GetCoachExperience())
	{
		res1++;
	}
	else if (league[ik].GetCoachExperience() > league[it].GetCoachExperience()) {
		res2++;
	}

	cout << endl << "Match ended with result " << res1 << " : " << res2 << endl;
	if (!res1 && !res2)
		cout << "It was bad day for the both teams" << endl;
	if (league[it].IsAnyoneINTheTeam() && league[ik].IsAnyoneINTheTeam()) {
		/*if (res1 == 0)
			cout << "Nobody could score to " << league[ik].GetNick() << endl;
		 if(res2 == 0)
				cout << "Nobody could score to " << league[it].GetNick() << endl;
		else {

		if (res1 == 0)
			cout << "For " << league[it].GetNick() << " scored  : Nobody \n";
		else {
			cout << "For " << league[it].GetNick() << " scored  : \n";
			for (int i = 0; i < res1; i++) {//переделать что выполнение функций было связано с циклом , чтобы забивали мячи в зависимости от кол-ва голов

				pair<int, int>score = { 0 ,0 };

				vector<Name>v_tmp1 = league[it].GetReturnedPlayerList();
				int tmp1 = rand() % (v_tmp1.size() - 1);
				Name first_scorer = v_tmp1[tmp1];

				league[it].SetGoal(league[it].FindPlayerByName(first_scorer));
				cout << first_scorer.SurName << "  ";
				cout << "New trasfer price : " << league[it].GetTransferPrice(league[it].FindPlayerByName(first_scorer)) << endl;;
			}
		}

		if (res2 == 0)
			cout << "For " << league[ik].GetNick() << " scored  : Nobody \n";
		else
		{
			cout << "For " << league[ik].GetNick() << " scored  : \n";
			for (int j = 0; j < res2; j++)
			{
				vector<Name>v_tmp2 = league[ik].GetReturnedPlayerList();
				int tmp2 = rand() % (v_tmp2.size() - 1);
				Name second_scorer = v_tmp2[tmp2];
				league[ik].SetGoal(league[ik].FindPlayerByName(second_scorer));
				cout << second_scorer.SurName << "  ";
				cout << "New trasfer price : " << league[ik].GetTransferPrice(league[ik].FindPlayerByName(second_scorer)) << endl;
			}
		}
	}

	else {
		cout << endl << "Huy";
	}
}*/
