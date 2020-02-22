#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <set>
#include <map>

/*
int ComputeDistance(const std::string& source, const std::string& destination)
{
	return source.length() - destination.length();
}

class Route
{
public:
	Route()
	{
		source = "Moscow";
		destination = "Saint Petersburg";
		UpdateLength();
		std::cout << "Default constructed\n";
	}

	Route(const std::string& new_source, const std::string new_destination)
	{
		source = new_source;
		destination = new_destination;
		UpdateLength();
		std::cout << "Constructed\n";
	}

	~Route()
	{
		std::cout << "Destructed\n";
	}

	std::string GetSource() const
	{
		return source;
	}

	std::string GetDestination() const
	{
		return destination;
	}

	int GetLength() const
	{
		return length;
	}

	void SetSource(const std::string& new_source)
	{
		source = new_source;
		UpdateLength();
	}

	void SetDestination(const std::string& new_destination)
	{
		destination = new_destination;
		UpdateLength();
	}

private:
	void UpdateLength()
	{
		length = ComputeDistance(source, destination);
		compute_distance_log.push_back(source + " - " + destination);
	}

	std::string source;
	std::string destination;
	int length;
	std::vector <std::string> compute_distance_log;
};

void PrintRoute(const Route& route)
{
	std::cout << route.GetSource() << "-" << route.GetDestination() << "\n";
}

void ReverseRoute(Route& route)
{
	std::string old_source = route.GetSource();
	std::string old_destination = route.GetDestination();

	route.SetDestination(old_source);
	route.SetSource(old_destination);
}*/

/*class Person
{
public:
	Person(const std::string& first, const std::string& second, int age)
	{

	}
};*/

/*class ReversibleString
{
public:
	ReversibleString() {str = "";}

	ReversibleString(std::string s)
	{
		str = s;
	}

	void Reverse()
	{
		std::string result;

		int n = str.length() - 1;
		for (int i = 0; i < (str.length() / 2); i++)
		{
			std::swap(str[i], str[n]);
			n--;
		}
	}
	std::string ToString() const
	{
		return str;
	}

private:
	std::string str;

};*/

/*class Person {
public:
	Person (const std::string& first_name, const std::string& last_name, int year)
	{
		firstname[year] = first_name;
		lastname[year] = last_name;
		birth = year;
	}

	void ChangeFirstName(int year, const std::string& first_name) {
		firstname[year] = first_name;
	}

	void ChangeLastName(int year, const std::string& last_name) {
		lastname[year] = last_name;
	}

	std::string GetFullName(int year) const
	{
		if (year < birth)
		{
			return "No person";
		}

		std::string result{};
		bool check_firstname = true;
		bool check_lastname = true;

		auto fn = firstname.upper_bound(year);

		if (firstname.begin() == fn)
		{
			check_firstname = false;
		}
		else
		{
			fn = std::prev(fn);
		}

		auto ln = lastname.upper_bound(year);

		if (lastname.begin() == ln)
		{
			check_lastname = false;
		}
		else
		{
			ln = std::prev(ln);
		}

		if (!check_firstname && !check_lastname)
		{
			result = "Incognito";
		}
		else if (!check_firstname)
		{
			result = ln->second + " with unknown first name";
		}
		else if (!check_lastname)
		{
			result = fn->second + " with unknown last name";
		}
		else
		{
			result = fn->second + " " + ln->second;
		}

		return result;
	}

	std::string GetFullNameWithHistory(int year) const
	{
		if (year < birth)
		{
			return "No person";
		}

		std::string result{};
		std::vector<std::string> list_fn;
		std::vector<std::string> list_ln;

		for (const auto& item : firstname)
		{
			if (item.first <= year)
			{
				if (list_fn.empty())
				{
					list_fn.push_back(item.second);
					continue;
				}

				if (list_fn.back() != item.second)
				{
					list_fn.push_back(item.second);
				}
			}
			else
			{
				break;
			}
		}

		for (const auto& item : lastname)
		{
			if (item.first <= year)
			{
				if (list_ln.empty())
				{
					list_ln.push_back(item.second);
					continue;
				}

				if (list_ln.back() != item.second)
				{
					list_ln.push_back(item.second);
				}
			}
			else
			{
				break;
			}
		}

	    if (list_fn.empty() && list_ln.empty()) {
	    	result = "Incognito";
	    }
	    else if (list_fn.empty())
		{
	    	result = print_list(list_ln) + " with unknown first name";
		}
	    else if (list_ln.empty())
	    {
	    	result = print_list(list_fn) + " with unknown last name";
	    }
	    else
	    {
	    	result = print_list(list_fn) + " " + print_list(list_ln);
	    }

		return result;
	}

private:
	int birth;
	std::map <int, std::string> firstname;
	std::map <int, std::string> lastname;

	std::string print_list(std::vector<std::string>& list) const
	{
		std::string result{};
		result = list[0];

		std::vector<std::string> list2;

		//result = list[0];
		result = list.back();

		if (list.size() > 1)
		{
			result += " (";
			for (int i = 1; i < list.size(); i++)
			{
				result += list[list.size() - i - 1] + ", ";
			}
			result.erase(result.size() - 2);
			result += ")";
		}

		return result;
	}

};*/

