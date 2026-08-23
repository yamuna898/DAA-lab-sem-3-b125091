# 📈 DAA Lab 04
__________________________________
Q4: Application of sorting-IV (Peak Simultaneous Attendees)
__________________________________ 

---

## 📌 Overview
This repository contains the C programming implementation for **Question 4** of our DAA Lab-04 assignment.
The objective is to analyze the entry times $a_i$ and exit times $b_i$ ($b_i > a_i$) of $n$ distinct persons attending a party (with no tie times) to determine the exact time when the maximum number of people were simultaneously present in $O(n \log n)$ time.

## ⚙️ Algorithmic Logic & Justification

1. **Event Decomposition:** Split each guest's interval $(a_i, b_i)$ into two distinct point events: an Arrival event `(+1)` at $a_i$ and a Departure event `(-1)` at $b_i$.
2. **Sort Events:** Place all $2n$ events into a single array and sort them chronologically by timestamp in $O(n \log n)$ time.
3. **Sweep-Line Traversal:** Iterate through the sorted timeline while maintaining a `current_guests` counter. Increment on entry, decrement on exit, and update `max_guests` and `peak_time` whenever `current_guests` exceeds the previous maximum.
4. **Justification:** Sorting $2n$ timestamps requires $O(2n \log(2n)) = O(n \log n)$ time. The linear sweep takes $O(n)$ time, bounding the total complexity to $O(n \log n)$.

-------------------------------------------

## 💻 Given the output below showing the execution of the sweep

Below is the computational output evaluating attendee data for $n = 4$ party guests.

### Performance Comparison (Attendees $n = 4$)

| Guest Intervals $(a_i, b_i)$ | Total Timestamps | Max Simultaneous Guests | Peak Timestamp Recorded |
| :--- | :--- | :--- | :--- |
| `(1, 5), (2, 8), (6, 10), (3, 7)` | 8 | **3 Persons** | **Timestamp 3** |

---   

Note: At timestamp 3, persons 1, 2, and 4 are inside the party simultaneously.
