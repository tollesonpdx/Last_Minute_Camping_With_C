# Chad Tolleson Copyright (c) 2019
# New Beginnings - Capstone Project
# filename: makefile

CC = gcc

OBJS = capstone.o f_currDateTime.o f_getUserData.o \
        f_printUserData.o f_sqlOpenMakeDB.o f_sqlExec.o \
        f_sqlSetDb.o f_sqlMakeTables.o f_sqlInsertUser.o   \
        f_sqlUsersWOutGeo.o f_wrapField.o f_convertAddress2G.o \
        f_bufferInit.o f_bufferWrite.o f_curlGeocode.o \
        cJSON.o f_parseCoords.o f_sqlUpdateUsrCoords.o \
        f_doubleToString.o f_geocodeUser.o \
        f_userListMake.o f_userListAdd.o f_userListPrint.o \
        f_userListDelete.o f_userListTravGeo.o \
        f_sqlUpdateUserFromDb.o f_sqlCampsFromDb.o \
        f_campTreeMake.o f_campTreeAdd.o f_campTreeAddNode.o \
        f_campTreePrintNode.o f_haversine.o \
        f_campTreePrint.o f_campTreeTravPrint.o \
        f_campTreeDelete.o f_campTreeDeleteNode.o \
        f_campTreeProcess.o f_campTreeTravProc.o \
        f_sqlUpdateCampDist.o f_sqlClearCampDist.o f_chadcat.o \
        f_curlWeathers.o f_parseWeathers.o f_campTreeLogNode.o \
        f_logEntry.o

all: capstone

capstone: $(OBJS)
	$(CC) -o capstone $(OBJS) -lm -lcurl -lsqlite3 -fstack-protector-all

.c.o:
	$(CC) $(CFLAGS) -g -Wall -c $<

clean:
	rm -f capstone *.o core
