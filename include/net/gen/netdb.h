/*-
 * Copyright (c) 1980, 1983, 1988 Regents of the University of California.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 * 3. All advertising materials mentioning features or use of this software
 *    must display the following acknowledgement:
 *	This product includes software developed by the University of
 *	California, Berkeley and its contributors.
 * 4. Neither the name of the University nor the names of its contributors
 *    may be used to endorse or promote products derived from this software
 *    without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
 * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
 *
 *	@(#)netdb.h	5.15 (Berkeley) 4/3/91
 */

#ifndef _NETDB_H_
#define _NETDB_H_

#define	_PATH_HEQUIV	"/etc/hosts.equiv"
#define	_PATH_HOSTS	"/etc/hosts"
#define	_PATH_NETWORKS	"/etc/networks"
#define	_PATH_PROTOCOLS	"/etc/protocols"
#define	_PATH_SERVICES	"/etc/services"
#define	_PATH_SERVACCES	"/etc/serv.access"

/*
 * Structures returned by network data base library.  All addresses are
 * supplied in host order, and returned in network order (suitable for
 * use in system calls).
 */
struct	hostent {
	char	*h_name;	/* official name of host */
	char	**h_aliases;	/* alias list */
	int	h_addrtype;	/* host address type */
	int	h_length;	/* length of address */
	char	**h_addr_list;	/* list of addresses from name server */
#define	h_addr	h_addr_list[0]	/* address, for backward compatiblity */
};

/*
 * Assumption here is that a network number
 * fits in 32 bits -- probably a poor one.
 */
struct	netent {
	char		*n_name;	/* official name of net */
	char		**n_aliases;	/* alias list */
	int		n_addrtype;	/* net address type */
	unsigned long	n_net;		/* network # */
};

struct	servent {
	char	*s_name;	/* official service name */
	char	**s_aliases;	/* alias list */
	int	s_port;		/* port # */
	char	*s_proto;	/* protocol to use */
};

struct	protoent {
	char	*p_name;	/* official protocol name */
	char	**p_aliases;	/* alias list */
	int	p_proto;	/* protocol # */
};

/*
 * Error return codes from gethostbyname() and gethostbyaddr()
 * (left in extern int h_errno).
 */
extern int h_errno;

#define	HOST_NOT_FOUND	1 /* Authoritative Answer Host not found */
#define	TRY_AGAIN	2 /* Non-Authoritive Host not found, or SERVERFAIL */
#define	NO_RECOVERY	3 /* Non recoverable errors, FORMERR, REFUSED, NOTIMP */
#define	NO_DATA		4 /* Valid name, no data record of requested type */
#define	NO_ADDRESS	NO_DATA		/* no address, look for MX record */

#ifndef _MINIX_ANSI_H
#include <minix/ansi.h>
#endif

void		endhostent _ARGS((void));
void		endnetent _ARGS((void));
void		endprotoent _ARGS((void));
void		endservent _ARGS((void));
struct hostent	*gethostbyaddr _ARGS((const char *, int, int));
struct hostent	*gethostbyname _ARGS((const char *));
struct hostent	*gethostent _ARGS((void));
struct netent	*getnetbyaddr _ARGS((long, int)); /* u_long? */
struct netent	*getnetbyname _ARGS((const char *));
struct netent	*getnetent _ARGS((void));
struct protoent	*getprotobyname _ARGS((const char *));
struct protoent	*getprotobynumber _ARGS((int));
struct protoent	*getprotoent _ARGS((void));
struct servent	*getservbyname _ARGS((const char *, const char *));
struct servent	*getservbyport _ARGS((int, const char *));
struct servent	*getservent _ARGS((void));
void		herror _ARGS((const char *));
void		sethostent _ARGS((int));
/* void		sethostfile _ARGS((const char *)); */
void		setnetent _ARGS((int));
void		setprotoent _ARGS((int));
void		setservent _ARGS((int));
#ifdef _MINIX
int		servxcheck _ARGS((unsigned long _peer, const char *_service,
			void (*_logf) _ARGS((int _pass, const char *_name))));
char		*servxfile _ARGS((const char *_file));
#endif

/*  
 * The definitions below are based on 
 * http://www.opengroup.org/onlinepubs/009695399/basedefs/netdb.h.html
 */

#ifdef _POSIX_SOURCE

/* headers exposed by netdb.h */
#include <inttypes.h>
#include <netinet/in.h>
#include <sys/socket.h>

/* struct for use with getaddrinfo() */
struct addrinfo
{
	int              ai_flags;     /* Input flags */
	int              ai_family;    /* Address family of socket */
	int              ai_socktype;  /* Socket type */
	int              ai_protocol;  /* Protocol of socket */
	socklen_t        ai_addrlen;   /* Length of socket address */
	struct sockaddr *ai_addr;      /* Socket address of socket */
	char            *ai_canonname; /* Canonical name of service location */
	struct addrinfo *ai_next;      /* Pointer to next in list */
};

/* values for struct addrinfo.ai_flags */
#define AI_PASSIVE	0x00000001
#define AI_CANONNAME	0x00000002
#define AI_NUMERICHOST	0x00000004
#define AI_NUMERICSERV	0x00000008
/* 
#define AI_V4MAPPED	0x00000010
#define AI_ALL		0x00000020
#define AI_ADDRCONFIG	0x00000040
*/

/* flags for getnameinfo() */
/* #define NI_NOFQDN	0x00000001 */
#define NI_NUMERICHOST	0x00000002
#define NI_NAMEREQD	0x00000004
#define NI_NUMERICSERV	0x00000008
/* #define NI_NUMERICSCOPE	0x00000010 */
#define NI_DGRAM	0x00000020

/* error values for getaddrinfo() and getnameinfo() */
#define EAI_AGAIN	1
#define EAI_BADFLAGS	2
#define EAI_FAIL	3
#define EAI_FAMILY	4
#define EAI_MEMORY	5
#define EAI_NONAME	6
#define EAI_SERVICE	7
#define EAI_SOCKTYPE	8
#define EAI_SYSTEM	9
#define EAI_OVERFLOW	10

/* getaddrinfo() and friends */
void freeaddrinfo(struct addrinfo *ai);
int getaddrinfo(const char *nodename,
       const char *servname,
       const struct addrinfo *hints,
       struct addrinfo **res);
int getnameinfo(const struct sockaddr *sa, socklen_t salen,
       char *node, socklen_t nodelen, char *service,
       socklen_t servicelen, int flags);
const char *gai_strerror(int ecode);

#endif

#endif /* !_NETDB_H_ */

