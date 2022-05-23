#include <iostream>
#include "gacha.h"

int main() {
    gacha::GlobalDataManager::InitCharacterActivitysInfomationMap();
    gacha::GlobalDataManager::InitCharacterActivitysInfomationMapEvent2();
    gacha::GlobalDataManager::InitWeaponActivitysInfomationMap();
    gacha::GachaHelperFactory factory;
    auto helper = factory.GetHelper(gacha::BannerType::Weapon_Event_Wish);
    dynamic_cast<gacha::WeaponGachaHelper*>(helper)->SetBanner(11);
    dynamic_cast<gacha::WeaponGachaHelper*>(helper)->SetFateWeapon(gacha::FateWeapon::Weapon_1);
    for (int i = 0; i < 100; i++) {
        helper->GachaGacha();
        if (helper->GetRarity() == gacha::Rarity::Superior_Super_Rare_Characeter) {
            std::cout << "rarity: SSR";
            std::cout << " item name: " << gacha::s_pname_cn[helper->GetItemId()]
                << std::endl;
        }
        if (helper->GetRarity() == gacha::Rarity::Super_Rare_Character) {
            std::cout << "rarity: SR";
            std::cout << " item name: " << gacha::s_pname_cn[helper->GetItemId()]
                << std::endl;
        }
        if (helper->GetRarity() == gacha::Rarity::Super_Rare_Weapon) {
            std::cout << "rarity: SR";
            std::cout << " item name: " << gacha::s_pname_cn[helper->GetItemId()]
                << std::endl;
        }
    }
    return 0;
}