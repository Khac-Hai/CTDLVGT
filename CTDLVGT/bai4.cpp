#include <iostream>
#include <string>
#include <queue>

/**
 * @brief Function to generate binary numbers from 1 to N using a queue.
 *
 * @param N the max value of the sequence
 *
 * Return: a vector of converted binary numbers
 */
std::vector<std::string> generate(int N) {
  std::queue<std::pair<int, std::string> > q;
  std::vector<std::string> ans;

  q.push({1, "1"});

  while (q.size()) {
  	int num = q.front().first; 
    std::string s_num = q.front().second;
    q.pop(); 
    ans.push_back(s_num);

    

    if (2*num <= N) {
      q.push({2*num, s_num + "0"});
    }
    if (2*num + 1 <= N) {
      q.push({2*num + 1, s_num + "1"});
      
    }
  }
  return ans;
}

int main() {
  int N;
  std::vector<std::string> result;

  std::cout << "Enter N: ";
  std::cin >> N;

  result = generate(N);
  for (std::vector<std::string>::iterator it = result.begin(); it != result.end(); ++it)
    std::cout << *it << std::endl;

  return 0;
}