#include "模板方法.h"
#include <iostream>

using namespace std;

namespace _nmsp1
{
	Warrior::Warrior(int life, int magic, int attack) : m_life(life), m_magic(magic), m_attack(attack)
	{

	}

	void Warrior::JN_Burn()
	{
		cout << "让所有敌人失去500点生命" << endl;
		cout << "主角失去300点生命" << endl;
		m_life -= 300;
	}
}

namespace _nmsp2
{
	Fighter::Fighter(int life, int magic, int attack) : m_life(life), m_magic(magic), m_attack(attack)
	{

	}

	Fighter::~Fighter()
	{

	}

	void Fighter::JN_Burn()
	{
		if (canUseJN() == false)  // 判断能否使用技能
			return;
		effect_enemy();
		effect_self();
		play_effect();
	}

	void Fighter::play_effect()
	{
		cout << "BIUBIUBIU，技能特效。。。" << endl;
	}

	// 战士类
	F_Warrior::F_Warrior(int life, int magic, int attack) : Fighter(life, magic, attack)
	{

	}

	void F_Warrior::effect_enemy()
	{
		cout << "战士主角：让所有敌人失去500点生命" << endl;
	}

	void F_Warrior::effect_self()
	{
		cout << "战士主角自身失去300点生命" << endl;
		m_life -= 300;
	}

	bool F_Warrior::canUseJN()
	{
		if (m_life < 300)
		{
			return false;
		}
		return true;
	}

	// 法师类
	F_Mage::F_Mage(int life, int magic, int attack) : Fighter(life, magic, attack)
	{

	}

	void F_Mage::effect_enemy()
	{
		cout << "法师主角：让所有敌人失去650点生命" << endl;
	}

	void F_Mage::effect_self()
	{
		cout << "法师主角自身失去100魔法值" << endl;
		m_magic -= 100;
	}

	bool F_Mage::canUseJN()
	{
		if (m_magic < 100)
		{
			return false;
		}
		return true;
	}

}
