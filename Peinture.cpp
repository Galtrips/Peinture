#include <SDL.h>
#include <SDL_ttf.h>
#include "config_sdl.h"
#include <iostream>
#include <fstream>
#include <ctime>
#include <cstring>

using namespace std;

const int CARRE = 30;  //hauteur fenetre
const int LARGEUR = 12; //largeur fenetre
const int HAUTEUR = 16;  //hauteur
const int TAILLEX = CARRE * LARGEUR + 120;  
const int TAILLEY = CARRE * HAUTEUR;


void init_tab(SDL_Color tab[HAUTEUR][LARGEUR], SDL_Renderer* rendu) {

   
    ifstream entree("Mystere.txt", ios::in);
    char ligne;
    if (!entree)
        cout << "Probleme d'ouverture \n";
    else {
        
            
            for (int i = 0; i < HAUTEUR ; i++) {
                for (int j = 0; j < LARGEUR; j++) {

                    entree >> ligne;
                    switch (ligne) {
                    case 'B':
                        tab[i][j].r = 255;
                        tab[i][j].g = 255;
                        tab[i][j].b = 255;
                        break;
                    case 'N':
                        tab[i][j].r = 0;
                        tab[i][j].g = 0;
                        tab[i][j].b = 0;
                        break;
                    case 'R':
                        tab[i][j].r = 255;
                        tab[i][j].g = 0;
                        tab[i][j].b = 0;
                        break;
                    case 'V':
                        tab[i][j].r = 106;
                        tab[i][j].g = 164;
                        tab[i][j].b = 30;
                        break;
                    case 'J':
                        tab[i][j].r = 255;
                        tab[i][j].g = 255;
                        tab[i][j].b = 0;
                        break;
                    }

                }
            }
           
        
        
        entree.close();

    }

    SDL_Rect rect;

    for (int i = 0; i < HAUTEUR; i++) {
        for (int j = 0; j < LARGEUR; j++) {

            SDL_SetRenderDrawColor(rendu, tab[i][j].r, tab[i][j].g, tab[i][j].b, 255);
            rect.x = CARRE*j;
            rect.y = CARRE*i;
            rect.w = CARRE;
            rect.h = CARRE;
            SDL_RenderFillRect(rendu, &rect);
          
        }
    }
    SDL_RenderPresent(rendu);
}

void negatif(SDL_Color tab[HAUTEUR][LARGEUR], SDL_Renderer* rendu) {

    SDL_Rect rect;

    for (int i = 0; i < HAUTEUR; i++) {
        for (int j = 0; j < LARGEUR; j++) {


            tab[i][j].r = 255 - tab[i][j].r;
            tab[i][j].g = 255 - tab[i][j].g;
            tab[i][j].b = 255 - tab[i][j].b;

            SDL_SetRenderDrawColor(rendu, tab[i][j].r, tab[i][j].g, tab[i][j].b, 255);
            rect.x = CARRE * j;
            rect.y = CARRE * i;
            rect.w = CARRE;
            rect.h = CARRE;
            SDL_RenderFillRect(rendu, &rect);
 
        }
    }

    SDL_RenderPresent(rendu);



}

void charger_palette(SDL_Renderer* rendu) {


    SDL_Rect rect;

    
    SDL_SetRenderDrawColor(rendu, 0, 0, 0, 255);
    rect.x = TAILLEX - 120 + 25;
    rect.y = 20;
    rect.w = CARRE;
    rect.h = CARRE;
    SDL_RenderFillRect(rendu, &rect);
    SDL_SetRenderDrawColor(rendu, 255, 255, 255, 255); //pinceau blanc
    SDL_RenderDrawRect(rendu, &rect); //on trace un rectangle vide

   
    SDL_SetRenderDrawColor(rendu, 255, 255, 255, 255);
    rect.x = TAILLEX - 120 + 25 + 40;
    rect.y = 20;
    rect.w = CARRE;
    rect.h = CARRE;
    SDL_RenderFillRect(rendu, &rect);
   
    SDL_SetRenderDrawColor(rendu, 255, 0, 0, 255);
    rect.x = TAILLEX - 120 + 25;
    rect.y = 20 +40;
    rect.w = CARRE;
    rect.h = CARRE;
    SDL_RenderFillRect(rendu, &rect);

    SDL_SetRenderDrawColor(rendu, 106, 164, 30, 255);
    rect.x = TAILLEX - 120 + 25 + 40;
    rect.y = 20 +40;
    rect.w = CARRE;
    rect.h = CARRE;
    SDL_RenderFillRect(rendu, &rect);

    SDL_SetRenderDrawColor(rendu, 255, 255, 0, 255);
    rect.x = TAILLEX - 120 + 25;
    rect.y = 20 + 80;
    rect.w = CARRE;
    rect.h = CARRE;
    SDL_RenderFillRect(rendu, &rect);

    SDL_SetRenderDrawColor(rendu, 0, 0, 255, 255);
    rect.x = TAILLEX - 120 + 25 + 40;
    rect.y = 20 + 80;
    rect.w = CARRE;
    rect.h = CARRE;
    SDL_RenderFillRect(rendu, &rect);

    SDL_RenderPresent(rendu);



}

