/*
 * CDE - Common Desktop Environment
 *
 * Copyright (c) 1993-2012, The Open Group. All rights reserved.
 *
 * These libraries and programs are free software; you can
 * redistribute them and/or modify them under the terms of the GNU
 * Lesser General Public License as published by the Free Software
 * Foundation; either version 2 of the License, or (at your option)
 * any later version.
 *
 * These libraries and programs are distributed in the hope that
 * they will be useful, but WITHOUT ANY WARRANTY; without even the
 * implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
 * PURPOSE. See the GNU Lesser General Public License for more
 * details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with these libraries and programs; if not, write
 * to the Free Software Foundation, Inc., 51 Franklin Street, Fifth
 * Floor, Boston, MA 02110-1301 USA
 */
/*
 * File:         XeUserMsg.h $XConsortium: XeUserMsg.h /main/3 1995/10/26 15:46:16 rswiston $
 * Language:     C
 *
 * (c) Copyright 1988, Hewlett-Packard Company, all rights reserved.
 *
 * (c) Copyright 1993, 1994 Hewlett-Packard Company			*
 * (c) Copyright 1993, 1994 International Business Machines Corp.	*
 * (c) Copyright 1993, 1994 Sun Microsystems, Inc.			*
 * (c) Copyright 1993, 1994 Novell, Inc.				*
 */

#ifndef _XeUserMsg_h
#define _XeUserMsg_h

#include <bms/sbport.h>

/* Global Variables */
/* ---------------- */

extern XeString XeProgName; /* saves value of arg[0] */

#if defined(__STDC__) || defined(__cplusplus) || defined(c_plusplus)
typedef enum {
  XeIgnore,
  XeInformation,
  XeWarning,
  XeError,
  XeFatalError,
  XeInternalError
} XeSeverity;
#else
# define XeIgnore 0
# define XeInformation 1
# define XeWarning 2
# define XeError 3
# define XeFatalError 4
# define XeInternalError 5
  typedef int XeSeverity;
#endif

#define export	              /* Use this noop to mark non-static procedures. */

#endif /* _XeUserMsg_h */
/* DON'T ADD STUFF AFTER THIS #endif */
