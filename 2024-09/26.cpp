// Problem: 729. My Calendar I
// Link: https://leetcode.com/problems/my-calendar-i/
// Beats: 95.05% with 64 ms runtime, 66.95% with 42.68 MB memory usage

/*
Explanation:
- We use a `set` to store events in pairs of integers representing the [start, end) times.
- `lower_bound(event)` finds the first event that has a start time greater than or equal to the new event's start time.
- We then check if the new event overlaps with the next event (by comparing the start time of the next event and the end time of the new event).
- Similarly, we check if the new event overlaps with the previous event (by comparing the end time of the previous event and the start time of the new event).
- If there is no overlap, the new event is added to the `set`.

Time Complexity:
- The `lower_bound` function and `insert` function on the `set` both take O(log n) time, where n is the number of events.
- Hence, for each `book` operation, the time complexity is O(log n).

Space Complexity:
- The space complexity is O(n), where n is the number of events stored in the `set`.

*/

#include <iostream>
#include <set>

using namespace std;

class MyCalendar
{
private:
    set<pair<int, int>> calendar; // Set to store events as pairs of (start, end)

public:
    // Function to book a new event
    bool book(int start, int end)
    {
        const pair<int, int> event{start, end};

        // Find the first event that has a start time >= the new event's start time
        const auto nextEvent = calendar.lower_bound(event);

        // Check if the new event overlaps with the next event
        if (nextEvent != calendar.end() && nextEvent->first < end)
        {
            return false; // There's an overlap with the next event
        }

        // Check if the new event overlaps with the previous event
        if (nextEvent != calendar.begin())
        {
            const auto prevEvent = prev(nextEvent);
            if (prevEvent->second > start)
            {
                return false; // There's an overlap with the previous event
            }
        }

        // No overlap, so insert the new event into the calendar
        calendar.insert(event);
        return true;
    }
};

int main()
{
    MyCalendar myCalendar;

    // Example 1
    cout << "Example 1: " << endl;
    cout << "Book (10, 20): " << myCalendar.book(10, 20) << endl; // Expected Output: true
    cout << "Book (15, 25): " << myCalendar.book(15, 25) << endl; // Expected Output: false
    cout << "Book (20, 30): " << myCalendar.book(20, 30) << endl; // Expected Output: true

    return 0;
}
