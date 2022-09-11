#ifndef __COMM_H__
#define __COMM_H__

//5XXX -- 用户操作
#define OK                  5000	//操作成功
#define REGISTER            5001	//注册
#define LOGIN               5002	//登录
#define SIGNLE_GETQUESTION	5003	//个人训练获取题目
#define RANK                5004	//排位赛
#define ANSWER              5005	//排位赛中回答问题
#define RANKOVER            5006    //排位赛结束,将结果发给服务器
#define CANCEL              5007 	//取消匹配

//6XXX -- 管理员操作
#define ADMIN               6000	//管理员上线
#define RANKLIST            6001    //管理员查看排名
#define ADVERT              6002    //广告

//8XXX -- 发生错误
#define ERROR               8001	//未知错误
#define USEREXIST           8002	//用户已存在
#define NAMEORPASSWORD		8003    //账号(用户名)或密码错误
#define USERLOGIN           8004	//用户已登录
#define ENEMYERROR          8005    //对手在答题时掉线

//其它
#define QUESTION_NUM 		5       //每次答题获取的题目数(包括rank和single)

#endif


