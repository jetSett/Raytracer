#ifndef CHRONOF_H_INCLUDED
#define CHRONOF_H_INCLUDED

#include <tuple>
#include <chrono>
#include <iostream>

/// \file JetChrono.h
/// Contiend le namespace, la classe et les fonctions permettant de chronomÃ©trer
/// \author JetSett joel [POINT] feldo [AT] gmail [POINT] com
/// \date 06/03/13
/// \warning compiler avec l'option std=c++11 ou std=c++0x


using std::chrono::system_clock;
using std::chrono::time_point;
using std::chrono::duration;


/// \class Chrono
/// Utilisant le RAII du c++, cette classe permet de chronomÃ©trer un scope
/// Vous instanciez cette classe au moment oÃ¹ vous voulez l'utiliser, et au moment oÃ¹ elle seras dÃ©truite,
/// elle afficheras le temps Ã©coulÃ©. Notez bien qu'il est possible d'utiliser la fonction elapsedTime() pour
/// obtenir le temps Ã©coulÃ©, ou encore la fonction reset() pour rÃ©initialiser le timer
/// \param Period type de pÃ©riode de temps (millisecond, secondes, microsecondes...)
/// \param ReturnType type de retour voulu pour le temps Ã©coulÃ©
/// \todo permettre Ã  l'utilisateur de choisir le flux de sortie souhaitÃ© pour le destructeur
template<class Period = std::milli, class ReturnType = unsigned long >
class Chrono{
public:
    /// \fn Chrono(bool destruct)
    /// \param destruct active ou desactive l'utilisation du temps Ã©coulÃ© avec le destructeur
    Chrono(bool destruct = true) : _destruct(destruct){
        _begin = system_clock::now();
    }

    ~Chrono(){
        if(_destruct){
            std::cout << "Temps ecoule dans le scope : " << elapsedTime().count() << std::endl;
        }
    }
    /// \fn reset()
    /// remet Ã  0 le chrono
    void reset(){
        _begin = system_clock::now();
    }

    /// \fn elapsedTime()
    /// \return un objet de type std::duration correspondant Ã  la durÃ©e Ã©coulÃ©e depuis l'instanciation de l'objet (ou depuis le dernier reset())
    duration<ReturnType, Period> elapsedTime(){
        system_clock::time_point now = system_clock::now();
        return std::chrono::duration_cast<std::chrono::duration<ReturnType,Period>>(now-_begin);
    }

private:
    system_clock::time_point _begin;
    bool _destruct;
};
/// \fn chronoFonct(void(*fonct)(Arg...), Arg... arguments)
/// \arg Period type de pÃ©riode de temps (millisecond, secondes, microsecondes...)
/// \arg fonct pointeur sur la fonction Ã  chronomÃ©trer
/// \arg arguments liste des arguments Ã  passer Ã  la fonction
/// \return le temps d'exÃ©cution de la fonction passÃ©e en argument
/// \note Cette fonction est utilisÃ©e pour les fonction sans retour (les fonctions void) pour les autres, voir plus bas
template<class Period = std::ratio<1,1000>, typename... Arg>
long chronoFonct(void(*fonct)(Arg...), Arg... arguments) {
    system_clock::time_point debut = system_clock::now();
    fonct(arguments...);
    system_clock::time_point fin = system_clock::now();

    duration<int, Period> temps = std::chrono::duration_cast<std::chrono::duration<int,Period>>(fin-debut);
    return temps.count();
}

/// \fn chronoFonct(Ret(*fonct)(Arg...), Arg... arguments)
/// \arg Period type de pÃ©riode de temps (millisecond, secondes, microsecondes...)
/// \arg Ret le type de retour de la fonction (gÃ©nÃ©ralement, pas besoin de le prÃ©ciser)
/// \arg fonct pointeur sur la fonction Ã  chronomÃ©trer
/// \arg arguments liste des arguments Ã  passer Ã  la fonction
/// \return un std::pair contenant le temps d'exÃ©cution de la fonction et son retour
/// \note cette fonction est utilisÃ©e pour les fonction ayant un retour. Pour les procÃ©dures (fonctions "void") voir plus haut
template<class Period = std::ratio<1,1000>, typename Ret, typename... Arg>
std::pair<long, Ret> chronoFonct(Ret(*fonct)(Arg...), Arg... arguments) {
    Ret r;
    system_clock::time_point debut = system_clock::now();
    r = fonct(arguments...);
    system_clock::time_point fin = system_clock::now();
    duration<long, Period> temps = std::chrono::duration_cast<std::chrono::duration<long,Period>>(fin-debut);
    return std::make_pair(temps.count(), r);
}

#endif // CHRONOF_H_INCLUDED
