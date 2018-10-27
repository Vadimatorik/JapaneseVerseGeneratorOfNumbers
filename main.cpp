#include "global_data.h"
#include "generator.h"
#include "numeric_string_generator.h"

QTextStream outStream( stdout );

void printVector ( QVector< uint > d ) {
	for ( auto outData : d ) {
		outStream << outData << ' ';
	}
	outStream << endl;
}

int main ( int argc, char* argv[] ) {
	/// Добавить метод разбора параметров командной строки.
	( void )argc;	( void )argv;

	initRandomGenerator();

	printVector( convertRhymeStringToNumbersArray( "Oo Oo Oo Oo" ) );
	printVector( convertRhymeStringToNumbersArray( "Oo Ooo oO" ) );

	return 0;
}
