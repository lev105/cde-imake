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
/* $XConsortium: tokscan.c /main/3 1995/11/01 18:53:10 rswiston $ */
/***************************************************************
*                                                              *
*                      AT&T - PROPRIETARY                      *
*                                                              *
*         THIS IS PROPRIETARY SOURCE CODE LICENSED BY          *
*                          AT&T CORP.                          *
*                                                              *
*                Copyright (c) 1995 AT&T Corp.                 *
*                     All Rights Reserved                      *
*                                                              *
*           This software is licensed by AT&T Corp.            *
*       under the terms and conditions of the license in       *
*       http://www.research.att.com/orgs/ssr/book/reuse        *
*                                                              *
*               This software was created by the               *
*           Software Engineering Research Department           *
*                    AT&T Bell Laboratories                    *
*                                                              *
*               For further information contact                *
*                     gsf@research.att.com                     *
*                                                              *
***************************************************************/

/* : : generated by proto : : */

#if !defined(__PROTO__)
#if defined(__STDC__) || defined(__cplusplus) || defined(_proto) || defined(c_plusplus)
#if defined(__cplusplus)
#define __MANGLE__	"C"
#else
#define __MANGLE__
#endif
#define __STDARG__
#define __PROTO__(x)	x
#define __OTORP__(x)
#define __PARAM__(n,o)	n
#if !defined(__STDC__) && !defined(__cplusplus)
#if !defined(c_plusplus)
#define const
#endif
#define signed
#define void		int
#define volatile
#define __V_		char
#else
#define __V_		void
#endif
#else
#define __PROTO__(x)	()
#define __OTORP__(x)	x
#define __PARAM__(n,o)	o
#define __MANGLE__
#define __V_		char
#define const
#define signed
#define void		int
#define volatile
#endif
#if defined(__cplusplus) || defined(c_plusplus)
#define __VARARG__	...
#else
#define __VARARG__
#endif
#if defined(__STDARG__)
#define __VA_START__(p,a)	va_start(p,a)
#else
#define __VA_START__(p,a)	va_start(p)
#endif
#define va_listval(p)		(*(p))
#define va_listarg		va_list*
#endif
#include <ast.h>
#if defined(va_copy)
#define __VA_COPY__(d,s) va_copy(d,s)
#else
#define __VA_COPY__(d,s) __va_copy(d,s)
#endif

static char	empty[1];

/*
 * get one string token into p
 */

static char*
lextok __PARAM__((char* s, int c, char** p, int* n), (s, c, p, n)) __OTORP__(char* s; int c; char** p; int* n;){
	char*	t;
	int	q;
	char*		b;
	char*		u;

	if (*s == '(' && (!c || c == ' ' || c == '\n'))
	{
		q = strtol(s + 1, &b, 10);
		if (*b == ':')
		{
			if (*(t = ++b + q) == ')' || *t == '\t')
			{
				s = t;
				*s++ = 0;
				goto end;
			}
		}
		else if (strneq(b, "null)", 5))
		{
			s = b + 5;
			b = 0;
			goto end;
		}
	}
	b = s;
	q = 0;
	t = 0;
	for (;;)
	{
		if (!*s || !q && *s == '\n')
		{
			if (!q)
			{
				if (!c || c == ' ' || c == '\n') (*n)++;
				else
				{
					s = b;
					b = empty;
					break;
				}
			}
			if (t) *t = 0;
			break;
		}
		else if (*s == '\\')
		{
			u = s;
			if (!*++s || *s == '\n' && (!*++s || *s == '\n')) continue;
			if (p)
			{
				if (b == u) b = s;
				else if (!t) t = u;
			}
		}
		else if (q)
		{
			if (*s == q)
			{
				q = 0;
				if (!t) t = s;
				s++;
				continue;
			}
			else if (*s == '\r') *s = '\n';
		}
		else if (*s == '"' || *s == '\'')
		{
			q = *s++;
			if (p)
			{
				if (b == (s - 1)) b = s;
				else if (!t) t = s - 1;
			}
			continue;
		}
		else if (*s == c || c == ' ' && *s == '\t')
		{
			*s++ = 0;
			if (t) *t = 0;
		end:
			if (c == ' ') while (*s == ' ' || *s == '\t') s++;
			(*n)++;
			break;
		}
		if (t) *t++ = *s;
		s++;
	}
	if (p) *p = b;
	return(s);
}