/*class Incognizable
{
public:
	Incognizable() {}
	Incognizable(int a) {}
	Incognizable(int a, int b) {}
};*/

/*class Weather {
public:
  Weather(const std::string& new_state, int new_temperature) {
    state = new_state;
    temperature = new_temperature;
    std::cout << 'c';
  }
  ~Weather() {
    std::cout << 'd';
  }
private:
  std::string state;
  int temperature;
};*/

/*void f(int x) {
  std::cout << 'a';
  if (x % 2 == 0) {
    Weather weather("rain", 5);
    std::cout << 'b';
    return;
  }
  Weather weather2("fog", 4);
  std::cout << 'e';
}*/

/*void f(int x) {
  std::cout << 'a';
  if (x % 2 == 1) {
    Weather weather("rain", 5);
    std::cout << 'b';
  }
  Weather weather2("fog", 4);
  std::cout << 'e';
}

Weather GetMayWeather(int day) {
  if (day == 9) {
    std::cout << 'b';
    return {"clear", 10};
  } else {
	  std::cout << 'b';
    return {"cloudy", 10};
  }
}*/

/*struct Day
{
	int value;
	explicit Day (int new_value)
	{
		value = new_value;
	}
};

struct Mounth
{
	int value;
	explicit Mounth (int new_value)
	{
		value = new_value;
	}
};

struct Year
{
	int value;
	explicit Year (int new_value)
	{
		value = new_value;
	}
};

struct Date
{
	int day;
	int mounth;
	int year;

	Date(Day new_day, Mounth new_mounth, Year new_year)
	{
		day = new_day.value;
		mounth = new_mounth.value;
		year = new_year.value;
	}
};

void PrintDate(const Date& date)
{
	std::cout << date.day << "." << date.mounth << "." << date.year << "\n";
}*/

struct Specialization
{
	std::string value;
	explicit Specialization (std::string new_value)
	{
		value = new_value;
	}
};

struct Course
{
	std::string value;
	explicit Course (std::string new_value)
	{
		value = new_value;
	}
};

struct Week
{
	std::string value;
	explicit Week (std::string new_value)
	{
		value = new_value;
	}
};

struct LectureTitle {
	std::string specialization;
	std::string course;
	std::string week;

	LectureTitle(Specialization new_specialization, Course new_course, Week new_week)
	{
		specialization = new_specialization.value;
		course = new_course.value;
		week = new_week.value;
	}
};

int main()
{

	LectureTitle title(
	    Specialization("C++"),
	    Course("White belt"),
	    Week("4th")
	);

	/*Date date = {Day{1}, Mounth{1}, Year{2017}};
	PrintDate(date);*/

	/*std::vector<int> days(2, 1);
	  for (int day : days) {
		  std::cout << 'a';
	    Weather weather = GetMayWeather(day);
	    std::cout << 'e';
	  }
	  std::cout << 'f';

	//f(11);
*/
	/*std::cout << 'a';
	Weather weather("snow", -5);
	std::cout << 'b';*/

	/*for (int i : {0, 1})
	{
		std::cout << "Step: " << i << ": " << 1 << "\n";
		Route route;
		std::cout << "Step: " << i << "; " << 2 << "\n";
	}

	std::cout << "End\n";*/

	/*std::cout << 1 << "\n";
	Route route;
	std::cout << 2 << "\n";*/

	/*Route route("Moscow", "Saint Petersburg");
	route.SetSource("Vyborg");
	route.SetDestination("Vologda");*/
	/*Incognizable a;
	Incognizable b = {};
	Incognizable c = {0};
	Incognizable d = {0, 1};*/

	  /*Person person("Polina", "Sergeeva", 1960);
	  for (int year : {1959, 1960}) {
	    std::cout << person.GetFullNameWithHistory(year) << std::endl;
	  }

	  person.ChangeFirstName(1965, "Appolinaria");
	  person.ChangeLastName(1967, "Ivanova");
	  for (int year : {1965, 1967}) {
		  std::cout << person.GetFullNameWithHistory(year) << std::endl;
	  }*/

	/*ReversibleString s("live");
	s.Reverse();
	std::cout << s.ToString() << std::endl;

	s.Reverse();
	const ReversibleString& s_ref = s;
	std::string tmp = s_ref.ToString();
	std::cout << tmp << std::endl;

	ReversibleString empty;
	std::cout << '"' << empty.ToString() << '"' << std::endl;*/

	//std::vector <Person> p;

	//p.push_back("A", "P", 1);

	/*Route route("Zvenigorod", "Istra");
	std::cout << route.GetLength() << "\n";*/

	/*route.SetSource("Moscow");
	route.SetDestination("Vologda");
	ReverseRoute(route);
	PrintRoute(route);*/

	return 0;
}
