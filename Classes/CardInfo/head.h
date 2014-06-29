#ifndef HEAD_H_
#define HEAD_H_

#include <iostream>

#define SET_GET_FUNC(__type__,__name__,__func__) protected:__type__ m_##__name__;\
											public:const __type__ &get##__func__()const {return m_##__name__;}\
											public:void set##__func__(const __type__ &var){m_##__name__ = var;}

#define SET_FUNC(__type__,__name__,__func__) protected:__type__ m_##__name__;\
										public:void set##__func__(const __type__ &var){m_##__name__ = var;}

#define GET_FUNC(__type__,__name__,__func__) protected:__type__ m_##__name__;\
										public:const __type__ &get##__func__()const {return m_##__name__;}

#define SET_GET(__type__,__name__) SET_GET_FUNC(__type__,__name__,__name__)

#define SET(__type__,__name__) SET_FUNC(__type__,__name__,__name__)

#define GET(__type__,__name__) GET_FUNC(__type__,__name__,__name__) 

#define SET_GET_FUNC_N(__type__,__name__,__num__,__func__) \
	protected:__type__ m_##__name__[__num__];\
	public:__type__ *get##__func__(){return m_##__name__;}\
	public:void set##__func__(const __type__ *var){strcpy(m_##__name__,var);}

#define SET_FUNC_N(__type__,__name__,__num__,__func__) protected:__type__ m_##__name__[__num__];\
										public:void set##__func__(const __type__ &var){strcpy(m_##__name__,var);}

#define GET_FUNC_N(__type__,__name__,__num__,__func__) protected:__type__ m_##__name__[__num__];\
										public:__type__ *get##__func__(){return m_##__name__;}

#define SET_GET_N(__type__,__name__,__num__) SET_GET_FUNC_N(__type__,__name__,__num__,__name__)

#define SET_N(__type__,__name__,__num__) SET_FUNC_N(__type__,__name__,__num__,__name__)

#define GET_N(__type__,__name__,__num__) GET_FUNC_N(__type__,__name__,__num__,__name__) 

#define V_SET_GET_FUNC(__type__,__name__,__func__) protected:__type__ m_##__name__;\
											public:__type__ get##__func__();\
											public:void set##__func__(const __type__ &var);

#define V_SET_FUNC(__type__,__name__,__func__) protected:__type__ m_##__name__;\
										public:void set##__func__(const __type__ &var);

#define V_GET_FUNC(__type__,__name__,__func__) protected:__type__ m_##__name__;\
										public:__type__ get##__func__();

#define V_SET_GET(__type__,__name__) V_SET_GET_FUNC(__type__,__name__,__name__)

#define V_SET(__type__,__name__) V_SET_FUNC(__type__,__name__,__name__)

#define V_GET(__type__,__name__) V_GET_FUNC(__type__,__name__,__name__) 

enum class STATUS{openning,	//����			0
		bout,				//�غ�			1	
		events,				//�¼�			2
		skill_begin,		//����			3
		skill,				//����			4
		skill_end,			//����			5
		fight_round_end,	//ս������ȡ���ƺ�6
		fight,				//ս��			7
		settlement,			//����			8
		pickup,				//����			9
		IV,					//����			10
		bout_end,			//�غϽ���		11
		ending,				//����			12
		die,				//����			13
		reply,				//��Ѫ			14
		hurt,				//��Ѫ			15
		show_card,			//����			16
		whenever,			//�κ�ʱ��		17
		fight_round_begin,	//ս������ȡ����ǰ��18
};
#endif