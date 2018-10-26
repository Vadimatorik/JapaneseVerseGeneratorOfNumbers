#include <QString>

extern QString namesOfNumbers[];

extern uint	characterType_o[];
extern uint	characterType_O[];
extern uint	characterType_Oo[];
extern uint	characterType_OO[];

QString namesOfNumbers[] = {
	QString( "ゼロ" ),
	QString( "いち" ),
	QString( "に" ),
	QString( "さん" ),
	QString( "よん" ),
	QString( "ご" ),
	QString( "ろく" ),
	QString( "なな" ),
	QString( "はち" ),
	QString( "きゅう" ),
	QString( "じゅう" )
};

uint	characterType_o[ 2 ]	=	{ 2, 9 };
uint	characterType_O[ 3 ]	=	{ 3, 4, 5 };
uint	characterType_Oo[ 3 ]	=	{ 1, 6, 8 };
uint	characterType_OO[ 1 ]	=	{ 7 };
