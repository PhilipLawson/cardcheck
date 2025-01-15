#include <iostream>
#include <algorithm>
#include <string>
#include <list>
#include <numeric>
#include <vector>

/*Test Card- 6011000990139424*/

bool validCard(std::string cardnum, int size);
int sizeOfNumber(std::string cardnum);
int sumOfDigits(std::vector<int> singleDigitList, int size);
int addAllOddNums(std::string cardnum);
bool isDivisibleByTen(int sumOfOddNums);
std::vector<int> doubleEverSecondDigit(std::string cardnum, int size);

int main()
{
    std::string cardnum;
    bool isCardValid;
    int numSize;

    std::cout << "Please enter your credit card number:- " << '\n';
    std::cin >> cardnum;
    const std::string *user_card = &cardnum;
    std::cout << "***************************************" << '\n';
    std::cout << *user_card << '\n';
    std::cout << "***************************************" << '\n';

    numSize = sizeOfNumber(*user_card);

    isCardValid = validCard(*user_card, numSize);

    return 0;
}


bool validCard(std::string cardnum, int size)
{
    std::string tempString;
    int sumOfSingleDigits;
    int sumOfOddNums;
    int temp = 0;
    int totalSum = 0;
    std::vector<int> singleDigitList;

    // Double every second digit and split if int is two digits
    singleDigitList = doubleEverSecondDigit(cardnum, size);

    std::cout << "Single Digit List:" << '\n';
    for (int elm : singleDigitList)
    {
        std::cout << elm << " ";
    }
    std::cout << '\n';
    
    // Add all the single digits
    sumOfSingleDigits = sumOfDigits(singleDigitList, size);
    std::cout << "SUM: " << sumOfSingleDigits << '\n';
    
    // Add all the odd number digits from right to left
    sumOfOddNums = addAllOddNums(cardnum);
    std::cout << "SUM of odd digits: " << sumOfOddNums << '\n';
  
    // if result from previous step is divisible by 10, # is valid
    totalSum = sumOfSingleDigits + sumOfOddNums;
    std::cout << "Total Sum: " << totalSum << '\n';

    if (isDivisibleByTen(totalSum) == true)
    {
        std::cout << "Card is valid" << '\n';
    }
    else
    {
        std::cout << "Card is invalid" << '\n';
    }
    std::cout << std::endl;

    return 0;
}


std::vector<int> doubleEverSecondDigit(std::string cardnum, int size)
{
    std::vector<int> tempList;
    int tempInt;
    int tempDouble;
    std::string tempString = "";
    int sumOfList = 0;

    for (int i = cardnum.size() -2; i >= 0; i-=2)
    {
        tempString = cardnum[i];
        tempInt = (cardnum[i] - '0');
        tempDouble = tempInt * 2;
        
        if (std::to_string(tempDouble).length() > 1)
        {   
            tempList.insert(tempList.begin(), (int)std::to_string(tempDouble)[0] - '0');
            tempList.insert(tempList.begin(), (int)std::to_string(tempDouble)[1] - '0');
        }
        else
        {
            tempList.insert(tempList.begin(), tempDouble);
        }
    }
    return tempList;
}


int sizeOfNumber(std::string cardnum)
{
    return cardnum.length();
}


int sumOfDigits(std::vector<int> singleDigitList, int size)
{
    int sum = std::accumulate(singleDigitList.begin(), singleDigitList.end(), 0);
    return sum;
}


int addAllOddNums(std::string cardnum)
{
    int totalOddNums = 0;
    std::vector<int> tempList;


    for (int i = cardnum.size() -1; i >= 0; i -= 2)
    {
        tempList.push_back(cardnum[i] - '0');
        std::cout << (cardnum[i] - '0') << " ";
    }
    std::cout << '\n';

    totalOddNums = std::accumulate(tempList.begin(), tempList.end(), 0);
    return totalOddNums;
}


bool isDivisibleByTen(int sumOfOddNums)
{
    double test = (sumOfOddNums % 10);
    if (test == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}
