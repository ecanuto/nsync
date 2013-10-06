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

#include <stdio.h>
#include <stdarg.h>
#include "nsyncd.h"
#include "logger.h"
#include "watcher.h"

void *watcher(void *args)
{
	while (!terminate)
	{
		logger(LOG_DEBUG, "watcher beat");
	}
}