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
#include <stdbool.h>
#include <signal.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>
#include "logger.h"

bool terminate;
bool daemonize;

void signal_handler(int signal)
{
	logger(LOG_NOTICE, "Received %s signal", strsignal(signal));
	terminate = true;
}

void *watcher(void *args)
{
	while (!terminate)
	{
		logger(LOG_DEBUG, "watcher beat");
	}
}

void *syncer(void *args)
{
	while (!terminate)
	{
		logger(LOG_DEBUG, "syncer beat");
	}
}

int main(int argc, char *argv[])
{
	terminate = false;
	daemonize = false;

	pthread_t watcher_thread, syncer_thread;

	// posix daemon (fork, setid and close file descriptors)
	if (daemonize && (daemon(1, 0) < 0))
		return EXIT_FAILURE;

	// initialize logging
	logger_open("nsyncd.log");

	// signal handler
	signal(SIGHUP,  signal_handler);
	signal(SIGINT,  signal_handler);
	signal(SIGTERM, signal_handler);
	signal(SIGQUIT, signal_handler);

	logger(LOG_NOTICE, "Starting %s %s", PACKAGE_NAME, PACKAGE_VERSION);

	printf("%s %s\n", PACKAGE_NAME, PACKAGE_VERSION);

	// create file watcher and syncronization threads
	pthread_create(&watcher_thread, NULL, watcher, NULL);
	pthread_create(&syncer_thread, NULL, syncer, NULL);

	// wait for threads termination
	pthread_join(watcher_thread, NULL);
	pthread_join(syncer_thread, NULL);

	// close logging
	logger_close();

	return EXIT_SUCCESS;
}
