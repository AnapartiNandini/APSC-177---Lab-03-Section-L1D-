/*----------------------------------------------------------------------------------------------*
* APSC 177 – Lab Section L1D  - Lab 03                                                  	*
*                                                                 				*
* Student Name: Nandini Anaparti                                                        	*               
* Student ID: 27794205                                                                  	*        
* Brief Description: This program asks for user input for the number of trains on 4 		*
* train tracks. It sorts the tracks in descending order, giving precedence to the track 	*
* with the highest number of trains. If two tracks have the same number of input trains,	*
* the program follows the pre-determined priority order going from Track 4 to Track 1 		*
* where Track 4 has the highest priority.Based on the priority order, one train is 		*
* cleared to travel at a time and all other trains are stopped, on all tracks. The 		*
* information regarding how many trains are on each track, which track has cleared the  	*
* train, and how many trains are stopped on each track are displayed.				*
*-----------------------------------------------------------------------------------------------*/


#include <algorithm> // library required to perform the sort function
#include <iostream>  // add other preprocessor directories as needed
#include <string>    // library required to use strings

using namespace std;

int main() {

// Declaration of user input variables
  int track_1, track_2, track_3,
      track_4; // stores the user inputed value of trains, per track.
  
  // Asks user input for the value of Track 1
  cout << "Enter the number of trains on Track 1: ";
  cin >> track_1; // assigns the value provided by the user to track_1

  // Asks user input for the value of Track 2
  cout << "Enter the number of trains on Track 2: ";
  cin >> track_2; // assigns the value provided by the user to track_2

  // Asks user input for the value of Track 3
  cout << "Enter the number of trains on Track 3: ";
  cin >> track_3; // assigns the value provided by the user to track_3

  // Asks user input for the value of Track 4
  cout << "Enter the number of trains on Track 4: ";
  cin >> track_4; // assigns the value provided by the user to track_4
  
  //Declaration of unassigned variables.

  int cleared_track_number;  // stores the value for the track number which has
                             // been allowed to clear one of its trains for
                             // travel.
                
  int arr_priority_order[4]; // int array, with length 4. Stores the priority
                             // order
                
  string track_1_output_statement; // cout statement for track 1
  string track_2_output_statement; // cout statement for track 2
  string track_3_output_statement; // cout statement for track 3
  string track_4_output_statement; // cout statement for track 4

  // Declaration and Assignment of variable
  int input_track_arr[4] = {
      track_1, track_2, track_3,
      track_4}; // int array, with a length of 4. Stores the input track values.
                // Makes the process of sorting to determine priority order,
                // more efficent.
  int arr_sort_end =
      sizeof(input_track_arr) /
      sizeof(input_track_arr[0]); // returns the number of elements in the
                                  // array. Can also be said to be the ending
                                  // location of the sort function.
  bool duplicate_train_value =
      false; // Binary variable used to determine whether any user inputed
             // values for the number of trains per track, are the same for more
             // than one track - i.e. Does more than one track have the same
             // number of trains?

  bool cleared_track = false; // checks if a track has been cleared

  // sort(start of range, end of range, comparison function).
  // greater<int>() compares two consecutive integers and if first integer > second integer, it returns true. It performs the neccessary steps to arrange the elements of an array in descending order.
  sort(input_track_arr, input_track_arr + arr_sort_end,
       greater<int>()); // sorts the input track array in descending order. If
                        // duplicates exist, gives prescedence in the priority
                        // order of Track 4 (highest) to Track 1 (lowest)

  /*
   * checks which track has highest priority and sets the cleared_track_number
   * to the number of that track, and sets appropriate output statement (the
   * statement which will be displayed to the user) for that track. If the
   * cleared track has more than 4 trains on the track, an appropriate alert
   * will also be displayed
   */

  if (input_track_arr[0] == track_4 && !cleared_track) {
    cleared_track_number = 4;
    track_4_output_statement = "Track 4 has 1 train cleared and " +
                               to_string(track_4 - 1) + " train(s) stopped. ";
    cleared_track = true;

    if ((track_4 - 1) >= 4) {
      track_4_output_statement += "Track 4 alert!";
    }
  } else {
    track_4_output_statement =
        "Track 4 has " + to_string(track_4) + " train(s) stopped. ";
  }

  if (input_track_arr[0] == track_3 && !cleared_track) {
    cleared_track_number = 3;
    track_3_output_statement = "Track 3 has 1 train cleared and " +
                               to_string(track_3 - 1) + " train(s) stopped. ";
    cleared_track = true;

    if ((track_3 - 1) >= 4) {
      track_3_output_statement += "Track 3 alert!";
    }
  } else {
    track_3_output_statement =
        "Track 3 has " + to_string(track_3) + " train(s) stopped. ";
  }

  if (input_track_arr[0] == track_2 && !cleared_track) {
    cleared_track_number = 2;
    track_2_output_statement = "Track 2 has 1 train cleared and " +
                               to_string(track_2 - 1) + " train(s) stopped. ";
    cleared_track = true;

    if ((track_2 - 1) >= 4) {
      track_2_output_statement += "Track 2 alert!";
    }
  } else {
    track_2_output_statement =
        "Track 2 has " + to_string(track_2) + " train(s) stopped. ";
  }

  if (input_track_arr[0] == track_1 && !cleared_track) {
    cleared_track_number = 1;
    track_1_output_statement = "Track 1 has 1 train cleared and " +
                               to_string(track_1 - 1) + " train(s) stopped. ";
    cleared_track = true;
    if ((track_1 - 1) >= 4) {
      track_1_output_statement += "Track 1 alert!";
    }
  } else {
    track_1_output_statement =
        "Track 1 has " + to_string(track_1) + " train(s) stopped. ";
  }

  // The following line of code prints the track info. for track 1
  cout << track_1_output_statement << endl;
  // The following line of code prints the track info. for track 2
  cout << track_2_output_statement << endl;
  // The following line of code prints the track info. for track 3
  cout << track_3_output_statement << endl;
  // The following line of code prints the track info. for track 4
  cout << track_4_output_statement << endl;

  return 0;
}
