/*
 * @Author: Sergio Hernandez <>
 * @Date: 04-07-2021 15:36
 * @Last Modified by: Sergio Hernandez <>
 * @Last Modified time: 04-07-2021 15:36
 */

#ifndef TWO_DIMENSIONS_VIEW_HPP
#define TWO_DIMENSIONS_VIEW_HPP

#include <SFML/Graphics.hpp>
#include "../core/grid.hpp"

namespace graphics
{

/**
 * @brief A two dimensional view of the grid
 */
class TwoDimensionsView
{
    public:
        /**
         * @brief Instantiates a TwoDimensionsView object
         *
         * @param grid The grid to display
         * @param window The window in which to display the grid
         */
        TwoDimensionsView(const core::Grid& grid) noexcept;

        /**
         * @brief Updates the window with the current grid view
         *
         * @param window The window to update
         */
        void update(sf::RenderWindow& window);

    private:
        /**
         * @brief Hidden default constructor
         *
         */
        TwoDimensionsView();

        /**
         * @CELL_ACTIVE_FILL_COLOUR The fill colour of each active cell
         */
        const sf::Color CELL_ACTIVE_FILL_COLOUR = sf::Color(100, 250, 50);

        /**
         * @CELL_INACTIVE_FILL_COLOUR The fill colour of each inactive cell
         */
        const sf::Color CELL_INACTIVE_FILL_COLOUR = sf::Color(150, 150, 150);

        /**
         * @CELL_OUTLINE_COLOUR The outline colour of each cell
         */
        const sf::Color CELL_OUTLINE_COLOUR = sf::Color(255, 255, 255);
        
        /**
         * @CELL_OUTLINE_THICKNESS The outline thickness of each cell
         */
        static constexpr float CELL_OUTLINE_THICKNESS = 5;

        /**
         * @m_grid The grid to display
         */
        const core::Grid& m_grid;
};

}  // namespace graphics

#endif
