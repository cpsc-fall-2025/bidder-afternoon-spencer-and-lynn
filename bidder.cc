#include <fstream>
#include <iostream>
#include <string>
#include <vector>

// ============================================================================
// INSTRUCTIONS
// ============================================================================
// 1. Implement the three functions below.
// 2. You may use the main() function at the bottom to test your code locally.
// 3. Do not change the function signatures.
// ============================================================================

// TODO: Implement this function to return a vector of strings
// containing the names of everyone on your team.
std::vector<std::string> GetTeamMembers() {
  // Your code here
  return {"Spencer Seegrist", "Lynn Harb"};
}

// TODO: Implement this function to return a string that describes
// the strategy your logic uses to bid (e.g'
// ., "We bid high early on").
std::string GetStrategy() {
  // Your code here
  return "even bids in the middle";
}

// TODO: Implement the bidding logic.
// parameters:
//   rounds: The total number of rounds in the game.
//   budget: The total points available to spend across all rounds.
//   output_filename: The name of the file where the bids should be written.
//
// Logic:
//   1. Calculate how much to bid in each round.
//   2. Open 'output_filename' for writing.
//   3. Write the bid for each round on a new line in the file.
//
// Constraints:
//   - You must write exactly 'rounds' number of lines.
//   - The sum of all bids must not exceed 'budget'.
//   - Bids must be non-negative integers.
void GenerateBids(int rounds, int budget, std::string output_filename) {
  // Your code here
  std::ofstream out{output_filename};
  int start = rounds / 3;
  int end =  rounds /3 * 2;
  int bid = budget / start;
  for (int i = 0; i < rounds; i++) {
      if (i >= start && i < end && budget - bid > 0) {
        out << bid << "\n";
        budget -= bid;
      }
      else if (i >= end && budget > 0) {
        out << budget << "\n";
        budget = 0;
      }
      else {
        out << 0 << "\n";
      }
  }
}

// ============================================================================
// MAIN FUNCTION
// Use this to test your code.
// This function will be ignored by the "make test" command.
// ============================================================================
int main() {
  // You can write code here to call your functions and see if they work.
  // Example:
  // GenerateBids(20, 300, "test_output.txt");
  
  return 0;
}
