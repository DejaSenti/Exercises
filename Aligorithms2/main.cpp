#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <numeric>

using namespace std;

void PrintVector(vector<int>& vec, const string& name)
{
	cout << name << ": ";
	for_each(cbegin(vec), cend(vec), [](int n) { cout << n << " "; });
	cout << endl;
}

void Mismatch(vector<int>& vec1, vector<int>& vec2)
{
	PrintVector(vec1, "vec1");
	PrintVector(vec2, "vec2");

	auto diff = mismatch(cbegin(vec1), cend(vec1), cbegin(vec2), cend(vec2));

	if (diff.second == cend(vec2) || diff.first == cend(vec1))
	{
		cout << "There is no difference between vec1 and vec2." << endl;
	}
	else
	{
		cout << "The first difference between vec1 and vec2 is " << *diff.first << " and " << *diff.second << " at index " << distance(cbegin(vec1), diff.first) << endl;
	}
}

template<typename Pred>
void SomeOf(vector<int>& vec, Pred pred, const string& predicate)
{
	PrintVector(vec, "Vector");

	if (all_of(cbegin(vec), cend(vec), pred))
	{
		cout << "All elements are " << predicate << endl;
	}
	else if (any_of(cbegin(vec), cend(vec), pred))
	{
		cout << "At least one element is " << predicate << endl;
	}
	else if (none_of(cbegin(vec), cend(vec), pred))
	{
		cout << "None of the elements are " << predicate << endl;
	}
}

void BinarySearch(vector<int>& vec, int val)
{
	PrintVector(vec, "Vector");

	if (!is_sorted(cbegin(vec), cend(vec)))
	{
		cout << "The input is not sorted!" << endl;
		return;
	}

	cout << "Vector " << (binary_search(cbegin(vec), cend(vec), val) ? "contains " : "doesn't contain ") << val << endl;
}

void Includes(string str1, string str2)
{
	cout << "str1: " << str1 << endl;
	cout << "str2: " << str2 << endl;

	sort(begin(str1), end(str1));
	sort(begin(str2), end(str2));

	cout << "sorted str1: " << str1 << endl;
	cout << "sorted str2: " << str2 << endl;

	cout << "str1 " << (includes(cbegin(str1), cend(str1), cbegin(str2), cend(str2)) ? "includes " : "doesn't include ") << "all characters from str2" << endl;
}

int main(void)
{
	cout << "========TEST MISMATCH=========" << endl;

	vector<int> vec1 { 1, 2, 3, 4, 5, 6 };
	vector<int> vec2 { 1, 2, 3, 4, 5, 6 };
	vector<int> vec3 { 1, 2, 3, 65, 9514, 7523 };

	Mismatch(vec1, vec2);
	Mismatch(vec1, vec3);

	cout << "==============================" << endl;

	cout << "=========TEST SOME OF=========" << endl;

	vector<int> vec4 { 2, 4, 6, 8, 20 };
	vector<int> vec5 { 1, 3, 5, 7, 9, 81 };

	const string EVEN("even");
	const string ODD("odd");
	auto is_even = [](int n) { return n % 2 == 0; };
	auto is_odd = [&](int n) { return !is_even(n); };

	SomeOf(vec1, is_even, EVEN);
	SomeOf(vec1, is_odd, ODD);
	SomeOf(vec4, is_even, EVEN);
	SomeOf(vec4, is_odd, ODD);
	SomeOf(vec5, is_even, EVEN);
	SomeOf(vec5, is_odd, ODD);

	cout << "==============================" << endl;

	cout << "======TEST BINARY SEARCH======" << endl;

	BinarySearch(vec1, vec1[3]);
	BinarySearch(vec1, 654);
	BinarySearch(vec3, vec3[0]);

	cout << "==============================" << endl;

	cout << "=========TEST INCLUDES========" << endl;

	Includes("Hi there, would you like to sign my petition?", "abc");
	Includes("Hi there, would you like to sign my petition?", ",?");
	Includes("Hi there, would you like to sign my petition?", "Hhtw ");

	cout << "==============================" << endl;

	cout << "=========TEST NUMERIC=========" << endl;

	const int IOTA_SIZE = 10;
	const int IOTA_INC = 50;

	vector<int> iota_vec(IOTA_SIZE);

	iota(begin(iota_vec), end(iota_vec), IOTA_INC);
	cout << "This vector should start with " << IOTA_INC << " and increment by 1 for " << IOTA_SIZE << " elements:" << endl;
	PrintVector(iota_vec, "Iota vector");

	int sum = accumulate(begin(iota_vec), end(iota_vec), 0);

	cout << "Sum of elements in this vector: " << sum << endl;

	int odds_sum = accumulate(begin(iota_vec), end(iota_vec), 0, [&](int sum, int n) { return (is_odd(n) ? sum += n : sum); });

	cout << "Sum of odd elements in this vector: " << odds_sum << endl;

	cout << "==============================" << endl;

	cout << "========TEST WRITE-ONLY=======" << endl;

	const int NUM_FILL = 10;
	const int NUM_FILL_N = 3;
	const int FILL_VALUE_A = 50;
	const int FILL_VALUE_B = 100;

	vector<int> fill_vec(NUM_FILL);

	fill(begin(fill_vec), end(fill_vec), FILL_VALUE_A);
	cout << "This vector should have " << NUM_FILL << " values in it, all " << FILL_VALUE_A << ":" << endl;
	PrintVector(fill_vec, "Fill vector");

	fill_n(begin(fill_vec), NUM_FILL_N, FILL_VALUE_B);
	cout << "This vector should have " << NUM_FILL << " values in it, the first " << NUM_FILL_N << " being " << FILL_VALUE_B << " and the rest " << FILL_VALUE_A << ":" << endl;
	PrintVector(fill_vec, "Fill vector");

	const int GENERATE_START_NUM = 1;

	class SquareFunctor
	{
	public:
		int operator()() { ++n; return n * n; }
	private:
		int n{GENERATE_START_NUM - 1};
	};

	vector<int> generate_vec(NUM_FILL);
	generate(begin(generate_vec), end(generate_vec), SquareFunctor());
	cout << "This vector should have " << NUM_FILL << " values in it, the squares of all numbers from " << GENERATE_START_NUM << " to " << NUM_FILL << ":" << endl;
	PrintVector(generate_vec, "Generate vector");

	cout << "==============================" << endl;
}