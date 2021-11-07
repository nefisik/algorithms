#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <map>

size_t minDistance(std::string word1, std::string word2)
{
	// Transform words to lowercase
	std::transform(word1.begin(), word1.end(), word1.begin(), tolower);
	std::transform(word2.begin(), word2.end(), word2.begin(), tolower);

	//Поиск подстроки в строке
	size_t pos = word1.find(word2);
	if (pos != std::string::npos)
	{
		if (pos == 0)
			return -1;
		else
			return 0;
	}

	// Determine which string is shorter.
	const std::string *short_ptr;
	const std::string *long_ptr;
	if (word1.length() < word2.length())
	{
		short_ptr = &word1;
		long_ptr = &word2;
	}
	else
	{
		short_ptr = &word2;
		long_ptr = &word1;
	}

	// O(min(m, n))
	int cache[short_ptr->length() + 1];
	for (int i = 0; i < short_ptr->length() + 1; i++)
	{
		cache[i] = i;
	}

	// tmp1: storing the most recently overridden element of cache
	// tmp2: storing the currently calculated value
	int tmp1, tmp2;

	for (int i = 1; i < long_ptr->length() + 1; i++)
	{
		tmp1 = cache[0];
		cache[0] = i;
		for (int j = 1; j < short_ptr->length() + 1; j++)
		{
			if (long_ptr->at(i - 1) == short_ptr->at(j - 1))
			{
				// Two strings have the same final character for this sub-problem
				tmp2 = tmp1;
				tmp1 = cache[j];
				cache[j] = tmp2;
			}
			else
			{
				tmp2 = std::min(std::min(tmp1, cache[j - 1]), cache[j]) + 1;
				tmp1 = cache[j];
				cache[j] = tmp2;
			}
		}
	}
	return cache[short_ptr->length()];
}

int main()
{
	std::vector<std::string> dictionary{
		"Ilya", "Petra", "Vasily", "Pedri", "Mentrocept", "Bogdan", "Hulian", "Pedra", "Lantropskys",
		"Perilo", "Kurilo", "Lesopoval", "Tranurik", "Kerimpopka", "Donateba", "Qudryazhob", "Pidor"};

	std::string search = "Pedro";

	std::map<size_t, std::string> result;

	for (const auto &word : dictionary)
	{
		auto dist = minDistance(word, search);
		if (dist < word.size() * 0.6)
		{
			result.insert(std::make_pair(dist, word));
		}
	}

	for (auto &word : result)
	{
		std::cout << word.second << std::endl;
	}

	return 0;
}
