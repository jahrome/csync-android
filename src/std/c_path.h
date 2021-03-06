/*
 * cynapses libc functions
 *
 * Copyright (c) 2007-2008 by Andreas Schneider <mail@cynapses.org>
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software Foundation,
 * Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
 *
 * vim: ft=c.doxygen ts=2 sw=2 et cindent
 */

/**
 * @file c_path.h
 *
 * @brief Interface of the cynapses libc path functions
 *
 * @defgroup cynPathInternals cynapses libc path functions
 * @ingroup cynLibraryAPI
 *
 * @{
 */

#ifndef _C_PATH_H
#define _C_PATH_H

#include "c_macro.h"

/**
 * @brief Parse directory component.
 *
 * dirname breaks a null-terminated pathname string into a directory component.
 * In the usual case, c_dirname() returns the string up to, but not including,
 * the final '/'. Trailing '/' characters are  not  counted as part of the
 * pathname. The caller must free the memory.
 *
 * @param path  The path to parse.
 *
 * @return  The dirname of path or NULL if we can't allocate memory. If path
 *          does not contain a slash, c_dirname() returns the string ".".  If
 *          path is the string "/", it returns the string "/". If path is
 *          NULL or an empty string, "." is returned.
 */
char *c_dirname(const char *path);

/**
 * @brief basename - parse filename component.
 *
 * basename breaks a null-terminated pathname string into a filename component.
 * c_basename() returns the component following the final '/'.  Trailing '/'
 * characters are not counted as part of the pathname.
 *
 * @param path The path to parse.
 *
 * @return  The filename of path or NULL if we can't allocate memory. If path
 *          is a the string "/", basename returns the string "/". If path is
 *          NULL or an empty string, "." is returned.
 */
char *c_basename (const char *path);

/**
 * @brief Make a temporary filename.
 *
 * @param template  Template to replace. The last six characters of template
 *                  must be XXXXXX and these are replaced with a string that
 *                  makes the filename more or less unique. Since it will be
 *                  modified, template must not be a string constant, but
 *                  should be declared as a character array.
 *
 * @return 0 on succes, < 0 on error with errno set.
 */
int c_tmpname(char *template);

/**
 * @brief parse a uri and split it into components.
 *
 * parse_uri parses an uri in the format
 *
 * [<scheme>:][//[<user>[:<password>]@]<host>[:<port>]]/[<path>]
 *
 * into its compoments. If you only want a special component,
 * pass NULL for all other components. All components will be allocated if they have
 * been found.
 *
 * @param uri       The uri to parse.
 * @param scheme    String for the scheme component
 * @param user      String for the username component
 * @param passwd    String for the password component
 * @param host      String for the password component
 * @param port      Integer for the port
 * @param path      String for the path component with a leading slash.
 *
 * @return  0 on success, < 0 on error.
 */
int c_parse_uri(const char *uri, char **scheme, char **user, char **passwd,
    char **host, unsigned int *port, char **path);

/**
 * }@
 */
#endif /* _C_PATH_H */
