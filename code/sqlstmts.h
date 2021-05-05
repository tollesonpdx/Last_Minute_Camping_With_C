// Chad Tolleson Copyright (c) 2019
// New Beginnings - Capstone Project
// filename: sqlstmts.h

#ifndef __SQLSTMTS_H_
#define __SQLSTMTS_H_

// SQL statements to be passed into SQLite functions

#define maketables "\
            create table userlocs(\
            usercity varchar(100),\
            userstate varchar(20),\
            userzip int,\
            userlat double,\
            userlong double);\
            \
            create table camps(\
            campid int primary key,\
            cname varchar(100),\
            caddress varchar(1000),\
            clat double,\
            clong double,\
            cavailable bool);\
            \
            create table weathers(\
            wid int primary key,\
            wname varchar(1000),\
            wlat double,\
            wlong double,\
            wforecast int);\
            \
            create table lightp(\
            pid int primary key,\
            pname varchar(1000),\
            plat double,\
            plong double,\
            pollut int);\
            \
            create table astro(\
            aid int primary key,\
            adesc varchar(1000),\
            abegdate varchar(100),\
            aenddate varchar(100);\
            "

#endif 
