#include "ģ�巽��.h"
#include <iostream>

using namespace std;

namespace _nmsp1
{
	Warrior::Warrior(int life, int magic, int attack) : m_life(life), m_magic(magic), m_attack(attack)
	{

	}

	void Warrior::JN_Burn()
	{
		cout << "�����е���ʧȥ500������" << endl;
		cout << "����ʧȥ300������" << endl;
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
		if (canUseJN() == false)  // �ж��ܷ�ʹ�ü���
			return;
		effect_enemy();
		effect_self();
		play_effect();
	}

	void Fighter::play_effect()
	{
		cout << "BIUBIUBIU��������Ч������" << endl;
	}

	// սʿ��
	F_Warrior::F_Warrior(int life, int magic, int attack) : Fighter(life, magic, attack)
	{

	}

	void F_Warrior::effect_enemy()
	{
		cout << "սʿ���ǣ������е���ʧȥ500������" << endl;
	}

	void F_Warrior::effect_self()
	{
		cout << "սʿ��������ʧȥ300������" << endl;
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

	// ��ʦ��
	F_Mage::F_Mage(int life, int magic, int attack) : Fighter(life, magic, attack)
	{

	}

	void F_Mage::effect_enemy()
	{
		cout << "��ʦ���ǣ������е���ʧȥ650������" << endl;
	}

	void F_Mage::effect_self()
	{
		cout << "��ʦ��������ʧȥ100ħ��ֵ" << endl;
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
