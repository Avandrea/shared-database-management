// databaseManager.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "DatabaseManager.h"
#include <windows.h>

// test sqlcipher
//#include <sqlite3.h>


int main()
{
	std::string db_path = ".";
	std::string db_name = "testdb.db";
	std::string table_name = "table1";

	DatabaseManager db(db_path, db_name);

	// Encryption
	std::string pass = "testkey";
	db.encrypt(pass);

	db.addTable(table_name);

	// Start thread that prints all the elements of table1
	db.startPrintThread(table_name);
	db.startInsertThread(table_name);

	Sleep(10000);

	db.stopPrintThread();
	db.stopInsertThread();
	//db.closeDatabase();

    return 0;
}

