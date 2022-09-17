#include<screen.h>
#include<iomanip>

namespace create
{
    screan::screan()
    {
        cout<<"constructor created"<<"\n";
    }
    bool screan::createscreen() //initializing video and creating a window
    {  
         if(SDL_Init(SDL_INIT_VIDEO) < 0)   {
            cout<<"video initialization didn't work"<<"\n";
                return false;
         }

            m_window = SDL_CreateWindow("anime name", SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED, 
            m_width, m_height, SDL_WINDOW_SHOWN|SDL_WINDOW_RESIZABLE);

            if(m_window < 0)
            {
                return false;
            }

            cout<<SDL_GetError()<<"\n";


         return true;
    }


    bool screan::create_rend_texture() //creating renderer and creating texture
    {
        m_renderwin = SDL_CreateRenderer(m_window,-1, SDL_RENDERER_ACCELERATED);
        m_texturewin = SDL_CreateTexture(m_renderwin, SDL_PIXELFORMAT_RGBA32, SDL_TEXTUREACCESS_STATIC, m_width,m_height);

        if(m_texturewin < 0 || m_renderwin < 0)
        {
            return false;
        }

         cout<<SDL_GetError()<<"\n";

        return true;
    }
     
    void screan::close() //closing and destroying the buffer 
    {
        delete []m_buffer;
        SDL_DestroyTexture(m_texturewin);
        SDL_DestroyRenderer(m_renderwin);
        SDL_DestroyWindow(m_window);
         cout<<SDL_GetError()<<"\n";

        SDL_Quit();

    }

   
}