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
	static CardDlg* create(Card *card,const std::string &picBackPath);
	virtual bool init() override;
	void exInit(Card *card,const std::string &picBackPath);
	
	//*********
	//�Ƿ���ʾ��falseΪ���棬trueΪ���档
	void setShow(bool show);

	//�Ƿ�ѡ��trueΪѡ��
	void setSelect(bool select);

	//��ÿ���id
	SET_GET(int, nCardID);

	//��ÿ���������Ϣ
	SET_GET(std::string, strDescribe);

	//��ÿ�������
	SET_GET(std::string, strName);

	//��ÿ��ƵĸߺͿ�
	float Wide(){ return m_spCard->getBoundingBox().size.width; }
	float Hight(){ return m_spCard->getBoundingBox().size.height; }

	//�ж��Ƿ񱻰�ס
	bool isTouch(const cocos2d::Point &point);
protected:
	const int m_nMoveHeight;
	bool m_bShow;
	bool m_bSelect;
	cocos2d::Sprite *m_spCard;    //���ƾ���
	cocos2d::Sprite *m_spCardBk;  //���Ʊ��澫��
};
#endif