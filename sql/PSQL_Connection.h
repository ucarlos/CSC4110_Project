#ifndef CSC4110_CONNECTION
#define CSC4110_CONNECTION
#include <string>
#include <pqxx/pqxx>
#include <sstream>
#include <ctime>
#include <fstream>
using namespace std;

//------------------------------------------------------------------------------
// Database Variables
//------------------------------------------------------------------------------
// Change depending on which system to compile to:
const string database_info_path = "../sql/database_info.txt";


static string database_address;
static string database_name;
static string database_table;

static string database_path;
void get_database_info_from_file(void);

//------------------------------------------------------------------------------
// Connection functions -- Defined in Connection.cc
//------------------------------------------------------------------------------

void initialize_connection(pqxx::connection &c);
void close_connection(pqxx::connection &c);
void open_connection(pqxx::connection &c);
pqxx::result
search_database(pqxx::connection &c, const std::string &date, const std::string &start_time,
				const std::string &end_time);

//------------------------------------------------------------------------------
// Project_Settings.xml functions
//------------------------------------------------------------------------------
void get_database_info_from_xml(const std::map<std::string, std::string> &db_info);

#endif