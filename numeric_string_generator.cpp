#include "global_data.h"
#include "generator.h"

extern uint	characterType_o[ 2 ];
extern uint	characterType_O[ 3 ];
extern uint	characterType_Oo[ 3 ];
extern uint	characterType_OO[ 1 ];

static uint getNumberInOneChar ( QString word ) {
	uint	returnValue;
	uint	pos;

	if ( word == "O" ) {
		pos = static_cast< uint >( gatRandomBetweenValue( 0, sizeof( characterType_O ) / sizeof( characterType_O[ 0 ] ) - 1 ) );
		returnValue = characterType_O[ pos ];
	} else {
		pos = static_cast< uint >( gatRandomBetweenValue( 0, sizeof( characterType_o ) / sizeof( characterType_o[ 0 ] ) - 1 ) );
		returnValue = characterType_o[ pos ];
	}

	return returnValue;
}

static uint getNumberInTwoChar ( QString word ) {
	uint	returnValue;
	uint	pos;

	if ( word == "Oo" ) {
		pos = static_cast< uint >( gatRandomBetweenValue( 0, sizeof( characterType_Oo ) / sizeof( characterType_Oo[ 0 ] ) - 1 ) );
		returnValue = characterType_Oo[ pos ];
	} else if ( word == "OO" ) {
		returnValue = characterType_OO[ gatRandomBetweenValue( 0, sizeof( characterType_Oo ) / sizeof( characterType_Oo[ 0 ] ) - 1 )];
	} else if ( word == "oO" ) {
		pos = static_cast< uint >( gatRandomBetweenValue( 0, sizeof( characterType_O ) / sizeof( characterType_O[ 0 ] ) - 1 ) );
		returnValue = 10 + characterType_O[ pos ];
	} else {		/// oo.
		pos = static_cast< uint >( gatRandomBetweenValue( 0, sizeof( characterType_o ) / sizeof( characterType_o[ 0 ] ) - 1 ) );
		returnValue = 10 + characterType_o[ pos ];
	}

	return returnValue;
}

static uint getNumberInThreeChar ( QString word ) {
	uint	returnValue;

	if ( word.at( 1 ) == 'o' ) {
		returnValue = getNumberInOneChar( word.at( 0 ) );
		returnValue *= 10;
		returnValue += getNumberInOneChar( word.at( 2 ) );
	} else if ( word.at( 0 ) == 'o' ) {			/// oOx.
		QString	char2Word( word.remove( 0, 1 ) );
		returnValue = 10 * getNumberInOneChar( char2Word );
	} else {
		outStream << "Стопы типа <<" << word << ">> не существует!";
		exit( 0 );
	}

	return returnValue;
}

static uint convertWordToNumber ( QString word ) {
	uint	returnValue	=	0;
	uint	lenWordChar	=	0;

	lenWordChar	=	static_cast< uint >( word.length() );

	if ( lenWordChar == 1 ) {
		returnValue = getNumberInOneChar( word );
	} else if ( lenWordChar == 2 ) {
		/// 20 - исключение и читается иначе.
		do {
			returnValue = getNumberInTwoChar( word );
		} while ( returnValue == 20 );
	} else if ( lenWordChar == 3 ) {
		returnValue = getNumberInThreeChar( word );
	};

	return returnValue;
}

QVector< uint > convertRhymeStringToNumbersArray ( QString rhymeString ) {
	QVector< uint >		returnVector;

	/// Разбиваем строку на "слова".
	QStringList	words;
	words = rhymeString.split( " " );

	/// Преобразовываем последовательно все слова.
	for ( QString word : words ) {
		returnVector.append( convertWordToNumber( word ) );
	}

	return returnVector;
}
