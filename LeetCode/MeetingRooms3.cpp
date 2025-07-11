// https://leetcode.com/problems/meeting-rooms-iii/description
#include <iostream>
#include <climits>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int mostBooked(int n, vector<vector<int>> &meetings)
{
    int m = meetings.size();
    sort(meetings.begin(),
         meetings.end()); // Sort by Starting Time of the Meeting
    vector<long long> lastAvailableAt(
        n, 0); // Stores end time of the meetings in each room
    vector<int> roomsUsedCount(
        n, 0); // Stores count of the meetings in each room
    for (vector<int> &meet : meetings)
    {
        int start = meet[0];
        int end = meet[1];
        int duration = end - start;
        bool found = false;
        long long earlyEndRoomTime = LLONG_MAX;
        int earlyEndRoom = -1;

        for (int room = 0; room < n; room++)
        {
            if (lastAvailableAt[room] <= start)
            {
                lastAvailableAt[room] = end; // Empty Room Found
                roomsUsedCount[room]++;      // Incrementing Count
                found = true;
                break;
            }
            if (lastAvailableAt[room] < earlyEndRoomTime)
            {
                earlyEndRoomTime = lastAvailableAt[room];
                earlyEndRoom = room;
            }
        }
        // Couldn't Find a Room
        if (!found)
        {
            // Pick That room Which will End Earlier
            lastAvailableAt[earlyEndRoom] += duration;
            roomsUsedCount[earlyEndRoom]++;
        }
    }
    int resultRoom = -1;
    int maxUse = 0;
    for (int i = 0; i < n; i++)
    {
        if (roomsUsedCount[i] > maxUse)
        {
            maxUse = roomsUsedCount[i];
            resultRoom = i;
        }
    }
    return resultRoom;
}

typedef pair<long long, int> P;
int mostBooked(int n, vector<vector<int>> &meetings)
{
    int m = meetings.size();
    sort(meetings.begin(),
         meetings.end()); // Sort by Starting Time of the Meeting
    vector<int> roomsUsedCount(
        n, 0); // Stores count of the meetings in each room

    priority_queue<P, vector<P>, greater<P>> usedRooms;
    priority_queue<int, vector<int>, greater<int>> availableRooms;

    for (int room = 0; room < n; room++)
    {
        availableRooms.push(room);
    }
    for (vector<int> &meet : meetings)
    {
        int start = meet[0];
        int end = meet[1];
        int duration = end - start;
        while (!usedRooms.empty() && usedRooms.top().first <= start)
        {
            int room = usedRooms.top().second;
            usedRooms.pop();
            availableRooms.push(room);
        }

        if (!availableRooms.empty())
        {
            int room = availableRooms.top();
            availableRooms.pop();
            usedRooms.push({end, room});
            roomsUsedCount[room]++;
        }
        else
        {
            int room = usedRooms.top().second;
            long long endTime = usedRooms.top().first;

            usedRooms.pop();
            usedRooms.push({endTime + duration, room});
            roomsUsedCount[room]++;
        }
    }

    int resultRoom = -1;
    int maxUse = 0;
    for (int i = 0; i < n; i++)
    {
        if (roomsUsedCount[i] > maxUse)
        {
            maxUse = roomsUsedCount[i];
            resultRoom = i;
        }
    }
    return resultRoom;
}

int main()
{
    int n = 2;
    vector<vector<int>> meetings = {{0, 10}, {1, 5}, {2, 7}, {3, 4}};
    vector<vector<int>> meetings2 = {{0, 10}, {1, 5}, {2, 7}, {3, 4}, {5, 6}};
    cout << mostBooked(n, meetings) << endl;  // Output: 0
    cout << mostBooked(n, meetings2) << endl; // Output: 0
    return 0;
}