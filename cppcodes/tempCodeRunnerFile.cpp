#include <iostream>
#include <vector>
// #include <iostream>
using namespace std;
vector<vector<int>> threeSum(vector<int> &nums)
{
    vector<vector<int>> result = {};
    vector<int> tempTriplet = {};
    bool duplicate = false;
    for (int i = 0; i < nums.size(); i++)
    {
        for (int j = i + 1; j < nums.size(); j++)
        {
            for (int k = j + 1; k < nums.size(); k++)
            {
                if (nums[i] + nums[j] + nums[k] == 0)
                {
                    tempTriplet = {nums[i], nums[j], nums[k]};
                    // duplicate check
                    duplicate = false;
                    for (int a = 0; a < result.size(); a++)
                    {
                        cout << "WELCOME" << endl;
                        cout << tempTriplet[0] << " " << tempTriplet[1] << " " << tempTriplet[2] << endl;

                        if (result[a][0] == tempTriplet[0] || result[a][0] == tempTriplet[1] || result[a][0] == tempTriplet[2])
                        {
                            if (result[a][1] == tempTriplet[0] || result[a][1] == tempTriplet[1] || result[a][1] == tempTriplet[2])
                            {
                                if (result[a][2] == tempTriplet[0] || result[a][2] == tempTriplet[1] || result[a][2] == tempTriplet[2])
                                {
                                    cout << "DUPLICATE" << endl;
                                    cout << result[a][0] << " " << result[a][1] << " " << result[a][2] << endl;
                                    cout << "END" << endl;
                                    duplicate = true;
                                }
                            }
                        }
                    }
                    if (!duplicate)
                    {
                        result.push_back(tempTriplet);
                    }
                }
            }
        }
    }

    return result;
}

int main()
{
    std::vector<int> nums = {0, 3, 0, 1, 1, -1, -5, -5, 3, -3, -3, 0};
    std::vector<std::vector<int>> result = threeSum(nums);
    cout << "Printing main() result:" << endl;

    for (int i = 0; i < result.size(); i++)
    {
        for (int j = 0; j < result[i].size(); j++)
        {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}