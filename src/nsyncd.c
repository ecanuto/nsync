/**
 * nsyncd - File syncronization tool
 *
 * Author(s): Everaldo Canuto <everaldo.canuto@gmail.com>
 *
 * The author disclaims copyright to this source code.  In place of a legal
 * notice, here is a blessing:
 *
 *    May you do good and not evil.
 *    May you find forgiveness for yourself and forgive others.
 *    May you share freely, never taking more than you give.
 */

#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <stdio.h>
#include <stdlib.h>
#include "logger.h"

int main(int argc, char *argv[])
{
	// initialize logging
	logger_open("nsyncd.log");

	logger(LOG_NOTICE, "Starting %s %s", PACKAGE_NAME, PACKAGE_VERSION);

	printf("%s %s\n", PACKAGE_NAME, PACKAGE_VERSION);

	// close logging
	logger_close();

	return EXIT_SUCCESS;
}
