#pragma once

/*
工厂模式：创建型模式
工厂模式：通过把创建对象的代码包装起来，做到创建对象的代码与具体的业务逻辑代码相隔离的目的。
工厂模式细分：a）简单工厂模式 b）工厂方法模式 c）抽象工厂模式
面向对象程序设计一个重要原则：开闭原则

（1）简单工厂（Simple Factory）模式
策划：亡灵类怪物，元素类怪物，机械类怪物：都有生命值、魔法值、攻击力三个属性
使用new + 具体类名来创建对象是一种依赖具体类型的紧耦合关系
使用工厂类可以实现创建怪物的代码与各个具体怪物类对象要实现的逻辑代码隔离
封装变化：把依赖范围尽可能缩小，把容易变化的代码段限制在一个小范围内，就可以在很大程度上提高代码的可维护性和可扩展性
通过增加新的if else分支来达到支持新怪物增加的目的 -- 违背了面向对象程序设计的原则：开闭原则
开闭原则：说的是代码扩展性问题--对扩展开放，对修改关闭。
详细的解释：当增加新功能，不应该通过修改已经存在的代码来进行，而是应该通过扩展代码（比如增加新类，增加新成员函数）来进行
如果if else分支不多（没有数十上百个），则适当违反开放封闭原则，是完全可以接受的。
大家要在代码的可读性和可扩展性之间做出权衡
引入“简单工厂”设计模式的定义（实现意图）：定义一个工厂类（MonsterFactory），该类的成员函数（createMonster）可以根据不同
	参数创建并返回不同的类对象。被创建对象所属的类一般都具有相同的父类，调用者无需关心创建对象的细节
*/

#include <string>

using namespace std;

namespace _nmsp1
{
	// 怪物父类
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

	// 亡灵类怪物
	class M_Undead : public Monster
	{
	public:
		M_Undead(int life, int magic, int attack);
	};

	// 元素类怪物
	class M_Element : public Monster
	{
	public:
		M_Element(int life, int magic, int attack);
	};

	// 机械类怪物
	class M_Mechanic : public Monster
	{
	public:
		M_Mechanic(int life, int magic, int attack);
	};

	// 怪物工厂类
	class MonsterFactory
	{
	public:
		static Monster* createMonster(string strmontype)
		{
			Monster* obj = nullptr;
			if (strmontype == "udd")
			{
				// 创建亡灵类
				obj = new M_Undead(200, 50, 80);
			}
			else if (strmontype == "elm")
			{
				// 创建元素类
				obj = new M_Element(200, 80, 100);
			}
			else if (strmontype == "mec")
			{
				// 创建机械类
				obj = new M_Mechanic(400, 0, 110);
			}
			return obj;
		}
	};
}

