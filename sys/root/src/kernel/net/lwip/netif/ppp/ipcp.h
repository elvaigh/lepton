/*
The contents of this file are subject to the Mozilla Public License Version 1.1 
(the "License"); you may not use this file except in compliance with the License.
You may obtain a copy of the License at http://www.mozilla.org/MPL/

Software distributed under the License is distributed on an "AS IS" basis, 
WITHOUT WARRANTY OF ANY KIND, either express or implied. See the License for the 
specific language governing rights and limitations under the License.

The Original Code is ______________________________________.

The Initial Developer of the Original Code is ________________________.
Portions created by ______________________ are Copyright (C) ______ _______________________.
All Rights Reserved.

Contributor(s): ______________________________________.

Alternatively, the contents of this file may be used under the terms of the eCos GPL license 
(the  [eCos GPL] License), in which case the provisions of [eCos GPL] License are applicable 
instead of those above. If you wish to allow use of your version of this file only under the
terms of the [eCos GPL] License and not to allow others to use your version of this file under 
the MPL, indicate your decision by deleting  the provisions above and replace 
them with the notice and other provisions required by the [eCos GPL] License. 
If you do not delete the provisions above, a recipient may use your version of this file under 
either the MPL or the [eCos GPL] License."
*/

#ifndef IPCP_H
#define IPCP_H

/*************************
*** PUBLIC DEFINITIONS ***
*************************/
/*
 * Options.
 */
#define CI_ADDRS            1      /* IP Addresses */
#define CI_COMPRESSTYPE     2      /* Compression Type */
#define CI_ADDR             3

#define CI_MS_WINS1         128    /* Primary WINS value */
#define CI_MS_DNS1          129    /* Primary DNS value */
#define CI_MS_WINS2         130    /* Secondary WINS value */
#define CI_MS_DNS2          131    /* Secondary DNS value */

#define IPCP_VJMODE_OLD     1      /* "old" mode (option # = 0x0037) */
#define IPCP_VJMODE_RFC1172 2      /* "old-rfc"mode (option # = 0x002d) */
#define IPCP_VJMODE_RFC1332 3      /* "new-rfc"mode (option # = 0x002d, */
                                   /*  maxslot and slot number compression) */

#define IPCP_VJ_COMP        0x002d /* current value for VJ compression option */
#define IPCP_VJ_COMP_OLD    0x0037 /* "old" (i.e, broken) value for VJ */
                                   /* compression option */ 


/************************
*** PUBLIC DATA TYPES ***
************************/

typedef struct ipcp_options {
  u_int   neg_addr      : 1; /* Negotiate IP Address? */
  u_int   old_addrs     : 1; /* Use old (IP-Addresses) option? */
  u_int   req_addr      : 1; /* Ask peer to send IP address? */
  u_int   default_route : 1; /* Assign default route through interface? */
  u_int   proxy_arp     : 1; /* Make proxy ARP entry for peer? */
  u_int   neg_vj        : 1; /* Van Jacobson Compression? */
  u_int   old_vj        : 1; /* use old (short) form of VJ option? */
  u_int   accept_local  : 1; /* accept peer's value for ouraddr */
  u_int   accept_remote : 1; /* accept peer's value for hisaddr */
  u_int   req_dns1      : 1; /* Ask peer to send primary DNS address? */
  u_int   req_dns2      : 1; /* Ask peer to send secondary DNS address? */
  u_short vj_protocol;       /* protocol value to use in VJ option */
  u_char  maxslotindex;      /* VJ slots - 1. */
  u_char  cflag;             /* VJ slot compression flag. */
  u32_t   ouraddr, hisaddr;  /* Addresses in NETWORK BYTE ORDER */
  u32_t   dnsaddr[2];        /* Primary and secondary MS DNS entries */
  u32_t   winsaddr[2];       /* Primary and secondary MS WINS entries */
} ipcp_options;


/*****************************
*** PUBLIC DATA STRUCTURES ***
*****************************/

extern fsm ipcp_fsm[];
extern ipcp_options ipcp_wantoptions[];
extern ipcp_options ipcp_gotoptions[];
extern ipcp_options ipcp_allowoptions[];
extern ipcp_options ipcp_hisoptions[];

extern struct protent ipcp_protent;


/***********************
*** PUBLIC FUNCTIONS ***
***********************/

#endif /* IPCP_H */
