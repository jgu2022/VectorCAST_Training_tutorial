#include <vector>
#include <deque>
#include <list>
#include <set>
#include <map>
#include <string>
#include <algorithm> // To use "sort"
#include <functional> // To use "greater"
#include <numeric> // To use "accumulate"
#include <ctime> // To update the seed per system time

// To calculate the average after trimming out the max and min elements in deque
double calculate_average( const int* arr, int len)
{
	std::deque<int>d;
	for (int i = 0; i < len; i++)
	{
		d.push_back(arr[i]);
	}
	sort(d.begin(), d.end(), std::greater<int>()); // Descending order

	d.pop_back(); // To trim out the min
	d.pop_front(); // To trim out the max

	int sum = accumulate(d.begin(), d.end(), 0);
	double avg = double(sum) / (double)d.size();

	return avg;
}

// Find the value of MAP, per the key provided
float map_lookup_by_key(const std::string& key, const std::map<std::string, float>& m)
{
   std::map<std::string, float>::const_iterator i = m.find(key);
   if (i != m.end())
      return i->second;
   else
      return 0.0;
}

// Customized Class
class Worker
{
public:
	std::string m_Name;
	int m_Salary;
};
// To assign the vector elements to MAP's values; with random Keys
void vectorToMap(const std::vector<Worker> &v, std::multimap<int, Worker> &m)
{
    srand((unsigned int)time(NULL)); // Call the system seed
    
	for (std::vector<Worker>::const_iterator i = v.begin(); i != v.end(); i++)
	{
		// Modulo on rand value to assign the Key
		int key = rand() % 3;

		// To complete the assignment on MAP
		m.insert(std::make_pair(key, *i));
	}
}

// To assign list to vector
std::vector<int> copy_list_to_vector(const std::list<int>& l)
{
   std::vector<int> v;
   for (std::list<int>::const_iterator i = l.begin(); i != l.end(); ++i)
      v.push_back(*i);

   return v;
}

// list
int sum_of_list(const std::list<int>& l)
{
   int sum = 0;
   for (std::list<int>::const_iterator i = l.begin(); i != l.end(); ++i)
      sum += *i;

   return sum;
}

 // set
std::set<int> get_set_of_ints();
bool exists_in_set(int val)
{
   std::set<int> s = get_set_of_ints();
   return s.find(val) != s.end();
}