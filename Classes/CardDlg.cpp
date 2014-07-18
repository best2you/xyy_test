#include "CardDlg.h"
#include "CardInfo\Card.h"

CardDlg::CardDlg() 
	:m_nMoveHeight(20)
{

}

CardDlg::~CardDlg()
{

}

CardDlg *CardDlg::create(Card *card,const std::string &picBackPath)
{
	auto dlg = new CardDlg();
	if (dlg && dlg->init())
	{
		dlg->autorelease();
		dlg->exInit(card,picBackPath);
		return dlg;
	}
	else
	{
		delete dlg;
		dlg = nullptr;
		return nullptr;
	}
}

bool CardDlg::init()
{
	return true;
}

void CardDlg::exInit( Card *card,const  std::string &picBackPath)
{
	m_spCard = cocos2d::Sprite::create(card->getPicturePath());
	addChild(m_spCard);
	m_spCard->setPosition(0, 0);
	m_spCard->setAnchorPoint(cocos2d::Point(0,0));
	m_spCard->setVisible(true);

	m_spCardBk = cocos2d::Sprite::create(picBackPath);
	addChild(m_spCardBk);
	m_spCardBk->setPosition(0, 0);
	m_spCardBk->setAnchorPoint(cocos2d::Point(0, 0));
	m_spCardBk->setVisible(false);

	m_nCardID = card->getID();

	m_strName = card->getName();

	// TODO : 缺少描述文本初始化
}

void CardDlg::setShow(bool show)
{
	m_spCardBk->setVisible(!show);
	m_spCard->setVisible(show);
}

void CardDlg::setSelect(bool select)
{
	m_spCard->setPositionY(m_spCard->getPositionX() + (select?m_nMoveHeight:0));
	m_spCardBk->setPositionX(m_spCardBk->getPositionX() + (select?m_nMoveHeight:0));
}

bool CardDlg::isTouch(const cocos2d::Point &point)
{
	auto nsp = m_spCard->convertToNodeSpace(point);
	auto anPoint = m_spCard->getAnchorPoint();
	auto bb = cocos2d::Rect(-Wide()*anPoint.x, Hight()*anPoint.y, Wide(), Hight());
	if (nsp.x >= bb.origin.x&&nsp.x <= bb.origin.x + bb.size.width 
		&& nsp.y >= bb.origin.y&&nsp.y <= bb.origin.y + bb.size.height)
	{
		return true;
	}
	return false;
}