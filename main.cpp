/*
 *  Cascades Bingo Caller, a text-based Bingo caller with some helper features.
 *  Copyright (C) 2021  Tony Prindel
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program.  If not, see <https://www.gnu.org/licenses/>.
 */

#include <iostream>
#include <vector>
#include <conio.h>
#include "Functions.h"
#ifdef _WIN32
#include <windows.h>
#else
#include <unistd.h>
#endif

int main() {
    std::vector<int> NumberVector;
    GenerateNumberVector(NumberVector);
    char input;

    std::cout << "CASCADES BINGO CALLER 3: Boogaloo Electric\n"
                 "By Tony Prindel, Copyright 2021\n\n"
                 "Controls (case doesn't matter):\n"
                 "Call number: Space\n"
                 "Enter checking mode: F\n"
                 "Display uncalled numbers: D\n\n";

    while (!NumberVector.empty()) {
        input = _getch();

        switch (input) {
            case ' ':
                PullNumber(NumberVector);
                std::cout << std::endl;
                break;
            case 'F':
            case 'f':
                CheckNums(NumberVector);
                std::cout << "Exited Checking Mode\n\n";
                break;
            case 'D':
            case 'd':
                DisplayUncalledNums(NumberVector);
                std::cout << std::endl;
                break;
            default:
                break;
        }
    }

    std::cout << "\n\nCalling finished! Press any key to exit.";
    Sleep(2000);
    _getch();

    return 0;
}
