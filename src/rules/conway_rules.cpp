/*
 * @Author: serhez <contact.sergiohernandez@gmail.com>
 * @Date: 18-06-2021 14:55
 * @Last Modified by: serhez <contact.sergiohernandez@gmail.com>
 * @Last Modified time: 20-06-2021 16:46
 */

#include "conway_rules.hpp"
#include "../core/grid.hpp"
#include "../utils/neighbours.hpp"

// NOTE: The number of neighbours of any cell in an infinite grid in d dimensions is just 2d
rules::ConwayRules::ConwayRules(const uint_fast8_t dimensions)
    : Rules{1}, m_d{dimensions},
    m_min_neighbours{static_cast<uint_fast64_t>(MIN_NEIGHBOURS_RATIO * (2 * m_d))},
    m_max_neighbours{static_cast<uint_fast64_t>(MAX_NEIGHBOURS_RATIO * (2 * m_d))}
    {}

bool rules::ConwayRules::applyToCell(const core::GridState& current_state,
    core::GridState& new_state, const core::GridCell& cell) const
{
    std::vector<core::GridCell> neighbours = utils::getNeighbours(m_d, cell);

    uint_fast8_t live_neighbours = 0;
    for(core::GridCell neighbour : neighbours)
    {
        if (current_state[neighbour] == core::Grid::ACTIVE_CELL_STATE)
        {
            ++live_neighbours;
        }
    }

    // Any live cell with fewer than 1/4 live neighbours dies
    // Any live cell with more than 3/8 live neighbours dies
    if (live_neighbours < m_min_neighbours 
        || live_neighbours > m_max_neighbours)
    {
        new_state[cell] = core::Grid::INACTIVE_CELL_STATE;
    }

    // Any live cell with 1/4 to 3/8 live neighbours lives
    else if (current_state[cell] == core::Grid::ACTIVE_CELL_STATE
        && live_neighbours >= m_min_neighbours
        && live_neighbours <= m_max_neighbours)
    {
        new_state[cell] = core::Grid::ACTIVE_CELL_STATE;
    }

    // Any dead cell with exactly 3/8 live neighbours becomes a live cell
    else if (live_neighbours == m_max_neighbours)
    {
        new_state[cell] = core::Grid::ACTIVE_CELL_STATE;
    }

    return true;
}
