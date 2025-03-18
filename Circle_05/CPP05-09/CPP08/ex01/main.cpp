#include "Span.hpp"

void  testMandatory()
{
  Span sp = Span(5);
  std::string error = "";

  try
  {
    sp.addNumber(6);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);
  }
  catch (std::exception &e)
  {
    std::cout << e.what() << std::endl;
    error += e.what();
  }
  if (!error.empty())
  {
    std::cout << PUR << "The program is no longer executable" << EOC << std::endl;
    exit(1);
  }
  std::cout << "shortestSpan: " << sp.shortestSpan() << std::endl;
  std::cout << " longestSpan: " << sp.longestSpan() << std::endl;
}

void testMax()
{
  Span sp = Span(10000);
  std::string error = "";

  for (int i = -5000; i <= 4999; i++)
  {
    try
    {
      sp.addNumber(i);
    }
    catch (std::exception &e)
    {
      std::cout << e.what() << std::endl;
      error += e.what();
    }
    if (!error.empty())
    {
      std::cout << PUR << "The program is no longer executable" << EOC << std::endl;
      exit(1);
    }
  }
  std::cout << "shortestSpan: " << sp.shortestSpan() << std::endl;
  std::cout << " longestSpan: " << sp.longestSpan() << std::endl;
}

void testRangeArray()
{
  int testArray[5] = {9, 3, 5, 7, 1};
  Span sp(5);
  std::string error = "";

  try
  {
    sp.addRange(std::vector<int>(testArray, testArray + 5));
  }
  catch (std::exception &e)
  {
    std::cout << e.what() << std::endl;
    error += e.what();
  }
  if (!error.empty())
  {
    std::cout << PUR << "The program is no longer executable" << EOC << std::endl;
    exit(1);
  }
  std::cout << "shortestSpan: " << sp.shortestSpan() << std::endl;
  std::cout << " longestSpan: " << sp.longestSpan() << std::endl;
}

void testRangeContainer()
{
  std::vector<int>  testVector;
  Span sp(9);
  std::string error = "";

  for (int i = 1; i < 10; i++)
  {
    testVector.push_back(i * 5);
  }
  try
  {
    sp.addRange(testVector);
  }
  catch (std::exception &e)
  {
    std::cout << e.what() << std::endl;
    error += e.what();
  }
  if (!error.empty())
  {
    std::cout << PUR << "The program is no longer executable" << EOC << std::endl;
    exit(1);
  }
  std::cout << "shortestSpan: " << sp.shortestSpan() << std::endl;
  std::cout << " longestSpan: " << sp.longestSpan() << std::endl;
}

void testNospan()
{
  try
  {
    Span sp(3);
    std::cout << "Case(1) capacity is 0 & check shortestSpan" << std::endl;
    std::cout << "shortestSpan: " << sp.shortestSpan() << std::endl;
  }
  catch (std::exception &e)
  {
    std::cerr << e.what() << std::endl;
  }

  std::cout << std::endl;

  try
  {
    Span sp(0);
    std::cout << "Case(2) capacity is 0 & Check longestSpan" << std::endl;
    std::cout << "longestSpan: " << sp.longestSpan() << std::endl;    
  }
  catch (std::exception &e)
  {
    std::cerr << e.what() << std::endl;
  }
}

void testOverCapacity()
{
  try
  {
    Span sp(0);
    sp.addNumber(9);
  }
  catch (std::exception &e)
  {
    std::cerr << e.what() << std::endl;
  }

  try
  {
    Span sp(1);
    int testArray[4] = {1, 2, 3, 4};
    sp.addRange(std::vector<int>(testArray, testArray + 5));
  }
  catch (std::exception &e)
  {
    std::cerr << e.what() << std::endl;
  }
}

int main()
{
  std::cout << GRE << "[ testMandatory ]"<< EOC << std::endl;
  testMandatory();
  std::cout << std::endl;

  std::cout << GRE << "[ testMax ]"<< EOC << std::endl;
  testMax();
  std::cout << std::endl;

  std::cout << GRE << "[ testRangeArray ]"<< EOC << std::endl;
  testRangeArray();
  std::cout << std::endl;

  std::cout << GRE << "[ testRangeContainer ]"<< EOC << std::endl;
  testRangeContainer();
  std::cout << std::endl;

  std::cout << GRE << "[ testNospan ]"<< EOC << std::endl;
  testNospan();
  std::cout << std::endl;

  std::cout << GRE << "[ testOverCapacity ]"<< EOC << std::endl;
  testOverCapacity();
  std::cout << std::endl;

  return 0;
}
