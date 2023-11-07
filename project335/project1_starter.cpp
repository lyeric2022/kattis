#include <bits/stdc++.h>
using namespace std;

void output(vector<pair<int, int>> &result)
{
    cout << "Free Times: \n";

    for (auto a : result)
    {
        cout << (a.first / 100) << ":" << (a.first % 100) << " - " << (a.second / 100) << ":" << (a.second % 100) << ", ";
    }
}

int parseMinTime(int mins)
{
    int result = 0;

    while (mins > 60)
    {
        result += 100;
        mins -= 60;
    }

    result += mins;

    return result;
}

void getAvailableTimes(int start_time, int end_time, int min_meeting_time, vector<pair<int, int>> &non_availabilities)
{
    sort(non_availabilities.begin(), non_availabilities.end());

    vector<pair<int, int>> result;

    int end = non_availabilities[0].second;
    int start = non_availabilities[0].first;

    if (start_time < start)
    {
        pair<int, int> available_time(start_time, start);
        result.push_back(available_time);
    }

    for (int i = 0; i < non_availabilities.size(); i++)
    {
        pair<int, int> interval = non_availabilities[i];

        if (interval.first > end)
        {
            if (interval.first > start_time && interval.second < end_time && min_meeting_time <= interval.first - end)
            {
                // cout << min_meeting_time << " " << interval.first << " " << end << "\n";
                pair<int, int> available_time(end, interval.first);
                result.push_back(available_time);
            }
        }

        end = max(end, interval.second);
    }

    if (end_time > end && min_meeting_time <= end_time - end)
    {
        pair<int, int> available_time(end, end_time);
        result.push_back(available_time);
    }

    output(result);

    // for (auto a : non_availabilities)
    // {
    //     cout << "busy times: " << a.first << " " << a.second << "\n";
    // }

    // cout << "start time: " << start_time << "\n";
    // cout << "end time: " << end_time << "\n";
    // cout << "min meeting time: " << min_meeting_time << "\n";
}

pair<int, int> readInterval(string &str, int index)
{
    pair<int, int> result = {0, 0};

    int num = 0;
    bool first_val = false;

    for (int i = index; i < str.size(); i++)
    {
        if (str[i] == ':')
        {
            continue;
        }
        else if (str[i] == '\'')
        {
            if (!first_val)
            {
                result.first = num;
            }
            else
            {
                result.second = num;
                return result;
            }

            i += 4;
            num = 0;
            first_val = true;
        }

        num *= 10;

        num += (str[i] - '0');
    }

    return {0, 0};
}

vector<pair<int, int>> readTimes(string &str)
{
    vector<pair<int, int>> result;

    for (int i = 0; i < str.size(); i++)
    {
        if (isdigit(str[i]))
        {
            result.push_back(readInterval(str, i));
            i += 14;
        }
    }

    return result;
}

void readFile()
{
    ifstream my_file("input.txt");
    vector<pair<int, int>> non_availabilities;

    string prev_line = "";
    bool is_times_blocked = true;

    int start_time = 0, end_time = INT_MAX, min_meeting_time;
    if (my_file.is_open())
    {
        while (my_file)
        {
            string my_line;
            getline(my_file, my_line);

            if (prev_line != my_line)
            {
                if (my_line.empty())
                {
                    continue;
                }

                if (my_line.size() <= 4)
                {
                    min_meeting_time = parseMinTime(stoi(my_line));
                }

                else if (is_times_blocked)
                {
                    vector<pair<int, int>> temp = readTimes(my_line);

                    for (auto a : temp)
                    {
                        non_availabilities.push_back(a);
                    }

                    is_times_blocked = !is_times_blocked;
                }
                else
                {
                    vector<pair<int, int>> temp = readTimes(my_line);

                    start_time = max(start_time, temp[0].first);
                    end_time = min(end_time, temp[0].second);

                    is_times_blocked = !is_times_blocked;
                }
            }

            prev_line = my_line;
        }

        getAvailableTimes(start_time, end_time, min_meeting_time, non_availabilities);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    readFile();

    return 0;
}