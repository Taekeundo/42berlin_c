#include "Span.hpp"

/* [ Orthodox Canonical Form ] */

/*  1. Default constructor
    = Initializes an empty Span object
*/  
Span::Span() : maxCapacity(0), vectorContainer() {}

/*  2. Parameterized constructor
    = Initializes a Span with a specified maximum capacity
*/
Span::Span(unsigned int value) : maxCapacity(value), vectorContainer() {}

/*  3. Copy constructor
    = Initializes a new Span by copying another Span object
*/
Span::Span(const Span& other) : maxCapacity(other.maxCapacity), vectorContainer() {}

/*  4. Overloaded assignment operator
    = Assigns values from another Span to this Span
*/
Span& Span::operator=(const Span& rhs)
{
  if (maxCapacity <= rhs.maxCapacity)
    throw (CapacityExceededException());
  if (this != &rhs)
    vectorContainer = rhs.vectorContainer;
  return (*this);
}

/*  5. Destructor
    = Cleans up resources when the Span object is destroyed
*/
Span::~Span() {}



/* [ Methods for adding values ] */
/*
  [ Definition ]
  Add one integer value to the Span ojbect.

  [ Logic ]
  Check, if the current number of elements exceeds maxCapacity of Span object.
    No exceed: Adds the 'value' to the end of the 'vectorContainer'.
    Exceed: throw 'Error'
*/
void  Span::addNumber(int value)
{
  if (vectorContainer.size() < maxCapacity)
    vectorContainer.push_back(value);
  else
    throw (CapacityExceededException());
}

/*
  [ Definition ]
  Add a range of values (from a vectorRange) to the Span object.

  [ Logic ]
  Check, if the total size of (vC + vR) would exceed the maxCapacity.
    Exceed: throw 'Error'
    No exceed: Add whole rangeVector to the end of vectorContainer.
*/
void Span::addRange(std::vector<int> vectorRange)
{
  if (vectorContainer.size() + vectorRange.size() > maxCapacity)
      throw(CapacityExceededException());
  else
    vectorContainer.insert(vectorContainer.end(), vectorRange.begin(), vectorRange.end());
}



/* [ Methods for calculating spans ] */
/*
  [ Definition ]
  Returns the smallest difference between consecutive elements.

  [ Background ]
  1. std::numeric_limits<unsigned int>::max();
    Gets the maximum value that can be expressed in the unsigned integer type.
    = 4294967295 (based on 32bits).
  
  2. WHY use max()
    최초 비교 대상 값을 최대값으로 설정해두면, 어떤 값과 비교하던지 모두 최초값보다 작거나 같기에
    어떤 값이 오던 그 값이 곧바로 최소값으로 설정될 수 있도록하기 위해서 최초값을 최대값으로 설정해둔다.
  
  [ Logic ]
  1. Ensure there are at least 2 elements to calculate a span.
  2. Initialize "shortestSpan" to the maximum possible unsigned int value.
  3. Create a reference to the (vectorContainer) & sort it in ascending order.
  4. Iterate through the sorted vector to find the shortest span.
     Difference between consecutive elements.
*/
unsigned int  Span::shortestSpan()
{
  // 1.
  if (vectorContainer.size() < 2)
    throw(InsufficientElementsException());

  // 2.
  unsigned int shortestSpan = std::numeric_limits<unsigned int>::max();

  // 3.
  std::vector<int>& sortedVector = vectorContainer;
  std::sort(sortedVector.begin(), sortedVector.end());

  // 4.
  for (unsigned int i = 0; i < sortedVector.size() - 1; i++)
  {
    unsigned int spanDifference = static_cast<unsigned int>(sortedVector[i + 1] - sortedVector[i]);
    if (spanDifference < shortestSpan)
      shortestSpan = spanDifference;
  }
  return (shortestSpan);
}

/*
  [ Definition ]
  Returns the longest difference between consecutive elements.
  
  [ Logic ]
  1. Ensure there are at least 2 elements to calculate a span.
  2. Find Max, Min value from the vectorContainer.
*/
unsigned int Span::longestSpan()
{
  if (vectorContainer.size() < 2)
    throw(InsufficientElementsException());

  int minimumValue = *std::min_element(vectorContainer.begin(), vectorContainer.end());
  int maximumValue = *std::max_element(vectorContainer.begin(), vectorContainer.end());
  return (static_cast<unsigned int>(maximumValue - minimumValue));
}



/* [ Custom class for exceptional cases ] */
// 1. Not enough elelments
const char* Span::InsufficientElementsException::what() const throw()
{
  return (RED "Insufficient element" EOC);
}

// 2. Capacity is exceeded
const char* Span::CapacityExceededException::what() const throw()
{
  return (RED "Not Enough Capacity" EOC);
}
