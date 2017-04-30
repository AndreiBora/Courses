#include "Utils.h"
#include <vector>
#include <sstream>

using namespace std;

std::vector<std::string> tokenize(const std::string & str, char delimiter)
{
	vector<string> result;
	stringstream ss(str);
	string token;
	while (getline(ss, token, delimiter))
		result.push_back(token);

	return result;
}