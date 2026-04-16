#include "bfs.h"
#include <queue> 
#include <algorithm>


void Bfs::setState(const AlgoState algoState)
{
    if(m_state != algoState){
        m_state = algoState;
    }
}

void Bfs::init(const GridData &data)
{
    m_data = data;

    m_queue = std::queue<int>();
    m_queue.push(m_data.startIndex);
    m_visited = std::vector<bool> (data.nodes.size(), false);
    m_visited[m_data.startIndex] = true;
    m_cameFrom = std::vector<int>(m_data.nodes.size(), -1);
    m_state = AlgoState::Running;
}

void Bfs::run(const GridData& data)
{
    init(data);
}

StepResult Bfs::step()
{
    //stopped, thread stops
    if(m_state == AlgoState::Stopped){
        return {StepResultType::Finished, -1};
    }

    //paused code not doing anything, thread continue
    if(m_state == AlgoState::Paused){
        return {StepResultType::Paused, -1};
    }

    if(m_queue.empty()){
        m_state = AlgoState::Stopped;
        return {StepResultType::Finished, -1};
    }

    int current = m_queue.front();
    m_queue.pop();

    if(current == m_data.endIndex){
        m_state = AlgoState::Stopped;
        return {StepResultType::Finished, current};
    }

    processNode(current);

    //return current node index for signal emit in worker
    return {StepResultType::Running, current};
}

void Bfs::blazzingRun(){
    while(step().state == StepResultType::Running) {

    }
}

std::vector<int> Bfs::getPath()
{
    std::vector<int> path;
    int current = m_data.endIndex;
    //in case of problems: change to this line instead if(m_cameFrom[current] == -1)
    if (current < 0 || current >= m_cameFrom.size() || m_cameFrom[current] == -1) {
        return path;
    }
    while (current != m_data.startIndex) {
        path.push_back(current);
        current = m_cameFrom[current];
        //in case of problems: comment lower line
        if (current == -1 || path.size() > m_data.nodes.size()) break;
    }
    // we got a path but it is reversed.
    // so we add the start node at the very end
    path.push_back(m_data.startIndex);
    // and reveerse our path 
    std::reverse(path.begin(), path.end());
    m_state = AlgoState::Stopped;
    return path;
}

AlgoState Bfs::state()
{
    return m_state;
}

std::vector<int> Bfs::neighbors(int current)
{

    //ToDO: optimize function to calculate neighbors for @current Node using @m_data
    std::vector<int> neighbors;

    /**
     * there are formulas for calculating rows and columns from grid
     * we are lucky that we have grid so we can count it by these two formula
     */
    int row = current / m_data.width;
    int col = current % m_data.width;
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

        if (next_row >= 0 && next_row < m_data.height && next_col >= 0 && next_col < m_data.width) {

            int index = next_row * m_data.width + next_col;
            /**
             * we converted our 2D coordinates into our 1D array
             * so now we can check whether this position has already been in our queue
             * if it has not, and if the position is not the wall
             * then we put our position in the visited list
             */
            if(m_data.nodes[index].type != NodeType::Wall) {
                neighbors.push_back(index);
            }
        }
    }
    return neighbors;
}

void Bfs::processNode(int current)
{
    std::vector<int> current_neighbors = neighbors(current);
    for(int next : current_neighbors) {

            if(!m_visited[next]){

                m_visited[next] = true;

                m_cameFrom[next] = current;

                m_queue.push(next);
            }
        }
}
