#include <iostream>
#include "¼òµ¥¹¤³§.h"

using namespace std;

int main()
{
	_nmsp1::Monster* pM1 = _nmsp1::MonsterFactory::createMonster("udd");
	_nmsp1::Monster* pM2 = _nmsp1::MonsterFactory::createMonster("elm");
	_nmsp1::Monster* pM3 = _nmsp1::MonsterFactory::createMonster("mec");
	delete pM1;
	delete pM2;
	delete pM3;
	return 0;
}
