#include <QTextStream>

extern QString namesOfNumbers[];

int main ( int argc, char* argv[] ) {
	/// Добавить метод разбора параметров командной строки.
	( void )argc;	( void )argv;

	QTextStream stream( stdout );
	for ( uint i = 0; i < 10; i++ ) {
		stream << namesOfNumbers[ i ] << " " << endl;
	}

	return 0;
}
