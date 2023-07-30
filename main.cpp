#include <iostream>
#include <vector>

class Solution
{
private:
    int MAX_VALUE = 0;
    bool isMeetZeroAgain = false;

public:
    int findMaxConsecutiveOnes(std::vector<int> &nums)
    {
        std::vector<unsigned int> numberOfOne;
        unsigned int number = 0;
        std::cout << nums.size() << std::endl;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] == 1)
            {
                number++;
                isMeetZeroAgain = false;
                if ((i == nums.size() - 1) && nums[i] == 1)
                {
                    numberOfOne.push_back(number);
                }
            }
            else if (nums[i] == 0)
            {
                if (!isMeetZeroAgain)
                {
                    numberOfOne.push_back(number);
                    number = 0;
                }
                isMeetZeroAgain = true;
            }
        }
        std::cout << numberOfOne.size() << std::endl;

        MAX_VALUE = numberOfOne[0];
        for (int i = 0; i < numberOfOne.size(); i++)
        {

            if (numberOfOne[i] > MAX_VALUE)
                MAX_VALUE = numberOfOne[i];
        }
        return MAX_VALUE;
    }
};

int main()
{
    std::vector<int> nums{1, 1, 0, 1, 1, 1};
    Solution mySolution;
    std::cout << mySolution.findMaxConsecutiveOnes(nums);
    return 0;
}