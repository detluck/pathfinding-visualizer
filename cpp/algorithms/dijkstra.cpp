#include "dijkstra.h"
#include <queue> 

void Dijkstra::run(const GridData& data)
{
    ///firstly we initialize our queue
    std::queue<int> myQueue;

    ///then put our starting position inside our queue
    myQueue.push(data.startIndex);

    /**
     * 
     * and we initialize our list with visited nodes with the size of total nodes we have
     * firstly have not visited any nodes so we just put false.
     */
    std::vector<bool> visited(data.nodes.size(), false);

    ///as we have put our starting position, we say that we have been here
    visited[data.startIndex] = true;

    while(!myQueue.empty()) {
        int current = myQueue.front();
        myQueue.pop();
        if(current == data.endIndex) {
            break;
        }
    
        /**
         * there are formulas for calculating rows and columns from grid
         * we are lucky that we have grid so we can count it by these two formula
         * how it works, example: we have number 12 and our grid is 5x5
         * we divide 12/5 and get 2. this is index 2 (row)
         * we get the leftover from 12/5 and get two 12-(5*2)=2. this is our column
         */
        int row = current / data.width;
        int col = current % data.width;

        /** 
         * created two arrays with directions
         * (-1,0) - up
         * (1,0) - down
         * (0,-1) - left
         * (0, 1) - right
         */
        int deltaRow[] = {-1,1,0,0};
        int deltaCol[] = {0,0,-1,1};
        /**
         * our loop that looks for neighbors
         * it counts until 4 because we have 4 directions: 0,1,2,3;
         */
        for(int i = 0; i < 4; i++){

            /**
             * inside we calculate these 4 directions by checking them with i
             * i = 0 for checking upper cell
             * i = 1 for checking lower cell
             * and so on.
             */
            int next_row = row + deltaRow[i];
            int next_col = col + deltaCol[i];

            /// basic check to be sure we are not beyond the borders
            if (next_row >= 0 && next_row < data.height && next_col >= 0 && next_col < data.width) {

                /**
                 * because of the fact that we have 1D array, 
                 * we have to use this formula to convert our 2D data to 1D
                 */
                int index = next_row * data.width + next_col;
                /**
                 * we converted our 2D coordinates into our 1D array
                 * so now we can check whether this position has already been in our queue
                 * if it has not, and if the position is not the wall
                 * then we put our position in the visited list
                 */
                if(!visited[index] && data.nodes[index] != NodeType::Wall) {
                    visited[index] = true;
                    myQueue.push(index);
                }
            }
        }
    }
}

void Dijkstra::pause()
{

}

void Dijkstra::resume()
{

}

void Dijkstra::stop()
{

}

bool Dijkstra::isRunning() const
{

}
