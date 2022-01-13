#include <iostream>
#include <array>
#include <map>

#include "to_string.hpp"

class Class1
{
	int mAge;
	std::string mName;
public:
	Class1(std::string&& _Name, int _Age)
		:
		mAge(_Age), mName(std::move(_Name)) {}
	std::string to_string()
	{
		return mName + ":" + std::to_string(mAge);
	}
	std::string to_string() const
	{
		return mName + ":" + std::to_string(mAge);
	}
};

int main()
{
	Class1 per1("RayeS", 20);
	Class1 per2("Pavel", 20);
	std::cout << ext::to_string(per1) << " and " << ext::to_string(per2) << std::endl;

	const char* hi = "Hello, ";
	const char wo[] = "world!!!";
	std::string str("(c) youre Traitor");
	std::cout << ext::to_string(hi) << ext::to_string(wo) << ext::to_string(str) << std::endl;

	std::array<int, 5> a{ 1,2,3,4,5 };
	std::cout << ext::to_string(a) << std::endl;

	std::cout << ext::to_string(21.5f) << " " << ext::to_string(190) << " " << ext::to_string(true) << std::endl;
	std::cout << ext::to_string(21.5f, 190, true) << std::endl;

	std::map<int, std::string> humans;
	humans[20] = "Pavel";
	humans[21] = "RayeS";

	std::string pairs;
	for (auto& pair : humans)
	{
		if (!pairs.empty())
			pairs += ",";
		pairs += ext::to_string(pair);
	}
	pairs += ";";
	std::cout << pairs << std::endl;
	return 0;
}