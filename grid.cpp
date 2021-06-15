/*
 * @Author: Hezser <contact.sergiohernandez@gmail.com>
 * @Date: 13-06-2021 04:24
 * @Last Modified by: Hezser <contact.sergiohernandez@gmail.com>
 * @Last Modified time: 13-06-2021 20:06
 */

#include "grid.hpp"

using namespace core;

Grid::Grid(uint_fast8_t dimensions, GridState initial_state, CellUpdateFunction rules, uint_fast8_t max_rule_radius) noexcept
    : m_d{dimensions}, m_state{initial_state}, m_rules{rules}, m_max_rule_radius{max_rule_radius} {}

bool Grid::update()
{
    // Copy the GridState to enforce rules
    GridState new_state(m_state.shape());
    std::copy(m_state.crbegin(), m_state.crend(), new_state.begin());

    // TODO: Check that there are at least m_max_rule_radius inactive cells in the grid at the ends of each dimension

    // TODO: Enforce the rules in each cell of the grid after

    // TODO: Make the copy the current state
}
