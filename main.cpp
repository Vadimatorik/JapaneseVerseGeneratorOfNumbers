#include <QTextStream>
#include <QString>
#include <QStringList>
#include <QTime>

QTextStream outStream( stdout );

extern QString namesOfNumbers[];


static int gatRandomBetweenValue ( int low, int high ) {
	return ( qrand() % ( ( high + 1 ) - low ) + low );
}


/*!
 *		\brief		Печатает аналог слова состоящего
 *					из одного ударного символа.
 */
void printOneElement ( void ) {
	uint numberIndex;
	numberIndex	=	gatRandomBetweenValue( 0, 5 );
	static const uint oneElementNumbers[] = { 2, 3, 4, 5, 9, 10 };
	outStream << namesOfNumbers[ oneElementNumbers[ numberIndex ] ];
}

void printTwoElement ( QString wordCodeString  ) {
	uint numberIndex;

	if ( wordCodeString == "OO" ) {
		numberIndex	=	gatRandomBetweenValue( 0, 1 );

		if ( numberIndex == 0 ) {
			outStream << namesOfNumbers[ 7 ];
		} else {
			numberIndex	=	gatRandomBetweenValue( 0, 1 );
			static const uint owoElementOONumbers[] = { 7 };
		}


	}
}

/*!
 *		\biref		Печатает одну строку стиха
 *					(из ритмического представления
 *					в требуемый).
 */
void printString ( QString codeLineOfVerse ) {
	/// Разбиваем строку на "слова".
	QStringList	rhymeStringArray;
	rhymeStringArray = codeLineOfVerse.split( " " );

	/// Идем по всем "словам" строки.
	for ( uint itemCounter = 0; itemCounter < rhymeStringArray.size(); itemCounter++ ) {
		uint lenItem;
		lenItem	=	rhymeStringArray.at( itemCounter ).size();

		if ( lenItem == 1 ) {
			printOneElement();
		}
	}
}


QString rhyme( "o Oo Oo Oo" );
//QString rhyme(	"Oo Ooo oO"		);

int main ( int argc, char* argv[] ) {
	/// Добавить метод разбора параметров командной строки.
	( void )argc;	( void )argv;

	QTime midnight( 0, 0, 0 );
	qsrand( static_cast< uint >( midnight.secsTo( QTime::currentTime() ) ) );

	printString( rhyme );



/*

	for ( uint i = 0; i < 10; i++ ) {
		stream << namesOfNumbers[ i ] << " " << endl;
	}
*/
	return 0;
}
