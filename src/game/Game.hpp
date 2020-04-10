#ifndef CYSKAT_GAME_HPP
#define CYSKAT_GAME_HPP

#include "cygui/GUIRenderManager.hpp"
#include "cygui/layout/VBox.hpp"
#include "cygui/widgets/Button.hpp"
#include "cysystem/sdl/SDL.hpp"
#include "cyvideo/font/SDLFont.hpp"
#include "cyvideo/renderer/SDLRenderer.hpp"
#include "cyvideo/window/SDLWindow.hpp"
#include "structures/Table.hpp"
#include "types.hpp"

namespace cyskat
{
    using namespace cyanide;

    enum class GAME_STATE : Uint8
    {
        START,
        MENU,
        DEAL,
        BID,
        DROP,
        PLAY,
        RESULT
    };

    struct GameState
    {
        GAME_STATE state    = GAME_STATE::START;
        GAME_STATE first    = GAME_STATE::START;
        GAME_STATE previous = GAME_STATE::START;

        void reset()
        {
            state = first;
        }

        void resume()
        {
            state = previous;
        }
    };

    class Game
    {
    private:
        GameState m_state;
        Table     m_table;

        cysystem::SDL                      m_sdl;
        SharedPtr<cyvideo::SDLWindow>      m_window;
        SharedPtr<cyvideo::SDLRenderer>    m_renderer;
        SharedPtr<cygui::GUIRenderManager> m_gui_renderer;
        SharedPtr<cyvideo::SDLFont>        m_font;

        cygui::VBox              m_box;

        void showMenu();

    public:
        Game();

        void run();
    };

}  // namespace cyskat

#endif  // CYSKAT_GAME_HPP
