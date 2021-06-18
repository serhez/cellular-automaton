/*
 * @Author: Hezser <contact.sergiohernandez@gmail.com>
 * @Date: 18-06-2021 14:55
 * @Last Modified by: Hezser <contact.sergiohernandez@gmail.com>
 * @Last Modified time: 18-06-2021 17:04
 */

#include "conway_rules.hpp"
#include "../core/grid.hpp"

using namespace rules;

ConwayRules::ConwayRules(const uint_fast8_t dimensions) : inactive_radius{1}, m_d{dimensions} 
{
    // TODO: Implement utils::getNumberNeighbours -> returns the number of neighbours of any given cell for d dimensions (place it in some utils/neighbours.cpp)
    // TODO: Implement utils::getNeighbours -> returns the coordinates of the neighbours of a given cell for d dimensions (place it in some utils/neighbours.cpp)
    m_min_neighbours = (1/4) * utils::getNumberNeighbours(m_d);
    m_min_neighbours = (3/8) * utils::getNumberNeighbours(m_d);
}

bool ConwayRules::applyToCell(const core::GridState& current_state, core::GridState& new_state, const std::vector<uint_fast64_t> cell)
{
    // TODO: Any live cell with fewer than 1/4 live neighbours dies
    // TODO: Any live cell with 1/4 to 3/8 live neighbours lives
    // TODO: Any live cell with more than 3/8 live neighbours dies
    // TODO: Any dead cell with exactly 3/8 live neighbours becomes a live cell

    return true;
}
