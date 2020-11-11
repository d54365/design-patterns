#pragma once

/*
����ģʽ��������ģʽ
����ģʽ��ͨ���Ѵ�������Ĵ����װ������������������Ĵ���������ҵ���߼�����������Ŀ�ġ�
����ģʽϸ�֣�a���򵥹���ģʽ b����������ģʽ c�����󹤳�ģʽ
�������������һ����Ҫԭ�򣺿���ԭ��

��1���򵥹�����Simple Factory��ģʽ
�߻�����������Ԫ��������е������������ֵ��ħ��ֵ����������������
ʹ��new + ��������������������һ�������������͵Ľ���Ϲ�ϵ
ʹ�ù��������ʵ�ִ�������Ĵ��������������������Ҫʵ�ֵ��߼��������
��װ�仯����������Χ��������С�������ױ仯�Ĵ����������һ��С��Χ�ڣ��Ϳ����ںܴ�̶�����ߴ���Ŀ�ά���ԺͿ���չ��
ͨ�������µ�if else��֧���ﵽ֧���¹������ӵ�Ŀ�� -- Υ����������������Ƶ�ԭ�򣺿���ԭ��
����ԭ��˵���Ǵ�����չ������--����չ���ţ����޸Ĺرա�
��ϸ�Ľ��ͣ��������¹��ܣ���Ӧ��ͨ���޸��Ѿ����ڵĴ��������У�����Ӧ��ͨ����չ���루�����������࣬�����³�Ա������������
���if else��֧���ࣨû����ʮ�ϰٸ��������ʵ�Υ�����ŷ��ԭ������ȫ���Խ��ܵġ�
���Ҫ�ڴ���Ŀɶ��ԺͿ���չ��֮������Ȩ��
���롰�򵥹��������ģʽ�Ķ��壨ʵ����ͼ��������һ�������ࣨMonsterFactory��������ĳ�Ա������createMonster�����Ը��ݲ�ͬ
	�������������ز�ͬ������󡣱�����������������һ�㶼������ͬ�ĸ��࣬������������Ĵ��������ϸ��
*/

#include <string>

using namespace std;

namespace _nmsp1
{
	// ���︸��
	class Monster
	{
	protected:
		int m_life;
		int m_magic;
		int m_attack;
	public:
		Monster(int life, int magic, int attack);
		virtual ~Monster();
	};

	// ���������
	class M_Undead : public Monster
	{
	public:
		M_Undead(int life, int magic, int attack);
	};

	// Ԫ�������
	class M_Element : public Monster
	{
	public:
		M_Element(int life, int magic, int attack);
	};

	// ��е�����
	class M_Mechanic : public Monster
	{
	public:
		M_Mechanic(int life, int magic, int attack);
	};

	// ���﹤����
	class MonsterFactory
	{
	public:
		static Monster* createMonster(string strmontype)
		{
			Monster* obj = nullptr;
			if (strmontype == "udd")
			{
				// ����������
				obj = new M_Undead(200, 50, 80);
			}
			else if (strmontype == "elm")
			{
				// ����Ԫ����
				obj = new M_Element(200, 80, 100);
			}
			else if (strmontype == "mec")
			{
				// ������е��
				obj = new M_Mechanic(400, 0, 110);
			}
			return obj;
		}
	};
}

