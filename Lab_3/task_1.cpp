#include<iostream>

// функция "вытяни туза" где req_map требуемая_карта, а deck_cards калода карт
void Proba_Bility (int req_map,  int deck_cards)
{
    // обьявляем переменню для расчёта вероятности
    float probability = static_cast<float> (req_map) / static_cast<float> (deck_cards);
    std::cout << "Вероятность вытянуть из колоды 52-х карт, туза = " << probability << " % " << "или 1/52" << '\n';
}


// фунция "игра в кости" где num_of_out количество исходов, а num_of_kmb общее число комбинаций
void Game_Dice (int num_of_out, int num_of_kmb)
{
    // обьявляем переменню для расчёта удачи
    float luck = static_cast<float>(num_of_out) / static_cast<float>(num_of_kmb);
    std::cout << "При игре в коси, двумя кубиками вероятность того, что сумма выпавших очков будет равна 7 = " << luck << " % " << " или "
                   << (num_of_out / num_of_out) << '/' << (num_of_kmb / num_of_out) << '\n';
}


// функция "игра с буквами" где total cards всего карточек, а location расположение карточек
void  Letter_Game(int total_cards, int location)
{
    // обьявляем переменню для расчёта вероятности
   float probability = static_cast<float> (total_cards) / static_cast<float> (location);
   std::cout << "Вероятность что при случайном расположении букв в ряд  получится слово «МАМА» = " << probability << " % "
                  << " или " << (total_cards / total_cards) << '/' << (location /total_cards) << '\n';
}

