#include <iostream>
#include "gacha.h"

int main() {
    gacha::GachaHelper helper;
    for (size_t i = 0; i < 10000; i++) {
        helper.GachaGacha(gacha::BannerType::Character_Event_Wish, 11);
        if (helper.m_current_rarity == gacha::Rarity::Superior_Super_Rare_Characeter) {
            std::cout << "rarity: SSR";
            std::cout << " item name: " << gacha::s_pname_cn[helper.item_id]
                << std::endl;
        }      
    }
    return 0;
}