/*
 * @Author: Sergio Hernandez <>
 * @Date: 04-07-2021 16:14
 * @Last Modified by: Sergio Hernandez <>
 * @Last Modified time: 04-07-2021 16:14
 */

#include "two_dimensions_view.hpp"

graphics::TwoDimensionsView::TwoDimensionsView(const core::Grid& grid) noexcept
    : m_grid{grid}
    {}

void graphics::TwoDimensionsView::update(sf::RenderWindow& window)
{
    // Clear previous frame
    window.clear();

    // Draw the grid
    const core::GridState& grid_state = m_grid.getState();
    const uint_fast64_t n_cells = grid_state.shape()[1];
    const uint_fast64_t window_x_size = window.getSize().x;
    const uint_fast64_t window_y_size = window.getSize().y;
    const uint_fast64_t cell_size = window_x_size / n_cells;

    for (uint_fast64_t x = 0; x < n_cells; ++x)
    {
        for (uint_fast64_t y = 0; y < n_cells; ++y)
        {
            sf::RectangleShape cell_view(sf::Vector2f(cell_size, cell_size));
            cell_view.setPosition(x * cell_size, y * cell_size);
            cell_view.setFillColor(grid_state[{x, y}] == m_grid.ACTIVE_CELL_STATE ? CELL_ACTIVE_FILL_COLOUR : CELL_INACTIVE_FILL_COLOUR);
            cell_view.setOutlineColor(CELL_OUTLINE_COLOUR);
            cell_view.setOutlineThickness(CELL_OUTLINE_THICKNESS);
            window.draw(cell_view);
        }
    }

    // Debuffer the frame
    window.display();
}
