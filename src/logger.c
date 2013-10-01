/**
 * logger - Simple C logging library
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

#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include <time.h>
#include "logger.h"

FILE *logger_file;

char *logger_priority_strings[] = {
	"EMERG", "ALERT", "CRIT", "ERROR", "WARNING", "NOTICE", "INFO", "DEBUG"
};

void logger_open(const char *filename)
{
	logger_file = fopen(filename, "a");
}

void logger_close()
{
	fclose(logger_file);
}

void logger (int priority, const char *format, ...)
{
	va_list args;

	time_t t = time(NULL);
	struct tm tm = *localtime(&t);

	fprintf(logger_file, "%.4d-%.2d-%.2d %.2d:%.2d:%.2d [%s] ",
		tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday,
		tm.tm_hour, tm.tm_min, tm.tm_sec,
		logger_priority_strings[priority]);

	va_start(args, format);
	vfprintf(logger_file, format, args);
	va_end(args);

	fprintf(logger_file, "\n");
	fflush(logger_file);
}
