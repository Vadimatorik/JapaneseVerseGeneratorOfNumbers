#include <QTime>

int gatRandomBetweenValue ( int low, int high ) {
	return ( qrand() % ( ( high + 1 ) - low ) + low );
}

void initRandomGenerator ( void ) {
	QTime midnight( 0, 0, 0 );
	qsrand( static_cast< uint >( midnight.secsTo( QTime::currentTime() ) ) );
}
