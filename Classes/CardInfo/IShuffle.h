#pragma once
#include "vector"
#include "map"
#include <algorithm>

class Card;

class IShuffle
{
public:
	IShuffle();
/*
* @remarks
	�����Ƶ��������
* @param
	�����Ƶ��б�
	error!!!
*/
void setList(const std::map<int ,Card*> &list)
{
	for(auto i = list.begin(); i != list.end();i++)
	{
		this->mShowCardList.push_back(i->first);
	}
	std::random_shuffle(mShowCardList.begin(), mShowCardList.end(),[](int i){return rand()%i;});
}
/*
* @remarks
	�����Ƶ��������
* @param
	�����Ƶ��б�
*/
	void setList(std::map<int ,int > &list);
/*
* @return 
	���ط���ֵ����Ϊ�㣬����ȡ��������
*/
	int getOne();
/*
* @return 
	����ʣ���ƶѿ�����
*/
	int getSurplus();
protected:
	int heat;
	std::vector<int> mShowCardList;
};