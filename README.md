# Formula One Race Simulator


## Summary
Welcome to the 2023 Formula One season! This program simulates a Formula One races based on the 2023 race calendar and drivers. The program initially gives the user a menu with the option to simulate races, view driver information, view circuit information, or exit the program. 

If the user chooses to simulate races, the `simulateRace` method in the `Race` class orchestrates a virtual Formula One race based off the 2023 season race calendar. The 
`simulateRace` method first starts off by initializing the race grid with provided drivers (read in from a file in the `loadDriverData` method in the `Driver` class), 
randomly shuffles their position, and determine the pole position (driver starting first). It then provides an introduction to the race, including details about the circuit,
like circuit name, length, and number of laps for the race. After the countdown using a delay function, the race begins, during which it simulates events like crashes and overtakes
(both have random chances of occurring). At the end of the race, the method assigns points based on race positions, determines and announces the winner, and displays the race
results with points. The user is then prompted if they would like to move onto the next race. If they do, the second race is simulated just like above. In total there are 23 
race, and if the user completes all 23, the program will return the user to the main menu. If the user does not want to move onto the next race, they returned to the main menu.

If the user chooses to view driver info, the `driverInfo` method in the `Driver` class prints out each driver's info. This info includes name, race number, team, nationality, 
and F1 Grand Prix debut. This method automatically returns the user to the main menu. Driver info is loaded in with the `loadDriverData` method in the `Driver` class.

If the user chooses to view circuit info, the `circuitInfo` method in the `Circuit` class prints out each circuit's info. This info includes name, length of circuit, and number
of laps for the race. This method automatically returns the user to the main menu. Circuit info is loaded in with the `loadCircuitData` method in the `Circuit` class.

**Note:** The skill levels used to compute driver performance are hypothetical values based on 2023 team and driver championship standings. 

## Languages used
* C++

## Known Bugs
At this time, the only bug known of is with the overtake logic. Sometimes a driver will overtake another driver, but then the next overtake is the same two drivers. For example,
overtake 1: A bold maneuver from Logan Sargeant as he seizes the opportunity to overtake Sergio Perez! Completed lap 36/57, and overtake 2: Incredible driving from Logan Sargeant 
as he passes Sergio Perez! Completed lap 41/57. Though these overtakes are 5 laps apart, there is no displayed event in between them to allow Sergio Perez to re-overtake the Logan 
Sargeant.

## Future Work
There is a lot of future work that can be done with this program that is not in this current version (4/2024). For starters, there's more race events that could
be added like weather conditions and having the conditions change during the race and affect the outcome of the race (create more crashes), different tire options that could make
one driver faster than the other, pit stops, red/yellow/green flags for race incidents, etc. Additionally, there could be more functionality implemented within the `Team` class. This includes adding different strategies that get assigned to each team, which could then affect driver performance. In terms of a drivers championship, one future feature could be displaying the total amount of points a driver has earned for each race the user continues with.

## References
* https://www.geeksforgeeks.org/sleep-function-in-cpp/
* https://www.geeksforgeeks.org/type-inference-in-c-auto-and-decltype/
* https://www.geeksforgeeks.org/swap-in-cpp/
* https://stackoverflow.com/questions/12885356/random-numbers-with-different-probabilities
* https://www.w3schools.com/cpp/cpp_break.asp

