# Basic Input Assignment 2 — C++ 

**Author:** Raymond Bawal III
**Professor** John Koss
**Course:** ITCS 2530 C++  
**Date:** October 24, 2025

A beginner C++ console program that collects a few inputs about the user’s favorite video game and prints a formatted summary. Than sumarizes and sends to  `report.txt`. The app adds small UX touches (console colors, pause/clear) using `windows.h`.

---

## What this program does

1. **Greets the user** with a styled title banner.
2. **Collects inputs** (with basic validation):
   - Favorite video game (string, can include spaces)
   - Favorite character (string)
   - Gaming platform (string)
   - Age (integer with range check)
   - Game price (double `$$.cc`)
   - Hours played (integer > 0)
3. **Computes** a derived value:  
   `value per hour = price / hoursPlayed`
4. **Outputs** a formatted summary table using `setw` and alignment.
5. **Saves the summary** to `report.txt`.
6. **UX polish**:
   - Light-cyan headers via `SetConsoleTextAttribute`
   - `system("pause")` before `system("cls")` so users can read text
   - Clean summary screen
   - Than any button to continue / end 

---

