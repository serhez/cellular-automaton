/*
 * @Author: Hezser <contact.sergiohernandez@gmail.com>
 * @Date: 13-06-2021 04:24
 * @Last Modified by: Hezser <contact.sergiohernandez@gmail.com>
 * @Last Modified time: 13-06-2021 05:41
 */

#include "grid.hpp"

using namespace core;

Grid::Grid(uint_fast8_t dimensions, GridState initial_state, CellUpdateFunction rules, uint_fast8_t max_rule_radius) noexcept
    : m_d{dimensions}, m_state{initial_state}, m_rules{rules}, m_max_rule_radius{max_rule_radius} {}

bool Grid::update()
{
    // TODO: Implement
}
