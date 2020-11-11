#pragma once

/*
模板方法（Template Method）模式
在固定步骤确定的情况下，通过多态机制在多个子类中对每个步骤的细节进行差异化实现，这就是模板方法能够达到的效果
模板方法模式：行为型模式

(1) 一个具体实现范例的逐步重构
A公司有一个小游戏项目 -- 开发单机闯关打斗类游戏（类似街机打拳类游戏）
一个游戏项目组最少需要三名担任不同角色的员工组成：游戏策划、游戏程序、游戏美术
a）游戏策划：简称策划，负责提出游戏的各种玩法需求，确定游戏中各种数值比如人物的生命值、魔法值
b）游戏程序：简称程序，需要与游戏策划紧密配合通过代码来实现游戏策划要求的各种游戏功能
c）游戏美术：角色设计、道具设计、游戏特效等

游戏策划需求：游戏主角是个战士（攻击力不够强，生命值比较多，耐揍），主角通过不断的往前走来闯关，
	遇到敌人就进行攻击，敌人也会反击，敌人也会近距离时主动攻击主角。
	主角：生命值1000（为0时主角死亡，游戏结束），魔法值0（暂时用不上）、攻击力200（打敌人一下敌人失去多少生命）
	技能“燃烧” -- 使用该技能可以使附近所有敌人每人失去500生命值，但是主角也会损失300生命值

	增加法师作为主角（攻击力强，生命值较少）
	主角：生命值800，魔法值200，攻击力300
	技能“燃烧” -- 使用该技能可以使附近所有敌人每人失去650生命值，但是主角也会损失100魔法值

	将要增加牧师作为主角
	每个主角都有一个叫做燃烧的技能。每个主角释放燃烧时技能效果都不同

战士和法师释放燃烧技能表现是不同的，这种不同的表现主要是通过F_Warrior和F_Mage子类中的effect_emeny和effest_self来实现的

(2) 引入模板方法模式
软件开发中需求变化频繁，开发人员要尝试寻找变化点，把变化部分和稳定部分分离开，在变化部分使用设计模式

模板方法模式的定义（实现意图）：定义了一个操作中的算法的骨架（稳定部分），而将一些步骤延迟到子类中去实现（父类中定义虚函数，子类中实现）
	从而达到在整体稳定的情况下能够产生一些变化的目的。
设计模式的经典总结：设计模式的作用就是在变化和稳定中间寻找隔离点，分离稳定和变化，从而来管理变化。

程序代码的进一步完善及应用联想
钩子方法：子类钩住父类从而反向控制父类行为的意思
*/

namespace _nmsp1
{
	// 定义一个战士类
	class Warrior
	{
	private:
		int m_life;    // 生命值
		int m_magic;   // 魔法值
		int m_attack;  // 攻击力
	public:
		Warrior(int life, int magic, int attack);
	public:
		void JN_Burn(); // 技能 燃烧
	};
}


namespace _nmsp2
{
	// 重构

	class Fighter
	{
	public:
		Fighter(int life, int magic, int attack);

		// 对主角自身会产生影响，对敌人产生影响
		// 分析：对敌人产生影响，函数effect_enemy。对自身产生影响，函数effect_self。播放技能特效play_effect函数
		void JN_Burn(); // 技能 燃烧

		virtual ~Fighter();
	private:
		virtual void effect_enemy() = 0;  // 对敌人产生影响

		virtual void effect_self() = 0;  // 对自身产生影响

		void play_effect();  // 播放技能特效

		virtual bool canUseJN() = 0;  // 判断能否使用技能
	protected:  // 可能被子类访问
		int m_life;    // 生命值
		int m_magic;   // 魔法值
		int m_attack;  // 攻击力
	};

	// 战士类
	class F_Warrior : public Fighter
	{
	public:
		F_Warrior(int life, int magic, int attack);
	private:
		void effect_enemy();

		void effect_self();

		bool canUseJN();
	};

	// 法师类
	class F_Mage : public Fighter
	{
	public:
		F_Mage(int life, int magic, int attack);
	private:
		void effect_enemy();

		void effect_self();

		bool canUseJN();
	};
}
