#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

struct language 
{
	string lang;
	string designer;
	int date;
};

ostream& operator<<(ostream& os_, const language& lang_)
{
	os_ << lang_.lang << ", " << lang_.designer << ", " << lang_.date;
	return os_;
}

int main()
{
	fstream file;
	file.open("languages2.txt", ios_base::in);

	if (!file)
		return -1;

	vector<language> languages;
	string input;

	while (getline(file, input))
	{
		istringstream iss(input);
		language lang;

		iss >> lang.lang;
		iss >> lang.designer;

		while (iss)
		{
			string temp;

			iss >> temp;
			if (isdigit(temp[0]))
			{
				lang.date = stoi(temp);
				break;
			}

			lang.designer += " " + temp;
		}

		languages.push_back(lang);
	}

	file.close();

	for (auto& lang : languages)
		cout << lang << endl;

	return 0;
}