#include "�򵥹���.h"
#include <iostream>
#include <string>

using namespace std;

namespace _nmsp1
{
	Monster::Monster(int life, int magic, int attack) : m_life(life), m_magic(magic), m_attack(attack)
	{

	}

	Monster::~Monster()
	{

	}

	M_Undead::M_Undead(int life, int magic, int attack) : Monster(life, magic, attack)
	{
		cout << "һ������������������������" << endl;
	}

	M_Element::M_Element(int life, int magic, int attack) : Monster(life, magic, attack)
	{
		cout << "һ��Ԫ��������������������" << endl;
	}

	M_Mechanic::M_Mechanic(int life, int magic, int attack) : Monster(life, magic, attack)
	{
		cout << "һ����е������������������" << endl;
	}

}
