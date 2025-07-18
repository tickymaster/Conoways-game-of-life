#include <iostream>
#include <cstdlib>
#include <vector>
#include <unistd.h>


void gameOfLife(size_t grid_size_rows = 10, size_t grid_size_cols = 10);
std::vector<std::vector<bool>> generateGrid(size_t grid_size_rows = 10, size_t grid_size_cols = 10);
size_t getNumberOfNeighbors(int row, int col, const std::vector<std::vector<bool>>& grid);
void printGrid(const std::vector<std::vector<bool>>& grid);

int main(){
    size_t grid_size_rows;
    size_t grid_size_cols;
    std::cout << "Welcome to the game of life!\n" << "How large do you want the grid to be (axb): " << std::endl;
    std::cout << "a: ";
    std::cin >> grid_size_rows;
    std::cout << "b: ";
    std::cin >> grid_size_cols;
    gameOfLife(grid_size_rows, grid_size_cols);
}

std::vector<std::vector<bool>> generateGrid(size_t grid_size_rows, size_t grid_size_cols){
    std::vector<std::vector<bool>> grid(grid_size_rows, std::vector<bool>(grid_size_cols, false));
    
    std::cout << "Welcome to the grid generation tool!\n\n" 
    << "Specify the locations to put a live cell into: \n" 
    << "specifying coordinates (-1,-1) will end the grid creation process...: \n"
    << std::endl;

    while (true)
    {
        short row;
        short col;
        
        std::cout << "Specify Row: ";
        std::cin >> row;
        std::cout << "\nSpecify Collumn: ";
        std::cin >> col;

        if (col == -1 && row == -1)
        {
            break;
        } else if((col < 0 || col >= grid_size_cols) || (row < 0 || row >= grid_size_rows))
        {
            std::cerr << "Error: Invaid index, please reenter valid indicies...\n";
        } else
        {
            grid[row][col] = true;
            std::cout << "Added live cell at coordinates (" << row << ',' << col << "), awaiting new coordinate input..\n";
        }
    }
    std::cout << "Returning a grid of size = (" << grid_size_rows << ',' << grid_size_cols << ')' << std::endl;
    return grid; 
    
}

void gameOfLife(size_t grid_size_rows, size_t grid_size_cols){
    std::vector<std::vector<bool>> old_grid = generateGrid(grid_size_rows, grid_size_cols);
    std::vector<std::vector<bool>> new_grid(grid_size_rows, std::vector<bool>(grid_size_cols, false));

    /*
    List of rules:
        1. A location that has zero or one neighbors will be empty the next generation. If a cell was in that 
        location, it dies of loneliness.
        2. A location with 2 neighbors is stable, if it was empty it remains empty the next generation and if it wasnt
        it will remain that way in for the next generation.
        3. A location with 3 neighbors will contain a cell in the next generation. If it was unoccupied before a new cell 
        will be born. If it already had a cell there, the cell remains - good times!
        4. A location with 4 or more neighbors will be empty in the next generation, if there was a cell there already - it dies 
        of overcrowding.
        5. The births and deaths that transform one generation to the next one must all take place simontanously ....
        yada yada, tldr - have one grid for the previou gen and have one for the next gen so that the next gen can be "built"
        from the last gen without destroying it you get what i mean....I hope.
    */

    while (true)
    {
        for (size_t row = 0; row < grid_size_rows; row++)
        {
            for (size_t col = 0; col < grid_size_cols; col++)
            {
                size_t number_of_neighbors = getNumberOfNeighbors(row, col, old_grid);

                // Rule checking

                if (number_of_neighbors <= 1)
                {
                    new_grid[row][col] = false;
                } else if (number_of_neighbors == 2)
                {
                    new_grid[row][col] = old_grid[row][col];
                } else if (number_of_neighbors == 3)
                {
                    new_grid[row][col] = true;
                } else if (number_of_neighbors >= 4)
                {
                    new_grid[row][col] = false;
                }
            }
        }
        std::cout << "\033[2J\033[H";
        printGrid(old_grid);
        old_grid = new_grid;

        usleep(300000);        
    }
    

}

void printGrid(const std::vector<std::vector<bool>>& grid){
    for (const std::vector<bool>& row : grid)
    {
        for (const bool& col : row)
        {
            std::cout << (col ? "■" : " ");
        }
        std::cout << "\n";
    }
    std::cout << '\n';
        
}

size_t getNumberOfNeighbors(int row, int col, const std::vector<std::vector<bool>>& grid){
    size_t count = 0;

    //boundries
    size_t rows = grid.size();
    size_t cols = grid[0].size();

    for (int i = -1; i < 2; i++){
        for (int j = -1; j < 2; j++){
            int r = row + i;
            int c = col + j;

            if (r >= 0 && r < rows && c >= 0 && c < cols)
            {
                if (grid[r][c])
                    count++;
            }
            
        }
    }

    if (grid[row][col])
        count--;

    return count;
}