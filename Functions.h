/*
 *  Cascades Bingo Caller, a text-based Bingo caller with some helper features.
 *  Copyright (C) 2021  Tony Prindel
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program.  If not, see <https://www.gnu.org/licenses/>.
 */

#include <vector>
#include <string>

#ifndef CASCALL_FUNCTIONS_H
#define CASCALL_FUNCTIONS_H

void GenerateNumberVector(std::vector<int>&);
void PullNumber(std::vector<int>&);
void CheckNums(const std::vector<int>&);
void DisplayUncalledNums(const std::vector<int>&);
void AddBingoLetter(const int&, std::string&);

#endif //CASCALL_FUNCTIONS_H
