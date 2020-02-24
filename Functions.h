#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <string>


void signInUser(std::string& id);
bool checkForUser(std::string& id,std::string& user);
void registerNewUser(std::string& id, std::string& user);
void addUserToRegistry(const std::string& user);
void timeStamp(std::string& user);
void validateID(std::string& id);
void title();

#endif
