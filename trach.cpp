
/*
 *		\brief		Печатает аналог слова состоящего
 *					из одного ударного символа.

void printOneElement ( void ) {
	uint numberIndex;
	numberIndex	=	static_cast< uint >( gatRandomBetweenValue( 0, 5 ) );
	static const uint oneElementNumbers[] = { 2, 3, 4, 5, 9, 10 };
	outStream << namesOfNumbers[ oneElementNumbers[ numberIndex ] ];
}

void printTwoElement ( QString wordCodeString  ) {
	uint numberIndex;

	if ( wordCodeString == "OO" ) {
		numberIndex	=	static_cast< uint >( gatRandomBetweenValue( 0, 1 ) );

		if ( numberIndex == 0 ) {
			outStream << namesOfNumbers[ 7 ];
		} else {
			numberIndex	=	static_cast< uint >( gatRandomBetweenValue( 0, 1 ) );
			static const uint owoElementOONumbers[] = { 7 };
		}


	}
}



 *		\biref		Печатает одну строку стиха
 *					(из ритмического представления
 *					в требуемый).
void printString ( QString codeLineOfVerse ) {
	/// Разбиваем строку на "слова".
	QStringList	rhymeStringArray;
	rhymeStringArray = codeLineOfVerse.split( " " );
	uint numberItems = static_cast< uint >( rhymeStringArray.size() );
	/// Идем по всем "словам" строки.
	for ( uint itemCounter = 0; itemCounter < numberItems; itemCounter++ ) {
		uint lenItem;
		lenItem	=	rhymeStringArray.at( itemCounter ).size();

		if ( lenItem == 1 ) {
			printOneElement();
		}
	}
}

*/