/*
 * scan entry
 */

int
tokscan __PARAM__((char* s, char** nxt, const char* fmt, ...), (va_alist)) __OTORP__(va_dcl)
{ __OTORP__(char* s; char** nxt; const char* fmt; )
	int	c;
	char*	f;
	int		num = 0;
	char*		skip = 0;
	int		q;
	int		onum;
	long		val;
	va_list		ap;
	char*		p_char;
	int*		p_int;
	long*		p_long;
	short*		p_short;
	char**		p_string;
	char*		prv_f = 0;
	va_list		prv_ap;

	__VA_START__(ap, fmt); __OTORP__(s = va_arg(ap, char* );nxt = va_arg(ap, char** );fmt = va_arg(ap, const char* );)
	if (!*s || *s == '\n')
	{
		skip = s;
		s = empty;
	}
	f = (char*)fmt;
	for (;;) switch (c = *f++)
	{
	case 0:
		if (f = prv_f)
		{
			prv_f = 0;
			__VA_COPY__( ap, prv_ap );
			continue;
		}
		goto done;
	case ' ':
		while (*s == ' ' || *s == '\t') s++;
		break;
	case '%':
		onum = num;
		switch (c = *f++)
		{
		case 'h':
		case 'l':
			q = c;
			c = *f++;
			break;
		default:
			q = 0;
			break;
		}
		switch (c)
		{
		case 0:
		case '%':
			f--;
			continue;
		case ':':
			prv_f = f;
			f = va_arg(ap, char*);
			__VA_COPY__( prv_ap, ap );
			__VA_COPY__(ap, va_listval(va_arg(ap, va_listarg)));
			continue;
		case 'c':
			p_char = va_arg(ap, char*);
			if (!(c = *s) || c == '\n')
			{
				if (p_char) *p_char = 0;
			}
			else
			{
				if (p_char) *p_char = c;
				s++;
				num++;
			}
			break;
		case 'd':
		case 'n':
		case 'o':
		case 'u':
		case 'x':
			switch (c)
			{
			case 'd':
				c = 10;
				break;
			case 'n':
			case 'u':
				c = 0;
				break;
			case 'o':
				c = 8;
				break;
			case 'x':
				c = 16;
				break;
			}
			if (!*s || *s == '\n')
			{
				val = 0;
				p_char = s;
			}
			else val = strtol(s, &p_char, c);
			switch (q)
			{
			case 'h':
				if (p_short = va_arg(ap, short*)) *p_short = val;
				break;
			case 'l':
				if (p_long = va_arg(ap, long*)) *p_long = val;
				break;
			default:
				if (p_int = va_arg(ap, int*)) *p_int = val;
				break;
			}
			if (s != p_char)
			{
				s = p_char;
				num++;
			}
			break;
		case 's':
			p_string = va_arg(ap, char**);
			if (q = *f) f++;
			if (!*s || *s == '\n')
			{
				if (p_string) *p_string = s;
			}
			else s = lextok(s, q, p_string, &num);
			break;
		case 'v':
			p_string = va_arg(ap, char**);
			c = va_arg(ap, int);
			if (q = *f) f++;
			if ((!*s || *s == '\n') && p_string)
			{
				*p_string = 0;
				p_string = 0;
			}
			while (*s && *s != '\n' && --c > 0)
			{
				s = lextok(s, q, p_string, &num);
				if (p_string) p_string++;
			}
			if (p_string) *p_string = 0;
			break;
		}
		if (skip) num = onum;
		else if (num == onum)
		{
			if (!num) num = -1;
			skip = s;
			s = empty;
		}
		break;
	case '\n':
		goto done;
	default:
		if ((*s++ != c) && !skip)
		{
			skip = s - 1;
			s = empty;
		}
		break;
	}
 done:
	va_end(ap);
	if (*s == '\n') *s++ = 0;
	if (nxt) *nxt = skip ? skip : s;
	return(num);
}
