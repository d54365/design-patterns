#include "简单工厂.h"
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
		cout << "一个亡灵类怪物来到了这个世界" << endl;
	}

	M_Element::M_Element(int life, int magic, int attack) : Monster(life, magic, attack)
	{
		cout << "一个元素类怪物来到了这个世界" << endl;
	}

	M_Mechanic::M_Mechanic(int life, int magic, int attack) : Monster(life, magic, attack)
	{
		cout << "一个机械类怪物来到了这个世界" << endl;
	}

}
