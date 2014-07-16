#ifndef CARDLISTDLG_H_
#define CARDLISTDLG_H_

#include "cocos2d.h"
#include "CC_Singleton.h"
#include "CardInfo/head.h"

class Card;
class CardDlg;

class CardListDlg:
	public cocos2d::Layer
{
public:
	enum class Model
	{
		single,			//��ѡһ��
		multiple,		//��ѡ
		sort,			//����
		sort_giveup,	//�����з�������
	};
	
	//��������Զ�������������꿨�ƺ��ٵ�����ʾ������������ֲ���Ҫ�Ŀ���Ч��
	static CardListDlg *create(Model model);
	CardListDlg();
	virtual bool init()override;

	// TODO: ��Ӱ�����Ӧ����

	////////////

	//�����б����ͣ�Ĭ��Ϊ��ѡ
	CC_SYNTHESIZE(Model, m_eModel, Model);

	//�����б��Ϸ��߶�
	CC_SYNTHESIZE(float, m_nTopDist, TopDist);

	//�����б��·��߶�
	CC_SYNTHESIZE(float, m_nBottonDist, BottonDist);

	//���ÿ���֮�����
	CC_SYNTHESIZE(float, m_nCardDist, CardDist);

	//���б������ӿ���
	//param �� cardID ����id
	void addCard(int cardID);
	void addCard(Card *card);

	//���ѡ�񵥸�����id��������singleģʽ������ģʽ�򷵻����һ����ѡ�Ŀ���
	//return �� ����id,��û��ѡ�񷵻�-1
	int  getSelectCard(){ return m_nSelectCardID; }

	//���ѡ�����б�id
	//return �� ��Ϊmultiple������ѡ����б�
	//			��Ϊsort�������������б�
	//			��Ϊsort_giveup ����ѡ�񲿷ֵ��б�
	std::vector<int> &getChoseCardList(){ return m_vChoseCardList; }

	//��÷������ֵĿ���id�� ��������sort_giveupģʽ������ģʽ���ؿ��б�
	//return �� ����id�б�
	std::vector<int> &getGiveupCardList(){ return m_vGiveupCardList; }

protected:
	//���¿�������
	void updateCardList();

protected:
	std::vector<CardDlg*> m_vCardList;		//�����б�
	std::vector<int> m_vChoseCardList;		//ѡ�����б�
	std::vector<int> m_vGiveupCardList;		//���������б�
	int   m_nSelectCardID;					//ѡ��Ŀ���id
};
#endif