/* Copyright (C) 2013 Codership Oy <info@codership.com>

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; version 2 of the License.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License along
   with this program; if not, write to the Free Software Foundation, Inc.,
   51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA. */

#if !defined(WSREP_SST_H) && defined(WITH_WSREP)
#define WSREP_SST_H

#include <mysql.h>                    // my_bool

#define WSREP_SST_OPT_ROLE     "--role"
#define WSREP_SST_OPT_ADDR     "--address"
#define WSREP_SST_OPT_AUTH     "--auth"
#define WSREP_SST_OPT_DATA     "--datadir"
#define WSREP_SST_OPT_CONF     "--defaults-file"
#define WSREP_SST_OPT_PARENT   "--parent"
#define WSREP_SST_OPT_BINLOG   "--binlog"

// mysqldump-specific options
#define WSREP_SST_OPT_USER     "--user"
#define WSREP_SST_OPT_PSWD     "--password"
#define WSREP_SST_OPT_HOST     "--host"
#define WSREP_SST_OPT_PORT     "--port"
#define WSREP_SST_OPT_LPORT    "--local-port"

// donor-specific
#define WSREP_SST_OPT_SOCKET   "--socket"
#define WSREP_SST_OPT_GTID     "--gtid"
#define WSREP_SST_OPT_BYPASS   "--bypass"

#define WSREP_SST_MYSQLDUMP    "mysqldump"
#define WSREP_SST_RSYNC        "rsync"
#define WSREP_SST_SKIP         "skip"
#define WSREP_SST_DEFAULT      WSREP_SST_RSYNC
#define WSREP_SST_ADDRESS_AUTO "AUTO"
#define WSREP_SST_AUTH_MASK    "********"

/* system variables */
extern const char* wsrep_sst_method;
extern const char* wsrep_sst_receive_address;
extern const char* wsrep_sst_donor;
extern       char* wsrep_sst_auth;
extern    my_bool  wsrep_sst_donor_rejects_queries;

/*! Synchronizes applier thread start with init thread */
extern void wsrep_sst_grab();
/*! Init thread waits for SST completion */
extern bool wsrep_sst_wait();
/*! Signals wsrep that initialization is complete, writesets can be applied */
extern void wsrep_sst_continue();
extern void wsrep_sst_auth_free();

extern void wsrep_SE_init_grab();   /*! grab init critical section */
extern void wsrep_SE_init_wait();   /*! wait for SE init to complete */
extern void wsrep_SE_init_done();   /*! signal that SE init is complte */
extern void wsrep_SE_initialized(); /*! mark SE initialization complete */

#endif /* WSREP_SST_H */
