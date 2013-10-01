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

#ifndef __LOGGER_H__
#define __LOGGER_H__

#define	LOG_EMERG	0	/* system is unusable */
#define	LOG_ALERT	1	/* action must be taken immediately */
#define	LOG_CRIT	2	/* critical conditions */
#define	LOG_ERR		3	/* error conditions */
#define	LOG_WARNING	4	/* warning conditions */
#define	LOG_NOTICE	5	/* normal but significant condition */
#define	LOG_INFO	6	/* informational */
#define	LOG_DEBUG	7	/* debug-level messages */

extern void logger_open(const char *);
extern void logger_close();
extern void logger(int, const char *, ...);

#endif /* __LOGGER_H__ */
