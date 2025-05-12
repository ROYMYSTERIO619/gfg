//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function Template for C++
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

class Solution {
  public:
    int mostBooked(int n, vector<vector<int>> &meetings) {
        sort(meetings.begin(), meetings.end());

        priority_queue<int, vector<int>, greater<int>> freeRooms;
        for (int i = 0; i < n; ++i) freeRooms.push(i);

        // Min-heap of (endTime, roomNumber)
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<>> busyRooms;

        vector<int> count(n, 0);

        for (const auto &meeting : meetings) {
            int start = meeting[0];
            int end = meeting[1];

            // Free rooms that have become available
            while (!busyRooms.empty() && busyRooms.top().first <= start) {
                int roomNumber = busyRooms.top().second;
                busyRooms.pop();
                freeRooms.push(roomNumber);
            }

            if (!freeRooms.empty()) {
                int room = freeRooms.top(); freeRooms.pop();
                count[room]++;
                busyRooms.push({end, room});
            } else {
                auto earliest = busyRooms.top(); busyRooms.pop();
                long long newStart = earliest.first;
                long long duration = (long long)end - start;
                long long newEnd = newStart + duration;
                int room = earliest.second;
                count[room]++;
                busyRooms.push({newEnd, room});
            }
        }

        int maxMeetings = 0, resultRoom = 0;
        for (int i = 0; i < n; ++i) {
            if (count[i] > maxMeetings) {
                maxMeetings = count[i];
                resultRoom = i;
            }
        }

        return resultRoom;
    }
};



//{ Driver Code Starts.

int main() {
    int t, n, m;
    cin >> t;
    while (t--) {
        cin >> n;
        cin >> m;
        vector<vector<int>> meetings(m, vector<int>(2));
        for (int i = 0; i < m; i++) {
            cin >> meetings[i][0] >> meetings[i][1];
        }
        Solution ob;
        cout << ob.mostBooked(n, meetings) << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends