#include "sqlite3.h"
#include <stdio.h>

int main() {
  sqlite3 *db;
  sqlite3_stmt *stmt;
  int rc;

  const char *db_filename = "./my_database.db";
  const char *sql = "SELECT person_id, name, email FROM persons;";

  // Open database
  rc = sqlite3_open(db_filename, &db);
  if (rc != SQLITE_OK) {
    fprintf(stderr, "Cannot open database: %s\n", sqlite3_errmsg(db));
    return 1;
  }

  rc = sqlite3_prepare_v2(db, sql, -1, &stmt, NULL);
  if (rc != SQLITE_OK) {
    fprintf(stderr, "Failed to prepare statement: %s\n", sqlite3_errmsg(db));
    sqlite3_close(db);
    return 1;
  }

  printf("Persons table:\n");
  while ((rc = sqlite3_step(stmt)) == SQLITE_ROW) {
    int person_id = sqlite3_column_int(stmt, 0);
    const unsigned char *email = sqlite3_column_text(stmt, 2);

    printf("ID: %d |  Email: %s\n", person_id,
           email ? (const char *)email : "NULL");
  }

  if (rc != SQLITE_DONE) {
    fprintf(stderr, "Error reading rows: %s\n", sqlite3_errmsg(db));
  }

  sqlite3_finalize(stmt);
  sqlite3_close(db);

  return 0;
}
