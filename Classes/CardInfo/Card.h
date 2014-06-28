#ifndef CARD_H_
#define CARC_H_

#include "head.h"
#include <vector>

class Card
{
public:
	Card();
	enum class MODEL{ Primary , Expert };
	SET_GET(int , ID);
	SET_GET_N(char , Name , 20);
	SET_GET_N(char , PicturePath,30);
	SET_GET(MODEL , Model);
};

class CardHand:
	public Card
{
public:
	CardHand();
	enum class TYPE{ Equip , Armor , SkillCard , Fight , Special};
	SET_GET(TYPE,Type);
	void setSkill(int skill_id);
	int getSkill(int skill_nom);  //more than 2(barring 2) return -1
protected:
	int mSkillList[2];
};

class CardMonster:
	public Card
{
public:
	CardMonster();
	enum class TYPE{wind,mine,water,fire,soil,};
	enum class CONDITION{out,win,lose,pet,};
	SET_GET(TYPE,Type);
	SET_GET(int ,Hit);
	SET_GET(int ,Attack);
	void setSkill(CONDITION condition,int skill_id);
	int getSkill(CONDITION condition);
protected:
	int mSkillList[4];
};

class CardNpc:
	public Card
{
public:
	CardNpc();
	SET_GET(int ,Hp);
	SET_GET(int ,Hit);
	SET_GET(int ,Attack);
	SET_GET(bool,Gender);
	void setAdore(int adore_id);
	std::vector<int> &getAdore();
	void setSkill(int skill_id);
	int getSkill(int skill_nom); // error return -1;
protected:
	std::vector<int> mAdore;
	std::vector<int> mSkillList;
};

class CardEvent:
	public Card
{
public:
	CardEvent();
	SET_GET_N(char , Test , 100);
	SET_GET(int ,SkillId);
};
#endif