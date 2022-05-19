#include <iostream>
#include "gacha.h"

int main() {
    gacha::GachaHelperFactor factory;
    auto helper = factory.GetHelper(gacha::BannerType::Character_Event_Wish);
    dynamic_cast<gacha::CharacterGachaHelper*>(helper)->SetBanner(11);
    for (int i = 0; i < 10000; i++) {
        helper->GachaGacha(gacha::BannerType::Character_Event_Wish, 11);
        if (helper->GetRarity() == gacha::Rarity::Superior_Super_Rare_Characeter) {
            std::cout << "rarity: SSR";
            std::cout << " item name: " << gacha::s_pname_cn[helper->GetItemId()]
                << std::endl;
        }
    }
    return 0;
}