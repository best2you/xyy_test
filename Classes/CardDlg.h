#ifndef CARDDLG_H_
#define CARDDLG_H_

#include "cocos2d.h"
#include "CardInfo\head.h"

class Card;
class CardDlg :
	public cocos2d::Node
{
public:
	CardDlg();
	~CardDlg();

	//*********
	//Param : card ������Ϣ
	//		: picBackPath  ���Ʊ���ͼƬ��ַ
	static CardDlg* create(Card *card, std::string &picBackPath);
	virtual bool init() override;
	void exInit(Card *card, std::string &picBackPath);
	
	//*********
	//�Ƿ���ʾ��falseΪ���棬trueΪ���档
	void setShow(bool show);

	//��ÿ���id
	SET_GET(int, nCardID);

	//��ÿ���������Ϣ
	SET_GET(std::string, strDescribe);

	//��ÿ�������
	SET_GET(std::string, strName);

private:
	bool m_bShow;
	cocos2d::Sprite *m_spCard;    //���ƾ���
	cocos2d::Sprite *m_spCardBk;  //���Ʊ��澫��
};
#endif