int main(int argn, char* argv[]) {

    SDL_Color tab[HAUTEUR][LARGEUR];

    //ouverture de la SDL
    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        cout << "Echec à l’ouverture";
        return 1;
    }

    //on crée la fenêtre
    SDL_Window* win = SDL_CreateWindow("Titre de la fenetre",
        SDL_WINDOWPOS_CENTERED,     //pos. X: autre option: SDL_WINDOWPOS_UNDEFINED
        SDL_WINDOWPOS_CENTERED,     //pos. Y: autre option: SDL_WINDOWPOS_UNDEFINED
        TAILLEX,                         //largeur en pixels                        
        TAILLEY,                         //hauteur en pixels
        SDL_WINDOW_SHOWN //d’autres options (plein ecran, resizable, sans bordure...)
    );

    if (win == NULL)
        cout << "erreur ouverture fenetre";

    SDL_Renderer* rendu = SDL_CreateRenderer(
        win,  //nom de la fenêtre
        -1, //par défaut
        SDL_RENDERER_ACCELERATED); //utilisation du GPU, valeur recommandée
 


    init_tab(tab, rendu);
    charger_palette(rendu);
    
    SDL_Rect rect;
    rect.x = TAILLEX - 120 + 25;
    rect.y = 20;
    rect.w = CARRE;
    rect.h = CARRE;

    SDL_Rect rect2;
    rect2.x = TAILLEX - 120 + 25 + 40;
    rect2.y = 20;
    rect2.w = CARRE;
    rect2.h = CARRE;

    SDL_Rect rect3;
    rect3.x = TAILLEX - 120 + 25;
    rect3.y = 20 + 40;
    rect3.w = CARRE;
    rect3.h = CARRE;

    SDL_Rect rect4;
    rect4.x = TAILLEX - 120 + 25 + 40;
    rect4.y = 20 + 40;
    rect4.w = CARRE;
    rect4.h = CARRE;


    SDL_Rect rect5;
    rect5.x = TAILLEX - 120 + 25;
    rect5.y = 20 + 80;
    rect5.w = CARRE;
    rect5.h = CARRE;
    


    SDL_Rect rect6;
    rect6.x = TAILLEX - 120 + 25 + 40;
    rect6.y = 20 + 80;
    rect6.w = CARRE;
    rect6.h = CARRE;


    

    bool continuer = true;   //booléen fin de programme
    SDL_Event event;//gestion des évènements souris/clavier,
                                    //SDL_Event est de type struct
    while (continuer)
    {
        SDL_WaitEvent(&event);//attente d’un évènement
        switch (event.type) //test du type d’évènement
        {
        case SDL_QUIT: //clic sur la croix de fermeture
                                        //on peut enlever SDL_Delay
            continuer = false;
            break;

        case SDL_KEYDOWN:
            if (event.key.keysym.sym == SDLK_n) { //touche j
                negatif(tab, rendu);
            }
            break;
        
        case SDL_MOUSEBUTTONUP://appui souris
            if (event.button.button == SDL_BUTTON_LEFT) {//si on clique bouton gauche
                if (event.button.x > rect.x && event.button.x<rect.x + rect.w && event.button.y>rect.y && event.button.y < rect.y + rect.h) { //dans         le rectangle
                    SDL_SetRenderDrawColor(rendu, 0, 0, 0, 255);
                }
                else if (event.button.x > rect2.x && event.button.x<rect2.x + rect2.w && event.button.y>rect2.y && event.button.y < rect2.y + rect2.h) { //dans         le rectangle
                    SDL_SetRenderDrawColor(rendu, 255, 255, 255, 255);
                }
                else if (event.button.x > rect3.x && event.button.x<rect3.x + rect3.w && event.button.y>rect3.y && event.button.y < rect3.y + rect3.h) { //dans         le rectangle
                    SDL_SetRenderDrawColor(rendu, 255, 0, 0, 255);
                }
                else if (event.button.x > rect4.x && event.button.x<rect4.x + rect4.w && event.button.y>rect4.y && event.button.y < rect4.y + rect4.h) { //dans         le rectangle
                    SDL_SetRenderDrawColor(rendu, 106, 164, 30, 255);
                }
                else if (event.button.x > rect5.x && event.button.x<rect5.x + rect5.w && event.button.y>rect5.y && event.button.y < rect5.y + rect5.h) { //dans         le rectangle
                    SDL_SetRenderDrawColor(rendu, 255, 255, 0, 255);
                }
                else if (event.button.x > rect6.x && event.button.x<rect6.x + rect6.w && event.button.y>rect6.y && event.button.y < rect6.y + rect6.h) { //dans         le rectangle
                    SDL_SetRenderDrawColor(rendu, 0, 0, 255, 255);
                    cout << "bruh";
                }
                
                
            }
            break;
        case SDL_MOUSEBUTTONDOWN://appui souris
            if (event.button.button == SDL_BUTTON_LEFT) {//si on clique bouton gauche
                
                SDL_Rect rect7;
                rect7.x = CARRE * LARGEUR;
                rect7.y = CARRE * HAUTEUR;
                rect7.w = CARRE;
                rect7.h = CARRE;
                
                if (event.button.x < rect7.x  && event.button.y < rect7.y) { //dans         le rectangle
                    
                        SDL_Rect rect8;
                        rect8.x = event.button.x -(event.button.x % 30);
                        rect8.y = event.button.y - (event.button.y % 30);
                        rect8.w = CARRE;
                        rect8.h = CARRE;
   
                        SDL_RenderFillRect(rendu, &rect8);
                        SDL_RenderPresent(rendu);
                }

            }
            
            break;
        }

    }



    //destruction à la fin
    SDL_DestroyRenderer(rendu);

    SDL_DestroyWindow(win);   //equivalent du delete

    //fermeture
    SDL_Quit();
    return 0;
}