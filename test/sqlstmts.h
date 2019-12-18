// filename: sqlstmts.h

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
            name varchar(100),\
            address varchar(1000),\
            clat double,\
            clong double,\
            available bool);\
            \
            create table weathers(\
            wid int primary key,\
            wname varchar(1000),\
            wlat double,\
            wlong double,\
            wforecast int);\
            "
    
